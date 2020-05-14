//game.cpp: entry point for a general outline of baordgame using glut and OpenGL
//			configures basic glut parameters and defines a scene wrapper for all 
//			call backs
//author:pss
//date of creation: 9/5/16

#include <iostream>
#include "boardgl.h"
#include "glut.h"

//#define GRID_SIZE	8		//NxN grid

/////////////////////////////////
//call back declarations: will be called by glut when registered
void OnDraw(void); 
void OnKeyboardDown(unsigned char key, int x, int y); 
void OnMouseClick(int button,int state, int x,int y);
void OnTimer(int value); 

////////////////////////////////////////////////
//global objects which make the world
Board gameboard(8);
BoardGL scene(&gameboard);

///////////////////////////////////////////////

int main(int argc,char* argv[]){
	//GL Initialization stuff
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Damas");

	
	//Register callbacks
	glutDisplayFunc(OnDraw);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);
	//glutTimerFunc(25,OnTimer,0);			 //set timer if required, currently not used

	//sets light and perspective
	scene.init();
	
	//glut takes control
	glutMainLoop();	

	return 0;   
}

void OnDraw(void){
//////////////////////
//captures drawing event
//gives control to scene
	scene.Draw();
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t){
//////////////////////
//captures keyboard event
//gives control to scene
	scene.KeyDown(key);
	glutPostRedisplay();
}

void OnMouseClick(int b,int state, int x,int y){
//////////////
//captures clicks with mouse with or without special keys (CTRL or SHIFT)// CAPTURA LOS MOVIMIENTOS TANTO SI USAS LAS TECLAS SHIFT Y CONTROL COMO SIN ELLAS
//gives control to board scene
	bool down=(state==GLUT_DOWN);
	int button;
	if(b==GLUT_LEFT_BUTTON){
		button=MOUSE_LEFT_BUTTON;
	}
	if(b==GLUT_RIGHT_BUTTON){
		button=MOUSE_RIGHT_BUTTON;
		cout<<"MOUSE_RIGHT_BUTTON"<<endl;
	}
	if (b == GLUT_MIDDLE_BUTTON) {
		button = MOUSE_MIDDLE_BUTTON;
		cout << "MOUSE_MIDDLE_BUTTON" << endl;
	}
		
	int specialKey = glutGetModifiers();
	bool ctrlKey= (specialKey & GLUT_ACTIVE_CTRL)? true:false ;
	bool sKey= specialKey & GLUT_ACTIVE_SHIFT ;

		
	scene.MouseButton(x,y,b,down,sKey,ctrlKey);
	glutPostRedisplay();
}


/*void OnTimer(int value){
	//****WRITE TIMER CODE HERE

	//sets new timer (do not delete)
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}*/
