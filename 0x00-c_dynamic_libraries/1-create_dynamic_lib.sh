#!/bin/bash

FILES=$(for i in *.c; do echo $i; done)

gcc -shared -fpic -o liball.so $FILES

