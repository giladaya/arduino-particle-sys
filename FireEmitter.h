/*
 * FireEmitter.h - a fire emitter
 * Release into public domain.
 */

#ifndef fire_emitter_h
#define fire_emitter_h

#include "Emitter.h"
#include "Arduino.h"

class FireEmitter : public Emitter {
public:
    static byte baseHue;
    static byte maxTtl;
    unsigned int counter;
    boolean cycleHue;
    byte maxDim;

    FireEmitter(byte maxDim);
    void emit(Particle *particle);
private:
};

#endif /* fire_emitter_h */
