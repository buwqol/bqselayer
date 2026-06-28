#!/bin/sh
set -e
CC=gcc
CFLAGS="-std=c11 -O2 -ffunction-sections -fdata-sections"
$CC $CFLAGS -c Bqselayer.c -o Bqselayer.o
ar rcs bqselayer.a Bqselayer.o
echo "Built bqselayer.a"