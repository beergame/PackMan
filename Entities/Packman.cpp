#include "Packman.hh"

Packman::Packman(std::string resources) {
	Packman::setResources(resources);
	setLife(1);
	/* when modify x/y modify fp to !! */
	setX(26);
	setY(26);
	setStatus(0);
	setDirection(1);
	setTimePowerUpEaten();
	chompBuffer.loadFromFile("../Sound/pacman_chomp.wav");
	chompSound.setBuffer(chompBuffer);
}

Packman::~Packman() {}

void Packman::Update(Map *map) {
	int direction = getDirection();
	double time = TimeManager::GetInstance().GetElapsedTime();
	double timeInSecond = time / 1000;
	double timeFromStart = TimeManager::GetInstance().GetStartedTime() / 1000;
	double newX = 0;
	double newY = 0;

	// Check if power-up expire
	double diff = timeFromStart - Packman::getTimePowerUpEaten();
	if (diff > Packman::powerUpDuration) {
		setStatus(0);
	}

	switch (direction) {
		case 1:
			newX = getX();
			newY = getY() - (timeInSecond * 10);
			break;
		case 2:
			newX = getX() + (timeInSecond * 10);
			newY = getY();
			break;
		case 3:
			newX = getX();
			newY = getY() + (timeInSecond * 10);
			break;
		case 4:
			newX = getX() - (timeInSecond * 10);
			newY = getY();
			break;
		default:
			break;
	};

	if (round(newY) == 14) {
		newX = Shortcut(newX);
	}
	newX = checkX(newX);
	newY = checkY(newY);

	int element = map->checkMap(newX, newY);

	switch (element) {
		case 0:
			map->movePackmanFp(direction, (int) round(getX()), (int) round(getY()), (int) round(newX), (int) round(newY));
			setX(newX);
			setY(newY);
			break;
		case 1:
			map->cleanElement(newX, newY);
			map->movePackmanFp(direction, (int) round(getX()), (int) round(getY()), (int) round(newX), (int) round(newY));
			playSound();
			setX(newX);
			setY(newY);
			break;
		case 2:
			map->cleanElement(newX, newY);
			map->movePackmanFp(direction, (int) round(getX()), (int) round(getY()), (int) round(newX), (int) round(newY));
			playSound();
			setX(newX);
			setY(newY);
			setTimePowerUpEaten();
			setStatus(1);
			for (auto &observer : observers) {
				observer->Notify(this);
			}
			break;
		case 3:
		default:
			break;
	}
}

void Packman::NotifyPackmanVsMonster(Monster *monster, Map *packMap) {
	if (isStatus()) {
		monster->reset(packMap);
	} else {
		setLife(0);
	}
}

void Packman::AddObserver(IObserver *observer) {
	observers.push_back(observer);
}

void Packman::RemoveObserver(IObserver *observer) {
	observers.remove(observer);
}

void Packman::Draw(sf::RenderWindow *window) {
	sf::Image image;
	sf::Texture texture;
	image.loadFromFile(getResources());
	image.createMaskFromColor(sf::Color::Black);
	texture.loadFromImage(image);
	int posX = 0;
	int posY = 0;

	if ((TimeManager::GetInstance().GetStartedTime() % 1000) > 500) {
		posX = 16;
	}

	switch (Packman::getDirection()) {
		case 1:
			posY = 32;
			break;
		case 2:
			posY = 0;
			break;
		case 3:
			posY = 48;
			break;
		case 4:
			posY = 16;
			break;
		default:
			break;
	}

	sf::Sprite sprite(texture, sf::IntRect(posX, posY, 16, 16));
	sprite.setPosition(((float) Packman::getX() * 16) + 50, ((float) Packman::getY() * 16) + 50);
	sprite.setScale(1.5, 1.5);
	window->draw(sprite);
}

void Packman::setLife(unsigned int i) {
	life = i;
}

int Packman::getLife() {
	return life;
}

void Packman::playSound() {
	if (chompSound.getStatus() == 0) {
		chompSound.play();
	}
}

double Packman::Shortcut(double X) {
	if (round(X) == 0) {
		return (26);
	}
	if (round(X) == 27) {
		return (1);
	}

	return (X);
}
