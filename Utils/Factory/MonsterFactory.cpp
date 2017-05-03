#include "MonsterFactory.hh"
#include "../../Manager/MonsterManager.hh"

MonsterFactory::MonsterFactory() {}

/**
 * Create all monster with their AI
 *
 * @param MonsterManager manager
 * @param Map            map
 */
void MonsterFactory::CreateMonster(MonsterManager *manager, Map *map)
{
	Monster *monster1 = new Monster("../Sprites/Red.png");
	monster1->setX(1);
	monster1->setY(1);
	monster1->ai = &Monster::clyde;
	Monster *monster2 = new Monster("../Sprites/Pink.png");
	monster2->setX(1);
	monster2->setY(29);
	monster2->ai = &Monster::pinky;
	Monster *monster3 = new Monster("../Sprites/Orange.png");
	monster3->setX(26);
	monster3->setY(1);
	monster3->ai = &Monster::blinky;
	Monster *monster4 = new Monster("../Sprites/Blue.png");
	monster4->setX(20);
	monster4->setY(29);
	monster4->ai = &Monster::inky;

	manager->addMonster(monster1);
	manager->addMonster(monster2);
	manager->addMonster(monster3);
	manager->addMonster(monster4);
}
