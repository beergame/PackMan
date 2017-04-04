#ifndef PACKMAN_PACKMAN_HH
#define PACKMAN_PACKMAN_HH

#include "../Abstract/Character.hh"
#include "../Utils/TimeManager.hh"
#include "../Utils/IObservable.hh"

class Packman : public Character, IObservable{
public:
    Packman();
    ~Packman();
    void Update(Map);
    void AddObserver(IObserver*);
    void RemoveObserver(IObserver*);
    void Draw();
};



#endif //PACKMAN_PACKMAN_HH
