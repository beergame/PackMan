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

void GameManager::Draw() {
    GameManager::getPlayerManager()->getPackman()->Draw();
    GameManager::getMonsterManager()->Draw();
}

int main(int argc, char* argv[]) {
    VideoMode videoMode(900,600);
    RenderWindow window(videoMode,"Packman");
    GameManager *gameManager = new GameManager();

    while (window.isOpen()) {
        window.clear();
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if ( (event.type == Event::Closed) ||
                 ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
                window.close();
            else {
                gameManager->Draw();
                window.clear();
                window.draw(gameManager->getPlayerManager()->getPackman()->getSprites());
                window.display();
            }
        }
    }
    return 0;
}
