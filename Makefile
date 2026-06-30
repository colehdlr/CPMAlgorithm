CC = gcc
TARGET = cpm
BUILD_DIR = build

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=$(BUILD_DIR)/%.o)
DEP = $(OBJ:.o=.d)

# Vendored raylib: static lib + headers under vendor/raylib/. Pick the right .a per platform.
RAYLIB_DIR     = vendor/raylib
RAYLIB_INCLUDE = $(RAYLIB_DIR)/include

UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

ifeq ($(UNAME_S),Darwin)
    RAYLIB_LIB    = $(RAYLIB_DIR)/lib/macos/libraylib.a
    PLATFORM_LIBS = -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL
else ifeq ($(UNAME_S),Linux)
    ifeq ($(UNAME_M),x86_64)
        RAYLIB_LIB = $(RAYLIB_DIR)/lib/linux-amd64/libraylib.a
    else
        $(error No vendored raylib for Linux $(UNAME_M). See vendor/raylib/README.md)
    endif
    PLATFORM_LIBS = -lGL -lm -lpthread -ldl -lrt -lX11
else
    $(error Unsupported platform $(UNAME_S). See vendor/raylib/README.md)
endif

CFLAGS  = -Wall -std=c99 -O2 -I$(RAYLIB_INCLUDE) -MMD -MP
LDFLAGS = $(RAYLIB_LIB) $(PLATFORM_LIBS)

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJ) | $(BUILD_DIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

-include $(DEP)

run: all
	./$(BUILD_DIR)/$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

# Tests: small binary that exercises cpm_compute directly (no parse, no raylib).
TEST_SRC = tests/test_cpm.c
TEST_BIN = $(BUILD_DIR)/test_cpm
TEST_OBJ = $(BUILD_DIR)/cpm.o

$(TEST_BIN): $(TEST_SRC) $(TEST_OBJ) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -Isrc $(TEST_SRC) $(TEST_OBJ) -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

.PHONY: all run clean test
