/*
 * FountainEmitter.h - a fountain of particles
 * Release into public domain.
 */

#ifndef fountain_emitter_h
#define fountain_emitter_h

#include "Emitter.h"
#include "Arduino.h"

class FountainEmitter : public Emitter
{
    public:
        signed char vx;  //horizontal velocity for emitted particles
        signed char vy;  //vertical velocity for emitted particles
        byte var; //emitted particles velocity variance
        Particle *source; //source point
        unsigned int counter;
        FountainEmitter(signed char vx, signed char vy, byte var, Particle *source);
        void emit(Particle * particle);
    private:
        byte _hVar;
};

#endif /* fountain_emitter_h */
