/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
 * Particle_Std.h - standard particle, dies when out of bounds
 */

#ifndef particle_std_h
#define particle_std_h

#include "PsConstants.h"
#include "Particle_Abstract.h"

class Particle_Std : public Particle_Abstract {
public:
    static signed char ax; //horizontal acceleration
    static signed char ay; //vertical acceleration

    Particle_Std();
    void update(void);
};

#endif /* particle_std_h */
