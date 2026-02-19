import socket

c = socket.socket()

try:
    c.connect(("127.0.0.1", 12346))
    print("Client binded successfully")
except socket.error as e:
    print(e)
    
    
res = c.recv(1024)
while True:
    i = input("Enter: ")
    c.send(str.encode(i))
    res = c.recv(1024)
    print(res.decode('utf-8'))
    
c.close()

