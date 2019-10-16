# !/usr/bin/python3
#pour linux

import socket

clientsocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = socket.gethostname() #ou sinon: host='192.168.0.28'
port = 444

clientsocket.connect((host, port))

message = clientsocket.recv(1024)

clientsocket.close()
print(message.decode('ascii'))

#pour utiliser le client: dans le cmd ; ecrire 'python3 client.py' (linux) 
# ou 'start D:\Raph\programmation\hacks\python_hsploit\client.py' (windows)