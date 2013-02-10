/*
 * particle.cpp - generic particle class
 * Release into public domain.
 */

#include "Particle_Std.h"

byte Particle_Std::maxDim = 255;
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
    vx = min(vx+ax, maxDim);
    vy = min(vy+ay, maxDim);

    //apply velocity
    unsigned int newX, newY;
    newX = x + vx;
    newY = y + vy;
    if(ttl == 0 || newX < 0 || newX > maxDim || newY < 0 || newY > maxDim) {
        isAlive = false;
    } else {
        x = (byte)newX;
        y = (byte)newY;
    }
}

