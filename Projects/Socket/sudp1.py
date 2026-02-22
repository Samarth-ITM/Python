import socket

ss = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

ss.bind(("127.0.0.1", 12345))
print("Server is running...")

while True:
    data, add = ss.recvfrom(4096)
    print(str(data))
    mess = b"Hello Client"
    ss.sendto(mess,add)
    
