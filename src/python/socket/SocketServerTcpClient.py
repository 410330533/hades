#!/usr/bin/env python
# -*- coding:utf-8 -*-

import socket

HOST = '0.0.0.0'
PORT = 21567
BUFSIZE = 1024
encoding = 'utf-8'

while True:
    tcpClientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    tcpClientSocket.connect((HOST, PORT))
    data = input('> ')
    if not data:
        break
    
    tcpClientSocket.send(bytes(data+"\r\n", encoding))
    data = tcpClientSocket.recv(BUFSIZE)
    if not data:
        break
    
    print(data.strip())
    tcpClientSocket.close()