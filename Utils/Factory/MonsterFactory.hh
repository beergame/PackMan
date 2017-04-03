#ifndef PACKMAN_MONSTERFACTORY_HH
#define PACKMAN_MONSTERFACTORY_HH


#include "../../Entities/Monster.hh
#include "../../Manager/MonsterManager.hh"

class MonsterFactory {
public:
    MonsterFactory();
    void CreateMonster(MonsterManager*);
};


#endif //PACKMAN_MONSTERFACTORY_HH
