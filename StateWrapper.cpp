#include "StateWrapper.h"


///!Adding a new state to stack
void StateWrapper::AddState(StateRef newState, bool isReplacing)
{
    this->_isAdding = true;
    this->_isReplacing = isReplacing;

    this->_newState = std::move(newState);
}

void StateWrapper::ProcessStateChanges()
{
    if (this->_isRemoving && !this->_states.empty())
    {
        this->_states.pop();
        this->_isRemoving = false;
    }

    if (this->_isAdding)
    {
        if (!this->_states.empty())
        {
            if (this->_isReplacing)
            {
                this->_states.pop();
            }
        }

        this->_states.push(std::move(this->_newState));
        this->_states.top()->Init();
        this->_isAdding = false;
    }
}

StateRef &StateWrapper::GetActiveState()
{
    return this->_states.top();
}