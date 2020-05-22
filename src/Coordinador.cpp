#include "Coordinador.h"
#include "ETSIDI.h"


Coordinador::Coordinador()
{
	estado = INICIO;
}


Coordinador :: ~Coordinador(){}


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
	if (estado = INICIO)
	{
		boardgll.KeyDown(key);
	}

}
void Coordinador::Draw(){
	if (estado == INICIO) {
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Fondo pantala inicio
		
		
		
		//glEnable(GL_TEXTURE_2D);
		cargarFondo();
		
		
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("DAMAS", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		
		

	}
}
void Coordinador::DrawGrid(){}
void Coordinador::DrawCell(int i, int j){}


void Coordinador::MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey){}

 void Coordinador::cargarFondo() {
	 glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/fondo.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-9.75, -7.5, -0.1);
		glTexCoord2d(1, 1); glVertex3f(9.75, -7.5, -0.1);
		glTexCoord2d(1, 0); glVertex3f(9.75, 7.5, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-9.75, 7.5, -0.1);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		//Carteles(condicion);
		glutSwapBuffers();
		Sleep(2000);


	

}
