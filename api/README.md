#### Getting started <aiohttp_api>

The following source illustrates a simple class setup with backend REST API server. The host class and backend server are running on seperate threads allowing asynchronous communication. The client can make put request any multiple endpoints.

    from api.aiohttp_api import Server, Client
    import asyncio
    import time

    class <Container>:
        
        def __init__(self):
            self.client = Client(self.handler, 'http://bacssaas_<endpoint>:6000')

        def handler(self, payload):

            print('Handler routine of {} running'.format(self.__class__.__name__))

            if payload['method'] == 'get':
                if payload['endpoint'] == 'about':
                    return 'Backend server response for {} container class'.format(self.__class__.__name__)


        def main(self):
            print('Main routine of {} running'.format(self.__class__.__name__))
            while 1:
                time.sleep(2)
                asyncio.run(self.client.get('about'))
                print('Idle..')


    if __name__ == '__main__':
        Server(Container()).main()

#### Getting started <database_api>

For BACSSaaS, each BOPTEST testcase creates its own database named to the testcase name