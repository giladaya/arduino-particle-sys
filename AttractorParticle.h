/*
 * AttractorParticle.h - standard particle
 * Release into public domain.
 */

#ifndef attractor_particle_h
#define attractor_particle_h

#include "Particle.h"

class AttractorParticle : public Particle
{
    public:
        static byte maxDim;
        static byte ax; //horizontal attractor position
        static byte ay; //vertical attractor position
        static signed char af; //attractor force
        
        AttractorParticle();
        void update(void);
    private:
};

#endif /* attractor_particle_h */
