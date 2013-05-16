/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Emitter_Spin.h - a spinning emitter
 * works well with 36 particles
 */

#ifndef emitter_spin_h
#define emitter_spin_h

#include "Emitter_Abstract.h"
#include "Arduino.h"

class Emitter_Spin : public Emitter_Abstract {
public:
    static byte maxTtl;
    byte x;   //left
    byte y;   //bottom
    byte r;   //radius
    signed char rv;  //radial velocity
    boolean oscilate; //whether to oscilate radial velocity
    unsigned int counter;
    Emitter_Spin(byte x, byte y, byte r, signed char rv);
    void emit(Particle_Abstract * particle);
    void update();
private:
    signed char vx;
    signed char vy;
    signed char tempRv;
};

#endif /* emitter_spin_h */
