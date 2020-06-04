

#ifndef _GLTOOLS_H
#define _GLTOOLS_H

#ifdef WIN32
#include <windows.h> //required for GL in Windows
#include <wingdi.h>
#include <gl/gl.h>
#include <gl/glu.h> 
#else     
#include <GL/gl.h>
#include <GL/glu.h>
#endif  


#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <vector>

using namespace std;

namespace gltools{
    enum {
        WHITE, RED, GREEN,
        GREEN_DARK, BLUE,
        MAGENTA, CYAN, YELLOW,
        ORANGE, PURPLE, PINK, GREY,
        BLACK, Grey_dark, BLUE_DARK,
        RED_DARK, GRIS_AZUL, GRIS_AZUL_2, PINK_dark, WHITEP, ORANGE_dark,
        BLUE_DARK2, RED_DARK2, GREEN_DARK2, Grey_dark2,MARRON, MARRON_DARK
    };
};


class GLTools 
{
public:
//Color utilities
	static void Color(int color,float transparency=1.0f);
	static void BackgroundColor(int color);
	
//Primitives
	static void DrawGrid(int num_cells,float size);
	static void DrawGrid(int num_cells,float size, int col, float transparency=(1.0f));			
	
};

#endif