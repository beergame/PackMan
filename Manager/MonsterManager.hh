#ifndef PACKMAN_MONSTERMANAGER_HH
# define PACKMAN_MONSTERMANAGER_HH


#include <vector>
#include "../Entities/Monster.hh"
#include "../Utils/IObserver.hh"
#include "../Entities/Packman.hh"

class Packman;

class MonsterManager : public IObserver
{
private:
	std::vector<Monster *> monsterList;

protected:
	Packman *observer;

public:
	MonsterManager();

	std::vector<Monster *> getMonsterList();

	void isPackmanVersusMonster(Packman *, Map *);

	void addMonster(Monster *);

	void changeStatusMonster();

	void Notify(IObservable *);

	void Draw(sf::RenderWindow *);

	void Update(Map *);

	void setPackmanObserver(Packman *);
};


#endif //PACKMAN_MONSTERMANAGER_HH
