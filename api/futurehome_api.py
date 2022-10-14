from configparser import ConfigParser
import paho.mqtt.client as mqtt
import json

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

class FutureHome():
    def __init__(self, ini, section, handler_fn=None) -> None:
        
        self.cfg = Config(ini).parse(section)

        self.mqttc = mqtt.Client(client_id="bacssaas:orchestrator", clean_session=True, userdata=None, protocol=mqtt.MQTTv311, transport="tcp")
        
        self.mqttc.on_connect = self.on_connect
        self.mqttc.on_message = self.on_message if handler_fn is None else handler_fn

        self.mqttc.username_pw_set(username=self.cfg['username'],password=self.cfg['password'])
        self.mqttc.connect(host=self.cfg['ip'],port=int(self.cfg['port']), keepalive=60)

    def subscribe(self, topic):
        self.mqttc.subscribe(topic)

    def on_connect(self, client, userdata, flags, rc):
        
        print(f"Connected with result code {str(rc)}")

    def on_message(self, client, userdata, msg):
        
        topic = dict(map(str.strip, sub.split(':', 1)) for sub in msg.topic.split('/'))
        data = json.loads(msg.payload.decode('utf8').replace("'", '"'))
        
        print('Receive msg for topic:{}'.format(topic))
        print('Payload data:{}'.format(json.dumps(data, indent=4, sort_keys=True)))

    def run(self):
        self.mqttc.loop_forever()

if __name__ == '__main__':

    # instantiate datasbe
    fh = FutureHome('../futurehome.ini', 'marafioti')
    
    fh.subscribe('pt:j1/#')
    fh.run()

