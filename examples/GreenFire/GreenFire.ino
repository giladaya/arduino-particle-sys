#include <Colorduino.h>
#include "StdParticle.h"
#include "FireEmitter.h"
#include "ParticleSys.h"
#include "PartMatrix.h"

//#define DEBUG 1
const byte maxDim = 255;
const byte numParticles = 90;
boolean pulseOn = false;

StdParticle particles[numParticles];
FireEmitter emitter(maxDim);
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

    StdParticle::ay = 1;
    FireEmitter::baseHue = 75;  //green
    //FireEmitter::baseHue = 156; //blue
    FireEmitter::maxTtl = 96;
    PartMatrix::isOverflow = false;

    //init all pixels to zero
    pMatrix.reset();

    Colorduino.FlipPage(); // swap screen buffers to show it
}

void loop()
{
    pSys.update();
    drawMatrix();

    Colorduino.FlipPage();
    delay(15);
}