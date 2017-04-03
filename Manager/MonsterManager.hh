#ifndef PACKMAN_MONSTERMANAGER_HH
#define PACKMAN_MONSTERMANAGER_HH


#include <vector>
#include "../Entities/Monster.hh"
#include "../Utils/IObserver.hh"
#include "../Entities/Packman.hh"
#include "../Utils/Factory/MonsterFactory.hh"

class MonsterManager : public IObserver{

private:
    std::vector<Monster*> monsterList;

public:
    MonsterManager();
    std::vector<Monster*> getMonsterList();
    void addMonster(Monster*);
    void changeStatusMonster();

    void Notify(Packman *observable);
};


#endif //PACKMAN_MONSTERMANAGER_HH
