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
  * Simulation of a color-changing flame, which height is controlled by voice.
  * The louder the sound, the higher the flame.
  * 
  * Note: this example responds to measured audio volume levels.
  * For this to work, an analog audio sensor or an amplified microphone
  * needs to be connected to pin A5
  */

//'r' for rainbowduino, 'c' for colorduino
#define BOARD 'r'

#if BOARD == 'c'
#include <Colorduino.h>
#else
#include <Rainbowduino.h>
#endif

//Arduino particle system library files
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
    pMatrix.fade();
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
  Emitter_Fountain::maxLife = 90;
  Particle_Std::ay = 1;
  PartMatrix::isOverflow = true;
 
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
    //update max particle life in proportion to the audio volume level
    //this has the effect of making the flame higher in proportion to the audio
    Emitter_Fountain::maxLife = min(getSample(), 85);
    //delay(20);
}

/*
 * Sample the volume level
 */
int getSample(){
    int minimum = 1024;
    int maximum = 0;
    for(int i=0;i<50;i++)
    {
        int value = analogRead(A5); 
        minimum = min(minimum, value);
        maximum = max(maximum, value);
    }
    return (maximum-minimum);
}
