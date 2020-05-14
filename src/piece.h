//piece.h: interface for the Piece class Hierarchy and definitions

#ifndef __PIECE_H__
#define __PIECE_H__

#include <iostream>
#include "gltools.h"
#include "glut.h"

using namespace std;

class Object{
//interface class for all pieces
public:
	enum type_t{QUEEN_GREEN, QUEEN_BLACK, EMPTY_CELL};
	virtual void getCellNumber(int&x, int&y)=0;
	virtual type_t getType()=0;
};

class Piece:public Object{
public:
	
protected:
	int x;
	int y;
	type_t type;
public:
	
	Piece():x(-1), y(-1), type(EMPTY_CELL){}// constructor inicial con valores por defecto
	void setCell(int x, int y, type_t t){this->x=x; this->y=y; this->type=t;}// dar valores a las piezas iniciales
	virtual void getCellNumber(int&x, int&y){x=this->x; y=this->y;}// conocer los valores en este caso , la posición x e y de la pieza
	virtual type_t getType(){return type;}
};

#endif
