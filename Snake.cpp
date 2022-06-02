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

	this->direction = 2;
	this->isAlive = true;
	this->pastKey = 0;

	this->score = KEY_RIGHT;
}

std::vector<std::vector<int>> Snake::getSnakeInfo() {
	std::vector<std::vector<int>> tmp;
	tmp = this->snakeBody;
	for (int i = 0; i < tmp.size(); i++) {
		tmp[i].pop_back();
	}
	return	tmp;
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
	this->direction = 2;
}

int Snake::understandKey(int key)
{
    Info info;
    for(int i=0;i<info.allWallLoc.size();i++){
        if(snakeBody[0][0] == info.allWallLoc[i][0] && snakeBody[0][1] == info.allWallLoc[i][1]){
            return 2;
        }
    }
    
	if ((key == 99) || (key == getPastKey()))
		return 1;

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
		if (snakeBody[0][1] - 1 >= 0)
		{
			addSnakeBody(snakeBody[0][0], snakeBody[0][1] - 1, 3);
			setDirection(4);
		}
		break;
	case KEY_RIGHT:
		addSnakeBody(snakeBody[0][0], snakeBody[0][1] + 1, 3);
		setDirection(2);
		break;
	case KEY_UP:
		addSnakeBody(snakeBody[0][0] - 1, snakeBody[0][1], 3);
		setDirection(1);
		break;
	case KEY_DOWN:
		addSnakeBody(snakeBody[0][0] + 1, snakeBody[0][1], 3);
		setDirection(3);
		break;
	}
    

	setPastKey(key);
	usleep(500000);
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

// score board accessor
void Snake::setCurrentLength(int cl)
{
	currentLength = cl;
}
int Snake::getCurrentLength()
{
	return currentLength;
}
void Snake::setMaxLength(int ml)
{
	maxLength = ml;
}
int Snake::getMaxLength()
{
	return maxLength;
}
void Snake::setGrowthItems(int gi)
{
	growthItems = gi;
}
int Snake::getGrowthItems()
{
	return growthItems;
}
void Snake::setPoisonItems(int pi)
{
	poisonItems = pi;
}
int Snake::getPoisonItems()
{
	return poisonItems;
}
void Snake::setGateUses(int gu)
{
	gateUses = gu;
}
int Snake::getGateUses()
{
	return gateUses;
}
