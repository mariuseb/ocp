#import matplotlib
#matplotlib.use('QtAgg') # or 'TkAgg'
import pandas as pd
import sys, os
import dateutil.parser as dp
import requests # See http://docs.python-requests.org/
import numpy as np
import re
    
def sanitize_index(frame):
    frame["dt_index"] = frame.index
    frame['clean_date'] = frame["dt_index"].str.replace(
        r'\sCE[S]?T$', '', regex=True
    )
    frame = frame[~frame.index.duplicated(keep='first')]
    drop_inds = [
        ndx for ndx in frame.index if not len(frame.loc[ndx, "clean_date"].split(" ")[1]) == 8
    ]
    #frame = frame.drop([drop_inds], axis=1)
    for ndx in drop_inds:
        frame = frame.drop(ndx)
    frame['datetime_naive'] = pd.to_datetime(
        frame['clean_date'], format='%d/%m/%Y %H:%M:%S'
    )
    frame.index = frame["datetime_naive"]
    return frame


def read_single_series(
    path
):
    frame = pd.read_csv(
        path,
        index_col=0,
        header=[1]
    )
    frame["dt_index"] = frame.index
    frame['clean_date'] = frame["dt_index"].str.replace(
        r'\sCE[S]?T$', '', regex=True
    )
    frame['clean_date'] = frame['clean_date'].apply(
        lambda x: re.sub(r"\.\d{3}(?!\d)", "", x)
    )
    index = pd.to_datetime(
        frame["clean_date"].values, format='%d/%m/%Y %H:%M:%S'
    )
    frame.index = index
    frame = frame["Value"]
    return frame


def read_data(dirname):
    files = os.listdir(dirname)
    frames = []
    for file in files:
        frame = pd.read_csv(
            os.path.join(
                dirname,
                file
            ),
            index_col=0,
            header=1
        )
        colname = file[:-4]
        frame.rename(
            columns={
                "Value": colname
            },
            inplace=True
        )
        frame = sanitize_index(frame)
        frame = frame[colname]
        frames.append(frame)
        
    frames = [
        frame.loc[~frame.index.duplicated(keep="first")]
        for frame in frames
    ]
    df = pd.concat(frames, axis=1, join="inner")
    return df

def get_stations(
        client_id, 
        start,
        end,
        names
    ):
    """
    Get the available stations.
    """
    r = requests.get(
        'https://frost.met.no/sources/v0.jsonld',
        #{'sources': station, 
        # 'elements': voi, #, sum(precipitation_amount PT12H)', 
        # 'referencetime': start+'/'+end},
        auth=(client_id, '')
    )
    _json = r.json()["data"]
    df = pd.DataFrame(columns = ["municipality", "name", "id"])
    matches = []
    for elem in _json:
        #if elem["country"] == "Norge":
        try:
            kommune = elem["municipality"]
            _id = elem["id"]
            if kommune in names:
                matches.append(_id)
                df.loc[_id] = np.zeros(3,)
                #df.loc[i, "municipality"] = elem[""]
                for col in df.columns:
                    df.loc[_id, col] = elem[col]
        except KeyError:
            pass
    return df
      
def get_observations(
        client_id,
        station_id,
        start,
        stop
    ):
    r = requests.get(
        'https://frost.met.no/observations/availableTimeSeries/v0.jsonld',
        {'sources': station_id,
        'referencetime': start+'/'+stop},
        auth=(client_id, '')
    )
    _json = r.json()["data"]
    df = pd.DataFrame(columns=["id", "res"])
    for i, elem in enumerate(_json):
        df.loc[i] = [elem["elementId"],elem["timeResolution"]]
    return df
      

def get_metno_data(
        station,
        voi,
        start,
        end,
        client_id
    ):
    """
    This function follows the metno example. https://frost.met.no/langex_python
    """
    # issue an HTTP GET request
    r = requests.get(
        'https://frost.met.no/observations/v0.jsonld',
        {'sources': station, 
         'elements': voi, #, sum(precipitation_amount PT12H)', 
         'referencetime': start+'/'+end,
         "timeresolutions": "PT1H"},
        auth=(client_id, '')
    )

    time = []
    data = {}

    # extract the time series from the response
    if r.status_code == 200:
        """
        for element in range(0, len(r.json()['data'][0]['observations'])):
            data[r.json()['data'][0]['observations'][element]['elementId']] = []
        for item in r.json()['data']:
            iso8601 = item['referenceTime']
            secsSince1970 = dp.parse(iso8601).strftime('%s')
            #sys.stdout.write('{} {} {}\n'.format(iso8601, secsSince1970, item['observations'][0]['value']))
            time.append(iso8601)
            for element in range(0, len(item['observations'])):
                data[item['observations'][element]['elementId']].append(item['observations'][element]['value'])
        """
        rows = []
        for item in r.json()["data"]:
            for obs in item["observations"]:
                rows.append({
                    "referenceTime": item["referenceTime"],
                    "sourceId": item["sourceId"],
                    "elementId": obs["elementId"],
                    "value": obs["value"],
                    "unit": obs.get("unit"),
                    "timeOffset": obs.get("timeOffset"),
                    "timeResolution": obs.get("timeResolution"),
                    "level": obs.get("level"),
                    "qualityCode": obs.get("qualityCode"),
                    "performanceCategory": obs.get("performanceCategory"),
                })
        row_df = pd.DataFrame(rows)
        if voi == "air_temperature":
            row_df = row_df[
                row_df["level"].apply(
                    lambda level: (
                        isinstance(level, dict)
                        and level.get("levelType") == "height_above_ground"
                        and level.get("value") == 2
                    )
                )
            ]

    else:
        sys.stdout.write('error:\n')
        sys.stdout.write('\tstatus code: {}\n'.format(r.status_code))
        if 'error' in r.json():
            assert(r.json()['error']['code'] == r.status_code)
            sys.stdout.write('\tmessage: {}\n'.format(r.json()['error']['message']))
            sys.stdout.write('\treason: {}\n'.format(r.json()['error']['reason']))
        else:
            sys.stdout.write('\tother error\n')
    #df = pd.DataFrame(data, index=time)
    return row_df
