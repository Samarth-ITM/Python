import socket

c = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)


mess = b"Hello Server"

c.sendto(mess, ("127.0.0.1", 12345))




data, add = c.recvfrom(4096)

print(str(data))

c.close()
    