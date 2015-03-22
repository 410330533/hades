#!/usr/bin/env python
# -*- coding:utf-8 -*-

import socket

HOST = 'localhost'
PORT = 21567
BUFSIZE = 1024

while True:
    tcpClientSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    tcpClientSocket.connect((HOST, PORT))
    data = raw_input('> ')
    if not data:
        break
    
    tcpClientSocket.send('%s\r\n' % data)
    data = tcpClientSocket.recv(BUFSIZE)
    if not data:
        break
    
    print(data.strip())
    tcpClientSocket.close()