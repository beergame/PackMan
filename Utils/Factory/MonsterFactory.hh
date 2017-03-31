#ifndef PACKMAN_MONSTERFACTORY_HH
#define PACKMAN_MONSTERFACTORY_HH


#include "../../Entities/Map.hh"
#include "../../Entities/Monster.hh

class MonsterFactory {
public:
    MonsterFactory(Map*);

private:
    void CreateMonster(Map*);
};


#endif //PACKMAN_MONSTERFACTORY_HH
