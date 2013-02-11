/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Particle_Bounce.h - a particle that bounces off the "box" walls
 */

#ifndef particle_bounce_h
#define particle_bounce_h

#include "PsConstants.h"
#include "Particle_Abstract.h"

class Particle_Bounce : public Particle_Abstract {
public:
    static signed char ax; //horizontal acceleration
    static signed char ay; //vertical acceleration

    Particle_Bounce();
    void update(void);
};

#endif /* particle_bounce_h */
