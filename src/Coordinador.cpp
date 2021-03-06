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
			estado = INSTRUCCIONES;
			break;

		case '2':
			ETSIDI::play("sonidos/campana.wav");
			variante = ESPAN;
			estado = INSTRUCCIONES;//espa�olas
			break;


		case'3':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas inglesas
			variante = CHECKERS;
			estado = INSTRUCCIONES;
			break;

		case'4':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas peruana
			variante = PERUANA;
			estado = INSTRUCCIONES;
			break;

		case'5':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas rusas
			variante = RUSA;
			estado = INSTRUCCIONES;
			break;

		case'6':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas turca
			variante = TURCA;
			estado = INSTRUCCIONES;
			break;

		case'7':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas italiana
			variante = ITALIANA;
			estado = INSTRUCCIONES;
			break;
		case '8':
			ETSIDI::play("sonidos/campana.wav");
			//tablero damas italiana
			variante = CANADIENSE;
			dimensiones = 12;
			estado = INSTRUCCIONES;
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
			ETSIDI::play("sonidos/campana.wav");
			estado = INICIO;
			tablero = 0;
			delete  scene;
			delete a;
		}
				break;

				break;
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

	else if (estado == INSTRUCCIONES) {

	
		if (key == 'c') {
			ETSIDI::play("sonidos/campana.wav");	
			if (variante == INTERNACIONAL)estado = TABLERO;
			else estado = MODO;
		}
		else if (key == 'e') {
			estado = VARIANTES;
			ETSIDI::play("sonidos/campana.wav");
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
		Imagen("imagenes/tablero1.png"); //cargador de im�genes en pantalla

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

		Imagen("imagenes/tablero1.png"); //cargador de im�genes en pantalla

		ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
		ETSIDI::setFont("fuentes/4.ttf", 50);
		ETSIDI::printxy("|VARIANTES|", -6, 11);
		ETSIDI::setTextColor(0.95, 0.95, 0.95);
		ETSIDI::setFont("fuentes/bitwise.ttf", 18);
		ETSIDI::printxy("Pulse la tecla -1- INTERNACIONALES", -5, 9);
		ETSIDI::printxy("Pulse la tecla -2- ESPANOLAS", -5, 8);
		ETSIDI::printxy("Pulse la tecla -3- CHECKERS", -5, 7);
		ETSIDI::printxy("Pulse la tecla -4- PERUANAS", -5, 6);
		ETSIDI::printxy("Pulse la tecla -5- RUSAS", -5, 5);
		ETSIDI::printxy("Pulse la tecla -6- TURCAS", -5, 4);
		ETSIDI::printxy("Pulse la tecla -7- ITALIANAS", -5, 3);
		ETSIDI::printxy("Pulse la tecla -8- CANADIENSES", -5, 2);
	}
	else if (estado == MODO) {

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Imagen("imagenes/tablero1.png"); //cargador de im�genes en pantalla
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
		Imagen("imagenes/tablero1.png"); //cargador de im�genes en pantalla
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
		crearTablero();
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
		

	}

	else if (estado == DERROTAB)
	{
	ETSIDI::play("sonidos/GAMEOVER.wav");
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
	ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -6, 4);
	}

	else if (estado == VICTORIAB)
	{
	ETSIDI::play("sonidos/win.wav");
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
	ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -6, 4);
		
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
	ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -6, 5);
	}


	else if (estado == INSTRUCCIONES)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		gluLookAt(0, 7.5, 20, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
			//Fondo pantala inicig

		Imagen("imagenes/tablero1.png"); //cargador de im�genes en pantalla
		if (variante == ITALIANA) {
			ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
			ETSIDI::setFont("fuentes/4.ttf", 50);
			ETSIDI::printxy("INSTRUCCIONES", -6, 11);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("1- LOS PEONES NO PUEDEN CAPTURAR A LAS DAMAS NUNCA", -9, 8.5);
			ETSIDI::printxy("2  LAS DAMAS SOLO PUEDEN COMER A LAS FICHAS ENEMIGAS  ", -9, 7.5);
			ETSIDI::printxy("CONTIGUAS TANTO ADELANTE COMO HACIA ATRAS", -8, 6.5);
			ETSIDI::printxy("3  SI EL JUGADOR NO PUEDE MOVER NI COMER PIERDE  ", -9, 5.5);
			ETSIDI::printxy("4  EMPIEZAN LAS DORADAS", -9, 4.5);
			ETSIDI::printxy("5  LOS PEONES SOLO PUEDEN COMER HACIA DELANTE", -9, 3.5);
			ETSIDI::printxy("6  SE PUEDE REALIZAR SOPLIDO ", -9, 2.5);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
			ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -8, 1.5);
			ETSIDI::printxy("Pulse tecla -E- PARA CAMBIAR DE JUEGO", -1, 1.5);
		}
		else if (variante == CHECKERS) {
			ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
			ETSIDI::setFont("fuentes/4.ttf", 50);
			ETSIDI::printxy("INSTRUCCIONES", -6, 11);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("1- LAS DAMAS SOLO SE PUEDEN MOVER UNA CASILLA HACIA ", -9, 9.5);
			ETSIDI::printxy("DELANTE Y HACIA ATRAS", -8, 8.5);
			ETSIDI::printxy("2  LAS DAMAS SOLO PUEDEN COMER A LAS FICHAS ENEMIGAS  ", -9, 7.5);
			ETSIDI::printxy("CONTIGUAS TANTO ADELANTE COMO HACIA ATRAS", -8, 6.5);
			ETSIDI::printxy("3  SI EL JUGADOR NO PUEDE MOVER NI COMER PIERDE -AHOGADO-  ", -9, 5.5);
			ETSIDI::printxy("4  EMPIEZAN LAS ROJAS", -9, 4.5);
			ETSIDI::printxy("5  LOS PEONES SOLO PUEDEN COMER HACIA DELANTE", -9, 3.5);
			ETSIDI::printxy("6  SE PUEDE REALIZAR SOPLIDO ", -9, 2.5);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
			ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -8, 1.5);
			ETSIDI::printxy("Pulse tecla -E- PARA CAMBIAR DE JUEGO", -1, 1.5);

		}
		else if (variante == PERUANA) {
			ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
			ETSIDI::setFont("fuentes/4.ttf", 50);
			ETSIDI::printxy("INSTRUCCIONES", -6, 11);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("1- PIERDE QUIEN SE QUEDA SIN FICHAS EN EL TABLERO", -9, 8.5);
			ETSIDI::printxy("2  LAS DAMAS SOLO PUEDEN COMER A LAS FICHAS ENEMIGAS  ", -9, 7.5);
			ETSIDI::printxy("CONTIGUAS TANTO ADELANTE COMO HACIA ATRAS", -8, 6.5);
			ETSIDI::printxy("3  SI EL JUGADOR NO PUEDE MOVER NI COMER PIERDE  ", -9, 5.5);
			ETSIDI::printxy("4  EMPIEZAN LAS AZULES", -9, 4.5);
			ETSIDI::printxy("5  LA FICHA QUE CAPTURA OCUPA EL LUGAR DE LA FICHA CAPTURADA", -9, 3.5);
			ETSIDI::printxy("6  SE PUEDE REALIZAR SOPLIDO ", -9, 2.5);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
			ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -8, 1.5);
			ETSIDI::printxy("Pulse tecla -E- PARA CAMBIAR DE JUEGO", -1, 1.5);
		}
		else if (variante == RUSA) {
			ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
			ETSIDI::setFont("fuentes/4.ttf", 50);
			ETSIDI::printxy("INSTRUCCIONES", -6, 11);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("1- LAS DAMAS SOLO SE PUEDEN MOVER UNA CASILLA HACIA ", -9, 10);
			ETSIDI::printxy("DELANTE Y HACIA ATRAS", -8, 9);
			ETSIDI::printxy("2  LAS DAMAS SOLO PUEDEN COMER A LAS FICHAS ENEMIGAS", -9, 8);
			ETSIDI::printxy("CONTIGUAS TANTO ADELANTE COMO HACIA ATRAS", -8, 7);
			ETSIDI::printxy("3  SI EL JUGADOR NO PUEDE MOVER NI COMER PIERDE  ", -9, 6);
			ETSIDI::printxy("4  EMPIEZAN LAS BLANCAS", -9, 5);
			ETSIDI::printxy("5  LOS PEONES SOLO PUEDEN COMER HACIA DELANTE", -9, 4);
			ETSIDI::printxy("6  AL SER DAMA UN PEON NO PIERDE SU TURNO", -9, 3);
			ETSIDI::printxy("7  SE PUEDE REALIZAR SOPLIDO ", -9, 2);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
			ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -8, 1);
			ETSIDI::printxy("Pulse tecla -E- PARA CAMBIAR DE JUEGO", -1, 1);
		}
		else if (variante == ESPAN) {
			ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
			ETSIDI::setFont("fuentes/4.ttf", 50);
			ETSIDI::printxy("INSTRUCCIONES", -6, 11);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("1- EL JUEGO SE DESARROLLA SOBRE LAS CASILLAS BLANCAS ", -9, 9.5);
			ETSIDI::printxy("2  LOS PEONES SOLO PUEDEN COMER HACIA DELANTE", -9, 8.5);
			ETSIDI::printxy("3  LAS DAMAS CAPTURAN Y SE DESPLAZAN EN DIAGONAL ", -9, 7.5);
			ETSIDI::printxy(" TANTO ADELANTE COMO ATRAS CUALQUIER NUMERO DE CASILLAS", -9, 6.5);
			ETSIDI::printxy("4  SI EL JUGADOR NO PUEDE MOVER ES TABLAS  ", -9, 5.5);
			ETSIDI::printxy("5  EMPIEZAN LAS BLANCAS", -9, 4.5);
			ETSIDI::printxy("6  LOS PEONES SOLO PUEDEN COMER HACIA DELANTE", -9, 3.5);
			ETSIDI::printxy("7  SE PUEDE REALIZAR SOPLIDO ", -9, 2.5);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
			ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -8, 1.5);
			ETSIDI::printxy("Pulse tecla -E- PARA CAMBIAR DE JUEGO", -1, 1.5);
		}
		else if (variante == TURCA) {
			ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
			ETSIDI::setFont("fuentes/4.ttf", 50);
			ETSIDI::printxy("INSTRUCCIONES", -6, 11);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("1- CAPTURAN Y SE DESPLAZAN EN LINEA RECTA HACIA ", -9, 9.5);
			ETSIDI::printxy(" DELANTE O HACIA LOS LADOS", -8, 8.5);
			ETSIDI::printxy("2  LAS DAMAS CAPTURAN Y SE DESPLAZAN EN LINEA RECTA", -9, 7.5);
			ETSIDI::printxy(" TANTO ADELANTE COMO ATRAS TODAS LAS CASILLAS QUE QUIERAN  ", -9, 6.5);
			ETSIDI::printxy("3  SI EL JUGADOR NO PUEDE MOVER NI COMER PIERDE  ", -9, 5.5);
			ETSIDI::printxy("4  EMPIEZAN LAS BLANCAS", -9, 4.5);
			ETSIDI::printxy("5  LOS PEONES SOLO PUEDEN COMER HACIA DELANTE", -9, 3.5);
			ETSIDI::printxy("6  SE PUEDE HACER SOPLIDO ", -9, 2.5);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
			ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -8, 1.5);
			ETSIDI::printxy("Pulse tecla -E- PARA CAMBIAR DE JUEGO", -1, 1.5);
		}
		else if (variante == INTERNACIONAL) {
			ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
			ETSIDI::setFont("fuentes/4.ttf", 50);
			ETSIDI::printxy("INSTRUCCIONES", -6, 11);
			ETSIDI::setTextColor(1, 1, 1);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
			ETSIDI::printxy("1- CAPTURAN EN LINEA DIAGONAL HACIA DELANTE O", -9, 9.5);
			ETSIDI::printxy("HACIA ATR�S", -8, 8.5);
			ETSIDI::printxy("2  LAS DAMAS CAPTURAN Y SE DESPLAZAN EN DIAGONAL ", -9, 7.5);
			ETSIDI::printxy(" TANTO ADELANTE COMO ATRAS CUALQUIER NUMERO DE CASILLAS", -9, 6.5);
			ETSIDI::printxy("3  SI EL JUGADOR NO PUEDE MOVER NI COMER ES TABLAS  ", -9, 5.5);
			ETSIDI::printxy("4  EMPIEZAN LAS BLANCAS", -9, 4.5);
			ETSIDI::printxy("5  SE PUEDE HACER SOPLIDO ", -9, 3.5);
			ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
			ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -8, 1.5);
			ETSIDI::printxy("Pulse tecla -E- PARA CAMBIAR DE JUEGO", -1, 1.5);
		}
		else if (variante == CANADIENSE) {
		ETSIDI::setTextColor(0.20f, 0.75f, 0.60f);
		ETSIDI::setFont("fuentes/4.ttf", 50);
		ETSIDI::printxy("INSTRUCCIONES", -6, 11);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("1- CAPTURAN EN LINEA DIAGONAL HACIA DELANTE O", -9, 9.5);
		ETSIDI::printxy("HACIA ATR�S", -8, 8.5);
		ETSIDI::printxy("2  LAS DAMAS CAPTURAN Y SE DESPLAZAN EN DIAGONAL ", -9, 7.5);
		ETSIDI::printxy(" TANTO ADELANTE COMO ATRAS CUALQUIER NUMERO DE CASILLAS", -9, 6.5);
		ETSIDI::printxy("3  SI EL JUGADOR NO PUEDE MOVER NI COMER ES TABLAS  ", -9, 5.5);
		ETSIDI::printxy("4  EMPIEZAN LAS BLANCAS", -9, 4.5);
		ETSIDI::printxy("5  SE PUEDE HACER SOPLIDO ", -9, 3.5);
		ETSIDI::printxy("6  EL TABLERO ES DE 12X12 CASILLAS ", -9, 2.5);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 10);
		ETSIDI::printxy("Pulse tecla -C- PARA CONTINUAR", -8, 1.5);
		ETSIDI::printxy("Pulse tecla -E- PARA CAMBIAR DE JUEGO", -1, 1.5);
		}
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
}

void Coordinador::crearTablero(void)
{
	switch (variante)
	{
	case ESPAN:
		if (IA) {
			a = new BoardEspa�olasIA();
			tablero++;
		}
		else if (!IA) {
			a = new BoardEspa�olas();
			tablero++;
		}
		break;
	case PERUANA:
		if (IA) {
			a = new BoardPeruanasIA();
			tablero++;
		}
		else if (!IA) {
			a = new BoardPeruanas();
			tablero++;
		}
		break;
	case RUSA:
		if (IA) {
			a = new BoardRusasIA();
			tablero++;
		}
		else if (!IA) {
			a = new BoardRusas();
			tablero++;
		}
		break;
	case CHECKERS:
		if (IA) {
			a = new BoardCheckersIA();
			tablero++;
		}
		else if (!IA) {
			a = new BoardCheckers();
			tablero++;
		}
		break;
	case ITALIANA:
		if (IA) {
			a = new BoardItalianasIA();
			tablero++;
		}
		else if (!IA) {
			a = new BoardItalianas();
			tablero++;
		}
		break;
	case TURCA:
		if (IA) {
			a = new BoardTurcasIA();
			tablero++;
		}
		else if (!IA) {
			a = new BoardTurcas();
			tablero++;
		}
		break;
	case INTERNACIONAL:
		if (IA) {
			a = new BoardIA(dimensiones);
			tablero++;
		}
		else if (!IA) {
			a = new Board(dimensiones);
			tablero++;
		}
		break;
	case CANADIENSE:
		if (IA) {
			a = new BoardCanadienseIA();
			tablero++;
		}
		else if (!IA) {
			a = new BoardCanadiense();
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