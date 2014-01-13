#!/usr/bin/env python

import socket
import time

TCP_IP = 'localhost'        
TCP_PORT = 9999   
BUFFER_SIZE = 1024      
MESSAGE = '01'  

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)    
s.bind((TCP_IP, TCP_PORT))     
s.listen(1)     

conn, addr = s.accept()         
print ('Connection address:', addr)      
while 1:       
    #data = conn.recv(BUFFER_SIZE)     
    #if not data: break      
    #print ('received data:', data)               
    #bytes = '\x12\x00\x12\x00\x12\x00\x12\x00'   
    #conn.send(bytes)  # echo
    time.sleep(1)
    bytes = '\x12\x00'
    conn.send(bytes)  # echo
    time.sleep(1)
    bytes = '\x13\x00'
    conn.send(bytes)  # echo
    time.sleep(1)
    bytes = '\x12\x00'
    conn.send(bytes)  # echo
    time.sleep(1)
    bytes = '\x20\x03\xFF\x00\x00';
    conn.send(bytes)  # echo
    #time.sleep(1)
    #conn.send('Bulb Random')  # echo
    #time.sleep(1)
    #conn.send('Bulb GREEN')  # echo
    break 

#print ('Sending data to client...')   
#s.connect((addr, TCP_PORT))
#s.send(MESSAGE)
#data = s.recv(BUFFER_SIZE)
s.close()