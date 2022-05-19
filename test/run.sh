#!/bin/bash
DIR="$(dirname "$(realpath "$0")")"
gcc -Wall -Werror -pedantic -std=gnu89 $DIR/../*.c -o $DIR/hsh && valgrind $DIR/hsh
