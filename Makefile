BUILD_DIR := build
EXE_NAME  := NN-Visualizer

all: run

configure:
	@if [ ! -d "$(BUILD_DIR)" ]; then cmake -B $(BUILD_DIR); fi

build: configure
	@cmake --build $(BUILD_DIR)

run: build
	@./$(BUILD_DIR)/$(EXE_NAME)

.PHONY: all configure build run
