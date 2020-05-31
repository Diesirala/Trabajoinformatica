#include "gltools.h"
#include "boardgl.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <glut.h>
#include "ETSIDI.h"
#include "Formas3D.h"
#include "Enumeraciones.h"
#define DEG2RAD M_PI/180.0			//not used


enum {
	WHITE, RED, GREEN,
	GREEN_DARK, BLUE,
	MAGENTA, CYAN, YELLOW,
	ORANGE, PURPLE, PINK, GREY,
	BLACK, Grey_dark, BLUE_DARK, RED_DARK,
	GRIS_AZUL, GRIS_AZUL_2, PINK_dark,
	WHITEP, ORANGE_Dark,BLUE_DARK2,
	RED_DARK2, GREEN_DARK2, Grey_dark2
};



void BoardGL::DrawGrid(){
	
//////////////////////
// Draws NxN grid of size width with the upper left hand corner
// at (0,0)

	glDisable(GL_LIGHTING);
	GLTools::Color(gltools::BLACK);// EL COLOR DE LAS LINEAS
	float dist=N*width;
	for (int i = 0;i <=N ;i++) {// se dibuja todo el tablero entero
		if (i % N == 0) {
			glLineWidth(4);
		}// grosor cuadricula de fuera
		else {
			glLineWidth(3);
		}// grosor cuadricula interna
		glBegin(GL_LINES); 	
			glVertex3f(i*width,0,0);	
			glVertex3f(i*width,-dist,0);
			glVertex3f(0,-i*width,0);
			glVertex3f(dist, -i*width,0);	
		glEnd();
	}
	glEnable(GL_LIGHTING);
	
}



void BoardGL::DrawCell(int i,int j){
////////////////////
// Draws contents of cell	
// Note:(0, 0) screen coordinates is the upper left hand corner of the board
//
// INPUT: (i, j) are cell coordinates, (0,0) is the upper left hand square of the board// 

	float glx, gly;
	switch(m_board->getTab()[i][j].getType()){
	case Object::QUEEN_GREEN:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glTranslatef(glx,gly,0);
		dibuja(1);
		glTranslatef(-glx,-gly,0);
		glEnable(GL_LIGHTING);

		break;

	case Object::QUEEN_BLACK:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glTranslatef(glx, gly, 0);
		dibuja(2);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);

		break;

	case Object::QUEEN_GREENR:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::RED);//color de las esferas solidas
		glTranslatef(glx, gly, 0);
		dibuja(3);//dibujamos la reina
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);

		break;

	case Object::QUEEN_BLACKR:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::GREY);
		glTranslatef(glx, gly, 0);
		dibuja(4);//dibujamos la reina
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);

		break;

	case Object::EMPTY_CELL:
	default:
		;
	}
}

void BoardGL::Draw(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	center_x=N*width/2;
	center_y=-N*width/2;
	center_z=0;

	//Borrado de la pantalla	
	//glClearColor(1,1,1,1);// blanco del fondo
	//GLTools::BackgroundColor(gltools::WHITE); // cambiar el color del fondo
	setFondo();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	
	//Para definir el punto de vista
	setOjo(m_board->getSize());
	glEnable(GL_LIGHTING);
	//setFondo(pieza.getTipo());
	//Draws board and grid
	//GLTools::Color(gltools::WHITE, 1.0f);
	DrawGrid();
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			DrawCell(i, j);
		}
	}
		
	//Draw a transparent rectangle over the board to capture mouse input
	//with gluUnProject
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND); 
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 
	glTranslatef(center_x,center_y, center_z);
    glRectf(N*width/2.0f,N*width/2.0f, -N*width/2.0f, -N*width/2.0f);
	glTranslatef(-center_x,-center_y, -center_z);
	glEnable(GL_LIGHTING);
}

void BoardGL::setOjo(int m) {// se encarga de camviar la vista según dimension del tablero
	if (m == 8) {
		gluLookAt(0.57, -2, -1.2, // posicion del ojo
		0.57, 0.2, 1, // hacia que punto mira (0,7.5,0)
		0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	}
	if (m == 10) {
		gluLookAt(0.75, -2.3, -1.5, // posicion del ojo
			0.75, 0.2, 1, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
	}
}

void BoardGL::setFondo() {
	if (variante == ESPAN) {
		GLTools::BackgroundColor(gltools::WHITE);
	}
	else if (variante == PERUANA) {
		GLTools::BackgroundColor(gltools::GREEN);
	}
	else if (variante == RUSA) {
		GLTools::BackgroundColor(gltools::BLUE);
	}
	else if (variante == INGLESA) {
		GLTools::BackgroundColor(gltools::RED);
	}
	

}
void BoardGL::dibuja(int n) {
	if (n == 1) {
		if (variante == ESPAN) {
			Formas3D::Cilindro(0.06, 0.05,WHITEP,GREY);
			GLTools::Color(gltools::WHITE, 1.0f);//Cambiamos el color del tablero
		}
	
		else if (variante == PERUANA) {
			Formas3D::Cilindro(0.06, 0.05,BLUE,BLUE_DARK);
			GLTools::Color(gltools::WHITE, 1.0f);
		}
		else if (variante == INGLESA) {
			Formas3D::Cilindro(0.06, 0.05, RED,RED_DARK);
			GLTools::Color(gltools::WHITE, 1.0f);//Cambiamos el color del tablero
		}
		else if (variante == RUSA) {
			Formas3D::Cilindro(0.06, 0.05,GRIS_AZUL,GRIS_AZUL_2 );
			GLTools::Color(gltools::WHITE, 1.0f);//Cambiamos el color del tablero
		}
	}
	else if (n == 2) {
		Formas3D::Cilindro(0.06, 0.05,Grey_dark, BLACK);
		GLTools::Color(gltools::WHITE, 1.0f);
	}

	else if (n==3) {
		if (variante == ESPAN) {
			Formas3D::Reina(WHITE,WHITEP,GREY);
			GLTools::Color(gltools::WHITE, 1.0f);
		}
		else if (variante == PERUANA) {
			Formas3D::Reina(BLUE, BLUE_DARK, BLUE_DARK2);
			GLTools::Color(gltools::WHITE, 1.0f);
		}
		else if (variante == INGLESA) {
			Formas3D::Reina(RED,RED_DARK,RED_DARK2);
			GLTools::Color(gltools::WHITE, 1.0f);
		}
		else if (variante == RUSA) {
			Formas3D::Reina(GREEN, GREEN_DARK,GREEN_DARK2);
			GLTools::Color(gltools::WHITE, 1.0f);
		}
	} // caso reina JUGADOR

	else if (n == 4) {
		Formas3D::Reina(YELLOW, ORANGE, ORANGE_Dark);//Reina negra
		GLTools::Color(gltools::WHITE, 1.0f);
	}
}