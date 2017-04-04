#include "MonsterManager.hh"
#include "../Utils/Factory/MonsterFactory.hh"

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

void MonsterManager::Notify(IObservable *observable) {
    changeStatusMonster();
}

MonsterManager::MonsterManager() {
}
