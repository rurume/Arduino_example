import socket
import sys
from thread import *
 
ServerIp = ''   
ServerPort = 54321 #Socket Server Port Num
 
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print 'Socket created'
 
try:
    s.bind((ServerIp, ServerPort))
except socket.error , msg:
    print 'Bind failed. Error Code : ' + str(msg[0]) + ' Msg ' + msg[1]
    sys.exit()
     
print 'Socket Bind OK!!'
 
s.listen(10)
print 'Socket Listening..'
 
def clientthread(conn):
    conn.send('This is Rpi Socket Server.') 
     
    while True:
         
        data = conn.recv(1024)
        print data
        if not data: 
            break
     
        conn.sendall('Recv Cmd Success!!')
     
    conn.close()
 
while 1:
    conn, ipAddr = s.accept()
    print 'Socket Client(Android phone) IP is' + ipAddr[0] + ':' + str(ipAddr[1])
    
    start_new_thread(clientthread ,(conn,))
 
s.close()
