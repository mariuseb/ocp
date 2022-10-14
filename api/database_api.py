from configparser import ConfigParser
from sqlalchemy import create_engine, text

import datetime as datetime
import pandas as pd
import numpy as np

class Config():
    def __init__(self,ini):
        self.ini = ini

    def parse(self, section):
        
        parser = ConfigParser()
        parser.read(self.ini)

        cfg = {}
        if parser.has_section(section):
            params = parser.items(section)
            for param in params:
                cfg[param[0]] = param[1]
        else:
            raise Exception('Section {0} not found in the {1} file'.format(self.section, self.ini))

        return cfg

class Database():
    def __init__(self,ini, section, db):
        
        self.cfg = Config(ini).parse(section)
        self.conn = self.engine()
        self.create(db)
        self.connect(db)

        print('PostgreSQL version: {}'.format(self.version()))
        print('Current database : {}'.format(self.current()))

    def version(self):
        return self.conn.execute( text( 'SELECT version();')).fetchall()[0]['version']


    def engine(self, db='postgres'):
        
        return create_engine(   self.cfg['db_type']+'+'+ self.cfg['db_connector']+ '://'+ 
                                self.cfg['user']+':'+ self.cfg['password']+'@'+
                                self.cfg['host']+':'+self.cfg['port']+'/'+db)

    def create(self, db):
        
        if db not in self.list():
            self.conn.connect().execution_options(isolation_level="AUTOCOMMIT").execute( text( 'CREATE DATABASE '+db+';'))

    def current(self):
        
        return self.conn.execute( text( 'SELECT current_database();')).fetchall()[0][0]

    def connect(self, db):
        
        if db in self.list() and db not in self.current():
            self.conn.connect().invalidate()
            self.conn.dispose()
            self.conn = self.engine(db)

    def list(self):
        
        if self.engine is not None:
            resp = self.conn.execute( text( 'SELECT datname FROM pg_database WHERE datistemplate = false;')).fetchall()
            return [resp[i][0] for i in range(len(resp))] 
    # drop database
    def drop(self, *args):
        
        if len(args[0]) == 1:
            db = args[0]
            if db in self.list():
                self.conn.connect().execution_options(isolation_level="AUTOCOMMIT").execute( text( 'DROP DATABASE '+db+';'))
            
        elif len(args[0]) == 3:
            db = args[0][0]
            schema = args[0][1]
            table = args[0][2]
            sql = 'DROP TABLE IF EXISTS {}.{}.{};'.format(db,schema, table)
            self.conn.execute( text( sql ))

    def write(self, schema, table, df):
        columns = list(df.columns)
        data = df.values

        if self.has_table(schema, table, columns):
            
            sql_columns = '\",\"'.join(columns)
            sql = 'INSERT INTO {}.{} ('.format(schema, table) + '\"' + sql_columns.lower() + '\") VALUES\n'
            for row in range(data.shape[0]):
                sql_values = '\',\''.join(data[row,:])
                print('row {}'.format(row))
                sql += ' ( \'' +sql_values+ '\'' + (' ),\n' if row<=data.shape[0]-2 else ' );')
            self.conn.execute( text( sql ))

    def read(self, schema, table, N=1):
        sql = 'SELECT * FROM {}.{} ORDER BY time ASC LIMIT {};'.format(schema,table,N)
        return pd.read_sql_query(sql, self.conn)
                
    def sample(self, schema, table, N=1):
        sql = 'SELECT * FROM {}.{} ORDER BY random() LIMIT {};'.format(schema,table,N)
        return pd.read_sql_query(sql, self.conn)
        

    def has_table(self, schema, table, columns):
        # check if schema exists and create, if not
        resp = self.conn.execute( text( 'SELECT schema_name FROM information_schema.schemata;')).fetchall()
        if schema not in [resp[i][0] for i in range(len(resp))]:
            self.conn.execute( text( 'CREATE SCHEMA '+schema+';'))
      
        # check is table in schema exists and create if not
        resp = self.conn.execute( text( 'SELECT * FROM information_schema.tables WHERE table_schema = \'{}\';'.format(schema))).fetchall()
        if len(resp) == 0 or table not in list(resp[0]):
            print('Create new schema.table: {}.{}'.format(schema, table))
            sql = 'CREATE TABLE ' + schema +'.'+ table + ' ( time '
            for column in columns:
               sql +=  ', ' + column + ' float ( 24 )' if column != 'time' else 'TIMESTAMP(3) PRIMARY KEY'
            sql += ' );'
            self.conn.execute( text( sql ))

        return True

if __name__ == '__main__':

    # instantiate database
    db = Database('../database.ini', 'postgresql','bacssaas')
   
    # Generate some random data
    columms = ['time','CO2RooAirSou_y','TRooAirNor_y','CO2RooAirNor_y','TRooAirSou_y','PHeaNor_y','PHeaSou_y']

    N = 100
    T = 5
    f = 1/T
    Ts = 0.1
    t0=datetime.datetime.now()
    time = [(t0+datetime.timedelta(seconds=k*Ts)).strftime('%Y-%m-%d %H:%M:%S.%f')[:-3]    for k in range(N)]
    CO2RooAirSou_y = [np.sin(2*np.pi*f*k*Ts) for k in range(N)]
    TRooAirNor_y = [np.sin(2*np.pi*f*k*Ts) for k in range(N)]
    CO2RooAirNor_y = [np.sin(2*np.pi*f*k*Ts) for k in range(N)]
    TRooAirSou_y = [np.sin(2*np.pi*f*k*Ts) for k in range(N)]
    PHeaNor_y = [np.sin(2*np.pi*f*k*Ts) for k in range(N)]
    PHeaSou_y = [np.sin(2*np.pi*f*k*Ts) for k in range(N)]

    data = np.stack([time, CO2RooAirSou_y, TRooAirNor_y, CO2RooAirNor_y, TRooAirSou_y, PHeaNor_y, PHeaSou_y], axis=1)

    # Drop table if it exists
    db.drop('bacssaas','test_schema','test_table')

    # Write the data
    db.write('test_schema','test_table', pd.DataFrame(columns=columms, data=data))

    # sample random rows
    print( 'Sample {} random samples from {}.{}: {}'.format( 10,'test_schema','test_table', db.sample('test_schema','test_table',N=10)))

    # read last 10 entries
    print( 'Read {} samples from database {}.{}: {}'.format( 10,'test_schema','test_table', db.read('test_schema','test_table',N=10)))

    print('Sucessfully tested class {}'.format(db.__class__.__name__))