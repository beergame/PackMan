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

bool Character::isStatut() const {
    return statut;
}

void Character::setStatut(bool statut) {
    Character::statut = statut;
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

double Character::getPowerUpEaten() {
    return powerUpEaten;
}

/*
 * Save elapsedTime the last time Packman has eaten a power-up
 */
void Character::setPowerUpEaten() {
    powerUpEaten = TimeManager::GetInstance().GetElapsedTime() / 1000;
}
