#!/usr/bin/env python
# -*- coding:utf-8 -*-

import socket
from time import ctime

HOST = '127.0.0.1'
PORT = 21567
BUFFERSIZE = 1024

udpServSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udpServSocket.bind((HOST, PORT))

while True:
    print('Waiting for message...')
    data, addr = udpServSocket.recvfrom(BUFFERSIZE)
    udpServSocket.sendto('[%s] %s' % (ctime(), data), addr)
    print('...received from and return to:', addr)

udpServSocket.close()