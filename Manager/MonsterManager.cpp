#include "MonsterManager.hh"
#include "../Utils/Factory/MonsterFactory.hh"

MonsterManager::MonsterManager() {}

std::vector<Monster *> MonsterManager::getMonsterList()
{
	return (monsterList);
}

void MonsterManager::isPackmanVersusMonster(Packman *p)
{
	for (auto monster : getMonsterList()) {
		if (round(p->getX()) == round(monster->getX()) &&
			round(p->getY()) == round(monster->getY())) {
			p->NotifyPackmanVsMonster(monster);
		}
	}
}

void MonsterManager::addMonster(Monster *monster)
{
	monsterList.push_back(monster);
}

void MonsterManager::changeStatusMonster()
{
	for (auto monster : monsterList) {
		monster->setTimePowerUpEaten();
		monster->setStatus(1);
	}
}

void MonsterManager::Notify(IObservable *observable)
{
	changeStatusMonster();
}

void MonsterManager::Draw(sf::RenderWindow *window)
{
	for (auto monster : monsterList) {
		monster->Draw(window);
	}
}

void MonsterManager::Update(Map *map)
{
	for (auto monster: monsterList) {
		monster->Update(map);
	}
}

void MonsterManager::setPackmanObserver(Packman *p)
{
	observer = p;
}
