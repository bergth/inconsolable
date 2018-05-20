#!/bin/sh

BOARD="arduino:sam:arduino_due_x_dbg"
PORT="/dev/ttyACM0"

rm -rf tmp
mkdir -p tmp/main
cp arduino/* tmp/main
cp code/* tmp/main
cp ILI9341_due/* tmp/main
cd tmp/main

#arduino --verify --board $BOARD --port $PORT main.ino
arduino --upload --board $BOARD --port $PORT main.ino
#cd ..
#rm -rf tmp

