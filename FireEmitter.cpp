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
}

void FireEmitter::emit(Particle * particle)
{
   counter++;

   particle->x = random(maxDim);
   particle->y = 1;
 
   particle->vx = 0;
   particle->vy = 0;
  
   switch(particle->x)
   {
      case 0:
      case 7:
        particle->ttl = random(1,(maxTtl>>3));
        break;
      case 1:
      case 6:
        particle->ttl = random(1,(maxTtl>>2));
        break;
      case 2:
      case 5:
        particle->ttl = random(1,(maxTtl>>1));
        break;
      case 3:
      case 4:
        particle->ttl = random(1,maxTtl);
        break;
   }

   particle->hue = baseHue;
   particle->isAlive = true;
}
