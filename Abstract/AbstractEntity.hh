#ifndef PACKMAN_ABSTRACTENTITY_HH
#define PACKMAN_ABSTRACTENTITY_HH


#include "../Entities/Map.hh"
#include <SFML/Graphics.hpp>

class AbstractEntity {
protected:
    AbstractEntity();
public:
    virtual ~AbstractEntity();
    virtual void Update(Map*) = 0;
    virtual void Draw(sf::RenderWindow*) = 0;
};


#endif //PACKMAN_ABSTRACTENTITY_HH
