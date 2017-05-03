#ifndef PACKMAN_MAP_HH
# define PACKMAN_MAP_HH

# include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <iterator>

class Map
{
private:
	std::vector<std::vector<int>> map;
public:
	/* fingerprint packman for monster IA */
	int packmanPrint[3][2];

	int checkMap(double, double);

	int checkWays(double, double);

	Map(std::vector<std::vector<int> >);

	std::vector<std::vector<int> > getMap();

	void cleanElement(double, double);

	void Draw(sf::RenderWindow *);

	void movePackmanFp(int, int, int, int, int);
};

#endif //PACKMAN_MAP_HH
