/*
 * Emitter_Spin.h - a spinning emitter
 * works well with 36 particles
 * Release into public domain.
 */

#ifndef emitter_spin_h
#define emitter_spin_h

#include "Emitter_Abstract.h"
#include "Arduino.h"

class Emitter_Spin : public Emitter_Abstract {
public:
    byte x;   //left
    byte y;   //bottom
    byte r;   //radius
    signed char rv;  //radial velocity
    unsigned int counter;
    Emitter_Spin(byte x, byte y, byte r, signed char rv);
    void emit(Particle_Abstract * particle);
    void update();
private:
    static byte perCycle;
    byte cycleRemaining;
};

#endif /* emitter_spin_h */
