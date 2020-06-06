CC  = g++
CXX = g++ -O0 -std=c++11

# Comment out one of the following 2 lines to enable/disable BASIC4TRACE.
INCLUDES =
#INCLUDES =

CFLAGS   = -g -Wall $(INCLUDES)
CXXFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g -L.
LDLIBS  = -lcryptopp

executables = main
objects = block.o blockchain.o

.PHONY: default
default: $(executables)

$(executables): block.o blockchain.o

$(objects): blockchain.hh block.hh transaction.hh

.PHONY: clean
clean:
	rm -f *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default
