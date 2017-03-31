#ifndef IOBSERVABLE_HH
#define IOBSERVABLE_HH

#include "IObserver.hh"
#include <iostream>
#include <list>

class IObservable {
public:
    virtual void AddObserver(IObserver*) = 0;
    virtual void RemoveObserver(IObserver*) = 0;
    virtual ~IObservable(){};
protected:
    IObservable(){};
    std::list<IObserver*> observers;
};
#endif //IOBSERVABLE_HH
