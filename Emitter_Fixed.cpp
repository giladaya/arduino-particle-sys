/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */
 
/*
 * Emitter_Fixed.cpp - emit a particle with the same parameters each time
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
