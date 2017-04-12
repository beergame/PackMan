#ifndef PACKMAN_MONSTER_HH
#define PACKMAN_MONSTER_HH

#include "../Abstract/Character.hh"
#include "../Utils/TimeManager.hh"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

class Monster : public Character{
public:
    Monster(std::string);
    ~Monster();
    void Update(Map*);
    void changeDirection();
    void Draw(sf::RenderWindow*);
};


#endif //PACKMAN_MONSTER_HH
