#include "PlayerManager.hh"

PlayerManager::PlayerManager() {
    packman = new Packman("../Sprites/Packman.png");
}

Packman* PlayerManager::getPackman() {
    return packman;
}
