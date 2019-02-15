CC = gcc
CFLAGS = -Wall
INCLUDE = ./

test.exe: containers.o tests.o macro_list.h
	$(CC) $^ -o $@

%.o: %.c macro_list.h
	$(CC) -I $(INCLUDE) $(CFLAGS) -c $< -o $@

run: test.exe macro_list.h
	./test.exe