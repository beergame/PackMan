#include "Monster.hh"

Monster::Monster(std::string sprites) {
	Monster::setRessources(sprites);
	setStatut(0);
	setTimePowerUpEaten();
	changeDirection(9);
}

void Monster::Update(Map *map) {
	double time = TimeManager::GetInstance().GetElapsedTime();

	navigateTheMaze(map, time);

	double diff = time - Monster::getTimePowerUpEaten();
	if (diff > Monster::powerUpDuration) {
		setStatut(0);
	}
}

void Monster::changeDirection(int direction) {
	if ((direction + 1) > 4)
		setDirection(1);
	else
		setDirection(direction + 1);
}

void Monster::Draw(sf::RenderWindow *window) {
	int posX = 0;
	sf::Texture texture;
	texture.loadFromFile(this->getRessources());

	switch (Monster::getDirection()) {
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

Monster::~Monster() {

}

void Monster::navigateTheMaze(Map *map, double time) {
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
		changeDirection(direction);
	} else {
		setX(newX);
		setY(newY);
	}
}
