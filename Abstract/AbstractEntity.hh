#ifndef PACKMAN_ABSTRACTENTITY_HH
#define PACKMAN_ABSTRACTENTITY_HH


class AbstractEntity {
protected:
    AbstractEntity();
public:
    virtual ~AbstractEntity() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
};


#endif //PACKMAN_ABSTRACTENTITY_HH
