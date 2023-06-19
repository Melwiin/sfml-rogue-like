#include "StateManager.hpp"

StateManager::StateManager() : m_isAdding(false), m_isReplacing(false), m_isRemoving(false) {

}

StateManager::~StateManager() {

}

void StateManager::pushState(StateRef newState, bool isReplacing) {
    m_isAdding = true;
    m_isReplacing = isReplacing;
    m_newState = std::move(newState);
}

void StateManager::popState() {
    m_isRemoving = true;
}

void StateManager::processStateChanges() {
    if (m_isRemoving && !m_states.empty()) {
        m_states.pop();

        if (!m_states.empty()) {
            m_states.top()->resume();
        }

        m_isRemoving = false;
    }

    if (m_isAdding) {
        if (!m_states.empty()) {
            if (m_isReplacing) {
                m_states.pop();
            } else {
                m_states.top()->pause();
            }
        }

        m_states.push(std::move(m_newState));
        m_states.top()->init();

        m_isAdding = false;
    }
}

StateRef &StateManager::getActiveState() {
    return m_states.top();
}