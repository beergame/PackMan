#include "Packman.hh"

Packman::Packman() {
    setX(0);
    setY(0);
    setStatut(0);
    setPowerUpEaten();
}

void Packman::Update() {
    int direction = getDirection();
    double time = TimeManager::GetInstance().GetElapsedTime() / 1000;

    // Check if power-up expire
    double diff = time - Packman::getPowerUpEaten();
    if (diff > Packman::powerUpDuration) {
        setStatut(0);
    }

    switch (direction) {
        case 1:
            setY(getY() + time);
            break;
        case 2:
            setX(getX() + time);
            break;
        case 3:
            setY(getY() - time);
            break;
        case 4:
            setX(getX() - time);
            break;
        default:
            break;
    };

    //@TODO Check map if there is a power up to be eaten then change status to 1 and use setPowerUpEaten.
}