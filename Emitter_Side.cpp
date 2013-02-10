/*
 * Emitter_Side.cpp - emit particles from one side
 * Release into public domain.
 */

#include "Emitter_Side.h"

byte Emitter_Side::baseHue = 128; //blues
byte Emitter_Side::maxTtl = 128;

Emitter_Side::Emitter_Side(char side)
{
    counter = 0;
    this->side = side;
}

void Emitter_Side::emit(Particle_Abstract * particle)
{
    counter++;

    switch(side) {
    case 't':
        particle->x = random(PS_MAX_X);
        particle->y = PS_MAX_X-PS_P_RADIUS;
        break;
    case 'r':
        particle->x = PS_MAX_X-PS_P_RADIUS;
        particle->y = random(PS_MAX_Y);
        break;
    case 'b':
        particle->x = random(PS_MAX_X);
        particle->y = 1;
        break;
    case 'l':
        particle->x = 1;
        particle->y = random(PS_MAX_Y);
        break;
    }

    particle->vx = 0;
    particle->vy = 0;

    particle->ttl = random(1, maxTtl);
    particle->hue = baseHue;
    particle->isAlive = true;
}
