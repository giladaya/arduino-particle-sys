/*
 * BounceParticle.h - bouncing particle
 * Release into public domain.
 */

#ifndef bounce_particle_h
#define bounce_particle_h

#include "Particle.h"

class BounceParticle : public Particle
{
    public:
        static byte maxDim;
        static signed char ax; //horizontal acceleration
        static signed char ay; //vertical acceleration
        
        BounceParticle();
        void update(void);
    private:
};

#endif /* bounce_particle_h */
