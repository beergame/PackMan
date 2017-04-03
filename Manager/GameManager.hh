#ifndef PACKMAN_GAMEMANAGER_HH
#define PACKMAN_GAMEMANAGER_HH


#include "PlayerManager.hh"
#include "MonsterManager.hh"
#include "../Utils/Factory/MapFactory.hh"

class GameManager {
private:
    PlayerManager* playerManager;
    MonsterManager* monsterManager;
    Map* map;

public:
    GameManager();
    PlayerManager* getPlayerManager();
    MonsterManager* getMonsterManager();
    Map* getMap();

};


#endif //PACKMAN_GAMEMANAGER_HH
