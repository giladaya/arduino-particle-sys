/*
 * particle.cpp - generic particle class
 * Release into public domain.
 */

#include "BounceParticle.h"

byte BounceParticle::maxDim = 255;
signed char BounceParticle::ax = 0;
signed char BounceParticle::ay = 0;

BounceParticle::BounceParticle()
{
   isAlive = false;
}

void BounceParticle::update(void){
    //age
    ttl--;
    
    //apply acceleration
    vx = min(vx+ax, maxDim);
    vy = min(vy+ay, maxDim);
    
    //apply velocity
    unsigned int newX, newY;
    if (y == 0 || y == maxDim){
        vy = -1*vy;
    }
    if (x == 0 || x == maxDim){
        vx = -1*vx;
    }
    if (ttl == 0 || (vx == 0 && vy == 0)){
        isAlive = false;
    }
    else {
        x = min(max(x+vx, 0), maxDim);
        y = min(max(y+vy, 0), maxDim);
    }
 }

