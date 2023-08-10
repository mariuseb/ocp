#!/bin/bash

# Function to recursively delete files starting with "MPC" or "MHE" or "jit" and ending with ".c", ".so", or ".o"
delete_files() {
    local dir="$1"

    # Check if the directory exists
    if [ ! -d "$dir" ]; then
        echo "Directory '$dir' does not exist."
        exit 1
    fi

    # Recursively find files and delete them
    find "$dir" -type f \( -name "MPC*.c" -o -name "MPC*.so" -o -name "MPC*.o" -o -name "MHE*.c" -o -name "MHE*.so" -o -name "MHE*.o" -o -name "jit*.c" -o -name "jit*.so" -o -name "jit*.o" -o -name "tmp*.so" -o -name "tmp*.o" \) -exec rm -f {} +
}

# Check if the user provided a directory path
if [ -z "$1" ]; then
    echo "Usage: $0 <directory_path>"
    exit 1
fi

# Call the function to delete files starting with "MPC" or "MHE" or "jit" and ending with ".c", ".so", or ".o"
delete_files "$1"
