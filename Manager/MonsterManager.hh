#ifndef PACKMAN_MONSTERMANAGER_HH
# define PACKMAN_MONSTERMANAGER_HH


#include <vector>
#include "../Entities/Monster.hh"
#include "../Utils/IObserver.hh"
#include "../Entities/Packman.hh"

class MonsterFactory;

class Packman;

class MonsterManager : public IObservable, public IObserver
{

private:
	std::vector<Monster *> monsterList;

public:
	MonsterManager();

	std::vector<Monster *> getMonsterList();

	void isPackmanVersusMonster(Packman *);

	void addMonster(Monster *);

	void changeStatusMonster();

	void Notify(IObservable *);

	void Draw(sf::RenderWindow *);

	void Update(Map *);

	void AddObserver(IObserver *);

	void RemoveObserver(IObserver *);
};


#endif //PACKMAN_MONSTERMANAGER_HH
