#include "Character.hh"
#include "../Utils/TimeManager.hh"

Character::Character() {
}

double Character::getX() const {
    return X;
}

void Character::setX(double X) {
    Character::X = X;
}

double Character::getY() const {
    return Y;
}

void Character::setY(double Y) {
    Character::Y = Y;
}

bool Character::isStatus() const {
    return status;
}

void Character::setStatus(bool status) {
    Character::status = status;
}

/*
 * Direction où se dirige le personnage
 * 1 => haut
 * 2 => droite
 * 3 => bas
 * 4 => gauche
 */
int Character::getDirection() const{
    return direction;
}

void Character::setDirection(int direction) {
    Character::direction = direction;
}

double Character::getTimePowerUpEaten() {
    return timePowerUpEaten;
}

/*
 * Save elapsedTime the last time Packman has eaten a power-up
 */
void Character::setTimePowerUpEaten() {
    timePowerUpEaten = TimeManager::GetInstance().GetStartedTime() / 1000;
}

Character::~Character() {

}

void Character::setResources(std::string sprites) {
    Character::resources = sprites;
}

std::string Character::getResources() {
    return Character::resources;
}

double Character::checkX(double X) {
    if (X >= 27)
        return 27;
    return X;
}

double Character::checkY(double Y) {
    if (Y >= 30)
        return 30;
    return Y;
}
