#include "ColorRGB.h"
#include "glut.h"


ColorRGB::ColorRGB(Byte _r, Byte _v, Byte _a)
{
	r=_r;
	g=_v;
	b=_a;
}
void ColorRGB::ponColor()
{
	glColor3ub(r,g,b);
}
ColorRGB::~ColorRGB()
{

}
