/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * particle.cpp - a particle that bounces off the "box" walls
 */

#include "Particle_Bounce.h"

signed char Particle_Bounce::ax = 0;
signed char Particle_Bounce::ay = 0;

Particle_Bounce::Particle_Bounce()
{
    isAlive = false;
}

void Particle_Bounce::update(void)
{
    //age
    ttl--;

    //apply acceleration
    vx = min(vx + ax, PS_MAX_X);
    vy = min(vy + ay, PS_MAX_Y);

    //apply velocity
    unsigned int newX, newY;
    if (y == 0 || y >= PS_MAX_Y) {
        vy = -1 * vy;
    }
    if (x == 0 || x >= PS_MAX_X) {
        vx = -1 * vx;
    }
    if (ttl == 0 || (vx == 0 && vy == 0)) {
        isAlive = false;
    } else {
        x = min(max(x + vx, 0), PS_MAX_X);
        y = min(max(y + vy, 0), PS_MAX_Y);
    }
}

