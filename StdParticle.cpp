/*
 * particle.cpp - generic particle class
 * Release into public domain.
 */

#include "StdParticle.h"

byte StdParticle::maxDim = 255;
signed char StdParticle::ax = 0;
signed char StdParticle::ay = 0;

StdParticle::StdParticle()
{
   isAlive = false;
}

void StdParticle::update(void){
    //age
    ttl--;
    
    //apply acceleration
    vx = min(vx+ax, maxDim);
    vy = min(vy+ay, maxDim);
    
    //apply velocity
    unsigned int newX, newY;
    newX = x + vx;
    newY = y + vy;
    if(ttl == 0 || newX < 0 || newX > maxDim || newY < 0 || newY > maxDim){
       isAlive = false;
    }
    else {
       x = (byte)newX;
       y = (byte)newY;
    }
}

