#pragma once

#include <memory>
#include <stack>

#include "State.hpp"

typedef std::unique_ptr<State> StateRef;

class StateManager
{
public:
    StateManager();
    ~StateManager();

    void pushState(StateRef newState, bool isReplacing = true);
    void popState();

    void processStateChanges();

    StateRef &getActiveState();

private:
    std::stack<StateRef> m_states;
    StateRef m_newState;

    bool m_isRemoving;
    bool m_isAdding;
    bool m_isReplacing;
};
