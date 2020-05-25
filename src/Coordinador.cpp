#include "Coordinador.h"
#include "ETSIDI.h"


Coordinador::Coordinador()
{
	estado = INICIO;
}



/*est Coordinador::estadoPartida() {

}*/


/*void Coordinador::cambiarPantallas(void) {
	//switch (estado)

		/*VARIANTES: {
	//if peruanas
	Board Logica(8);
	BoardGL(*Logica);
	}
	


}*/

void Coordinador::SpecialKeyDown(unsigned char key)
{}

void Coordinador::KeyDown(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			
			estado = VARIANTES;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == VARIANTES) {
		switch (VARIANTES)
		{
		case '1': {
			//Tablero damas españolas
			break;
		}
		case '2': {
			//tablero damas peruanas
			break;
		}
		case'3': {
			//tablero damas inglesas
			break;
		}
		case'4': {
			//tablero damas rusas
			break;
		}
			
		}

	}

}
void Coordinador::Draw(){
	if (estado == INICIO) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Fondo pantala inicio
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-10, 0, -0.1);
		glTexCoord2d(1, 1); glVertex3f(10, 0, -0.1);
		glTexCoord2d(1, 0); glVertex3f(10, 15, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-10, 15, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		
		
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/icecube.ttf",50);
		ETSIDI::printxy("DAMAS", -5, 8);
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		
	}
	else if (estado == VARIANTES)
	{
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/icecube.ttf", 50);
		ETSIDI::printxy("Elige el tipo de damas:", -5, 8);
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("1. Damas españolas", -5, 7);
		ETSIDI::printxy("2. Damas peruanas", -5, 6);
		ETSIDI::printxy("3. Damas inglesas", -5, 5);
		ETSIDI::printxy("4. Damas rusas", -5, 4);

	}
}
void Coordinador::DrawGrid(){}
void Coordinador::DrawCell(int i, int j){}
void Coordinador::MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey){}

 