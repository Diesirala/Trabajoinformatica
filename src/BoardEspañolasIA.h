#pragma once
#include "BoardIA.h"

class BoardEspañolasIA :public BoardIA {
public:
	BoardEspañolasIA() :BoardIA(8) {
		variante = ESPAN;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tab[i][j].setCell(-1, -1, Object::EMPTY_CELL);

			}

		}
		for (int j = 1; j < N; j += 2) {
			tab[0][j].setCell(0, j, Piece::QUEEN_BLACK);
			tab[N - 2][j].setCell(N - 2, j, Piece::QUEEN_GREEN);
			tab[2][j].setCell(2, j, Piece::QUEEN_BLACK);
		}
		for (int j = 0; j < N; j += 2) {
			tab[1][j].setCell(1, j, Piece::QUEEN_BLACK);
			tab[N - 1][j].setCell(N - 1, j, Piece::QUEEN_GREEN);
			tab[N - 3][j].setCell(N - 3, j, Piece::QUEEN_GREEN);
		}
	}

	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual void actualizarEstado(void);
	virtual void estadSoplido(void);
};