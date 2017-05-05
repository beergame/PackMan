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
	monster1->setX(11);
	monster1->setY(11);
	monster1->latenceAi = 0;
	monster1->ai = &Monster::blinky;
	std::vector<std::vector<int>> map1(28, std::vector<int>(31));
	monster1->map = factory->setInternalWall(map1);
	monster1->initTrace(packMap);
	monster1->latenceTimming = 90;

	Monster *monster2 = new Monster("../Sprites/Orange.png");
	monster2->setX(12);
	monster2->setY(11);
	monster2->ai = &Monster::clyde;
	std::vector<std::vector<int>> map2(28, std::vector<int>(31));
	monster2->map = factory->setInternalWall(map2);
	monster2->initTrace(packMap);
	monster2->latenceTimming = 100;

	Monster *monster3 = new Monster("../Sprites/Pink.png");
	monster3->setX(13);
	monster3->setY(11);
	monster3->ai = &Monster::pinky;
	std::vector<std::vector<int>> map3(28, std::vector<int>(31));
	monster3->map = factory->setInternalWall(map3);
	monster3->initTrace(packMap);
	monster3->latenceTimming = 150;

	Monster *monster4 = new Monster("../Sprites/Blue.png");
	monster4->setX(15);
	monster4->setY(11);
	monster4->ai = &Monster::inky;
	std::vector<std::vector<int>> map4(28, std::vector<int>(31));
	monster4->map = factory->setInternalWall(map4);
	monster4->initTrace(packMap);
	monster4->latenceTimming = 100;

	manager->addMonster(monster1);
	manager->addMonster(monster2);
	manager->addMonster(monster3);
	manager->addMonster(monster4);
}
