/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Particle_Attractor.h - particle with an attractor
 */

#ifndef particle_attractor_h
#define particle_attractor_h

#include "PsConstants.h"
#include "Particle_Abstract.h"

class Particle_Attractor : public Particle_Abstract {
public:
    static byte atx; //horizontal attractor position
    static byte aty; //vertical attractor position
    static signed char atf; //attractor force

    Particle_Attractor();
    void update(void);
};

#endif /* particle_attractor_h */
