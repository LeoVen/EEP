CC = gcc
CFLAGS = -Wall

test.exe: common_lists.o tests.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@