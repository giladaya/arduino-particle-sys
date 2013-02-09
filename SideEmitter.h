/*
 * SideEmitter.h - a rainning emitter
 * Release into public domain.
 */

#ifndef side_emitter_h
#define side_emitter_h

#include "Emitter.h"
#include "Arduino.h"

class SideEmitter : public Emitter {
public:
    static byte baseHue;
    static byte maxTtl;
    unsigned int counter;
    char side;
    byte maxDim;

    SideEmitter(char side, byte maxDim);
    void emit(Particle * particle);
private:
};

#endif /* side_emitter_h */
