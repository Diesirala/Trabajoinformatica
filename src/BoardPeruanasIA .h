#pragma once
#include "BoardIA.h"
class BoardPeruanasIA : public BoardIA {
public:
	BoardPeruanasIA() :BoardIA(8) {
		variante = PERUANA;
	}

	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual void actualizarEstado(void);
	virtual void estadSoplido(void);
};