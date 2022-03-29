#ifndef STATEWRAPPER_H
#define STATEWRAPPER_H


#include <memory>
#include <stack>

#include "State.h"

typedef std::unique_ptr<State> StateRef;
///klasa odpowiedzialna za zarządzanie oknami gry
class StateWrapper
{
public:
    StateWrapper() { }
    ~StateWrapper() { }

    ///Funkcja dodająca stan
    void AddState(StateRef newState, bool isReplacing = true);

    ///Funkcja monitorujaca stan
    void ProcessStateChanges();

    StateRef &GetActiveState();

private:
    std::stack<StateRef> _states;
    StateRef _newState;

    bool _isRemoving;
    bool _isAdding, _isReplacing;
};

#endif // STATEWRAPPER_H