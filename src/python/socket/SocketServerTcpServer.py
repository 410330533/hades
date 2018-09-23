#!/usr/bin/env python
# -*- coding:utf-8 -*-

import socketserver
from time import ctime

HOST = '0.0.0.0'
PORT = 21567
encoding = 'utf-8'

class MyRequestHandler(socketserver.BaseRequestHandler):
    def handle(self):
        print('connected from... ', self.client_address)
        data = str(self.request.recv(1024), 'utf-8')
        self.request.sendall(bytes("[Server] {}".format(data), encoding))

tcpServ = socketserver.TCPServer((HOST, PORT), MyRequestHandler)
print('waiting for connection...')
tcpServ.serve_forever()