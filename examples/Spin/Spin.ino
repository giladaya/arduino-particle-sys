#include <Colorduino.h>
#include "ParticleSys.h"
#include "Particle_Bounce.h"
#include "Emitter_Spin.h"
#include "PartMatrix.h"

const byte numParticles = 40;

Particle_Bounce particles[numParticles];
Emitter_Spin emitter(112, 112, 4, 5);
ParticleSys pSys(numParticles, particles, &emitter);
PartMatrix pMatrix;

/**
 * Render the particles into a low-resolution matrix
 */
void drawMatrix(){
    pMatrix.fade();
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
  
  pMatrix.reset();
 
  Colorduino.FlipPage(); // swap screen buffers to show it
}

void loop()
{
    pSys.update();
    drawMatrix();
    Colorduino.FlipPage();
    delay(20);
}