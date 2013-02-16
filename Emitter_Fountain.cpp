/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Emitter_Fountain.cpp - a fountain of particles
 */

#include "Emitter_Fountain.h"

byte Emitter_Fountain::minLife = 50;
byte Emitter_Fountain::maxLife = 250;

Emitter_Fountain::Emitter_Fountain(signed char vx, signed char vy, byte var, Particle_Abstract *source)
{
    this->vx = vx;
    this->vy = vy;
    this->var = var;
    this->_hVar = (var>>1);
    this->source = source;
    counter = 0;
}

void Emitter_Fountain::update()
{
    source->update();
}

void Emitter_Fountain::emit(Particle_Abstract * particle)
{
    counter++;
    source->update();

    particle->x = source->x;
    particle->y = source->y;
    particle->vx = vx + random(var)-_hVar;
    particle->vy = vy + random(var)-_hVar;

    //particle->ttl = random(20,100);
    particle->ttl = random(minLife, maxLife);
    particle->hue = counter%255;
    particle->isAlive = true;
}
