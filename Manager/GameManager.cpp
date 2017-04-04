#include "GameManager.hh"

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
