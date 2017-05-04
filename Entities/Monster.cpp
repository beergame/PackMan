#include <zconf.h>
#include "Monster.hh"

Monster::Monster(std::string sprites)
{
	setResources(sprites);
	setStatus(0);
	setTimePowerUpEaten();
}

Monster::~Monster() {}

void Monster::Update(Map *map)
{
	double time = TimeManager::GetInstance().GetElapsedTime();
	double timeFromStart = TimeManager::GetInstance().GetStartedTime() / 1000;
	double diff = timeFromStart - Monster::getTimePowerUpEaten();

	navigateTheMaze(map, time);
	if (diff > Monster::powerUpDuration) {
		setStatus(0);
	}
}

void Monster::Draw(sf::RenderWindow *window)
{
	int posX = 0;
	sf::Image image;
	sf::Texture texture;
	if (isStatus()) {
		image.loadFromFile("../Sprites/coward.png");
	} else {
		image.loadFromFile(this->getResources());
	}
	image.createMaskFromColor(sf::Color::Black);
	texture.loadFromImage(image);

	if (!isStatus()) {
		switch (this->getDirection()) {
			case 1:
				posX = 64;
				break;
			case 2:
				posX = 0;
				break;
			case 3:
				posX = 96;
				break;
			case 4:
				posX = 32;
				break;
			default:
				break;
		}
	}

	if ((TimeManager::GetInstance().GetStartedTime() % 1000) > 500) {
		posX += 16;
	}

	sf::Sprite sprite(texture, sf::IntRect(posX, 0, 16, 16));
	sprite.setPosition(((float) Monster::getX() * 16) + 50, ((float) Monster::getY() * 16) + 50);
	sprite.setScale(1.5, 1.5);
	window->draw(sprite);
}

void PrintDaMaze(std::vector<std::vector<int>> map)
{
	for (int i = 0; i < 31; ++i) {
		for (int j = 0; j < 28; ++j) {
			printf("%i", map[j][i]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void Monster::navigateTheMaze(Map *packMap, double time)
{
	double timeInSecond = time / 1000;
	double newY = 0;
	double newX = 0;

	switch (findTheTraceDirection()) {
		case 1:
			newX = getX();
			newY = getY() - (timeInSecond * 4);
			break;
		case 2:
			newX = getX() + (timeInSecond * 4);
			newY = getY();
			break;
		case 3:
			newX = getX();
			newY = getY() + (timeInSecond * 4);
			break;
		case 4:
			newX = getX() - (timeInSecond * 4);
			newY = getY();
			break;
		default:
			break;
	};

	this->latenceAi++;
	if (this->latenceAi > latenceTimming) {
		this->latenceAi = 0;
		clearTrace();
		(this->*ai)(packMap);
	} else {
		setX(newX);
		setY(newY);
	}
}

void Monster::reset(Map *packMap)
{
	setStatus(0);
	setX(14);
	setY(11);
	setTimePowerUpEaten();
	clearTrace();
	(this->*ai)(packMap);
}

bool Monster::solveMazeToPackmanFp(int X, int Y, int pX, int pY)
{
	map[Y][X] = 1;


	if (Y == pX && X == pY) {
		return true;
	}

	/* Recursively search for our goal */
	if (Y > pY) {
		if (X < pX) {
			/* DOWN PRIVILEGE */
			if (X < 31 && map[Y][X + 1] == 0 && solveMazeToPackmanFp(X + 1, Y, pX, pY)) {
				return true;
			}

			/* LEFT PRIVILEGE */
			if (Y > 0 && map[Y - 1][X] == 0 && solveMazeToPackmanFp(X, Y - 1, pX, pY)) {
				return true;
			}

			/* UP PRIVILEGE */
			if (X > 0 && map[Y][X - 1] == 0 && solveMazeToPackmanFp(X - 1, Y, pX, pY)) {
				return true;
			}

			/* RIGHT PRIVILEGE */
			if (Y < 28 && map[Y + 1][X] == 0 && solveMazeToPackmanFp(X, Y + 1, pX, pY)) {
				return true;
			}
		} else if (X > pX) {
			/* UP PRIVILEGE */
			if (X > 0 && map[Y][X - 1] == 0 && solveMazeToPackmanFp(X - 1, Y, pX, pY)) {
				return true;
			}

			/* LEFT PRIVILEGE */
			if (Y > 0 && map[Y - 1][X] == 0 && solveMazeToPackmanFp(X, Y - 1, pX, pY)) {
				return true;
			}

			/* DOWN PRIVILEGE */
			if (X < 31 && map[Y][X + 1] == 0 && solveMazeToPackmanFp(X + 1, Y, pX, pY)) {
				return true;
			}

			/* RIGHT PRIVILEGE */
			if (Y < 28 && map[Y + 1][X] == 0 && solveMazeToPackmanFp(X, Y + 1, pX, pY)) {
				return true;
			}
		} else if (X == pX) {
			/* LEFT PRIVILEGE */
			if (Y > 0 && map[Y - 1][X] == 0 && solveMazeToPackmanFp(X, Y - 1, pX, pY)) {
				return true;
			}

			/* UP PRIVILEGE */
			if (X > 0 && map[Y][X - 1] == 0 && solveMazeToPackmanFp(X - 1, Y, pX, pY)) {
				return true;
			}

			/* RIGHT PRIVILEGE */
			if (Y < 28 && map[Y + 1][X] == 0 && solveMazeToPackmanFp(X, Y + 1, pX, pY)) {
				return true;
			}

			/* DOWN PRIVILEGE */
			if (X < 31 && map[Y][X + 1] == 0 && solveMazeToPackmanFp(X + 1, Y, pX, pY)) {
				return true;
			}
		}
	} else if (Y < pY) {
		if (X < pX) {
			/* DOWN PRIVILEGE */
			if (X < 31 && map[Y][X + 1] == 0 && solveMazeToPackmanFp(X + 1, Y, pX, pY)) {
				return true;
			}

			/* RIGHT PRIVILEGE */
			if (Y < 28 && map[Y + 1][X] == 0 && solveMazeToPackmanFp(X, Y + 1, pX, pY)) {
				return true;
			}

			/* UP PRIVILEGE */
			if (X > 0 && map[Y][X - 1] == 0 && solveMazeToPackmanFp(X - 1, Y, pX, pY)) {
				return true;
			}

			/* LEFT PRIVILEGE */
			if (Y > 0 && map[Y - 1][X] == 0 && solveMazeToPackmanFp(X, Y - 1, pX, pY)) {
				return true;
			}
		} else if (X > pX) {
			/* UP PRIVILEGE */
			if (X > 0 && map[Y][X - 1] == 0 && solveMazeToPackmanFp(X - 1, Y, pX, pY)) {
				return true;
			}

			/* RIGHT PRIVILEGE */
			if (Y < 28 && map[Y + 1][X] == 0 && solveMazeToPackmanFp(X, Y + 1, pX, pY)) {
				return true;
			}

			/* DOWN PRIVILEGE */
			if (X < 31 && map[Y][X + 1] == 0 && solveMazeToPackmanFp(X + 1, Y, pX, pY)) {
				return true;
			}

			/* LEFT PRIVILEGE */
			if (Y > 0 && map[Y - 1][X] == 0 && solveMazeToPackmanFp(X, Y - 1, pX, pY)) {
				return true;
			}
		} else if (pX == X) {
			/* RIGHT PRIVILEGE */
			if (Y < 28 && map[Y + 1][X] == 0 && solveMazeToPackmanFp(X, Y + 1, pX, pY)) {
				return true;
			}

			/* UP PRIVILEGE */
			if (X > 0 && map[Y][X - 1] == 0 && solveMazeToPackmanFp(X - 1, Y, pX, pY)) {
				return true;
			}

			/* LEFT PRIVILEGE */
			if (Y > 0 && map[Y - 1][X] == 0 && solveMazeToPackmanFp(X, Y - 1, pX, pY)) {
				return true;
			}

			/* DOWN PRIVILEGE */
			if (X < 31 && map[Y][X + 1] == 0 && solveMazeToPackmanFp(X + 1, Y, pX, pY)) {
				return true;
			}
		}
	} else if (pY == Y) {
		if (pX > X) {
			/* DOWN PRIVILEGE */
			if (X < 31 && map[Y][X + 1] == 0 && solveMazeToPackmanFp(X + 1, Y, pX, pY)) {
				return true;
			}

			/* LEFT PRIVILEGE */
			if (Y > 0 && map[Y - 1][X] == 0 && solveMazeToPackmanFp(X, Y - 1, pX, pY)) {
				return true;
			}

			/* UP PRIVILEGE */
			if (X > 0 && map[Y][X - 1] == 0 && solveMazeToPackmanFp(X - 1, Y, pX, pY)) {
				return true;
			}

			/* RIGHT PRIVILEGE */
			if (Y < 28 && map[Y + 1][X] == 0 && solveMazeToPackmanFp(X, Y + 1, pX, pY)) {
				return true;
			}
		} else if (pX < X) {
			/* UP PRIVILEGE */
			if (X > 0 && map[Y][X - 1] == 0 && solveMazeToPackmanFp(X - 1, Y, pX, pY)) {
				return true;
			}

			/* RIGHT PRIVILEGE */
			if (Y < 28 && map[Y + 1][X] == 0 && solveMazeToPackmanFp(X, Y + 1, pX, pY)) {
				return true;
			}

			/* DOWN PRIVILEGE */
			if (X < 31 && map[Y][X + 1] == 0 && solveMazeToPackmanFp(X + 1, Y, pX, pY)) {
				return true;
			}

			/* LEFT PRIVILEGE */
			if (Y > 0 && map[Y - 1][X] == 0 && solveMazeToPackmanFp(X, Y - 1, pX, pY)) {
				return true;
			}
		}
	}

	/* backtrack and find another solution */
	map[Y][X] = 0;

	return (false);
}


/* follower */
void Monster::blinky(Map *packMap)
{
	int x = packMap->packmanPrint[0][0];
	int y = packMap->packmanPrint[0][1];

	if (!solveMazeToPackmanFp(getY(), getX(), x, y)) {
		printf("blinky PLANTE\n");
		reset(packMap);
	}
}

/* random move */
void Monster::clyde(Map *packMap)
{
	int x = (rand() % 1) ? 1 : 26;
	int y = (rand() % 1) ? 26 : 1;

	if (!solveMazeToPackmanFp(getY(), getX(), x, y)) {
		printf("clyde PLANTE\n");
		reset(packMap);
	}
}

/* hunter */
void Monster::pinky(Map *packMap)
{
	int x = packMap->packmanPrint[1][0];
	int y = packMap->packmanPrint[1][1];

	if (!solveMazeToPackmanFp(getY(), getX(), x, y)) {
		printf("pinky PLANTE\n");
		reset(packMap);
	}
}

/* rogue */
void Monster::inky(Map *packMap)
{
	int x = packMap->packmanPrint[2][0];
	int y = packMap->packmanPrint[2][1];

	if (!solveMazeToPackmanFp(getY(), getX(), x, y)) {
		printf("inky PLANTE\n");
		reset(packMap);
	}
}

void Monster::initTrace(Map *pMap)
{
	/* init the trace */
	(this->*ai)(pMap);
}

int Monster::findTheTraceDirection()
{
	map[getX()][getY()] = 0;
	if (getY() < 30 && map[getX()][getY() + 1] == 1) {
		setDirection(3);
		return (3);
	} else if (getY() > 0 && map[getX()][getY() - 1] == 1) {
		setDirection(1);
		return (1);
	} else if (getX() < 27 && map[getX() + 1][getY()] == 1) {
		setDirection(2);
		return (2);
	} else if (getX() > 0 && map[getX() - 1][getY()] == 1) {
		setDirection(4);
		return (4);
	}

	return (0);
}

void Monster::clearTrace()
{
	for (int i = 0; i < 28; ++i) {
		for (int j = 0; j < 31; ++j) {
			if (map[i][j] == 1) {
				map[i][j] = 0;
			}
		}
	}

}
