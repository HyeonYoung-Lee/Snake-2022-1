CC=g++
CCFLAGS=-std=c++11
OBJECTS=src/*.cpp
CURSE=-lncurses

all:
	$(CC) $(CCFLAGS) $(OBJECTS) $(CURSE) -o /tmp/a.out && /tmp/a.out
