#include "board.h"
#include "piece.h"

void Board::cambiarPosicion(int x, int y, int posicionx, int posiciony) {
	if (tab[posicionx][posiciony].getType == Piece::EMPTY_CELL && ) {
		tab[x][y].setCell(posicionx, posiciony, tab[x][y].getType);
		tab[x][y].setCell(x, y, Piece::EMPTY_CELL);
	}

}