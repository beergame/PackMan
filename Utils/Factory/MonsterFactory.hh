#ifndef PACKMAN_MONSTERFACTORY_HH
# define PACKMAN_MONSTERFACTORY_HH

# include "../../Entities/Monster.hh"
# include "MapFactory.hh"

class MonsterManager;

class MonsterFactory
{
public:
	MonsterFactory();

	void CreateMonster(MonsterManager *, MapFactory *, Map *);
};


#endif //PACKMAN_MONSTERFACTORY_HH
