#pragma once
#include "board.h"
class BoardTurcas : public Board {
public:
	BoardTurcas() :Board(8) {
		variante = TURCA;
	}
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual int cambiarPosicion(int x, int y, int posicionx, int posiciony);
	virtual void estadSoplido(void);
	virtual void actualizarEstado(void);
	virtual void pasoTurno(void);


};