#!/usr/bin/env python
# -*- coding:utf-8 -*-

import socket
from time import ctime

HOST = '127.0.0.1'
PORT = 5000
BUFFERSIZE = 1024

tcpServSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcpServSocket.bind((HOST, PORT))
tcpServSocket.listen(5)

while True:
    print('Waiting for connection...')
    tcpCliSocket, address = tcpServSocket.accept()
    print('Connected by', address)

    while True:
        data = tcpCliSocket.recv(BUFFERSIZE)
        if not data:
            break
        tcpCliSocket.send('[%s] %s' % (ctime(), data))
        
    tcpCliSocket.close()
tcpServSocket.close()
