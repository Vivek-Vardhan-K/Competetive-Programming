#!/bin/bash

# Check if a contest number is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <CONTEST_NUMBER>"
  echo "Example: $0 1234"
  exit 1
fi

CONTEST_NUMBER=$1
FOLDER_NAME="$CONTEST_NUMBER"

# Create the folder
echo "Creating folder: $FOLDER_NAME"
mkdir -p "$FOLDER_NAME"

# Check if folder creation was successful
if [ $? -ne 0 ]; then
  echo "Error: Could not create folder $FOLDER_NAME. Exiting."
  exit 1
fi

# Create the .cpp files inside the folder
echo "Creating files in $FOLDER_NAME:"
touch "$FOLDER_NAME/SOL_A.cpp"
echo "  - $FOLDER_NAME/SOL_A.cpp"
touch "$FOLDER_NAME/SOL_B.cpp"
echo "  - $FOLDER_NAME/SOL_B.cpp"
touch "$FOLDER_NAME/SOL_C.cpp"
echo "  - $FOLDER_NAME/SOL_C.cpp"
touch "$FOLDER_NAME/SOL_D.cpp"
echo "  - $FOLDER_NAME/SOL_D.cpp"

echo "Done!"