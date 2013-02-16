/*
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/* 
 * ParticleSys.h - generic particle system class
 */

#ifndef p_system_h
#define p_system_h

#include "PsConstants.h"
#include "Particle_Abstract.h"
#include "Emitter_Abstract.h"


//#include "Arduino.h"

class ParticleSys {
public:
    static byte perCycle;
    byte num;
    Particle_Abstract *particles;
    Emitter_Abstract *emitter;

    ParticleSys(byte num, Particle_Abstract particles[], Emitter_Abstract *emitter);
    void update();

private:
    byte cycleRemaining;
};

#endif /* p_system_h */
