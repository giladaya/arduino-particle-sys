/*
 * Emitter_Side.cpp - emit particles from one side
 * Release into public domain.
 */

#include "Emitter_Side.h"

byte Emitter_Side::baseHue = 128; //blues
byte Emitter_Side::maxTtl = 128;

Emitter_Side::Emitter_Side(char side, byte maxDim)
{
    counter = 0;
    this->side = side;
    this->maxDim = maxDim;
}

void Emitter_Side::emit(Particle_Abstract * particle)
{
    counter++;

    switch(side) {
    case 't':
        particle->x = random(maxDim);
        particle->y = maxDim-32;
        break;
    case 'r':
        particle->x = maxDim-32;
        particle->y = random(maxDim);
        break;
    case 'b':
        particle->x = random(maxDim);
        particle->y = 1;
        break;
    case 'l':
        particle->x = 1;
        particle->y = random(maxDim);
        break;
    }

    particle->vx = 0;
    particle->vy = 0;

    particle->ttl = random(1, maxTtl);
    particle->hue = baseHue;
    particle->isAlive = true;
}
