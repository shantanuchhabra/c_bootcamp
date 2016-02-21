CC := gcc
CFLAGS := -std=c99 -Og -g -Wall -Wextra -Wpedantic

demo: queue.o
queue.o: queue.h
