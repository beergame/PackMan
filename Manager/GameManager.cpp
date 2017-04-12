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

void GameManager::Draw(RenderWindow *window) {
    TimeManager::GetInstance().Update();
    GameManager::getPlayerManager()->getPackman()->Draw(window);
    GameManager::getMonsterManager()->Draw(window);
}

void GameManager::exec() {
    VideoMode videoMode(900,600);
    RenderWindow window(videoMode,"Packman");
    TimeManager::GetInstance().Start();

    while (window.isOpen()) {
        window.clear();


        Event event;
        while (window.pollEvent(event)) {
            if ( (event.type == Event::Closed) ||
                 ((event.type == Event::KeyPressed) && (event.key.code==Keyboard::Escape)) )
                window.close();
            if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Z || event.key.code == Keyboard::Up))
                this->getPlayerManager()->getPackman()->setDirection(1);
            else if (event.type == Event::KeyPressed && (event.key.code == Keyboard::D || event.key.code == Keyboard::Right))
                this->getPlayerManager()->getPackman()->setDirection(2);
            else if (event.type == Event::KeyPressed && (event.key.code == Keyboard::S) || (event.key.code == Keyboard::Down))
                this->getPlayerManager()->getPackman()->setDirection(3);
            else if (event.type == Event::KeyPressed && (event.key.code == Keyboard::Q) || (event.key.code == Keyboard::Left))
                this->getPlayerManager()->getPackman()->setDirection(4);
        }
        GameManager::Draw(&window);
        window.display();
    }
}

int main(int argc, char* argv[]) {
    GameManager gameManager;
    gameManager.exec();
    return 0;
}
