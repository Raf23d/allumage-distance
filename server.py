#17:18 ; https://www.youtube.com/watch?v=2P8s_KV51rM&feature=youtu.be

# !/usr/bin/python3
#pour linux /\

import socket

serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = '192.168.0.28' #ou sinon: host=socket.gethostbyname()
port = 444 #port de connexion

serversocket.bind((host, port)) #on peut aussi rentrer directement notre ip et notre port

serversocket.listen(1) #nombre de connection qu'on veut ecouter au max

while True :
    clientsocket, address = serversocket.accept()
    print('connection reçue de %s ' % str(address))
    message='merci pour la connection au server' + '\r\n'
    clientsocket.send(message.encode('ascii'))
    clientsocket.close()

#pour mettre à mour le serveur dans le cmd: clic R ; 'run python file in terminal'