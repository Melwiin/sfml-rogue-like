CC := C:/msys64/mingw64/bin/g++.exe
CFLAGS := -fdiagnostics-color=always -g
LIBRARIES := -lsfml-main -lsfml-graphics -lsfml-window -lsfml-system
SFML_INCLUDE := $(SFML_DIR)/include
SFML_LIB := $(SFML_DIR)/lib

SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
EXE := $(BUILD_DIR)/out.exe

.PHONY: all run clean

all: $(EXE)

$(EXE): $(SRCS)
	$(CC) $(CFLAGS) $^ -I$(SFML_INCLUDE) -I$(INCLUDE_DIR) -L$(SFML_LIB) $(LIBRARIES) -o $(EXE)

debug: $(SRCS)
	$(CC) $(CFLAGS) $^ -I$(SFML_INCLUDE) -I$(INCLUDE_DIR) -L$(SFML_LIB) $(LIBRARIES) -D__DEBUG__ -o $(BUILD_DIR)/debug.exe

run_clean: run clean

run: $(EXE)
	$(EXE)

clean:
	PowerShell -Command "Remove-Item -Path '$(EXE)' -Force"