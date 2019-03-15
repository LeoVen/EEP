import socket
import time
import datetime
import pickle

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

    data = {1: "Hello,", 2: " World!"}
    # Encode
    msg = pickle.dumps(data)

    msg = bytes(f"{len(msg):<{HDRSIZE}}", "utf-8") + msg

    # Send information to client
    clientsocket.send(msg)
