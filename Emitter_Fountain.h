/*
 * Emitter_Fountain.h - a fountain of particles
 * Release into public domain.
 */

#ifndef emitter_fountain_h
#define emitter_fountain_h

#include "Emitter_Abstract.h"
#include "Particle_Abstract.h"
#include "Arduino.h"

class Emitter_Fountain : public Emitter_Abstract {
public:
    signed char vx;  //horizontal velocity for emitted particles
    signed char vy;  //vertical velocity for emitted particles
    byte var; //emitted particles velocity variance
    Particle_Abstract *source; //source point
    unsigned int counter;
    Emitter_Fountain(signed char vx, signed char vy, byte var, Particle_Abstract *source);
    void emit(Particle_Abstract * particle);
private:
    byte _hVar;
};

#endif /* emitter_fountain_h */
