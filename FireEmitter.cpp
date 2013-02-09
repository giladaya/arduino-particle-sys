/*
 * FireEmitter.cpp - emit particles from one side
 * Release into public domain.
 */

#include "FireEmitter.h"

byte FireEmitter::baseHue = 128; //blues
byte FireEmitter::maxTtl = 128;

FireEmitter::FireEmitter(byte maxDim)
{
    counter = 0;
    this->maxDim = maxDim;
    cycleHue = false;
}

void FireEmitter::emit(Particle *particle)
{
    counter++;
    if (cycleHue) baseHue = counter%240;

    if (counter % 2 == 0) {
        particle->x = random(maxDim >> 2, 3 * (maxDim >> 2));
        switch (particle->x / 32) {
        case 0:
        case 7:
            particle->ttl = random(1, 7);
            break;
        case 1:
        case 6:
            particle->ttl = random(5, 14);
            break;
        case 2:
        case 5:
            particle->ttl = random(15, 21);
            break;
        case 3:
        case 4:
            particle->ttl = random(25, 28);
            break;
        }
        particle->hue = baseHue+16;
    } else {
        particle->x = random(maxDim);
        switch (particle->x / 32) {
        case 0:
        case 7:
            particle->ttl = random(1, 20);
            break;
        case 1:
        case 6:
            particle->ttl = random(5, 40);
            break;
        case 2:
        case 5:
            particle->ttl = random(20, 70);
            break;
        case 3:
        case 4:
            particle->ttl = random(40, 100);
            break;
        }
        particle->hue = baseHue;
    }

    particle->y = 1;

    particle->vx = 0;
    particle->vy = 0;


    particle->isAlive = true;
}
