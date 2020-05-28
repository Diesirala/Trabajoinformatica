#include "gltools.h"
#include "boardgl.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <glut.h>
#include "ETSIDI.h"
#include "Formas3D.h"
#define DEG2RAD M_PI/180.0			//not used





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
		pieza.dibuja(1);
		glTranslatef(-glx,-gly,0);
		glEnable(GL_LIGHTING);

		break;

	case Object::QUEEN_BLACK:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		glTranslatef(glx, gly, 0);
		pieza.dibuja(2);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);

		break;

	case Object::QUEEN_GREENR:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::RED);//color de las esferas solidas
		glTranslatef(glx, gly, 0);
		pieza.dibuja(3);//dibujamos la reina
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);

		break;

	case Object::QUEEN_BLACKR:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::GREY);
		glTranslatef(glx, gly, 0);
		pieza.dibuja(4);//dibujamos la reina
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
	if (tipoPieza == ESPAN) {
		GLTools::BackgroundColor(gltools::WHITE);
	}
	else if (pieza.getTipo() == PERUANA) {
		GLTools::BackgroundColor(gltools::GREEN);
	}
	else if (pieza.getTipo() == RUSA) {
		GLTools::BackgroundColor(gltools::BLUE);
	}
	else if (pieza.getTipo() == INGLESA) {
		GLTools::BackgroundColor(gltools::RED);
	}
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
	if (tipoPieza == ESPAN) {
		GLTools::BackgroundColor(gltools::WHITE);
	}
	else if (tipoPieza == PERUANA) {
		GLTools::BackgroundColor(gltools::GREEN);
	}
	else if (tipoPieza == RUSA) {
		GLTools::BackgroundColor(gltools::BLUE);
	}
	else if (tipoPieza == INGLESA) {
		GLTools::BackgroundColor(gltools::RED);
	}
	

}