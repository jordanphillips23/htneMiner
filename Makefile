CC  = g++
CXX = g++ -O0 -std=gnu++14

# Comment out one of the following 2 lines to enable/disable BASIC4TRACE.
INCLUDES =
#INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g -Lcryptopp820
LDLIBS  = -lcryptopp

executables = main
objects = block.o blockchain.o

main: main.o block.o blockchain.o

main.o: main.cpp
.PHONY: default

blockchain.o: blockchain.cpp blockchain.hh block.hh

block.o: block.cpp block.hh

default: $(executables)



.PHONY: clean
clean:
	rm -f *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default
