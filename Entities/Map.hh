#ifndef PACKMAN_MAP_HH
#define PACKMAN_MAP_HH

#include <vector>
#include <math.h>
#include <SFML/Graphics.hpp>

class Map {
private:
    std::vector<std::vector<int> > map;

public:
    int checkMap(double, double);
    Map(std::vector<std::vector<int> >);
    std::vector<std::vector<int> > getMap();
    void cleanElement(double, double);
    void Draw(sf::RenderWindow*);
};


#endif //PACKMAN_MAP_HH
