#include "Monster.hh"

Monster::Monster(std::string sprites) {
    Monster::setRessources(sprites);
    setX(0);
    setY(0);
    setStatut(0);
    setTimePowerUpEaten();
    changeDirection();
}

void Monster::Update(Map *map) {
    int direction = getDirection();
    double time = TimeManager::GetInstance().GetElapsedTime();
    double timeInSecond = time / 1000;
    double newY = 0;
    double newX = 0;
    int element = 3;

    double diff = time - Monster::getTimePowerUpEaten();
    if (diff > Monster::powerUpDuration) {
        setStatut(0);
    }

    while (element == 3) {
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
        element = map->checkMap(newX, newY);
        if (element == 3) {
            changeDirection();
        }
    }
    setX(newX);
    setY(newY);
}

void Monster::changeDirection() {
    srand (time(NULL));
    int dir = rand() % 4 + 1;
    setDirection(dir);
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

    sf::Sprite sprite(texture, sf::IntRect(posX,0,16,16));
    sprite.setPosition(((float)Monster::getX() * 8) + 50, ((float)Monster::getY() * 8) + 50);
    window->draw(sprite);
}

Monster::~Monster() {

}


