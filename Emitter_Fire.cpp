/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Emitter_Fire.cpp - emit particles to simulate fire
 */

#include "Emitter_Fire.h"

byte Emitter_Fire::baseHue = 128; //blues
byte Emitter_Fire::maxTtl = 128;

Emitter_Fire::Emitter_Fire()
{
    counter = 0;
    cycleHue = false;
}

void Emitter_Fire::update()
{
}

void Emitter_Fire::emit(Particle_Abstract *particle)
{
    counter++;
    if (cycleHue) baseHue = (counter>>2)%240;

    if (counter % 2 == 0) {
        particle->x = random(PS_MAX_X >> 2, 3 * (PS_MAX_X >> 2));
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
        particle->x = random(PS_MAX_X);
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
