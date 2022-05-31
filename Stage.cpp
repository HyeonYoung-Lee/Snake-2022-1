#include "Stage.h"

void MapSet::LoadMap(int mapNum)
{
	std::ifstream mapfile;
	srand((unsigned)time(NULL));
	mapfile.open("stage" + std::to_string(mapNum), std::ios_base::in | std::ios_base::binary);

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

void MapSet::setMap(int row, int col, int num, Snake snake) {
	// char type map에 접근하여 변경. 사용법: row, column, 바꿀 수
	this -> map[row][col] = num + '0';
}

void	MapSet::printSnake(Snake snake) {
	for (int i = 0; i < snake.getSnakeBody().size(); i++) {
		setMap(snake.getSnakeBody()[i][0], snake.getSnakeBody()[i][1], snake.getSnakeBody()[i][2], snake);
	}
}

char *MapSet::getMap(int row)
{
	return (this->map[row]);
}

int MapSet::getRow()
{
	return (row);
}

bool	MapSet::checkMapElement(std::vector<std::vector<int> > snakeBody) {
	int	row = snakeBody[0][0];
	int	col = snakeBody[0][1];
	if (this -> map[row][col] == 1 || this -> map[row][col] == 2 || this -> map[row][col] == 4)
		return	false;
	return	true;
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
