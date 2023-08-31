#!/bin/bash


SERIAL_POART=/dev/ttyACM0

# make a DFU image
idf.py dfu

idf.py -p ${SERIAL_POART} flash monitor