#include "gltools.h"
#include "boardgl.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <glut.h>

#define DEG2RAD M_PI/180.0			//not used

void BoardGL::init(){	
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800/600.0f, 0.1, 150);
}

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
		GLTools::Color(gltools::RED);//color de las esferas solidas
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
	case Object::EMPTY_CELL:
	default:
		;
	}
}

void BoardGL::Draw(){
	
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
void BoardGL::MouseButton(int x,int y,int button,bool down, bool sKey, bool ctrlKey){
/////////////////////////
// sets state of mouse control buttons + special keys

/////////
//computes cell coordinates from mouse coordinates
	
	GLint viewport[4];
    GLdouble modelview[16];
    GLdouble projection[16];
    GLfloat winX, winY, winZ;
    GLdouble posX, posY, posZ;

    glGetDoublev( GL_MODELVIEW_MATRIX, modelview );
    glGetDoublev( GL_PROJECTION_MATRIX, projection );
    glGetIntegerv( GL_VIEWPORT, viewport );

    winX = (float)x;
    winY = (float)viewport[3] - (float)y;
    glReadPixels( x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ );
	gluUnProject( winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);      
   
	//finally cell coordinates
	world2cell(posX,posY,xcell_sel, ycell_sel);					
		
///////////////////////////	
//capture other mouse events

	if(down){	
		controlKey=ctrlKey;
		shiftKey=sKey;
	}else{
		controlKey=shiftKey=false;
	}
			
	if(button==MOUSE_LEFT_BUTTON)
		leftButton=down;
	else if(button==MOUSE_RIGHT_BUTTON)
		rightButton=down;
	else if(button==MOUSE_MIDDLE_BUTTON)
		midButton=down;
///////////////////////////
	
	//***WRITE ACTIONS CONNECTED TO MOUSE STATE HERE

	//print cell coordinates after click
	if (down)
	{
		cout << "(" << xcell_sel << "," << ycell_sel << ")" << endl;// estas dos variables son las coordenadas de cada casilla
		cout << "(" << posX << "," << posY << ")" << endl;// con esto coges todas las posiciones que pertenecen a la misma casilla
	}
	
}

void BoardGL::KeyDown(unsigned char key){
//////////////////
// enlarges or reduces grid by one

	//if(key=='s'){// para poder redibujar algo 
		//** do something
		//if(N<=8) N++;
	//}

	//if(key=='a'){
		//** do something
		//if (N >= 2)
		//{
			
			//setSize(N-=1);// o N--
		//};
	//}
}

