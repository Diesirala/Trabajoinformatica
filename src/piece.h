//piece.h: interface for the Piece class Hierarchy and definitions
//Prueba conjunta 3

#ifndef __PIECE_H__
#define __PIECE_H__

#include <iostream>
#include "gltools.h"
#include "glut.h"
#include "Formas3D.h"

enum tipo_juego{ESPAN,PERUANA,RUSA,INGLESA};

using namespace std;
//Prueba 2 conjunta
class Object{
//interface class for all pieces
public:
	enum type_t { EMPTY_CELL, QUEEN_GREEN, QUEEN_BLACK,  QUEEN_GREENR, QUEEN_BLACKR };
	virtual void getCellNumber(int&x, int&y)=0;
	virtual type_t getType()=0;
};

class Piece:public Object{
public:
	
protected:
	int x;
	int y;
	type_t type;
	tipo_juego pieza;
public:
	friend class Formas3D;
	Piece():x(-1), y(-1), type(EMPTY_CELL){}// constructor inicial con valores por defecto
	~Piece() {};
	void setCell(int x, int y, type_t t ){this->x=x; this->y=y; this->type=t;}// dar valores a las piezas iniciales
	void setFicha(tipo_juego p) {this->pieza = p;}
	virtual void getCellNumber(int&x, int&y){x=this->x; y=this->y;}// conocer los valores en este caso , la posición x e y de la pieza
	virtual type_t getType(){return type;}
	virtual tipo_juego getTipo() { return pieza; }
	void dibuja(int n);
};

#endif
