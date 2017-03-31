#include "MonsterFactory.hh"

/**
 * Factory, @TODO temp coordinate to change when map is set up
 * @param map
 */
MonsterFactory::MonsterFactory(Map map) {
    Monster *monster1 = new Monster();
    monster1->setX(0);
    monster1->setY(0);
    Monster *monster2 = new Monster();
    monster2->setX(0);
    monster2->setY(0);
    Monster *monster3 = new Monster();
    monster3->setX(0);
    monster3->setY(0);

    map.addMonster(monster1);
    map.addMonster(monster2);
    map.addMonster(monster3);
}
