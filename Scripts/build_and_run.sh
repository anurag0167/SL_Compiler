#!/bin/bash

# Ensure the script exits if any command fails
set -e

# Variables
EXECUTABLE_NAME="lexer"
SRC_FILES="lexerf.c main.c"
INPUT_FILE="input.sl"

# Step 1: Check if input file exists
if [ ! -f $INPUT_FILE ]; then
    echo "Error: Input file '$INPUT_FILE' not found!"
    exit 1
fi

# Step 2: Compile the code
echo "Compiling the lexer..."
gcc -o $EXECUTABLE_NAME $SRC_FILES -Wall -Wextra
echo "Compilation successful."

# Step 3: Run the lexer with the input file
echo "Running the lexer..."
./$EXECUTABLE_NAME $INPUT_FILE
