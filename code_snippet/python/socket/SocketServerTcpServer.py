#!/usr/bin/env python
# -*- coding:utf-8 -*-

import SocketServer
from time import ctime

HOST = 'localhost'
PORT = 21567

class MyRequestHandler(SocketServer.StreamRequestHandler):
    def handle(self):
        print('...connected from: ', self.client_address)
        self.wfile.write('[%s] %s' % (ctime(), self.rfile.readline()))

tcpServ = SocketServer.TCPServer((HOST, PORT), MyRequestHandler)
print('waiting for connection...')
tcpServ.serve_forever()