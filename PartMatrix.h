/**
 * PartMatrix.h particle system to an RGB matrix renderer
 */

#ifndef part_matrix_h
#define part_matrix_h

#include "PsConstants.h"
#include "Particle_Abstract.h"

//#include "Arduino.h"

typedef struct {
    byte r;
    byte g;
    byte b;
} ColorRGB;

//a color with 3 components: h, s and v
typedef struct {
    byte h;
    byte s;
    byte v;
} ColorHSV;

class PartMatrix {
public:
    static boolean isOverflow;
    ColorRGB matrix[PS_PIXELS_X][PS_PIXELS_Y];

    PartMatrix();
    void render(Particle_Abstract particles[], byte numParticles);
    void reset(void);
    void fade(void);
    static void HSVtoRGB(ColorRGB *colorRGB, ColorHSV *colorHSV);

private:
    void addColor(byte col, byte row, ColorRGB *rgb, unsigned long value);
};

#endif /* part_matrix_h */