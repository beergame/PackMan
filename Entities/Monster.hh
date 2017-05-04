#ifndef PACKMAN_MONSTER_HH
# define PACKMAN_MONSTER_HH

# include "../Abstract/Character.hh"
# include "../Utils/TimeManager.hh"
# include "../Utils/IObserver.hh"
# include "../Utils/IObservable.hh"
# include <stdlib.h>
# include <time.h>
# include <stdio.h>

class Monster : public Character
{
public:
	int latenceAi;

	Monster(std::string);

	~Monster();

	void Update(Map *);

	/* random move */
	void clyde(Map *);

	/* follower */
	void blinky(Map *);

	/* hunter */
	void pinky(Map *);

	/* rogue */
	void inky(Map *);

	void (Monster::*ai)(Map *);

	void Draw(sf::RenderWindow *);

	void reset();

	bool solveMazeToPackmanFp(int, int, int, int);

	std::vector<std::vector<int>> map;

	void initTrace(Map *pMap);

private:
	void navigateTheMaze(Map *, double);

	int findTheTraceDirection();

	void clearTrace();
};


#endif //PACKMAN_MONSTER_HH
