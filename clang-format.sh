#!/bin/bash

THIS_PATH="$(realpath "$0")"
THIS_DIR="$(dirname "$THIS_PATH")"

# Find all files in THIS_DIR which end in .ino, .cpp, etc., as specified
# in the regular expression just below
FILE_LIST="$(find "$THIS_DIR/src" | grep -E ".*(\.ino|\.cpp|\.c|\.h|\.hpp|\.hh)$")"
FILE_LIST+=" "
FILE_LIST+="$(find "$THIS_DIR/include" | grep -E ".*(\.ino|\.cpp|\.c|\.h|\.hpp|\.hh)$")"

dos2unix $FILE_LIST
clang-format-12 --verbose -i --style=file $FILE_LIST
