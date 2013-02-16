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

#include <Colorduino.h>
#include "ParticleSys.h"
#include "Particle_Std.h"
#include "Particle_Attractor.h"
#include "Emitter_Fountain.h"
#include "PartMatrix.h"

const byte numParticles = 70;
boolean pulseOn = false;

Particle_Std particles[numParticles];
Particle_Attractor source;
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
    for (byte y=0;y<ColorduinoScreenHeight;y++) {
        for(byte x=0;x<ColorduinoScreenWidth;x++) {
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
  byte whiteBalVal[3] = {36,63,7}; // for LEDSEE 6x6cm round matrix
  Colorduino.SetWhiteBal(whiteBalVal);
  
  randomSeed(analogRead(0));
  
  source.vx = 3;
  source.vy = 1;
  source.x = random(50)+100;
  source.y = random(10)+1;
  Particle_Std::ay = 1;
  //PartMatrix::isOverflow = false;
  Emitter_Fountain::minLife = 100;
  Emitter_Fountain::maxLife = 200;
  //ParticleSys::perCycle = 2;
  Particle_Attractor::atf = 2;
 
  //init all pixels to zero
  pMatrix.reset();
}

void loop()
{
    pSys.update();
    drawMatrix();
    Colorduino.FlipPage();
    delay(50);
}