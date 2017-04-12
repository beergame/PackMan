#include "Packman.hh"

/**
 * @TODO Temp coordinate, to change when the map is set up
 */
Packman::Packman(std::string ressources) {
    Packman::setRessources(ressources);
    setX(100);
    setY(100);
    setStatut(0);
    setDirection(2);
    setTimePowerUpEaten();
}

void Packman::Update(Map map) {
    int direction = getDirection();
    double time = TimeManager::GetInstance().GetElapsedTime() / 1000;
    double newX = 0;
    double newY = 0;

    // Check if power-up expire
    double diff = time - Packman::getTimePowerUpEaten();
    if (diff > Packman::powerUpDuration) {
        setStatut(0);
    }

    switch (direction) {
        case 1:
            newX = getX();
            newY = getY() + time;
            break;
        case 2:
            newX = getX() + time;
            newY = getY();
            break;
        case 3:
            newX = getX();
            newY = getY() - time;
            break;
        case 4:
            newX = getX() - time;
            newY = getY();
            break;
        default:
            break;
    };

    int element = map.checkMap(newX, newY);
    switch (element) {
        case 0:
            setX(newX);
            setY(newY);
            break;
        case 1:
            setX(newX);
            setY(newY);
            map.cleanElement(newX, newY);
            break;
        case 2:
            setX(newX);
            setY(newY);
            map.cleanElement(newX, newY);
            setTimePowerUpEaten();
            setStatut(1);
            for (auto &observer : observers) {
                observer->Notify(this);
            }
            break;
        case 3:
        default:
            break;
    }
}

void Packman::AddObserver(IObserver *observer) {
    observers.push_back(observer);
}

Packman::~Packman() {
}

void Packman::RemoveObserver(IObserver *observer) {
    observers.remove(observer);
}

void Packman::Draw(sf::RenderWindow *window) {
    sf::Texture texture;
    texture.loadFromFile(this->getRessources());
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
    sprite.setPosition((float)Packman::getX(), (float)Packman::getY());
    window->draw(sprite);
}
