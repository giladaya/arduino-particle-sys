/*
 * Emitter_Fire.h - a fire emitter
 * Release into public domain.
 */

#ifndef emitter_fire_h
#define emitter_fire_h

#include "PsConstants.h"
#include "Emitter_Abstract.h"
#include "Arduino.h"

class Emitter_Fire : public Emitter_Abstract {
public:
    static byte baseHue;
    static byte maxTtl;
    unsigned int counter;
    boolean cycleHue;

    Emitter_Fire();
    void emit(Particle_Abstract *particle);
    void update();
private:
    static byte perCycle;
    byte cycleRemaining;
};

#endif /* emitter_fire_h */
