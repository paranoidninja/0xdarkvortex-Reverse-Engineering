#!/usr/bin/python3

##Author : Paranoid Ninja
##Email  : paranoidninja@protonmail.com
##Descr  : Listen on port 8080 for binary to connect and send a response based on the request

import socket

TCPSERVER = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
TCPSERVER.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
TCPSERVER_ADDRESS = ("127.0.0.1", 8080)
TCPSERVER.bind(TCPSERVER_ADDRESS)
TCPSERVER.listen(100)

while True:
	print("[+] Waiting for client connection...")
	(TCPCLIENT, TCPCLIENT_ADDRESS) = TCPSERVER.accept()
	print("[+] Client Connected: " + str((TCPCLIENT_ADDRESS)[0]) + ":" + str((TCPCLIENT_ADDRESS)[1]))
	GetKey = ((TCPCLIENT.recv(1024)).decode('utf-8')).rstrip()
	#GetKey = (TCPCLIENT.recv(1024))
	print("[!] Verifying Keys..")
	print(GetKey)
	if (GetKey == 'strongpass\x00'):
		TCPCLIENT.send(("Valid\n").encode('utf-8'))
	else:
		TCPCLIENT.send(("InValid").encode('utf-8'))
		TCPCLIENT.close()
