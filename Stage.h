#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

class MapSet {
	int	row;
	int	col;
	char **map;
public:
	void	LoadMap();
	void	setMap(int i, int j, int num);
	char**	getMap();
	char*	getMap(int row);
	int	getrow();
	friend std::ostream& operator<<(std::ostream& os, const MapSet& map);
};
