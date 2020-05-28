//boardgl.h: contains the painting functions for the board

#ifndef __BOARD_GL_H__
#define __BOARD_GL_H__

#include <string>
#include <vector>
#include "board.h"
#include "piece.h"

//enums to eliminate dependency of glut
enum {MOUSE_LEFT_BUTTON, MOUSE_MIDDLE_BUTTON, MOUSE_RIGHT_BUTTON};
enum {KEY_UP, KEY_DOWN, KEY_LEFT,KEY_RIGHT};


using namespace std;

class BoardGL{

public:
	Piece pieza;
	tipo_juego tipoPieza;
	BoardGL(Board* pb,  tipo_juego m ):m_board(pb), tipoPieza(m){
		width=0.15;				//width of each cell in the grid// DEFINE EL ANCHO DE CADA CELDA// LA VISTA DEPENDE DE ESTE PARAMETRO
		N=pb->getSize();	//Grid NxN
		dist=2;	
		//distance of viewpoint from center of the board// DISTANCIA A LA QUE VES EL TABLERO
		pieza.setFicha(tipoPieza);
	}
	virtual ~BoardGL(){}

		 	
//Event managers
	void Draw();
	void DrawGrid();
	void DrawCell(int i,int j);
	void setOjo(int);
	void setFondo();
	//Funcion friend para poder acceder a las cordenadas pulsadas por el raton y utilizarlas
	friend void OnMouseClick(int b, int state, int x, int y);
	
	//info
	void setSize(int s){N=s;}
	int getSize(){return N;}
	tipo_juego getType() { return tipoPieza; }
	//coord
	void cell2center(int cell_x, int cell_y, float& glx, float& gly){
		
		glx=cell_y*width+width/2.0f;
		gly=-cell_x*width-width/2.0f;
	}


protected:
	float width;
	int N;								 //size 
	Board* m_board;

//visualization	
	double center_x,center_y,center_z;
	double dist;
	//mouse	
	//int xcell_sel, ycell_sel;			//cell selected with mouse


	//mouse+special-keys combination state events 
	bool controlKey;
	bool shiftKey;
	bool leftButton;
	bool rightButton;
	bool midButton;
};

#endif

