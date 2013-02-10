#include <Colorduino.h>
#include "Particle_Bounce.h"
#include "Emitter_Fountain.h"
#include "ParticleSys.h"
#include "PartMatrix.h"

const byte maxDim = 255;
const byte numParticles = 40;
boolean pulseOn = false;

Particle_Bounce particles[numParticles];
Particle_Bounce source;
Emitter_Fountain emitter(0, 5, 2, &source);
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
  
  source.vx = 15;
  source.vy = 3;
  source.x = 1;
  source.y = 1;
  //Particle_Std::ay = 1;
  //PartMatrix::isOverflow = false;
 
  //init all pixels to zero
  pMatrix.reset();
}

void loop()
{
    pSys.update();
    drawMatrix();
    Colorduino.FlipPage();
    delay(20);
}
