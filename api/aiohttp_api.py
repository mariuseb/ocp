from threading import Thread
from http import HTTPStatus
from aiohttp import web
import json, requests

class Client:
    def __init__(self, parent, url):
        self.parent_class = parent.__class__.__name__
        self.fn = parent.handler
        self.url = url

    def request(self, payload):
        try:
            resp = requests.post( self.url+'/', data=json.dumps({'source':self.parent_class, 'meta':payload}))
            return resp.status_code, json.loads(str(resp.content, encoding='utf-8')) 
        except Exception as error:
            print('\033[91mException in {}.request:{}\033[0m'.format(self.__class__.__name__,  str(error))) 

class Server:
    def __init__(self, container):
        self.container = container

    async def post(self, request):
        try:
            text = json.dumps({'source':self.container.__class__.__name__,'meta':self.container.handler({'meta':await request.json()})})
            return web.Response(text=text)
        except Exception as error:
            print('\033[91mException in {}.request:{}\033[0m'.format(self.__class__.__name__,  str(error))) 

    def main(self):
        app = web.Application()

        app.add_routes([web.post('/', self.post)])
        
        Thread(target = self.container.main).start()
        web.run_app(app, port=6000)
