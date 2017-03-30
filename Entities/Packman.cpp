#include "Packman.hh"

Packman::Packman() {
    setX(0);
    setY(0);
    setStatut(0);
    setTimePowerUpEaten();
}

void Packman::Update(Map map) {
    int direction = getDirection();
    double time = TimeManager::GetInstance().GetElapsedTime() / 1000;
    double newX = 0;
    double newY = 0;
    int element = nullptr;

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

    element = map.checkMap(newX, newY);
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
            map.changeStatusMonster();
            break;
        case 3:
        default:
            break;
    }

}