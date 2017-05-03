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

void Monster::navigateTheMaze(Map *map, double time)
{
	int direction = getDirection();
	double timeInSecond = time / 1000;
	double newY = 0;
	double newX = 0;

	switch (direction) {
		case 1:
			newX = getX();
			newY = getY() - (timeInSecond * 3);
			break;
		case 2:
			newX = getX() + (timeInSecond * 3);
			newY = getY();
			break;
		case 3:
			newX = getX();
			newY = getY() + (timeInSecond * 3);
			break;
		case 4:
			newX = getX() - (timeInSecond * 3);
			newY = getY();
			break;
		default:
			break;
	};

	newX = checkX(newX);
	newY = checkY(newY);
	int newWay = map->checkWays(getX(), getY());
	int wall = map->checkMap(newX, newY);

	if (wall == 3) {
		(this->*ai)(map);
	}else if (newWay) {
		(this->*ai)(map);
		setX(newX);
		setY(newY);
	} else {
		setX(newX);
		setY(newY);
	}
}

void Monster::reset()
{
	setStatus(0);
	setX(13);
	setY(11);
	setTimePowerUpEaten();
}

bool Monster::SolveMazeToPackmanFp(Map *map, int X, int Y)
{
	// Make the move (if it's wrong, we will backtrack later.
	Maze[Y][X] = SomeDude;

	// If you want progressive update, uncomment these lines...
	//PrintDaMaze();
	//Sleep(50);

	// Check if we have reached our goal.
	if (X == EndingPoint.X && Y == EndingPoint.Y)
	{
		return true;
	}

	// Recursively search for our goal.
	if (X > 0 && Maze[Y][X - 1] == Free && Solve(X - 1, Y))
	{
		return true;
	}
	if (X < MazeWidth && Maze[Y][X + 1] == Free && Solve(X + 1, Y))
	{
		return true;
	}
	if (Y > 0 && Maze[Y - 1][X] == Free && Solve(X, Y - 1))
	{
		return true;
	}
	if (Y < MazeHeight && Maze[Y + 1][X] == Free && Solve(X, Y + 1))
	{
		return true;
	}

	// Otherwise we need to backtrack and find another solution.
	Maze[Y][X] = Free;

	// If you want progressive update, uncomment these lines...
	//PrintDaMaze();
	//Sleep(50);
	return false;
}


/* follower */
void Monster::clyde(Map *map)
{
	double newX = 0, newY = 0;
	int dir;

	/* dir 1 + 2 */
	if (map->packmanPrint[0][0] >= getX() && map->packmanPrint[0][1] >= getY()) {
		dir = 1;
		/* dir 3 + 4 */
	} else if (map->packmanPrint[0][0] <= getX() && map->packmanPrint[0][1] >= getY()) {
		dir = 3;
		/* dir 2 + 3 */
	} else if (map->packmanPrint[0][0] >= getX() && map->packmanPrint[0][1] <= getY()) {
		dir = 2;
		/* dir 4 + 1 */
	} else {
		dir = 4;
	}

	while (map->getMap()[(int) round(newX)][(int) round(newY)] == 3) {
		dir++;
		if (dir > 4) {
			dir = 1;
		}
		switch (dir) {
			case 1:
				newX = getX();
				newY = getY() - 1;
				break;
			case 2:
				newX = getX() + 1;
				newY = getY();
				break;
			case 3:
				newX = getX();
				newY = getY() + 1;
				break;
			case 4:
				newX = getX() - 1;
				newY = getY();
				break;
			default:
				break;
		}
	}
	setDirection(dir);
}

/* random move */
void Monster::blinky(Map *map)
{
	double newX = 0, newY = 0;

	while (map->getMap()[(int) round(newX)][(int) round(newY)] == 3) {
		setDirection(rand() % 4 + 1);
		switch (getDirection()) {
			case 1:
				newX = getX();
				newY = getY() - 1;
				break;
			case 2:
				newX = getX() + 1;
				newY = getY();
				break;
			case 3:
				newX = getX();
				newY = getY() + 1;
				break;
			case 4:
				newX = getX() - 1;
				newY = getY();
				break;
			default:
				break;
		}
	}

}

/* hunter */
void Monster::pinky(Map *map)
{
	double newX = 0, newY = 0;

	while (map->getMap()[(int) round(newX)][(int) round(newY)] == 3) {
		setDirection(rand() % 4 + 1);
		switch (getDirection()) {
			case 1:
				newX = getX();
				newY = getY() - 1;
				break;
			case 2:
				newX = getX() + 1;
				newY = getY();
				break;
			case 3:
				newX = getX();
				newY = getY() + 1;
				break;
			case 4:
				newX = getX() - 1;
				newY = getY();
				break;
			default:
				break;
		}
	}
}

/* rogue */
void Monster::inky(Map *map)
{
	double newX = 0, newY = 0;

	while (map->getMap()[(int) round(newX)][(int) round(newY)] == 3) {
		setDirection(rand() % 4 + 1);
		switch (getDirection()) {
			case 1:
				newX = getX();
				newY = getY() - 1;
				break;
			case 2:
				newX = getX() + 1;
				newY = getY();
				break;
			case 3:
				newX = getX();
				newY = getY() + 1;
				break;
			case 4:
				newX = getX() - 1;
				newY = getY();
				break;
			default:
				break;
		}
	}
}
