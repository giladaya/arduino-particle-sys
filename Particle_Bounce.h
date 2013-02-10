/*
 * Particle_Bounce.h - bouncing particle
 * Release into public domain.
 */

#ifndef particle_bounce_h
#define particle_bounce_h

#include "Particle_Abstract.h"

class Particle_Bounce : public Particle_Abstract {
public:
    static byte maxDim;
    static signed char ax; //horizontal acceleration
    static signed char ay; //vertical acceleration

    Particle_Bounce();
    void update(void);
};

#endif /* particle_bounce_h */
