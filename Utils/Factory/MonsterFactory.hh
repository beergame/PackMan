#ifndef PACKMAN_MONSTERFACTORY_HH
#define PACKMAN_MONSTERFACTORY_HH

#include "../../Entities/Monster.hh"

class MonsterManager;

class MonsterFactory
{
public:
	MonsterFactory();

	void CreateMonster(MonsterManager *, Map *);
};


#endif //PACKMAN_MONSTERFACTORY_HH
