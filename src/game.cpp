//game.cpp: entry point for a general outline of baordgame using glut and OpenGL
//			configures basic glut parameters and defines a scene wrapper for all 
//			call backs
//author:pss
//date of creation: 9/5/16

#include <iostream>
#include "boardgl.h"
#include"Coordinador.h"
#include "glut.h"

//#define GRID_SIZE	8		//NxN grid

Coordinador escena;

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
	//CASO CON TURNOS 
	/*gameboard.cambiarPosicion(5, 2, 4, 3);
	
	gameboard.cambiarPosicion(2, 5, 3, 4);
	gameboard.comer(4, 3, 2, 5);
	gameboard.pasoTurno();
	gameboard.cambiarPosicion(2 ,1, 3, 0);*/



	//gameboard.cambiarPosicion(2, 3, 3, 2);
	//gameboard.cambiarPosicion(3, 2, 4, 1);
	/*gameboard.cambiarPosicion(1, 2, 2, 3);
	gameboard.cambiarPosicion(2, 3, 3, 4);
	gameboard.cambiarPosicion(0, 3, 1, 2);
	gameboard.cambiarPosicion(1, 2, 2, 3);

	gameboard.comer(5, 2, 3, 0);
	gameboard.comer(3, 0, 1, 2);

	gameboard.cambiarPosicion(1, 2, 0, 3);
	gameboard.cambiarPosicion(0, 3, 3, 0);
	gameboard.cambiarPosicion(3, 0, 0, 3);

	gameboard.cambiarPosicion(5, 4, 4, 3);
	gameboard.cambiarPosicion(4, 3, 3, 2);
	gameboard.cambiarPosicion(3, 2, 2, 1);
	gameboard.cambiarPosicion(6, 5, 5, 4);
	gameboard.cambiarPosicion(5, 4, 4, 3);
	gameboard.cambiarPosicion(7, 6, 6, 5);

	gameboard.comer(1, 0, 3, 2);
	gameboard.comer(3, 2, 5, 4);
	gameboard.comer(5, 4, 7, 6);

	gameboard.cambiarPosicion(7, 6, 1, 0);
	gameboard.cambiarPosicion(1, 0, 2, 1);
	gameboard.cambiarPosicion(2, 1, 0, 3);
	gameboard.cambiarPosicion(0, 3, 3, 6);
	gameboard.cambiarPosicion(0, 3, 0, 4);


	gameboard.comer(1, 2, 3, 4);*/


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
	
	//escena.Draw();
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t){
//////////////////////
//captures keyboard event
//gives control to scene
	escena.KeyDown(key);
	glutPostRedisplay();
}

void OnMouseClick(int b,int state, int x,int y){
//////////////
//captures clicks with mouse with or without special keys (CTRL or SHIFT)// CAPTURA LOS MOVIMIENTOS TANTO SI USAS LAS TECLAS SHIFT Y CONTROL COMO SIN ELLAS
//gives control to board scene
	bool down=(state==GLUT_DOWN);
	static int xactual, yactual, posicionx, posiciony, count=0;
	 


	int button;
	if(b==GLUT_LEFT_BUTTON ){
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
	if (button == MOUSE_LEFT_BUTTON && down) {
		if (count == 0) {
			xactual = scene.xcell_sel;
			yactual = scene.ycell_sel;
			count++;
			cout << xactual << yactual <<"   actual"<< endl;
		}
		else {
			posicionx = scene.xcell_sel;
			posiciony = scene.ycell_sel;
			count--;
			cout << posicionx << posiciony << endl;
			gameboard.cambiarPosicion(xactual, yactual, posicionx, posiciony);
			gameboard.comer(xactual, yactual, posicionx, posiciony);
			gameboard.actualizarEstado();
		}
		cout << gameboard.estadoPartida() << endl;
	}
	
	if (button == MOUSE_RIGHT_BUTTON && down)
		gameboard.pasoTurno();
	glutPostRedisplay();
}


/*void OnTimer(int value){
	//****WRITE TIMER CODE HERE

	//sets new timer (do not delete)
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}*/
