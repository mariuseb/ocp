#!/bin/bash

# Function to recursively delete .c and .so files
delete_c_so_files() {
    local dir="$1"

    # Check if the directory exists
    if [ ! -d "$dir" ]; then
        echo "Directory '$dir' does not exist."
        exit 1
    fi

    # Recursively find .c and .so files and delete them
    find "$dir" -type f \( -name "*.c" -o -name "*.so" -o -name "*.o" \) -exec rm -f {} +
}

# Check if the user provided a directory path
if [ -z "$1" ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

# Call the function to delete .c and .so files
delete_c_so_files "$1"
