import socket

ss = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

host = '127.0.0.1'
port = 12345

ss.bind((host, port))
ss.listen(5)

print("Server listening...")

while True:
    cs, addr = ss.accept()
    print("Connected from:", addr)

    data = cs.recv(1024)
    print("Received:", data.decode())

    cs.send(b"Hello World")
    cs.close()
