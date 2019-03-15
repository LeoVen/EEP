import socket

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

    # Send information to client
    clientsocket.send(bytes("Welcome to the server!", "utf-8"))

    clientsocket.close()