/*
 * Emitter_Abstract.h - an emitter interface
 * Release into public domain.
 */

#ifndef emitter_abstract_h
#define emitter_abstract_h

#include "Arduino.h"
#include "Particle_Abstract.h"

class Emitter_Abstract {
public:
    virtual void emit(Particle_Abstract * particle);
    virtual void update(){}
};

#endif /* emitter_abstract_h */
