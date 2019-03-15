import socket

# Header size
HDRSIZE = 10

# AF_INET     = IPV4
# SOCK_STREAM = TCP
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect to socket
s.connect((socket.gethostname(), 1234))

while True:

	full_msg = ""
	new_msg = True
	msg_len = 0

	# Receive bytes
	while True:

		msg = s.recv(16)

		if new_msg:
			msg_len = int(msg[:HDRSIZE])
			print(f"New message length: {msg_len}")
			new_msg = False

		full_msg += msg.decode("utf-8")

		if len(full_msg) - HDRSIZE == msg_len:
			print("Full message received")
			print(full_msg[HDRSIZE:])
			new_msg = True
			full_msg = ""
