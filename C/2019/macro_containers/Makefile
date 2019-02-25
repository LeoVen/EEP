CC = gcc
CFLAGS = -Wall -Wextra
INCLUDE = ./

test.exe: containers.o tests.o macro_containers.h
	$(CC) $^ -o $@

%.o: %.c macro_containers.h
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

run: test.exe macro_containers.h
	./test.exe