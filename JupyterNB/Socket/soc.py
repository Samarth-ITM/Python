import socket
import sys

try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
except socket.error as e:
    print(e)
    sys.exit()
    
th = input("Target Host: ")
tp = int(input("Target Port: "))

try:
    s.connect((th, tp))
    print("Socket connected!")
    s.shutdown(2)
    
except socket.error as e:
    print(e)
    sys.exit()    
