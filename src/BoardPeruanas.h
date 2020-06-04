#pragma once
#include "board.h"
#include <stdlib.h>
class BoardPeruanas : public Board {
public:
	BoardPeruanas() :Board(8) {
		variante = PERUANA;
	}
	virtual ~BoardPeruanas() {};
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual void actualizarEstado(void);
	virtual void estadSoplido(void);


};