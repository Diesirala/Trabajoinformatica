#include "gltools.h"
#include "boardgl.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <glut.h>
#include "ETSIDI.h"

#define DEG2RAD M_PI/180.0			//not used





void BoardGL::DrawGrid(){
//////////////////////
// Draws NxN grid of size width with the upper left hand corner
// at (0,0)

	glDisable(GL_LIGHTING);
	GLTools::Color(gltools::BLACK);// EL COLOR DE LAS LINEAS
	float dist=N*width;
	for (int i = 0;i <=N ;i++) {// se dibuja todo el tablero entero
		if(i% N==0) glLineWidth(4);// grosor cuadricula de fuera
		else glLineWidth(1);// grosor cuadricula interna
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
		GLTools::Color(gltools::GREEN);//color de las esferas solidas
		glTranslatef(glx, gly, 0);
		glutSolidSphere((width/2.0f)*0.9f, 50, 50);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);

		break;
	case Object::QUEEN_BLACK:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::BLACK);
		glTranslatef(glx, gly, 0);
		glutSolidSphere((width/2.0f)*0.9f, 50, 50);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);

		break;

	case Object::QUEEN_GREENR:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::RED);//color de las esferas solidas
		glTranslatef(glx, gly, 0);
		glutSolidSphere((width / 2.0f)*0.9f, 50, 50);
		glTranslatef(-glx, -gly, 0);
		glEnable(GL_LIGHTING);

		break;

	case Object::QUEEN_BLACKR:
		cell2center(i, j, glx, gly);
		glDisable(GL_LIGHTING);
		GLTools::Color(gltools::GREY);
		glTranslatef(glx, gly, 0);
		glutSolidSphere((width / 2.0f)*0.9f, 50, 50);
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
	GLTools::BackgroundColor(gltools::WHITE); // cambiar el color del fondo
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);	
	glLoadIdentity();
	gluLookAt(center_x,center_y,dist,center_x,center_y,center_z,0,1,0);
	glEnable(GL_LIGHTING);

	//Draws board and grid
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
	GLTools::Color(gltools::WHITE,1.0f);
	glTranslatef(center_x,center_y, center_z);
    glRectf(N*width/2.0f,N*width/2.0f, -N*width/2.0f, -N*width/2.0f);
	glTranslatef(-center_x,-center_y, -center_z);
	glEnable(GL_LIGHTING);


}

