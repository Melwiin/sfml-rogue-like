#pragma once

class State
{
public:
    virtual void init() = 0;

    virtual void handleEvents() = 0;
    virtual void update(float dt) = 0;
    virtual void render() = 0;

    virtual void pause() { }
    virtual void resume() { }
};

