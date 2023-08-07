def d_water (t):
    a = 1.51728258718231E-05
    b = -5.79814298131964E-03
    c = 0.012190155722692
    d = 1000.26519274006
    rho =a*t**3+b*t**2+c*t+d #kg/m3
    return rho;

def h_water (t):
    a = 4.18575022797163
    b = 0.568872214709824
    enthalpy = (a*t+b)*1000 #J/kg
    return enthalpy;

def align_yaxis(ax1, v1, ax2, v2):
    """adjust ax2 ylimit so that v2 in ax2 is aligned to v1 in ax1"""
    _, y1 = ax1.transData.transform((0, v1))
    _, y2 = ax2.transData.transform((0, v2))
    adjust_yaxis(ax2,(y1-y2)/2,v2)
    adjust_yaxis(ax1,(y2-y1)/2,v1)

def adjust_yaxis(ax,ydif,v):
    """shift axis ax by ydiff, maintaining point v at the same location"""
    inv = ax.transData.inverted()
    _, dy = inv.transform((0, 0)) - inv.transform((0, ydif))
    miny, maxy = ax.get_ylim()
    miny, maxy = miny - v, maxy - v
    if -miny>maxy or (-miny==maxy and dy > 0):
        nminy = miny
        nmaxy = miny*(maxy+dy)/(miny+dy)
    else:
        nmaxy = maxy
        nminy = maxy*(miny+dy)/(maxy+dy)
    ax.set_ylim(nminy+v, nmaxy+v)
    
def dropRows (df, fromTime, toTime):
    from datetime import datetime
    mask = ((df.index<datetime.strptime(fromTime,"%Y-%m-%d %H:%S:%M")) | (df.index>datetime.strptime(toTime,"%Y-%m-%d %H:%S:%M"))) 
    df_filtered = df[mask]
    return df_filtered

def setTimeZone(df):
    import pytz
    tz=pytz.timezone('Europe/Oslo')
    df.index = df.index.tz_localize(tz)
    return df

def shiftPart(df, fromTime, freq):
    from datetime import datetime
    mask1 = (df.index<datetime.strptime(fromTime,"%Y-%m-%d %H:%S:%M"))
    mask2 = (df.index>=datetime.strptime(fromTime,"%Y-%m-%d %H:%S:%M"))
    df2 = df[mask2]
    df = df[mask1]
    df2=df2.shift(periods=1, freq=freq)
    df=df.append(df2)
    return df