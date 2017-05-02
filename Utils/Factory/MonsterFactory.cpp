#include "MonsterFactory.hh"
#include "../../Manager/MonsterManager.hh"

MonsterFactory::MonsterFactory() {}

/**
 * Factory, @TODO temp coordinate to change when map is set up
 * @param monsterManager
 */
void MonsterFactory::CreateMonster(MonsterManager* monsterManager) {
    Monster *monster1 = new Monster("../Sprites/Red.png");
    monster1->setX(1);
    monster1->setY(1);
    Monster *monster2 = new Monster("../Sprites/Pink.png");
    monster2->setX(1);
    monster2->setY(29);
    Monster *monster3 = new Monster("../Sprites/Orange.png");
    monster3->setX(26);
    monster3->setY(1);
    Monster *monster4 = new Monster("../Sprites/Blue.png");
    monster4->setX(20);
    monster4->setY(29);

    monsterManager->addMonster(monster1);
    monsterManager->addMonster(monster2);
    monsterManager->addMonster(monster3);
    monsterManager->addMonster(monster4);
}
