#include "PlayerManager.hh"

PlayerManager::PlayerManager() {
    packman = new Packman();
}

Packman* PlayerManager::getPackman() {
    return packman;
}
