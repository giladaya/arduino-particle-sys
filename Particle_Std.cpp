/*
 * particle.cpp - generic particle class
 * Release into public domain.
 */

#include "Particle_Std.h"

signed char Particle_Std::ax = 0;
signed char Particle_Std::ay = 0;

Particle_Std::Particle_Std()
{
    isAlive = false;
}

void Particle_Std::update(void)
{
    //age
    ttl--;

    //apply acceleration
    vx = min(vx+ax, PS_MAX_X);
    vy = min(vy+ay, PS_MAX_Y);

    //apply velocity
    unsigned int newX, newY;
    newX = x + vx;
    newY = y + vy;
    if(ttl == 0 || newX < 0 || newX > PS_MAX_X || newY < 0 || newY > PS_MAX_Y) {
        isAlive = false;
    } else {
        x = (byte)newX;
        y = (byte)newY;
    }
}

