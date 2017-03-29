//
// Created by satisfactory on 29/03/17.
//

#ifndef PACKMAN_CHARACTER_HH
#define PACKMAN_CHARACTER_HH


#include "AbstractEntity.hh"

class Character : public AbstractEntity{
protected:
    Character();
public:
    virtual ~Character() = 0;
    double getX() const;
    void setX(double X);
    double getY() const;
    void setY(double Y);
private:
    double X, Y;
};


#endif //PACKMAN_CHARACTER_HH
