/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/*
  * An example for the Arduino particle system library
 * A wandering particle that emits colorful smoke 
 * 
 * Note: this example uses the colorduino library becuse that is what I had, 
 * but any device that supports setting a pixel to an RGB value can be used
 */

//'r' for rainbowduino, 'c' for colorduino
#define BOARD 'r'

#if BOARD == 'c'
#include <Colorduino.h>
#else
#include <Rainbowduino.h>
#endif

#include "ParticleSys.h"
#include "Particle_Std.h"
#include "Particle_Fixed.h"
#include "Emitter_Fountain.h"
#include "PartMatrix.h"

const byte numParticles = 50;
boolean pulseOn = false;

Particle_Std particles[numParticles];
Particle_Fixed source;
Emitter_Fountain emitter(0, 0, 5, &source);
ParticleSys pSys(numParticles, particles, &emitter);
PartMatrix pMatrix;

/**
 * Render the particles into a low-resolution matrix
 */
void drawMatrix(){
    pMatrix.reset();
    pMatrix.render(particles, numParticles);
    //update the actual LED matrix
    for (byte y=0;y<PS_PIXELS_Y;y++) {
        for(byte x=0;x<PS_PIXELS_X;x++) {
#if BOARD == 'c'
            Colorduino.SetPixel(x, y, pMatrix.matrix[x][y].r, pMatrix.matrix[x][y].g, pMatrix.matrix[x][y].b);
#else
            Rb.setPixelXY(PS_PIXELS_Y-y-1, x, pMatrix.matrix[x][y].r, pMatrix.matrix[x][y].g, pMatrix.matrix[x][y].b);
#endif
        }
    }
}

void setup()
{
#if BOARD == 'c'    
    Colorduino.Init(); // initialize the board

    // compensate for relative intensity differences in R/G/B brightness
    // array of 6-bit base values for RGB (0~63)
    // whiteBalVal[0]=red
    // whiteBalVal[1]=green
    // whiteBalVal[2]=blue
    byte whiteBalVal[3] = {36,63,7}; // for LEDSEE 6x6cm round matrix
    Colorduino.SetWhiteBal(whiteBalVal);
#else
    Rb.init();
#endif   

    randomSeed(analogRead(0));

    //source.vx = 3;
    //source.vy = 1;
    source.x = 112;
    source.y = 1;
    Emitter_Fountain::minLife = 20;
    Emitter_Fountain::maxLife = 80;
    Particle_Std::ay = 1;
    //PartMatrix::isOverflow = false;

    //init all pixels to zero
    pMatrix.reset();
}

void loop()
{
    pSys.update();
    drawMatrix();
#if BOARD == 'c'    
    Colorduino.FlipPage();
#endif    
    delay(40);
}

