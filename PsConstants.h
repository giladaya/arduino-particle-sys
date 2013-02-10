//some constants
//matrix pixels
#ifndef PS_PIXELS_X
#define PS_PIXELS_X 8
#endif

#ifndef PS_PIXELS_Y
#define PS_PIXELS_Y 8
#endif

//particle dimensions
#ifndef PS_P_RADIUS
#define PS_P_RADIUS 32
#endif

#ifndef PS_P_SURFACE
#define PS_P_SURFACE PS_P_RADIUS*PS_P_RADIUS
#endif

//box dimensions
#ifndef PS_MAX_X
#define PS_MAX_X PS_PIXELS_X*PS_P_RADIUS-1
#endif

#ifndef PS_MAX_Y
#define PS_MAX_Y PS_PIXELS_Y*PS_P_RADIUS-1
#endif
