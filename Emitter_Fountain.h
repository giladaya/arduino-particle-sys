/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Emitter_Fountain.h - a fountain of particles
 */

#ifndef emitter_fountain_h
#define emitter_fountain_h

#include "Emitter_Abstract.h"
#include "Particle_Abstract.h"
#include "Arduino.h"

class Emitter_Fountain : public Emitter_Abstract {
public:
    static byte minLife;
    static byte maxLife;
    signed char vx;  //horizontal velocity for emitted particles
    signed char vy;  //vertical velocity for emitted particles
    byte var; //emitted particles velocity variance
    Particle_Abstract *source; //source point
    unsigned int counter;

    Emitter_Fountain(signed char vx, signed char vy, byte var, Particle_Abstract *source);
    void emit(Particle_Abstract * particle);
    void update();
private:
    byte _hVar;
};

#endif /* emitter_fountain_h */
