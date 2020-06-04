#pragma once
#include "BoardIA.h"
class BoardRusasIA : public BoardIA {
protected:
	virtual void reina(int posicionx, int posiciony);

public:
	BoardRusasIA() :BoardIA(8) {
		variante = RUSA;
	}

};
