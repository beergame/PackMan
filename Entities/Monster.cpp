#include "Monster.hh"

Monster::Monster(std::string sprites) {
    Monster::setRessources(sprites);
    setX(0);
    setY(0);
    setStatut(0);
    setTimePowerUpEaten();
    changeDirection();
}

void Monster::Update(Map map) {
    int direction = getDirection();
    double time = TimeManager::GetInstance().GetElapsedTime() / 1000;
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
        element = map.checkMap(newX, newY);
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
    sf::Texture texture;
    texture.loadFromFile(this->getRessources());

    sf::Sprite sprite(texture, sf::IntRect(0,0,16,18));
    sprite.setPosition((float)Monster::getX(), (float)Monster::getY());
    window->draw(sprite);
}

Monster::~Monster() {

}


