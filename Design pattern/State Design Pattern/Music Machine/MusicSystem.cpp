#include "MusicSystem.h"
#include "StoppedState.h"

MusicSystem::MusicSystem()
{
    m_CurrentState = new StoppedState();
}
bool MusicSystem::playMusic()
{
    if (m_CurrentState)
        return m_CurrentState->playMusic(this);
    return false;
}
bool MusicSystem::stopMusic()
{
    if (m_CurrentState)
        return m_CurrentState->stopMusic(this);
    return false;
}
bool MusicSystem::previousSong()
{
    if (m_CurrentState)
        return m_CurrentState->previousSong(this);
    return false;
}
bool MusicSystem::nextSong()
{
    if (m_CurrentState)
        return m_CurrentState->nextSong(this);
    return false;
}

void MusicSystem::setCurrentState(State * currentState)
{
    if(m_CurrentState){
        delete m_CurrentState;
        m_CurrentState = nullptr;
    }
    m_CurrentState = currentState;
}
