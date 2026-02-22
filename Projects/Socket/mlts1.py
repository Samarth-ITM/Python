import socket
from _thread import * # pyright: ignore[reportWildcardImportFromLibrary]

s = socket.socket()

thc = 0

try:
    s.bind(("127.0.0.1", 12346))
    print("Socket binded successfully")
except socket.error as e:
    print(e)

s.listen(5)


def client_thread(conn):
    conn.send(str.encode("Welcome to the server."))
    while True:
        data = conn.recv(2048)
        reply = b"Server: " + data
        if not data:
            break
        conn.sendall(reply)

    conn.close()

while True:
    client, add = s.accept()
    print("Socket connected to ", add[0], str(add[1]))
    start_new_thread(client_thread, (client, ))
    thc += 1
