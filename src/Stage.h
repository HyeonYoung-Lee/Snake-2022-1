#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Snake.h"
#include "Item.h"
#include "Gate.h"
#include "Info.h"
class MapSet
{
   int row;
   int col;
   char **map;

public:
   void LoadMap(int mapNum);
   void setMap(int row, int col, int num);
   void printSnake(Snake snake);
   void printItem(Item item);
   void printGate(Gate gate);
   char *getMap(int row);
   char *printMap(int row);
   int getRow();
   int getCol();
   bool checkMapElement(std::vector<std::vector<int>> snakeBody);
   friend std::ostream &operator<<(std::ostream &os, const MapSet &map);
};
