CC := gcc
CFLAGS := -std=c99 -Og -g -Wall -Wextra -Wpedantic

demo: queue.o
demo.o: queue.h
queue.o: queue.h

.PHONY: clean
clean:
	$(RM) demo *.o
