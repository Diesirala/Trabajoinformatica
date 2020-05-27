#include "Piece.h"

Piece::Piece() {
	x = -1;
	y = -1;
	type = EMPTY_CELL;
}

Piece::~Piece() {

}

void Piece::dibuja() {
	
}

void Piece::setColor(Byte r, Byte v, Byte a)
{
	color.set(r, v, a);
}