#!/usr/bin/env python
# -*- coding:utf-8 -*-

import socket

HOST = '127.0.0.1'
PORT = 5000
BUFFERSIZE = 1024

tcpCliSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcpCliSocket.connect((HOST, PORT))

while True:
    data = raw_input('> ')
    if not data:
        break
    tcpCliSocket.send(data)
    data = tcpCliSocket.recv(BUFFERSIZE)
    if not data:
        break
    print(data)

tcpCliSocket.close()