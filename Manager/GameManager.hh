#ifndef PACKMAN_GAMEMANAGER_HH
#define PACKMAN_GAMEMANAGER_HH


#include "PlayerManager.hh"
#include "MonsterManager.hh"
#include "../Utils/Factory/MapFactory.hh"
#include "../Utils/Factory/MonsterFactory.hh"
#include "../Menu/Menu.hh"
#include <string>
#include <SFML/System.hpp>

class GameManager
{
private:
	PlayerManager *playerManager;
	MonsterManager *monsterManager;
	Map *map;
	sf::Font font;

	void getFps(sf::RenderWindow *);

public:
	GameManager();

	PlayerManager *getPlayerManager();

	MonsterManager *getMonsterManager();

	Map *getMap();

	void Draw(sf::RenderWindow *);

	void exec();

	void Update();

	void drawString(sf::RenderWindow *, int, std::string);
};


#endif //PACKMAN_GAMEMANAGER_HH
