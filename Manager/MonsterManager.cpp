#include "MonsterManager.hh"

Map *MonsterManager::getMap() {
    return map;
}

std::vector<Monster *> MonsterManager::getMonsterList() {
    return monsterList;
}

void MonsterManager::addMonster(Monster* monster) {
    monsterList.push_back(monster);
}

void MonsterManager::changeStatusMonster() {
    for (auto monster : monsterList) {
        monster->setTimePowerUpEaten();
        monster->setStatut(1);
    }
}

void MonsterManager::Notify(Packman *observable) {
    if (observable->isStatut() == 1 ) {
        changeStatusMonster();
    }
}

MonsterManager::MonsterManager(Map* map) {
    this->map = map;
    MonsterFactory* monsterFactory = new MonsterFactory();
    monsterFactory->CreateMonster(this);
}
