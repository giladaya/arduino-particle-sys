/*
 * ParticleSys.cpp - generic particle system class
 * Release into public domain.
 */
#include "ParticleSys.h"

ParticleSys::ParticleSys(byte num, Particle_Abstract particles[], Emitter_Abstract *emitter)
{
    this->num = num;
    this->particles = particles;
    this->emitter = emitter;
}

void ParticleSys::update()
{
    emitter->update();
    for(int i = 0; i<num; i++) {
        particles[i].update();
        if (!particles[i].isAlive) {
            emitter->emit(&particles[i]);
        }
    }
}

