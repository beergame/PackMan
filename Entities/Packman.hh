#ifndef PACKMAN_PACKMAN_HH
#define PACKMAN_PACKMAN_HH

#include "../Abstract/Character.hh"
#include "../Utils/TimeManager.hh"
#include "Map.hh"
#include "../Utils/IObservable.hh"

class Packman : public Character, IObservable{
public:
    Packman(IObserver*);
    void Update(Map);
};



#endif //PACKMAN_PACKMAN_HH
