/*
 * Particle_Std.h - standard particle
 * Release into public domain.
 */

#ifndef particle_std_h
#define particle_std_h

#include "Particle_Abstract.h"

class Particle_Std : public Particle_Abstract {
public:
    static byte maxDim;
    static signed char ax; //horizontal acceleration
    static signed char ay; //vertical acceleration

    Particle_Std();
    void update(void);
private:
};

#endif /* particle_std_h */
