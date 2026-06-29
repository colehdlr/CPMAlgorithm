# ======================
# Project configuration
# ======================

CC = gcc
TARGET = cpm
BUILD_DIR = build

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=$(BUILD_DIR)/%.o)
DEP = $(OBJ:.o=.d)

# ======================
# Compiler flags
# ======================

CFLAGS = -Wall -std=c99 -O2 -Iinclude -MMD -MP
DEBUG_CFLAGS = -Wall -std=c99 -g -O0 -Iinclude -MMD -MP

LDFLAGS =

# ======================
# Build rules
# ======================

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEP)

# ======================
# Utilities
# ======================

run: all
	./$(BUILD_DIR)/$(TARGET)

debug: CFLAGS = $(DEBUG_CFLAGS)
debug: clean all

lldb: debug
	lldb ./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
