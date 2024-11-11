CC = g++

OUT = ./bin/main

CCFLAGS  = -std=gnu++2b -Wall -Wextra -Wpedantic
CCFLAGS += $(INCFLAGS)

INCFLAGS  = -I./lib/glfw/include
INCFLAGS += -I./lib/glm
INCFLAGS += -Isrc

LDFLAGS = -L./lib/glfw/.build/src/ -lglfw3 -lopengl32 -lgdi32 -luser32

SRC = $(shell find src -name "*.cpp")
OBJ = $(SRC:.cpp=.o)

# Control verbosity
VERBOSE ?= 0
ifeq ($(VERBOSE), 1)
	VECHO = 
else
	VECHO = @
endif

# Compile source files into object files
%.o: %.cpp
	$(VECHO)$(CC) -c $< -o $@ $(CCFLAGS)

# Build the target binary
build: $(OBJ)
	$(CC) -o $(OUT) $(filter %.o, $(OBJ)) $(LDFLAGS)

# Clean up build files
clean:
	@echo "Cleaning up..."
	$(VECHO)rm -f $(OBJ) $(OUT)

# Phony targets
.PHONY: build clean
