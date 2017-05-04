#include "MonsterFactory.hh"
#include "../../Manager/MonsterManager.hh"
#include "MapFactory.hh"
#include "../../Entities/Monster.hh"

MonsterFactory::MonsterFactory() {}

/**
 * Create all monster with their AI
 *
 * @param MonsterManager manager
 * @param Map            map
 */
void MonsterFactory::CreateMonster(MonsterManager *manager, MapFactory *factory, Map *packMap)
{
	Monster *monster1 = new Monster("../Sprites/Red.png");
	monster1->setX(1);
	monster1->setY(26);
	monster1->latenceAi = 0;
	monster1->ai = &Monster::blinky;
	std::vector<std::vector<int>> map1(28, std::vector<int>(31));
	monster1->map = factory->setInternalWall(map1);
	monster1->initTrace(packMap);

//	Monster *monster2 = new Monster("../Sprites/Orange.png");
//	monster2->setX(1);
//	monster2->setY(26);
//	monster2->ai = &Monster::clyde;
//	std::vector<std::vector<int>> map2(28, std::vector<int>(31));
//	monster2->map = factory->setInternalWall(map2);
//
//	Monster *monster3 = new Monster("../Sprites/Pink.png");
//	monster3->setX(26);
//	monster3->setY(1);
//	monster3->ai = &Monster::pinky;
//	std::vector<std::vector<int>> map3(28, std::vector<int>(31));
//	monster3->map = factory->setInternalWall(map3);
//
//	Monster *monster4 = new Monster("../Sprites/Blue.png");
//	monster4->setX(26);
//	monster4->setY(26);
//	monster4->ai = &Monster::inky;
//	std::vector<std::vector<int>> map4(28, std::vector<int>(31));
//	monster4->map = factory->setInternalWall(map4);

	manager->addMonster(monster1);
//	manager->addMonster(monster2);
//	manager->addMonster(monster3);
//	manager->addMonster(monster4);
}
