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
	double diff = time - Monster::getTimePowerUpEaten();

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
	image.loadFromFile(this->getResources());
	image.createMaskFromColor(sf::Color::Black);
	texture.loadFromImage(image);

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

	if ((TimeManager::GetInstance().GetStartedTime() % 1000) > 500) {
		posX += 16;
	}


	sf::Sprite sprite(texture, sf::IntRect(posX, 0, 16, 16));
	sprite.setPosition(((float) Monster::getX() * 16) + 50, ((float) Monster::getY() * 16) + 50);
	sprite.setScale(1.5, 1.5);
	window->draw(sprite);
}

void Monster::changeDirection(Map *map)
{
	double newX = 0, newY = 0;

	while (map->getMap()[(int) round(newX)][(int) round(newY)] == 3) {
		if ((getDirection() + 1) > 4) {
			setDirection(1);
		} else {
			setDirection(getDirection() + 1);
		}
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
				newX = getX() + 1;
				newY = getY();
				break;
			default:
				break;
		}
	}
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
	int element = map->checkMap(newX, newY);

	if (element == 3) {
		changeDirection(map);
	} else {
		setX(newX);
		setY(newY);
	}
}

void Notify(IObservable *) {}
