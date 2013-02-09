/*
 * SideEmitter.cpp - emit particles from one side
 * Release into public domain.
 */

#include "SideEmitter.h"

byte SideEmitter::baseHue = 128; //blues
byte SideEmitter::maxTtl = 128;

SideEmitter::SideEmitter(char side, byte maxDim)
{
    counter = 0;
    this->side = side;
    this->maxDim = maxDim;
}

void SideEmitter::emit(Particle * particle)
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
