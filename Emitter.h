/*
 * Emitter.h - an emitter interface
 * Release into public domain.
 */

#ifndef emitter_h
#define emitter_h

#include "Arduino.h"
#include "Particle.h"

class Emitter
{
    public:
        virtual void emit(Particle * particle);
};

#endif /* emitter_h */
