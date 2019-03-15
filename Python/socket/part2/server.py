import socket
import time
import datetime

# Header size
HDRSIZE = 10

# AF_INET     = IPV4
# SOCK_STREAM = TCP
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# bind socket (IP, PORT)
s.bind((socket.gethostname(), 1234))

# Queue of size 5
s.listen(5)

while True:
    clientsocket, address = s.accept()
    print(f"Connection from {address} has been established!")

    msg = "Welcome to the server!"
    msg = f"{len(msg):<{HDRSIZE}}" + msg

    # Send information to client
    clientsocket.send(bytes(msg, "utf-8"))

    while True:
        time.sleep(3)
        msg = f"The time is {datetime.datetime.now()}"
        msg = f"{len(msg):<{HDRSIZE}}" + msg
        clientsocket.send(bytes(msg, "utf-8"))
