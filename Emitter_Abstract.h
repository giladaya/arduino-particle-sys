/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Emitter_Abstract.h - an abstract emitter class
 */

#ifndef emitter_abstract_h
#define emitter_abstract_h

#include "Arduino.h"
#include "Particle_Abstract.h"

class Emitter_Abstract {
public:
    virtual void emit(Particle_Abstract * particle);
    virtual void update(){}
};

#endif /* emitter_abstract_h */
