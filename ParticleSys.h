/*
 * ParticleSys.h - generic particle system class
 * Release into public domain.
 */

#ifndef p_system_h
#define p_system_h

#include "PsConstants.h"
#include "Particle_Abstract.h"
#include "Emitter_Abstract.h"


//#include "Arduino.h"

class ParticleSys {
public:
    byte num;
    Particle_Abstract *particles;
    Emitter_Abstract *emitter;

    ParticleSys(byte num, Particle_Abstract particles[], Emitter_Abstract *emitter);
    void update();
};

#endif /* p_system_h */
