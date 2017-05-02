#ifndef PACKMAN_PACKMAN_HH
#define PACKMAN_PACKMAN_HH

#include "../Abstract/Character.hh"
#include "../Utils/TimeManager.hh"
#include "../Utils/IObservable.hh"
#include "../Manager/MonsterManager.hh"

class Packman : public Character, public IObservable
{
private:
	unsigned int life;
	sf::SoundBuffer chompBuffer;
	sf::Sound chompSound;
public:
	Packman(std::string);

	~Packman();

	void Update(Map *);

	void NotifyPackmanVsMonster(Monster *);

	void AddObserver(IObserver *);

	void RemoveObserver(IObserver *);

	void Draw(sf::RenderWindow *);

	int getLife();

	void setLife(unsigned int);

	void playSound();
};


#endif //PACKMAN_PACKMAN_HH
