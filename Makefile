#-----------------------------------------------------------------------

# GNU C/C++ compiler and linker:
CC = gcc
LINK = gcc

# Turn on optimization and warnings (add -g for debugging with gdb):
# CPPFLAGS = 		# preprocessor flags
CFLAGS = -g -O -Wall

VPATH = src

#-----------------------------------------------------------------------

# MAKE allows the use of "wildcards", to make writing compilation instructions
# a bit easier. GNU make uses $@ for the target and $^ for the dependencies.

all:    OddsCalc

# specific targets
OddsCalc:	OddsCalc.o
	$(LINK) -o $@ $^

# generic C and C++ targets for OpenGL programs consisting of only one file
# type "make filename" (no extension) to build
.c:
	$(CC) -o $@ $@.c

# utility targets
clean:
	rm -f *.o *~ core
