/*
 * SpinEmitter.h - a spinning emitter
 * works well with 36 particles
 * Release into public domain.
 */

#ifndef spin_emitter_h
#define spin_emitter_h

#include "Emitter.h"
#include "Arduino.h"

class SpinEmitter : public Emitter
{
    public:
        byte x;   //left
        byte y;   //bottom
        byte r;   //radius
        signed char rv;  //radial velocity
        unsigned int counter;
        SpinEmitter(byte x, byte y, byte r, signed char rv);
        void emit(Particle * particle);
    private:
};

#endif /* spin_emitter_h */
