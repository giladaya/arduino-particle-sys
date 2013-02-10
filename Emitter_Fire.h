/*
 * Emitter_Fire.h - a fire emitter
 * Release into public domain.
 */

#ifndef emitter_fire_h
#define emitter_fire_h

#include "Emitter_Abstract.h"
#include "Arduino.h"

class Emitter_Fire : public Emitter_Abstract {
public:
    static byte baseHue;
    static byte maxTtl;
    unsigned int counter;
    boolean cycleHue;
    byte maxDim;

    Emitter_Fire(byte maxDim);
    void emit(Particle_Abstract *particle);
private:
};

#endif /* emitter_fire_h */
