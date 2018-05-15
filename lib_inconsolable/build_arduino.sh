#!/bin/sh

BOARD="arduino:avr:uno"
PORT="/dev/ttyACM0"

rm -rf tmp
mkdir -p tmp/main
cp arduino/* tmp/main
cp code/* tmp/main
cd tmp/main

arduino --upload --board $BOARD --port $PORT main.ino
cd ..
rm -rf tmp

