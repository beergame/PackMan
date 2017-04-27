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

double Character::getTimePowerUpEaten() {
    return timePowerUpEaten;
}

/*
 * Save elapsedTime the last time Packman has eaten a power-up
 */
void Character::setTimePowerUpEaten() {
    timePowerUpEaten = TimeManager::GetInstance().GetElapsedTime() / 1000;
}

Character::~Character() {

}

void Character::setRessources(std::string sprites) {
    Character::ressources = sprites;
}

std::string Character::getRessources() {
    return Character::ressources;
}

double Character::checkX(double X) {
    if (X >= 30)
        return 30;
    return X;
}

double Character::checkY(double Y) {
    if (Y >= 27)
        return 27;
    return Y;
}
