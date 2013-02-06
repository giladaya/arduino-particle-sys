/*
 * SpinEmitter.cpp - a spinning emitter
 * Release into public domain.
 */

#include "SpinEmitter.h"

SpinEmitter::SpinEmitter(byte x, byte y, byte r, signed char rv)
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->rv = rv;
    counter = 0;
}

void SpinEmitter::emit(Particle * particle)
{
//    static char vx = 7;
//    static char vy = 3;
//    static byte maxDim = 255;
    float radAngle;
   
    counter++;
    particle->x = this->x;
    particle->y = this->y;
    
    // Conver from Degree -> Rad
   
    if (counter%2 == 0){
        radAngle = -counter*rv*(PI/180) ;
    }
    else {
        radAngle = 180-counter*rv*(PI/180) ;
    }
    // Convert Polar -> Cartesian
    particle->vx = (signed char)(r * cos(radAngle));
    particle->vy = (signed char)(r * sin(radAngle));
    
    particle->ttl = random(20,100);
    particle->hue = counter%255;
    particle->isAlive = true;
   
//    x = min(max(x+vx, 0), maxDim);
//    y = min(max(y+vy, 0), maxDim);
//    if (y == 0 || y == maxDim){
//        vy = -1*vy;
//    }
//    if (x == 0 || x == maxDim){
//        vx = -1*vx;
//    }
}
