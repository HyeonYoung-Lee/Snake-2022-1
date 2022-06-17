#include "Stage.h"

void MapSet::LoadMap(int mapNum)
{
	Info info;
	Info::allWallLoc.clear();
	Info::wallLoc.clear();
	Info::planeLoc.clear();
	std::ifstream mapfile;
	srand((unsigned)time(NULL));
	mapfile.open("./Framework/stage" + std::to_string(mapNum), std::ios_base::in | std::ios_base::binary);

	std::ofstream planeLog("./log/planeLog" + std::to_string(mapNum));

	if (mapfile.fail())
	{
		std::cout << "Map file does not exist.";
	}
	else
	{
		char ch;
		std::string line;
		std::vector<std::string> linearr;

		while (getline(mapfile, line))
		{
			linearr.push_back(line);
		}

		std::istringstream stream(linearr[0]);
		std::vector<int> mapinfoarr;
		std::string mapinfo;

		stream >> row;
		stream >> col;

		map = new char *[row];
		for (int i = 0; i < row; i++)
			map[i] = new char[col];

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				map[i][j] = linearr[i + 1][j];
				if ((map[i][j] == '1') || (map[i][j] == '2'))
				{
					std::vector<int> temp{i, j};
					info.setAllWallLoc(temp);
					if (map[i][j] == '1')
						info.setWallLoc(temp);
				}
				else if (map[i][j] == '0')
				{
					std::vector<int> temp{i, j};
					info.setPlaneLoc(temp);
					planeLog << i << " " << j << std::endl;
				}
			}
		}
		mapfile.close();
		planeLog.close();
	}
}

void MapSet::setMap(int row, int col, int num)
{
	// char type map에 접근하여 변경. 사용법: row, column, 바꿀 수
	this->map[row][col] = num + '0';
}

void MapSet::printSnake(Snake snake)
{
	for (int i = 0; i < snake.getSnakeBody().size(); i++)
	{
		setMap(snake.getSnakeBody()[i][0], snake.getSnakeBody()[i][1], snake.getSnakeBody()[i][2]);
	}
}

void MapSet::printItem(Item item)
{
	setMap(item.getX(), item.getY(), item.getValue());
}

void MapSet::printGate(Gate gate)
{
	setMap(gate.getX(), gate.getY(), gate.getValue());
}

char *MapSet::getMap(int row)
{
	return (this->map[row]);
}

char *MapSet::printMap(int row)
{
	Info info;
	char *tmp = this->map[row];
	for (int i = 0; i < getCol(); i++)
	{
		if (tmp[i] == '0')
			tmp[i] = ' ';
	}
	return tmp;
}
int MapSet::getRow()
{
	return (row);
}

int MapSet::getCol()
{
	return (col);
}

std::ostream &operator<<(std::ostream &os, const MapSet &m)
{
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			os << m.map[i][j];
		}
		os << "\n";
	}
	return (os);
}
