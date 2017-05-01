#ifndef PACKMAN_PACKMAN_HH
#define PACKMAN_PACKMAN_HH

#include "../Abstract/Character.hh"
#include "../Utils/TimeManager.hh"
#include "../Utils/IObservable.hh"
#include "../Manager/MonsterManager.hh"

class Packman : public Character, public IObservable, public IObserver
{
private:
	unsigned int life;
public:
	Packman(std::string);

	~Packman();

	void Update(Map *);

	void Notify(IObservable *);

	void AddObserver(IObserver *);

	void RemoveObserver(IObserver *);

	void Draw(sf::RenderWindow *);

	int getLife();

	void setLife(unsigned int);
};


#endif //PACKMAN_PACKMAN_HH
