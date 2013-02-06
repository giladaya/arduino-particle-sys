/**
 * PartMatrix.h particle system to an RGB matrix renderer
 */

#ifndef part_matrix_h
#define part_matrix_h

#include "Particle.h"

//#include "Arduino.h"

typedef struct
{
    byte r;
    byte g;
    byte b;
} ColorRGB;

//a color with 3 components: h, s and v
typedef struct 
{
    byte h;
    byte s;
    byte v;
} ColorHSV;

class PartMatrix
{
    public:
        static const byte resX = 8;
        static const byte resY = 8;
        static const byte pWidth = 32;
        static const byte pSurface = 1024;
        static boolean isOverflow;
        ColorRGB matrix[resX][resY];

        PartMatrix();
        void render(Particle particles[], byte numParticles);
        void reset(void);
        void fade(void);
        static void HSVtoRGB(ColorRGB *colorRGB, ColorHSV *colorHSV);

    private:
        void addColor(byte col, byte row, ColorRGB *rgb, unsigned long value);
};

#endif /* part_matrix_h */