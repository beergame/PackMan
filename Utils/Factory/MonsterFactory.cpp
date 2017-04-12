#include "MonsterFactory.hh"
#include "../../Manager/MonsterManager.hh"

MonsterFactory::MonsterFactory() {
}

/**
 * Factory, @TODO temp coordinate to change when map is set up
 * @param monsterManager
 */
void MonsterFactory::CreateMonster(MonsterManager* monsterManager) {
    Monster *monster1 = new Monster("../Sprites/Red.png");
    monster1->setX(0);
    monster1->setY(0);
    Monster *monster2 = new Monster("../Sprites/Pink.png");
    monster2->setX(0);
    monster2->setY(100);
    Monster *monster3 = new Monster("../Sprites/Orange.png");
    monster3->setX(100);
    monster3->setY(0);
    Monster *monster4 = new Monster("../Sprites/Blue.png");
    monster4->setX(200);
    monster4->setY(200);

    monsterManager->addMonster(monster1);
    monsterManager->addMonster(monster2);
    monsterManager->addMonster(monster3);
    monsterManager->addMonster(monster4);
}
