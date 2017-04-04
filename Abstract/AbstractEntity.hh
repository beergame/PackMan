#ifndef PACKMAN_ABSTRACTENTITY_HH
#define PACKMAN_ABSTRACTENTITY_HH


#include "../Entities/Map.hh"

class AbstractEntity {
protected:
    AbstractEntity();
public:
    virtual ~AbstractEntity();
    virtual void Update(Map) = 0;
    virtual void Draw() = 0;
};


#endif //PACKMAN_ABSTRACTENTITY_HH
