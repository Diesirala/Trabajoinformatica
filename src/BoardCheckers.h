
#pragma once
#include "board.h"
class BoardCheckers : public Board {
public:
	BoardCheckers() :Board(8) {
		turno = -1;
		variante = CHECKERS;

	}

	virtual int cambiarPosicion(int x, int y, int posicionx, int posiciony);
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual void actualizarEstado(void);
	virtual void estadSoplido(void);
}; 