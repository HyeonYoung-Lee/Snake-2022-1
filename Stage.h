#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>
#include "Snake.h"

class MapSet
{
   int row;
   int col;
   char **map;

public:
   void LoadMap(int mapNum);
   void setMap(int row, int col, int num, Snake snake);
   void	printSnake(Snake snake);
   char *getMap(int row);
   int getRow();
   bool	checkMapElement(std::vector<std::vector<int> > snakeBody);
   friend std::ostream &operator<<(std::ostream &os, const MapSet &map);
};
