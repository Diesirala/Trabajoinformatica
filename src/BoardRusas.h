#pragma once
#include "board.h"
#include <stdlib.h>
class BoardRusas : public Board {
protected:
	virtual void reina(int posicionx, int posiciony);

public:
	BoardRusas() :Board(8) {
		variante = RUSA;
	}

};