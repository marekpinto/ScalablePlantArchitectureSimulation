#!/bin/sh
gcc `pkg-config --cflags gtk+-3.0` -o WindowSlider WindowSlider.c `pkg-config --libs gtk+-3.0`
