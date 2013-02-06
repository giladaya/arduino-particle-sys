/*
 * StdParticle.h - standard particle
 * Release into public domain.
 */

#ifndef std_particle_h
#define std_particle_h

#include "Particle.h"

class StdParticle : public Particle
{
    public:
        static byte maxDim;
        static signed char ax; //horizontal acceleration
        static signed char ay; //vertical acceleration
        
        StdParticle();
        void update(void);
    private:
};

#endif /* std_particle_h */
