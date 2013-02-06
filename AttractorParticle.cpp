/*
 * AttractorParticle.cpp - attractor particle
 * Release into public domain.
 */

#include "AttractorParticle.h"

byte AttractorParticle::maxDim = 255;
byte AttractorParticle::ax = 0;
byte AttractorParticle::ay = 0;
signed char AttractorParticle::af = 0;

AttractorParticle::AttractorParticle()
{
   isAlive = false;
}

void AttractorParticle::update(void){
    int dx, dy;
    signed char acx, acy;
    float mult;
    //age
    //ttl--;

    dx = ax - x;
    dy = ay - y;
    mult = (float)af/sqrt(dx*dx+dy*dy); 
    acx = (signed char)(mult*dx);
    acy = (signed char)(mult*dy);
    
//    acx = -1*af;
//    acy = -1;
    
    //apply acceleration
    vx = min(vx+acx, maxDim);
    vy = min(vy+acy, maxDim);
    
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

