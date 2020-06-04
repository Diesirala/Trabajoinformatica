#pragma once
#include "BoardCheckers.h"
#include <stdlib.h>
class BoardItalianas : public BoardCheckers {
public:
	BoardItalianas() :BoardCheckers() {
		turno = 1;
		variante = ITALIANA;
	}
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual void actualizarEstado(void);
	virtual void estadSoplido(void);

};