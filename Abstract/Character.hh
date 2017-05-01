#ifndef PACKMAN_CHARACTER_HH
#define PACKMAN_CHARACTER_HH

#include "AbstractEntity.hh"
#include <string>

class Character : public AbstractEntity
{
protected:
	Character();

public:
	virtual ~Character();

	double getX() const;

	void setX(double X);

	double getY() const;

	void setY(double Y);

	bool isStatus() const;

	void setStatus(bool status);

	int getDirection() const;

	void setDirection(int direction);

	double getTimePowerUpEaten();

	void setTimePowerUpEaten();

	static constexpr double powerUpDuration = 15; //second
	void setResources(std::string);

	std::string getResources();

	double checkX(double);

	double checkY(double);

private:
	double X, Y;
	bool status;
	int direction;
	double timePowerUpEaten;
	std::string resources;

};


#endif //PACKMAN_CHARACTER_HH
