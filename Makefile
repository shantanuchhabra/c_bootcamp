# Use gcc to compile and link C code. (This isn't the default on the sharks!)
CC := gcc

# Make passes these into $(CC) when compiling a .c file into its .o object code.
CFLAGS := -std=c99 -Og -g -Wall -Wextra -Wpedantic

# The first target in the file becomes the default (and is run as: $ make).
# NOTE: GNU Make will infer the following rules automatically:
#        - demo: demo.o (generally, foo: foo.o for all foo)
#        - demo.o: demo.c   \
#                             (generally, bar.o: bar.c for all bar)
#        - queue.o: queue.c /
#       *However,* it will NOT infer anything of the form baz.o: baz.h
#       For this reason, we do so manually below. In particular, note that we
#       want changes to queue.h to trigger a rebuild of *both* queue.c *and*
#       demo.c, since each of these source files includes that header. We must
#       also tell Make that the object code from queue.o needs to be linked into
#       the demo executable (in addition to the demo.o object code); failure to
#       do so will result in 'undefined reference' linker errors resulting from
#       the attempt to produce a binary that doesn't include the queue code.
demo: queue.o
demo.o: queue.h
queue.o: queue.h

# The dependency on .PHONY here tells Make that there isn't expected to actually
# be a file called clean. Without this, creating one would prevent the target
# from ever being run, even when explicitly requested using: $ make clean
# This is because the clean file's timestamp would always be newer than those of
# its (zero) dependencies.
.PHONY: clean
clean:
	$(RM) demo *.o
