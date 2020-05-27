#include "PiezaPeruana.h"

#include "glut.h"

PiezaPeruana::PiezaPeruana(int col) {
	radio = 1;
	if (col==1) setColor(250, 200, 150);
	if (col == 2) setColor(0, 100, 100);
}

PiezaPeruana::~PiezaPeruana() {

}

void PiezaPeruana::dibuja()
{
	color.ponColor();
	glTranslatef( x,0, y);
	forma.Cilindro(1, .5),
	glTranslatef(-x,0, -y);
}

