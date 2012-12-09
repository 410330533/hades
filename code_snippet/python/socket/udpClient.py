#!/usr/bin/env python
# -*- coding:utf-8 -*-

import socket

HOST = '127.0.0.1'
PORT = 21567
BUFFERSIZE = 1024

udpCliSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# udpCliSocket.bind((HOST, PORT))

while True:
    data = raw_input('> ')
    if not data:
        break
    udpCliSocket.sendto(data, (HOST, PORT))
    data, addr = udpCliSocket.recvfrom(BUFFERSIZE)
    if not data:
        break
    print('%s from %s' % (data, addr))

udpCliSocket.close()