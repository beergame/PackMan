#ifndef PACKMAN_PLAYERMANAGER_HH
#define PACKMAN_PLAYERMANAGER_HH


#include "../Entities/Packman.hh"

class PlayerManager {
private:
    Packman* packman;

public:
    Packman* getPackman();
    PlayerManager();
};


#endif //PACKMAN_PLAYERMANAGER_HH
