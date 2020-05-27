#include "PiezaEspañola.h"
#include "glut.h"

PiezaEspañola::PiezaEspañola(int col) {
	radio = 1;
	if (col == 1) setColor(100, 0, 150);
	if (col == 2) setColor(200, 50, 100);
}

PiezaEspañola::~PiezaEspañola() {

}

void PiezaEspañola::dibuja()
{
	color.ponColor();
	glTranslatef(x,0, y);
	forma.Cilindro(1,.5),
	glTranslatef(-x,0, -y);
}

