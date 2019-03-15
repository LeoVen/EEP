import socket

# AF_INET     = IPV4
# SOCK_STREAM = TCP
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to socket
s.connect((socket.gethostname(), 1234))

full_msg = ""

# Receive bytes
while True:
	msg = s.recv(8)
	if len(msg) <= 0:
		break
	full_msg += msg.decode("utf-8")

print(full_msg)