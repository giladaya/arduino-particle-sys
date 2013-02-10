/*
 * particle.cpp - generic particle class
 * Release into public domain.
 */

#include "Particle_Bounce.h"

signed char Particle_Bounce::ax = 0;
signed char Particle_Bounce::ay = 0;

Particle_Bounce::Particle_Bounce()
{
    isAlive = false;
}

void Particle_Bounce::update(void)
{
    //age
    ttl--;

    //apply acceleration
    vx = min(vx + ax, PS_MAX_X);
    vy = min(vy + ay, PS_MAX_Y);

    //apply velocity
    unsigned int newX, newY;
    if (y == 0 || y >= PS_MAX_Y) {
        vy = -1 * vy;
    }
    if (x == 0 || x >= PS_MAX_X) {
        vx = -1 * vx;
    }
    if (ttl == 0 || (vx == 0 && vy == 0)) {
        isAlive = false;
    } else {
        x = min(max(x + vx, 0), PS_MAX_X);
        y = min(max(y + vy, 0), PS_MAX_Y);
    }
}

