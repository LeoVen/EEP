CC = gcc
INCLUDE = ../../../../C-Macro-Collections/src
CFLAGS = -Wall
BUILD = ./build
LINKLIB = -lws2_32
# DEFINES = -DCMC_LOG_COLOR
DEFINES =

.PHONY main: server.exe client.exe tests.exe

server.exe: $(BUILD)/messages.o $(BUILD)/server.o
	$(CC) $^ -o $@ $(LINKLIB)

client.exe: $(BUILD)/messages.o $(BUILD)/client.o
	$(CC) $^ -o $@ $(LINKLIB)

tests.exe: $(BUILD)/messages.o $(BUILD)/tests.o
	$(CC) $^ -o $@ $(LINKLIB)

$(BUILD)/server.o: server.c build_dir
	$(CC) -c $< -o $@ -I $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/client.o: client.c build_dir
	$(CC) -c $< -o $@ -I $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/tests.o: tests.c build_dir
	$(CC) -c $< -o $@ -I $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/messages.o: messages.c messages.h build_dir
	$(CC) -c $< -o $@ -I $(INCLUDE) $(CFLAGS) $(DEFINES)

.PHONY build_dir:
	mkdir -p $(BUILD)

clean:
	rm server client tests $(BUILD)/*.o
