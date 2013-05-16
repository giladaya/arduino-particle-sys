/*
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Emitter_Spin.cpp - a spinning emitter
 */

#include "Emitter_Spin.h"

byte Emitter_Spin::maxTtl = 100;

Emitter_Spin::Emitter_Spin(byte x, byte y, byte r, signed char rv)
{
    this->x = x;
    this->y = y;
    this->r = r;
    this->rv = tempRv = rv;
    oscilate = false;
    counter = 0;
}

void Emitter_Spin::update()
{
    static signed char direction = -1;
    float radAngle;
    counter++;

    //calculate velocity vector
    if (oscilate && (counter%20 == 0)){
        tempRv += direction;
        if (abs(tempRv) > rv){
            direction = -direction;
        }
    }

    // Conver from Degree -> Rad
    if (counter%2 == 0) {
        radAngle = -counter*tempRv*(PI/180) ;
    } else {
        radAngle = 180-counter*tempRv*(PI/180) ;
    }
    // Convert Polar -> Cartesian
    vx = (signed char)(r * cos(radAngle));
    vy = (signed char)(r * sin(radAngle));
}

void Emitter_Spin::emit(Particle_Abstract * particle)
{
    particle->x = this->x;
    particle->y = this->y;

    particle->vx = vx;
    particle->vy = vy;

    particle->ttl = random(20, maxTtl);
    particle->hue = (counter>>1)%255;
    particle->isAlive = true;
}
