#include "Snake.h"
#include "Info.h"

Snake::Snake()
{
	// SnakeBody First setting
	std::vector<int> v0;
	v0.push_back(6);
	v0.push_back(6);
	v0.push_back(3);
	std::vector<int> v1;
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(4);
	std::vector<int> v2;
	v2.push_back(6);
	v2.push_back(4);
	v2.push_back(4);
	snakeBody.push_back(v0);
	snakeBody.push_back(v1);
	snakeBody.push_back(v2);

	setAttribute();
	this->isAlive = true;
	this->pastKey = 0;

	this->score = KEY_RIGHT;
}
void Snake::setAttribute()
{
	this->direction = 2;
	this->maxLength = 12;
	this->growthItems = 0;
	this->poisonItems = 0;
	this->gateUses = 0;
}
std::vector<std::vector<int>> Snake::getSnakeInfo()
{
	std::vector<std::vector<int>> tmp;
	tmp = this->snakeBody;
	for (int i = 0; i < tmp.size(); i++)
	{
		tmp[i].pop_back();
	}
	return tmp;
}

void Snake::addSnakeBody(int row, int col, int num = 3)
{
	std::vector<int> toAdd;
	toAdd.push_back(row);
	toAdd.push_back(col);
	toAdd.push_back(num);
	snakeBody.insert(snakeBody.begin(), toAdd);
	snakeBody.pop_back();
	snakeBody[1][2] = 4;
}

void Snake::onlyaddSnakeBody(int row, int col, int num = 3)
{
	std::vector<int> toAdd;
	toAdd.push_back(row);
	toAdd.push_back(col);
	toAdd.push_back(num);
	snakeBody.insert(snakeBody.begin(), toAdd);
	snakeBody[1][2] = 4;
}

void Snake::snakePoisoned()
{
	snakeBody.pop_back();
}

void Snake::clearSnake()
{
	snakeBody.clear();
	std::vector<int> v0;
	v0.push_back(6);
	v0.push_back(6);
	v0.push_back(3);
	std::vector<int> v1;
	v1.push_back(6);
	v1.push_back(5);
	v1.push_back(4);
	std::vector<int> v2;
	v2.push_back(6);
	v2.push_back(4);
	v2.push_back(4);
	snakeBody.push_back(v0);
	snakeBody.push_back(v1);
	snakeBody.push_back(v2);
	setAttribute();
}

void Snake::moveSnakeHead()
{
	if (this->direction == 1)
		addSnakeBody(snakeBody[0][0] - 1, snakeBody[0][1], 3);
	else if (this->direction == 2)
		addSnakeBody(snakeBody[0][0], snakeBody[0][1] + 1, 3);
	else if (this->direction == 3)
		addSnakeBody(snakeBody[0][0] + 1, snakeBody[0][1], 3);
	else if (this->direction == 4)
		addSnakeBody(snakeBody[0][0], snakeBody[0][1] - 1, 3);
}

int Snake::understandKey(int key)
{
	// Info info;
	// for(int i=0;i<info.allWallLoc.size();i++){
	//     if(snakeBody[0][0] == info.allWallLoc[i][0] && snakeBody[0][1] == info.allWallLoc[i][1]){
	//         return 2;
	//     }
	// }
	if (key == 99)
		return -4;
	if (key == this->getPastKey())
		return -3;

	if (key == ERR)
	{
		if (getDirection() == 1)
			key = KEY_UP;
		else if (getDirection() == 2)
			key = KEY_RIGHT;
		else if (getDirection() == 3)
			key = KEY_DOWN;
		else if (getDirection() == 4)
			key = KEY_LEFT;
	}

	switch (key)
	{
	case KEY_LEFT:
		setDirection(4);
		break;
	case KEY_RIGHT:
		setDirection(2);
		break;
	case KEY_UP:
		setDirection(1);
		break;
	case KEY_DOWN:
		setDirection(3);
		break;
	}
	setPastKey(key);
	return 0;
}

void Snake::setPastKey(int key)
{
	pastKey = key;
}

int Snake::getPastKey()
{
	return pastKey;
}

void Snake::addScore()
{
	score++;
}

int Snake::getScore()
{
	return score;
}
