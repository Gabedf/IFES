# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall

# Libraries
LIBS = -lrt # time library

# Source directory
SRC_DIR = src

# Header directory
INC_DIR = include

# Executable name
TARGET = main

# Main file
MAIN = main.c

# Source files: main file plus the relevant .c files from the source directory
SRCS = $(MAIN) $(SRC_DIR)/patientQueue.c $(SRC_DIR)/machine_manager.c

# Rule to link source files and create the executable (target)
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -I$(INC_DIR) $(SRCS) -o $(TARGET) $(LIBS)

# Explicit compile target
# By default, the first target (this) is the one that will be executed if no target is specified
compile: $(TARGET)

# Run the program: depends on the target program
run: $(TARGET)
	./$(TARGET)

# Compile and run the program
all: compile run

# Clean up: remove the target program
clean:
	rm -f $(TARGET)
