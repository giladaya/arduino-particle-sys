/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Emitter_Fire.h - emit particles to simulate fire
 */

#ifndef emitter_fire_h
#define emitter_fire_h

#include "PsConstants.h"
#include "Emitter_Abstract.h"
#include "Arduino.h"

class Emitter_Fire : public Emitter_Abstract {
public:
    static byte baseHue;
    static byte maxTtl;
    unsigned int counter;
    boolean cycleHue;

    Emitter_Fire();
    void emit(Particle_Abstract *particle);
    void update();
};

#endif /* emitter_fire_h */
