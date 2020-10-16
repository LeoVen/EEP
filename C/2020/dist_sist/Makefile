CC = gcc
INCLUDE = ../../../../C-Macro-Collections/src
CFLAGS = -Wall --std=c11
BUILD = ./build
LINKLIB = -pthread
DEFINES = -DCMC_LOG_COLOR -DCMC_TEST_COLOR

.PHONY main: server.exe client.exe tests.exe

server.exe: $(BUILD)/messages.o $(BUILD)/server.o $(BUILD)/netapi.o
	$(CC) $^ -o $@ $(LINKLIB)

client.exe: $(BUILD)/messages.o $(BUILD)/client.o $(BUILD)/netapi.o
	$(CC) $^ -o $@ $(LINKLIB)

tests.exe: $(BUILD)/messages.o $(BUILD)/tests.o $(BUILD)/netapi.o
	$(CC) $^ -o $@ $(LINKLIB)

$(BUILD)/server.o: server.c build_dir
	$(CC) -c $< -o $@ -I $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/client.o: client.c build_dir
	$(CC) -c $< -o $@ -I $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/tests.o: tests.c build_dir
	$(CC) -c $< -o $@ -I $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/netapi.o: netapi.c netapi.h build_dir
	$(CC) -c $< -o $@ -I $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/messages.o: messages.c messages.h build_dir
	$(CC) -c $< -o $@ -I $(INCLUDE) $(CFLAGS) $(DEFINES)

.PHONY build_dir:
	mkdir -p $(BUILD)

clean:
	rm -f server.exe client.exe tests.exe $(BUILD)/*.o
