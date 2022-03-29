#ifndef STATE_H
#define STATE_H
//Virtual methods which are override later
class State
{
public:
    virtual void Init() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
};
#endif