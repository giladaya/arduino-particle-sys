/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * particle.h - abstract particle class
 */

#ifndef particle_abstract_h
#define particle_abstract_h

#include "PsConstants.h"
#include "Arduino.h"

class Particle_Abstract {
public:
    byte x;   //left
    byte y;   //bottom
    signed char vx;  //horizontal velocity
    signed char vy;  //vertical velocity
    byte ttl; //time to live
    byte hue; //hue
    boolean isAlive; //is alive?

    virtual void update(void);
};

#endif /* particle_abstract_h */
