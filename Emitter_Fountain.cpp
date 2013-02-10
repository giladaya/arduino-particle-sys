/*
 * Emitter_Fountain.cpp - a fountain of particles
 * Release into public domain.
 */

#include "Emitter_Fountain.h"

Emitter_Fountain::Emitter_Fountain(signed char vx, signed char vy, byte var, Particle_Abstract *source)
{
    this->vx = vx;
    this->vy = vy;
    this->var = var;
    this->_hVar = (var>>1);
    this->source = source;
    counter = 0;
}

void Emitter_Fountain::emit(Particle_Abstract * particle)
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
