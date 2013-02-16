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
  * Creates a green flame effect.
  * 
  * Note: this example uses the colorduino library becuse that is what I had, 
  * but any device that supports setting a pixel to an RGB value can be used
  */

#include <Colorduino.h>
#include "ParticleSys.h"
#include "Particle_Std.h"
#include "Emitter_Fire.h"
#include "PartMatrix.h"

const byte numParticles = 90;

Particle_Std particles[numParticles];
Emitter_Fire emitter;
ParticleSys pSys(numParticles, particles, &emitter);
PartMatrix pMatrix;

/**
 * Render the particles into a low-resolution matrix
 */
void drawMatrix()
{
    pMatrix.reset();
    pMatrix.render(particles, numParticles);
    //update the actual LED matrix
    for (byte y = 0; y < ColorduinoScreenHeight; y++)
    {
        for (byte x = 0; x < ColorduinoScreenWidth; x++)
        {
            Colorduino.SetPixel(x, y, pMatrix.matrix[x][y].r, pMatrix.matrix[x][y].g, pMatrix.matrix[x][y].b);
        }
    }
}

void setup()
{
    Colorduino.Init(); // initialize the board

    // compensate for relative intensity differences in R/G/B brightness
    // array of 6-bit base values for RGB (0~63)
    // whiteBalVal[0]=red
    // whiteBalVal[1]=green
    // whiteBalVal[2]=blue
    byte whiteBalVal[3] = {36, 63, 7}; // for LEDSEE 6x6cm round matrix
    Colorduino.SetWhiteBal(whiteBalVal);

    randomSeed(analogRead(0));

    Particle_Std::ay = 1;
    ParticleSys::perCycle = 10;
    Emitter_Fire::baseHue = 75;  //green
    //Emitter_Fire::baseHue = 156; //blue
    Emitter_Fire::maxTtl = 96;
    PartMatrix::isOverflow = false;

    //init all pixels to zero
    pMatrix.reset();
}

void loop()
{
    pSys.update();
    drawMatrix();

    Colorduino.FlipPage();
    delay(15);
}