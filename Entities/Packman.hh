#ifndef PACKMAN_PACKMAN_HH
#define PACKMAN_PACKMAN_HH

#include "../Abstract/Character.hh"
#include "../Utils/TimeManager.hh"
#include "Map.hh"

class Packman : public Character{
public:
    Packman();
    void Update(Map);
};



#endif //PACKMAN_PACKMAN_HH
