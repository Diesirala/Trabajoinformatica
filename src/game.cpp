

#include <iostream>
#include "boardgl.h"
#include"Coordinador.h"
#include "glut.h"
/////////////////////////////////
//call back declarations: will be called by glut when registered

void OnDraw(void); 
void OnKeyboardDown(unsigned char key, int x, int y); 
void OnMouseClick(int button,int state, int x,int y);
void OnTimer(int value); 

////////////////////////////////////////////////
//global objects which make the world


Coordinador escena;


///////////////////////////////////////////////

int main(int argc,char* argv[]){
	//GL Initialization stuff



	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("DAMAS");

	
	//Register callbacks
	glutDisplayFunc(OnDraw);
	glutKeyboardFunc(OnKeyboardDown);
	glutMouseFunc(OnMouseClick);
	
	
	//sets light and perspective
      escena.init();
	
	//glut takes control
	glutMainLoop();	

	return 0;   
}

void OnDraw(void){
//////////////////////
//captures drawing event
//gives control to scene
	
	escena.Draw();
	if(escena.getHayTablero()==1)//Se puede borrar tablero y funcionar con estado if Estado==jugando
	escena.scene->Draw();
	
	glutSwapBuffers();
}
//
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
	if(b==GLUT_RIGHT_BUTTON)
		button=MOUSE_RIGHT_BUTTON;
		
	if (b == GLUT_MIDDLE_BUTTON) {
		button = MOUSE_MIDDLE_BUTTON;
		
	}
		
	int specialKey = glutGetModifiers();
	bool ctrlKey= (specialKey & GLUT_ACTIVE_CTRL)? true:false ;
	bool sKey= specialKey & GLUT_ACTIVE_SHIFT ;
	escena.MouseButton(x,y,b,down,sKey,ctrlKey);
	if ((escena.xcell_sel < escena.dimensiones && escena.xcell_sel >= 0) && (escena.ycell_sel < escena.dimensiones && escena.ycell_sel >= 0)) {
		if (button == MOUSE_LEFT_BUTTON && down && escena.getHayTablero() == 1) {
			if (count == 0) {
				xactual = escena.xcell_sel;
				yactual = escena.ycell_sel;
				count++;
				
				if (escena.a->soplido(xactual, yactual) || escena.a->getPieceType(xactual, yactual) == Object::EMPTY_CELL) {
					
					count--;
				}
			
			}
			else {
				posicionx = escena.xcell_sel;
				posiciony = escena.ycell_sel;
				count--;
				
				escena.a->cambiarPosicion(xactual, yactual, posicionx, posiciony);
				
				escena.a->comer(xactual, yactual, posicionx, posiciony);
				
			}
			
		}
	}
	if (button == MOUSE_RIGHT_BUTTON && down) {
		escena.a->pasoTurno();
	}
	glutPostRedisplay();
}


void OnTimer(int value){
	//****WRITE TIMER CODE HERE

	//sets new timer (do not delete)
	glutTimerFunc(25,OnTimer,0);
	glutPostRedisplay();
}
