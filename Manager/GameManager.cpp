#include "GameManager.hh"
#include "../build/config.h"

using namespace sf;

GameManager::GameManager() {
    MapFactory* mapFactory = new MapFactory();
    MonsterFactory* monsterFactory = new MonsterFactory();
    map = mapFactory->createMap();
    playerManager = new PlayerManager();
    monsterManager = new MonsterManager();
    monsterFactory->CreateMonster(monsterManager);
    playerManager->getPackman()->AddObserver(monsterManager);
}

PlayerManager *GameManager::getPlayerManager() {
    return playerManager;
}

MonsterManager *GameManager::getMonsterManager() {
    return monsterManager;
}

Map *GameManager::getMap() {
    return map;
}

int main(int argc, char* argv[]) {
    VideoMode videoMode(320,240);
    RenderWindow window(videoMode,"Packman");

    while (window.isOpen()) {
        window.clear();
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if ( (event.type == Event::Closed) ||
                 ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
                window.close();
            else {

            }
        }
    }
    return 0;
}
