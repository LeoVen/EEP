CC = gcc
INCLUDE = -I ./lib/cmc -I ./include
CFLAGS = -Wall --std=c11
BUILD = ./build
LINKLIB = -pthread
DEFINES = -DCMC_LOG_COLOR -DCMC_TEST_COLOR
SRC_DIR = ./src
INCLUDE_DIR = ./include

.PHONY main: server.exe client.exe tests.exe

server.exe: $(BUILD)/messages.o $(BUILD)/server.o $(BUILD)/netapi.o $(BUILD)/collections.o $(BUILD)/mail.o $(BUILD)/database.o
	$(CC) $^ -o $@ $(LINKLIB)

client.exe: $(BUILD)/messages.o $(BUILD)/client.o $(BUILD)/netapi.o $(BUILD)/collections.o $(BUILD)/mail.o $(BUILD)/database.o
	$(CC) $^ -o $@ $(LINKLIB)

tests.exe: $(BUILD)/messages.o $(BUILD)/tests.o $(BUILD)/netapi.o $(BUILD)/collections.o $(BUILD)/mail.o $(BUILD)/database.o
	$(CC) $^ -o $@ $(LINKLIB)

$(BUILD)/server.o: $(SRC_DIR)/server.c build_dir
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/client.o: $(SRC_DIR)/client.c build_dir
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/tests.o: $(SRC_DIR)/tests.c build_dir
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/collections.o: $(SRC_DIR)/collections.c $(INCLUDE_DIR)/collections.h build_dir
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/database.o: $(SRC_DIR)/database.c $(INCLUDE_DIR)/database.h build_dir
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/mail.o: $(SRC_DIR)/mail.c $(INCLUDE_DIR)/mail.h build_dir
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/messages.o: $(SRC_DIR)/messages.c $(INCLUDE_DIR)/messages.h build_dir
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS) $(DEFINES)

$(BUILD)/netapi.o: $(SRC_DIR)/netapi.c $(INCLUDE_DIR)/netapi.h build_dir
	$(CC) -c $< -o $@ $(INCLUDE) $(CFLAGS) $(DEFINES)

.PHONY build_dir:
	mkdir -p $(BUILD)

clean:
	rm -f server.exe client.exe tests.exe $(BUILD)/*.o
