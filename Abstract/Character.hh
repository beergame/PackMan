#ifndef PACKMAN_CHARACTER_HH
#define PACKMAN_CHARACTER_HH

#include "AbstractEntity.hh"
#include <string>

class Character : public AbstractEntity{
protected:
    Character();
public:
    virtual ~Character();
    double getX() const;
    void setX(double X);
    double getY() const;
    void setY(double Y);
    bool isStatut() const;
    void setStatut(bool statut);
    int getDirection() const;
    void setDirection(int direction);
    double getTimePowerUpEaten();
    void setTimePowerUpEaten();
    static constexpr double powerUpDuration = 1; //second
    void setRessources(std::string);
    std::string getRessources();
private:
    double X, Y;
    bool statut;
    int direction;
    double timePowerUpEaten;
    std::string ressources;

};


#endif //PACKMAN_CHARACTER_HH
