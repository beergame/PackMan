#ifndef PACKMAN_CHARACTER_HH
#define PACKMAN_CHARACTER_HH

#include "AbstractEntity.hh"

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
private:
    double X, Y;
    bool statut;
    int direction;
    double timePowerUpEaten;
};


#endif //PACKMAN_CHARACTER_HH
