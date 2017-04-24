#ifndef PACKMAN_GAMEMANAGER_HH
#define PACKMAN_GAMEMANAGER_HH


#include "PlayerManager.hh"
#include "MonsterManager.hh"
#include "../Utils/Factory/MapFactory.hh"
#include "../Utils/Factory/MonsterFactory.hh"
#include <string>
#include <SFML/System.hpp>

class GameManager {
private:
    PlayerManager* playerManager;
    MonsterManager* monsterManager;
    Map* map;
    void getFps(sf::RenderWindow*);
public:
    GameManager();
    PlayerManager* getPlayerManager();
    MonsterManager* getMonsterManager();
    Map* getMap();
    void Draw(sf::RenderWindow*);
    void exec();
    void Update();
};


#endif //PACKMAN_GAMEMANAGER_HH
