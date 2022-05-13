CC=g++
CCFLAGS=-std=c++11
OBJECTS=main.cpp Scene.cpp Stage.cpp
CURSE=-lncurses

all:
	$(CC) $(CCFLAGS) $(OBJECTS) $(CURSE) -o /tmp/a.out && /tmp/a.out
