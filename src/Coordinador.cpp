#include "Coordinador.h"
#include "ETSIDI.h"



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
	else if (estado == VARIANTES)
	{
		switch (key)
		{
		case '1': {
			
			////Tablero damas españolas
			////iniciliza mundo con tablelo y lista de piezas
			mundo.inicializa(1);
			estado = JUGANDO;
			
			break;
		}
		case '2': {
			//tablero damas peruanas
			//a = new Peruanas();
			mundo.inicializa(2);
			estado = JUGANDO;

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
		//estado = JUGANDO;
		
		
	}
	else if (estado == JUGANDO)
	{ 
		//estado = JUGANDO;


	}
	else if (estado == DERROTAB)
	{
	}
	else if (estado == VICTORIAB)
	{

	}

	

}
void Coordinador::Draw(){
	
	if (estado == INICIO ) {
		//init();
		//glClearColor(1, 1, 1, 1);// blanco del fondo
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 20, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Fondo pantala inicig
		
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero1.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-20, 0, -0.1);
		glTexCoord2d(1, 1); glVertex3f(20, 0, -0.1);
		glTexCoord2d(1, 0); glVertex3f(20, 20, -0.1);
		glTexCoord2d(0, 0); glVertex3f(-20, 20, -0.1);
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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/icecube.ttf", 50);
		ETSIDI::printxy("Elige el tipo de damas:", -5, 9);
		ETSIDI::setTextColor(0, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("1. Damas españolas", -5, 7);
		ETSIDI::printxy("2. Damas peruanas", -5, 5);
		ETSIDI::printxy("3. Damas inglesas", -5, 3);
		ETSIDI::printxy("4. Damas rusas", -5, 1);


	}else if (estado == JUGANDO)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		mundo.dibuja();
	}
	else if (estado == DERROTAB)
	{
		//mundo.draw
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/icecube.ttf", 50);
		ETSIDI::printxy("GAMEOVER: Has perdido.", -5, 10);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5, 8);
		

	}
	else if (estado == VICTORIAB)
	{
		//draw
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/icecube.ttf", 50);
		ETSIDI::printxy("ENHORABUENA: ¡Has ganado!.", -5, 10);
		ETSIDI::printxy("PULSE LA TECLA -C- PARA CONTINUAR", -5, 8);
	}
	
}
void Coordinador::init() {
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
}

void Coordinador::MouseButton(int x, int y, int button, bool down, bool sKey, bool ctrlKey) {
	/////////////////////////
	// sets state of mouse control buttons + special keys

	/////////
	//computes cell coordinates from mouse coordinates

	GLint viewport[4];
	GLdouble modelview[16];
	GLdouble projection[16];
	GLfloat winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
	glGetDoublev(GL_PROJECTION_MATRIX, projection);
	glGetIntegerv(GL_VIEWPORT, viewport);

	winX = (float)x;
	winY = (float)viewport[3] - (float)y;
	glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
	gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	//finally cell coordinates
	world2cell(posX, posY, xcell_sel, ycell_sel);

	///////////////////////////	
	//capture other mouse events

	if (down) {
		controlKey = ctrlKey;
		shiftKey = sKey;
	}
	else {
		controlKey = shiftKey = false;
	}

	if (button == MOUSE_LEFT_BUTTON)
		leftButton = down;
	else if (button == MOUSE_RIGHT_BUTTON)
		rightButton = down;
	else if (button == MOUSE_MIDDLE_BUTTON)
		midButton = down;
	///////////////////////////

		//***WRITE ACTIONS CONNECTED TO MOUSE STATE HERE

		//print cell coordinates after click
	if (down)
	{
		cout << "(" << xcell_sel << "," << ycell_sel << ")" << endl;// estas dos variables son las coordenadas de cada casilla
		cout << "(" << posX << "," << posY << ")" << endl;// con esto coges todas las posiciones que pertenecen a la misma casilla
	}

}
void Coordinador::crearTablero(void)
{
	if (tablero == 0) {
		a = new Board(8);
		//Board* a = new Board(8);
		scene = new BoardGL(a);
		tablero++;
	}
}

