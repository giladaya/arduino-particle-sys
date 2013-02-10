/*
 * Particle_Attractor.h - standard particle
 * Release into public domain.
 */

#ifndef particle_attractor_h
#define particle_attractor_h

#include "PsConstants.h"
#include "Particle_Abstract.h"

class Particle_Attractor : public Particle_Abstract {
public:
    static byte ax; //horizontal attractor position
    static byte ay; //vertical attractor position
    static signed char af; //attractor force

    Particle_Attractor();
    void update(void);
};

#endif /* particle_attractor_h */
