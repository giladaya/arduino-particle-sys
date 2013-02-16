/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Particle_Fixed.h - a fixed particle that doen't move, just fades
 */

#ifndef particle_fixed_h
#define particle_fixed_h

#include "PsConstants.h"
#include "Particle_Abstract.h"

class Particle_Fixed : public Particle_Abstract {
public:
    static byte decayFactor;
    Particle_Fixed();
    void update(void);
};

#endif /* particle_fixed_h */
