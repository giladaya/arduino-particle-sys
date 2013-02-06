/**
 * PartMatrix.cpp particle system to an RGB matrix renderer
 */

#include "PartMatrix.h"

boolean PartMatrix::isOverflow = true;

PartMatrix::PartMatrix(){  
}

void PartMatrix::render(Particle particles[], byte numParticles){
    byte row, col, dx, dy;
    unsigned long tempVal;
    ColorHSV colorHSV;
    ColorRGB baseRGB;
    
    //go over particles and update matrix cells on the way
    for(int i = 0; i<numParticles; i++){
        if (! particles[i].isAlive){
            continue;
        }
        //generate RGB values for particle
        colorHSV.h = particles[i].hue;
        colorHSV.s = 255;
        colorHSV.v = 255;
        HSVtoRGB(&baseRGB, &colorHSV);
        
        dx = pWidth - (particles[i].x % pWidth);
        dy = pWidth - (particles[i].y % pWidth);

        //bottom left
        col = particles[i].x / pWidth;
        row = particles[i].y / pWidth;
        tempVal = ((unsigned long)dx*dy*particles[i].ttl)>>10; //divide by pSurface == 1024
        addColor(col, row, &baseRGB, tempVal);

        //bottom right;
        col++;
        if (col < resX){
            tempVal = ((unsigned long)(pWidth-dx)*dy*particles[i].ttl)>>10; //divide by pSurface == 1024
            addColor(col, row, &baseRGB, tempVal);
        }

        //top right
        row++;
        if (col < resX && row < resY){
            tempVal = ((unsigned long)(pWidth-dx)*(pWidth-dy)*particles[i].ttl)>>10; //divide by pSurface == 1024
            addColor(col, row, &baseRGB, tempVal);
        }
        
        //top left
        col--;
        if (row < resY){
            tempVal = ((unsigned long)dx*(pWidth-dy)*particles[i].ttl)>>10; //divide by pSurface == 1024
            addColor(col, row, &baseRGB, tempVal);
        }
    }
}

void PartMatrix::HSVtoRGB(ColorRGB *colorRGB, ColorHSV *colorHSV){
    float r, g, b, h, s, v; //this function works with floats between 0 and 1
    float f, p, q, t;
    int i;
    // ColorRGB *colorRGB=(ColorRGB *)vRGB;
    // ColorHSV *colorHSV=(ColorHSV *)vHSV;

    h = (float)(colorHSV->h / 256.0);
    s = (float)(colorHSV->s / 256.0);
    v = (float)(colorHSV->v / 256.0);

    //if saturation is 0, the color is a shade of grey
    if(s == 0.0) {
        b = v;
        g = b;
        r = g;
    }
    //if saturation > 0, more complex calculations are needed
    else
    {
        h *= 6.0; //to bring hue to a number between 0 and 6, better for the calculations
        i = (int)(floor(h)); //e.g. 2.7 becomes 2 and 3.01 becomes 3 or 4.9999 becomes 4
        f = h - i;//the fractional part of h

        p = (float)(v * (1.0 - s));
        q = (float)(v * (1.0 - (s * f)));
        t = (float)(v * (1.0 - (s * (1.0 - f))));

        switch(i)
        {
            case 0: r=v; g=t; b=p; break;
            case 1: r=q; g=v; b=p; break;
            case 2: r=p; g=v; b=t; break;
            case 3: r=p; g=q; b=v; break;
            case 4: r=t; g=p; b=v; break;
            case 5: r=v; g=p; b=q; break;
            default: r = g = b = 0; break;
        }
    }
    colorRGB->r = (int)(r * 255.0);
    colorRGB->g = (int)(g * 255.0);
    colorRGB->b = (int)(b * 255.0);
}

void PartMatrix::addColor(byte col, byte row, ColorRGB *colorRGB, unsigned long value){
    //ColorRGB *colorRGB=(ColorRGB *)vRGB;
    unsigned long tempVal;
    int res; //residual
    
    //RED
    if (colorRGB->r > 0){
        tempVal = matrix[col][row].r + ((value*colorRGB->r)>>8);
        matrix[col][row].r = min(tempVal, 255);
        if (isOverflow && tempVal > 255){
            res = tempVal-255;
            res = res>>2;
            matrix[col][row].g = min((matrix[col][row].g+res), 255);
            matrix[col][row].b = min((matrix[col][row].b+res), 255);
        }
    }
    
    //GREEN
    if (colorRGB->g > 0){
        tempVal = matrix[col][row].g + ((value*colorRGB->g)>>8);
        matrix[col][row].g = min(tempVal, 255);
        if (isOverflow && tempVal > 255){
            res = tempVal-255;
            res = res>>2;
            matrix[col][row].r = min((matrix[col][row].r+res), 255);
            matrix[col][row].b = min((matrix[col][row].b+res), 255);
        }
    }
    
    //BLUE
    if (colorRGB->g > 0){
        tempVal = matrix[col][row].b + ((value*colorRGB->b)>>8);
        matrix[col][row].b = min(tempVal, 255);
        if (isOverflow && tempVal > 255){
            res = tempVal-255;
            res = res>>2;
            matrix[col][row].r = min((matrix[col][row].r+res), 255);
            matrix[col][row].g = min((matrix[col][row].g+res), 255);
        }
    }
}

void PartMatrix::reset(void){
    //init all pixels to zero
    for (byte y=0;y<resY;y++) {
        for(byte x=0;x<resX;x++) {
            matrix[x][y].r = 0;
            matrix[x][y].g = 0;
            matrix[x][y].b = 0;
        }
    }
}

void PartMatrix::fade(void){
    //fade all pixels
    for (byte y=0;y<resY;y++) {
        for(byte x=0;x<resX;x++) {
            matrix[x][y].r = matrix[x][y].r>>1;
            matrix[x][y].g = matrix[x][y].g>>1;
            matrix[x][y].b = matrix[x][y].b>>1;
        }
    }
}