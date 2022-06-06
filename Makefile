CC=g++
CCFLAGS=-std=c++11
OBJECTS=main.cpp Scene.cpp Stage.cpp Snake.cpp ScoreBoard.cpp Mission.cpp Item.cpp Info.cpp Gate.cpp
CURSE=-lncurses

all:
	$(CC) $(CCFLAGS) $(OBJECTS) $(CURSE) -o /tmp/a.out && /tmp/a.out
