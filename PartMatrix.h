/* 
 * Copyright (C) 2013 Gilad Dayagi.  All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 */

/**
 * PartMatrix.h renders a particle system to an RGB matrix
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
    void reset(void);    //set each pixel to 0
    void fade(void);     //devide each pixel by half
    void fadeBy(byte amount); //substract amount from each pixel 
    static void HSVtoRGB(ColorRGB *colorRGB, ColorHSV *colorHSV);

private:
    void addColor(byte col, byte row, ColorRGB *rgb, unsigned long value);
};

#endif /* part_matrix_h */