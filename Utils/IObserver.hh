#ifndef IOBSERVER_HH
#define IOBSERVER_HH

class IObservable;

class IObserver {
public:
    virtual void Notify(IObservable* observable) = 0;
    virtual ~IObserver(){};
protected:
    IObserver(){};
};
#endif //IOBSERVER_HH
