/*
 * FountainEmitter.cpp - a fountain of particles
 * Release into public domain.
 */

#include "FountainEmitter.h"

FountainEmitter::FountainEmitter(signed char vx, signed char vy, byte var, Particle *source)
{
    this->vx = vx;
    this->vy = vy;
    this->var = var;
    this->_hVar = (var>>1);
    this->source = source;
    counter = 0;
}

void FountainEmitter::emit(Particle * particle)
{
    counter++;
    source->update();

    particle->x = source->x;
    particle->y = source->y;
    particle->vx = vx + random(var)-_hVar;
    particle->vy = vy + random(var)-_hVar;
    
    //particle->ttl = random(20,100);
    particle->ttl = counter%200+50;
    particle->hue = counter%255;
    particle->isAlive = true;
}
