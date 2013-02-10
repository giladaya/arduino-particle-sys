/*
 * Emitter_Fixed.cpp - emit a particle with the same parameters each time
 * Release into public domain.
 */

#include "Emitter_Fixed.h"

Emitter_Fixed::Emitter_Fixed(byte x, byte y, signed char vx, signed char vy, byte ttl)
{
    counter = 0;
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->ttl = ttl;
}

void Emitter_Fixed::emit(Particle_Abstract * particle)
{
    counter++;

    particle->vx = vx;
    particle->vy = vy;

    particle->x = x;
    particle->y = y;

    particle->ttl = ttl;
    particle->hue = counter%250;
    particle->isAlive = true;
}
