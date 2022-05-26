#include "Stage.h"
#include "Snake.h"

void MapSet::LoadMap()
{
	std::ifstream mapfile;
	srand((unsigned)time(NULL));
	mapfile.open("stage" + std::to_string(rand() % 4), std::ios_base::in | std::ios_base::binary);

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
			}
		}
		mapfile.close();
	}
}

void MapSet::setMap(int i, int j, int num)
{
	// char type map에 접근하여 변경. 사용법: row, column, 바꿀 수
	this->map[i][j] = num + '0';
}

void MapSet::moveSnake(Snake snake)
{
	this->map[snake.y][snake.x] = '3';
	return;
}

char *MapSet::getMap(int row)
{
	return (this->map[row]);
}

int MapSet::getrow()
{
	return (row);
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

/*
int main(void)
{
   MapSet ex;
   ex.LoadMap();
   std::cout << ex << std::endl;
   ex.setMap(1, 1, 3);
   std::cout << ex;
}
*/
