#!/bin/sh

rm -rf tmp
mkdir tmp

cp pc/libinc.* tmp/
cp code/* tmp/
cp make/Makefile.pc tmp/Makefile
cd tmp
make
cd ..
cp tmp/main .
rm -rf tmp
