#include "Coordinador.h"
#include "ETSIDI.h"


Coordinador::~Coordinador() {

}

void Coordinador::SpecialKeyDown(unsigned char key)
{}

void Coordinador::KeyDown(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e')
		{
			ETSIDI::play("sonidos/campana.wav");
			estado = VARIANTES;
		}
		if (key == 's')
			exit(0);
	}
	else if (estado == VARIANTES)
	{
		switch (key)
		{
		case '1':
			ETSIDI::play("sonidos/campana.wav");
			variante = INTERNACIONAL;
			estado = TABLERO;
			break;

		case '2':
			ETSIDI::play("sonidos/campana.wav");
			variante = ESPAN;
			estado = MODO;//españolas
			break;


		case'3':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas inglesas
			variante = CHECKERS;
			estado = MODO;
			break;

		case'4':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas peruana
			variante = PERUANA;
			estado = MODO;
			break;

		case'5':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas rusas
			variante = RUSA;
			estado = MODO;
			break;

		case'6':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas turca
			variante = TURCA;
			estado = JUGANDO;
			break;

		case'7':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas italiana
			variante = ITALIANA;
			estado = MODO;
			break;

		default:
			estado = VARIANTES;
			break;

		}
		
	}
	

	else if (estado == TABLERO) {
		switch (key)
		{
		case '1':
			ETSIDI::play("sonidos/campana.wav");
			dimensiones = 8;
			estado = MODO;
			break;

		case '2':
			ETSIDI::play("sonidos/campana.wav");
			dimensiones = 10;
			estado = MODO;
			break;

		default:
			ETSIDI::play("sonidos/campana.wav");
			estado = TABLERO;
			break;
		}
	}

	else if (estado == MODO) {
		switch (key)
		{
		case '1':
			ETSIDI::play("sonidos/campana.wav");
			IA = true;
			estado = JUGANDO;
			break;

		case '2':
			ETSIDI::play("sonidos/campana.wav");
			IA = false;
			estado = JUGANDO;
			break;

		default:
			estado = MODO;
			break;
		}

	}
	else if (estado == JUGANDO)
	{
		switch (key)
		{
		case 'e': {
			
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			estado = INICIO;
			tablero = 0;
			delete  scene;
			delete a;
		}
			break;
		case 'p'://Juan aqui meter pantalla de instrucciones. cuando le des a la tecla i
			estado = PAUSA;

		default:
			estado = JUGANDO;
			break;
		}

	}

	else if (estado == DERROTAB)
	{
		tablero = 0;
		delete  scene;
		delete a;

		if (key == 'c')
		{
			ETSIDI::play("sonidos/campana.wav");
			estado = INICIO;
		}
	}
	else if (estado == VICTORIAB)
	{
		tablero = 0;
		delete  scene;
		delete a;
		if (key == 'c')
		{
			ETSIDI::play("sonidos/campana.wav");
			estado = INICIO;
		}

	}
	else if (estado == TABLAS)
	{
		
		tablero = 0;
		delete  scene;
		delete a;
		if (key == 'c') 
		{
			ETSIDI::play("sonidos/campana.wav");
			estado = INICIO;
		}
	}

	

}
void Coordinador::Draw(){
	
	if (estado == INICIO) {
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 20, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Fondo pantala inicig
		//
		Imagen("imagenes/tablero1.png"); //cargador de imágenes en pantalla

		ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
		ETSIDI::setFont("fuentes/4.ttf", 50);
		ETSIDI::printxy("|DAMAS|", -4.75, 11);
		ETSIDI::setTextColor(1,1,1);
		ETSIDI::setFont("fuentes/bitwise.ttf", 18);
		ETSIDI::printxy("Pulse la tecla -E- PARA EMPEZAR", -6.5, 7);
		ETSIDI::printxy("Pulse la tecla -S- PARA SALIR", -6, 6);
		
	
	}
	else if (estado == VARIANTES)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 20, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Fondo pantala inicig

		Imagen("imagenes/tablero1.png"); //cargador de imágenes en pantalla

		ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
		ETSIDI::setFont("fuentes/4.ttf", 50);
		ETSIDI::printxy("|VARIANTES|", -6, 11);
		ETSIDI::setTextColor(0.95, 0.95, 0.95);
		ETSIDI::setFont("fuentes/bitwise.ttf", 18);
		ETSIDI::printxy("Pulse la tecla -1- INTERNACIONALES", -5, 7);
		ETSIDI::printxy("Pulse la tecla -2- ESPANOLAS", -5, 6);
		ETSIDI::printxy("Pulse la tecla -3- CHECKERS", -5, 5);
		ETSIDI::printxy("Pulse la tecla -4- PERUANAS", -5, 4);
		ETSIDI::printxy("Pulse la tecla -5- RUSAS", -5, 3);
		ETSIDI::printxy("Pulse la tecla -6- TURCAS", -5, 2);
		ETSIDI::printxy("Pulse la tecla -7- ITALIANAS", -5, 1);
	
	}
	else if (estado == MODO) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Imagen("imagenes/tablero1.png"); //cargador de imágenes en pantalla
		ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
		ETSIDI::setFont("fuentes/4.ttf", 50);
		ETSIDI::printxy("|MODO|", -3.75, 11);
		ETSIDI::setTextColor(0.95, 0.95, 0.95);
		ETSIDI::setFont("fuentes/bitwise.ttf", 18);
		ETSIDI::printxy("Pulse la tecla -1- 1 PLAYER", -5, 7);
		ETSIDI::printxy("Pulse la tecla -2- 2 PLAYERS", -5, 6);
		

	}
	else if (estado == TABLERO) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Imagen("imagenes/tablero1.png"); //cargador de imágenes en pantalla
		ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
		ETSIDI::setFont("fuentes/4.ttf", 50);
		ETSIDI::printxy("|Elige Tablero|", -6.25, 11);
		ETSIDI::setTextColor(0.95, 0.95, 0.95);
		ETSIDI::setFont("fuentes/bitwise.ttf", 18);
		ETSIDI::printxy("Pulse la tecla -1- (8x8)", -5, 7);
		ETSIDI::printxy("Pulse la tecla -2- (10x10)", -5, 6);
		
	}


	else if (estado == JUGANDO)
	{
		if (tablero == 0) 
		crearTablero(dimensiones, variante);
		if (a->estadoPartida() == DERROTAB) {
			estado = DERROTAB;
			tablero = 0;
		}
		if (a->estadoPartida() == VICTORIAB) {
			estado = VICTORIAB;
			tablero = 0;
		}
		if (a->estadoPartida() == TABLAS)
		{
			estado = TABLAS;
			tablero = 0;
		}
		switch (estado){
		case 2:
			cout << " Estado de la partida Jugando " << endl;
			break;
		case 3:
			cout << " Estado de la partida VictoriaB " << endl;
			break;
		case 4:
			cout << " Estado de la partida DerrotaB  " << endl;
			break;
		}

	}

	else if (estado == DERROTAB)
	{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 7.5, 20, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	//Fondo pantala inicig
	//draw
	Imagen("imagenes/tablero1.png");
	ETSIDI::setTextColor(0.95, 0.25, 0.25);
	ETSIDI::setFont("fuentes/3.ttf", 50);
	ETSIDI::printxy("The Player Black Win!", -7, 10);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::setTextColor(0.95, 0.95, 0.95);
	ETSIDI::printxy("Pulse techa -C- PARA CONTINUAR", -6, 4);
	}

	else if (estado == VICTORIAB)
	{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 7.5, 20, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	//Fondo pantala inicig
	//draw
	Imagen("imagenes/tablero1.png");
	ETSIDI::setTextColor(0.85, 0.85, 0);
	ETSIDI::setFont("fuentes/3.ttf", 50);
	ETSIDI::printxy("The Player White Win!", -7, 10);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::setTextColor(0.95, 0.95, 0.95);
	ETSIDI::printxy("Pulse techa -C- PARA CONTINUAR", -6, 4);
		
	}
	else if (estado == TABLAS)
	{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 7.5, 20, // posicion del ojo
		0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	//Fondo pantala inicig
	//draw
	Imagen("imagenes/tablero1.png");
	ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
	ETSIDI::setFont("fuentes/3.ttf", 50);
	ETSIDI::printxy("DRAW", -3.5, 11);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::setTextColor(0.95, 0.95, 0.95);
	ETSIDI::printxy("Pulse techa -C- PARA CONTINUAR", -6, 5);
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

void Coordinador::crearTablero(int n , tipo_juego tip)
{
	switch (tip)
	{
	case ESPAN:
		if (IA) {
			a = new BoardEspañolasIA(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		if (!IA) {
			a = new BoardEspañolas(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		break;
	case PERUANA:
		if (IA) {
			a = new BoardPeruanasIA(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		if (!IA) {
			a = new BoardPeruanas(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		break;
	case RUSA:
		if (IA) {
			a = new BoardRusasIA(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		if (!IA) {
			a = new BoardRusas(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		break;
	case CHECKERS:
		if (IA) {
			a = new BoardCheckersIA(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		if (!IA) {
			a = new BoardCheckers(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		break;
	case ITALIANA:
		if (IA) {
			a = new BoardItalianasIA(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		if (!IA) {
			a = new BoardItalianas(8, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		break;
	case TURCA:
				 a = new BoardTurcas(8, tip);
				 tablero++;
		break;
	case INTERNACIONAL:
		if (IA) {
			a = new BoardIA(n, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		if (!IA) {
			a = new Board(n, tip);
			//Board* a = new Board(8);
			tablero++;
		}
		break;
	default:
		break;
	}
	if(tablero)
	scene = new BoardGL(a);
}

void Coordinador::Imagen(const char* img) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture(img).id);
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
}