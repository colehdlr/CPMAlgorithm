# ======================
# Project configuration
# ======================

CC = gcc
TARGET = cpm
BUILD_DIR = build

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=$(BUILD_DIR)/%.o)

# Vendored single-file sources compiled into the same build dir.
VENDOR_OBJ = $(BUILD_DIR)/cJSON.o

DEP = $(OBJ:.o=.d) $(VENDOR_OBJ:.o=.d)

# ======================
# Vendored raylib
# ======================
# Static lib + headers live in vendor/raylib/. Pick the right .a per platform.

RAYLIB_DIR     = vendor/raylib
RAYLIB_INCLUDE = $(RAYLIB_DIR)/include

# ======================
# Vendored cJSON
# ======================
# Single-file library: compiled from source, no prebuilt lib needed.

CJSON_DIR     = vendor/cjson
CJSON_INCLUDE = $(CJSON_DIR)

UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

ifeq ($(UNAME_S),Darwin)
    RAYLIB_LIB     = $(RAYLIB_DIR)/lib/macos/libraylib.a
    PLATFORM_LIBS  = -framework Cocoa -framework IOKit -framework CoreVideo -framework OpenGL
else ifeq ($(UNAME_S),Linux)
    ifeq ($(UNAME_M),x86_64)
        RAYLIB_LIB = $(RAYLIB_DIR)/lib/linux-amd64/libraylib.a
    else
        $(error No vendored raylib for Linux $(UNAME_M). See vendor/raylib/README.md)
    endif
    PLATFORM_LIBS  = -lGL -lm -lpthread -ldl -lrt -lX11
else
    $(error Unsupported platform $(UNAME_S). See vendor/raylib/README.md)
endif

# ======================
# Compiler flags
# ======================

CFLAGS = -Wall -std=c99 -O2 -Iinclude -I$(RAYLIB_INCLUDE) -I$(CJSON_INCLUDE) -MMD -MP
DEBUG_CFLAGS = -Wall -std=c99 -g -O0 -Iinclude -I$(RAYLIB_INCLUDE) -I$(CJSON_INCLUDE) -MMD -MP

LDFLAGS = $(RAYLIB_LIB) $(PLATFORM_LIBS)

# ======================
# Build rules
# ======================

all: $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET): $(OBJ) $(VENDOR_OBJ) | $(BUILD_DIR)
	$(CC) $(OBJ) $(VENDOR_OBJ) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: src/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/cJSON.o: $(CJSON_DIR)/cJSON.c | $(BUILD_DIR)
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

# ======================
# Tests
# ======================
# Build a small test binary that exercises parse + cpm without raylib or main.

TEST_SRC = tests/test_cpm.c
TEST_BIN = $(BUILD_DIR)/test_cpm
TEST_OBJ = $(BUILD_DIR)/parse.o $(BUILD_DIR)/cpm.o $(VENDOR_OBJ)

$(TEST_BIN): $(TEST_SRC) $(TEST_OBJ) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -Isrc $(TEST_SRC) $(TEST_OBJ) -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

.PHONY: all run debug lldb clean test
