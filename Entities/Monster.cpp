#include "Monster.hh"

Monster::Monster() {
    setX(0);
    setY(0);
    setStatut(0);
    setPowerUpEaten();
    changeDirection();
}

void Monster::Update(Map map) {
    int direction = getDirection();
    double time = TimeManager::GetInstance().GetElapsedTime() / 1000;
    double newY = 0;
    double newX = 0;
    int element = nullptr;

    double diff = time - Monster::getTimePowerUpEaten();
    if (diff > Monster::powerUpDuration) {
        setStatut(0);
    }

    while (element == nullptr || element == 3) {
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


