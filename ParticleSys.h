/*
 * ParticleSys.h - generic particle system class
 * Release into public domain.
 */

#ifndef p_system_h
#define p_system_h

#include "Particle.h"
#include "Emitter.h"


//#include "Arduino.h"

class ParticleSys
{
	public:
		byte num;
		Particle *particles;
		Emitter *emitter;

		ParticleSys(byte num, Particle particles[], Emitter *emitter);
		void update();
	private:
};

#endif /* p_system_h */
