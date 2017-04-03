#include "MonsterFactory.hh"

MonsterFactory::MonsterFactory() {
}

/**
 * Factory, @TODO temp coordinate to change when map is set up
 * @param map
 */
void MonsterFactory::CreateMonster(MonsterManager* monsterManager) {
    Monster *monster1 = new Monster();
    monster1->setX(0);
    monster1->setY(0);
    Monster *monster2 = new Monster();
    monster2->setX(0);
    monster2->setY(0);
    Monster *monster3 = new Monster();
    monster3->setX(0);
    monster3->setY(0);

    monsterManager->addMonster(monster1);
    monsterManager->addMonster(monster2);
    monsterManager->addMonster(monster3);
}
