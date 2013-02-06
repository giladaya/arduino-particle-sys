/*
 * FixedEmitter.h - emit a particle with the same parameters each time
 * Release into public domain.
 */

#ifndef fixed_emitter_h
#define fixed_emitter_h

#include "Emitter.h"
#include "Arduino.h"

class FixedEmitter : public Emitter
{
    public:
        unsigned int counter;
        byte x;
        byte y;
        signed char vx;
        signed char vy;
        byte ttl;
        
        FixedEmitter(byte x, byte y, signed char vx, signed char vy, byte ttl);
        void emit(Particle * particle);
    private:
};

#endif /* fixed_emitter_h */
