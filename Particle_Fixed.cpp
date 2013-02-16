/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Particle_Fixed.cpp - a fixed particle that doen't move, just fades
 */

#include "Particle_Fixed.h"

byte Particle_Fixed::decayFactor = 10;

Particle_Fixed::Particle_Fixed()
{
    isAlive = false;
}

void Particle_Fixed::update(void)
{
    //age
    if (ttl < decayFactor) {
        isAlive = false;
        return;
    }
    ttl -= decayFactor;
}

