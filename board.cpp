#include "board.h"
#include <math.h>

void Board::cambiarPosicion(int x, int y, int posicionx, int posiciony)
{
	switch (tab[x][y].getType())
	{
	case Object::QUEEN_GREEN:
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x - 1) && (posiciony == (y - 1) || posiciony == (y + 1)))
		{
			tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREEN);
			tab[x][y].setCell(x, y, Object::EMPTY_CELL);
			if (posicionx == 0)
				reina(posicionx, posiciony);
		}
		break;
	case Object::QUEEN_BLACK:
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x + 1) && (posiciony == (y - 1) || posiciony == (y + 1)))
		{
			tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACK);
			tab[x][y].setCell(x, y, Object::EMPTY_CELL);
			if (posicionx == (N-1))
				reina(posicionx, posiciony);
		}
	case Object::EMPTY_CELL:
		break;

	default:// vamos a utilizarlo para las reinas que se mueven las dos igual
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && abs(posicionx - x) == abs(posiciony - y))
		{
			int u, k, cont = 0;
			if (posicionx - x < 0)
				u = -1;
			else u = 1;
			if (posiciony - y < 0)
				k = -1;
			else k = 1;
			for (int i = x, j = y;i != posicionx, j != posiciony;i += u, j += k)
			{
				if (tab[i][j].getType() == Object::EMPTY_CELL)
					cont++;
			}
			if ((cont + 1) == abs(posicionx - x))
			{
				if(tab[x][y].getType()==Object::QUEEN_GREENR)
				tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREENR);
				else
				tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACKR);
				tab[x][y].setCell(x, y, Object::EMPTY_CELL);
			}
		}
	}
}

void Board::comer(int x, int y, int posicionx, int posiciony)
{
	switch (tab[x][y].getType())
	{
	case Object::QUEEN_GREEN:
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && (posicionx == (x - 2) || posicionx == (x+2)) && (posiciony == (y - 2) || posiciony == (y + 2)))
		{
			int pmediox, pmedioy;
			pmediox = (posicionx + x) / 2;
			pmedioy = (posiciony + y) / 2;
			if (tab[pmediox][pmedioy].getType() == Object::QUEEN_BLACK)
			{
				tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREEN);
				tab[x][y].setCell(x, y, Object::EMPTY_CELL);
				tab[pmediox][pmedioy].setCell(pmediox, pmedioy, Object::EMPTY_CELL);
				if (posicionx == 0)
					reina(posicionx, posiciony);
			}
		}
		break;
	case Object::QUEEN_BLACK:
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && (posicionx == (x - 2) || posicionx == (x + 2)) && (posiciony == (y - 2) || posiciony == (y + 2)))
		{
			int pmediox, pmedioy;
			pmediox = (posicionx + x) / 2;
			pmedioy = (posiciony + y) / 2;
			if (tab[pmediox][pmedioy].getType() == Object::QUEEN_GREEN)
			{

				tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACK);
				tab[x][y].setCell(x, y, Object::EMPTY_CELL);
				tab[pmediox][pmedioy].setCell(pmediox, pmedioy, Object::EMPTY_CELL);
				if (posicionx == (N-1))
					reina(posicionx, posiciony);
			}
		}
	default:
		;
	}
}

void Board::reina(int posicionx, int posiciony)
{
	switch(tab[posicionx][posiciony].getType())
	{
	case Object::QUEEN_GREEN:
		tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREENR);
		
		break;
	case Object::QUEEN_BLACK:
		tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACKR);

		break;
	default:
		;
	}
}