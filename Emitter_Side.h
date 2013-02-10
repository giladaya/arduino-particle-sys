/*
 * Emitter_Side.h - a rainning emitter
 * Release into public domain.
 */

#ifndef emitter_side_h
#define emitter_side_h

#include "Emitter_Abstract.h"
#include "Arduino.h"

class Emitter_Side : public Emitter_Abstract {
public:
    static byte baseHue;
    static byte maxTtl;
    unsigned int counter;
    char side;
    byte maxDim;

    Emitter_Side(char side, byte maxDim);
    void emit(Particle_Abstract * particle);
};

#endif /* emitter_side_h */
