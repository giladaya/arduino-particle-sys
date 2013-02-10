#include <Colorduino.h>
#include "ParticleSys.h"
#include "Particle_Std.h"
#include "Emitter_Fire.h"
#include "PartMatrix.h"

const byte numParticles = 90;

Particle_Std particles[numParticles];
Emitter_Fire emitterE;
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
#ifdef DEBUG
    // start serial port at 9600 bps:
    Serial.begin(9600);
    Serial.print("start. width:");
    Serial.println(pWidth);
#endif

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