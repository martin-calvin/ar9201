#!/usr/bin/python
# -*- coding: UTF-8 -*-

import socket
import struct

s1 = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
s2 = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

host = socket.gethostname()
port = 1234

s1.connect(('192.168.199.56',port))
s2.connect(('192.168.199.56',port))

#test read reg 0x60633000
for i in range(1):
    #read trunk
    req=struct.pack('=BBBBHIBHBBIH', 0xff, 0x5a, 0, 0x1, 0x0, 0x8, 0x0, 0x0,               0x2, 0x1, 0x60633000, 0x4)
    s1.send(req)
    ack=s1.recv(1024)
    for j in range(len(ack)):
        print(hex(ack[j]), end=' ')
    print('')

    #read one by one
    req=struct.pack('=BBBBHIBHBBIIII', 0xff, 0x5a, 0, 0x1, 0x0, 0x12, 0x0, 0x0,            0x2, 0x0, 0x60633000, 0x60633004, 0x60633008, 0x6063300c)
    s1.send(req)
    ack=s1.recv(1024)
    for j in range(len(ack)):
        print(hex(ack[j]), end=' ')
    print('')

    #write trunk
    req=struct.pack('=BBBBHIBHBBIHIIII', 0xff, 0x5a, 0, 0x1, 0x0, 0x18, 0x0, 0x0,               0x0, 0x1, 0x60633000, 0x4, 0xa, 0xb, 0xc, 0xd)
    s1.send(req)
    ack=s1.recv(1024)
    for j in range(len(ack)):
        print(hex(ack[j]), end=' ')
    print('')

    #read trunk
    req=struct.pack('=BBBBHIBHBBIH', 0xff, 0x5a, 0, 0x1, 0x0, 0x8, 0x0, 0x0,               0x2, 0x1, 0x60633000, 0x4)
    s1.send(req)
    ack=s1.recv(1024)
    for j in range(len(ack)):
        print(hex(ack[j]), end=' ')
    print('')


    #write one by one
    req=struct.pack('=BBBBHIBHBBIIIIIIII', 0xff, 0x5a, 0, 0x1, 0x0, 0x22, 0x0, 0x0,               0x0, 0x0, 0x60633000, 0x5, 0x60633004, 0x6, 0x60633008, 0x7, 0x6063300c, 0x8)
    s1.send(req)
    ack=s1.recv(1024)
    for j in range(len(ack)):
        print(hex(ack[j]), end=' ')
    print('')

    #read one by one
    req=struct.pack('=BBBBHIBHBBIIII', 0xff, 0x5a, 0, 0x1, 0x0, 0x12, 0x0, 0x0,            0x2, 0x0, 0x60633000, 0x60633004, 0x60633008, 0x6063300c)
    s1.send(req)
    ack=s1.recv(1024)
    for j in range(len(ack)):
        print(hex(ack[j]), end=' ')
    print('')

s1.close()
s2.close()
