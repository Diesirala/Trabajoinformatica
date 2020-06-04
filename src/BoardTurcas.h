#pragma once
#include "board.h"
#include <stdlib.h>
class BoardTurcas : public Board {
public:
	BoardTurcas() :Board(8) {
		variante = TURCA;
	}
	//BoardTurcas(BoardTurcas& a):Board(a){}
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual int cambiarPosicion(int x, int y, int posicionx, int posiciony);
	virtual void estadSoplido(void);
	virtual void actualizarEstado(void);
	virtual void pasoTurno(void);


};