/*
 * Emitter_Spin.cpp - a spinning emitter
 * Release into public domain.
 */

#include "Emitter_Spin.h"

 byte Emitter_Spin::perCycle = 10;

Emitter_Spin::Emitter_Spin(byte x, byte y, byte r, signed char rv)
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->rv = rv;
    counter = 0;
    cycleRemaining = perCycle;
}

void Emitter_Spin::update()
{
    cycleRemaining = perCycle;
}

void Emitter_Spin::emit(Particle_Abstract * particle)
{
//    static char vx = 7;
//    static char vy = 3;
    float radAngle;

    counter++;
    particle->x = this->x;
    particle->y = this->y;

    // Conver from Degree -> Rad

    if (counter%2 == 0) {
        radAngle = -counter*rv*(PI/180) ;
    } else {
        radAngle = 180-counter*rv*(PI/180) ;
    }
    // Convert Polar -> Cartesian
    particle->vx = (signed char)(r * cos(radAngle));
    particle->vy = (signed char)(r * sin(radAngle));

    particle->ttl = random(20,100);
    particle->hue = counter%255;
    particle->isAlive = true;
}
