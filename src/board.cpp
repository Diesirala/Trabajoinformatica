#include "board.h"
#include <math.h>

void Board::tablas(int x, int y, int posicionx, int posiciony, int & posDeComer,int& posDeMover)
{
}

int Board::cambiarPosicion(int x, int y, int posicionx, int posiciony)
{
	switch (tab[x][y].getType()*movimientos*turno)// Enumeracion por el turno
	{
	case 1://Turno de las blancas, tienes un movimiento y has selecionado una blanca
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x - 1) && (posiciony == (y - 1) || posiciony == (y + 1)))
		{
			tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREEN);
			tab[x][y].setCell(x, y, Object::EMPTY_CELL);
			movimientos = 0;
			pasoTurno();
			if (posicionx == 0)
				reina(posicionx, posiciony);
			return 1;
		}
		else return 0;
		break;
	case -2://turno de las negras tienes un movimiento y la pieza seleccionada es una negra
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x + 1) && (posiciony == (y - 1) || posiciony == (y + 1)))
		{
			tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACK);
			tab[x][y].setCell(x, y, Object::EMPTY_CELL);
			movimientos = 0;
			pasoTurno();
			if (posicionx == (N-1))
				reina(posicionx, posiciony);
			return 1;
		}
		else return 0;
		break;
	case 0:
		return 0;
		break;

	default: // vamos a utilizarlo para las reinas que se mueven las dos igual
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && abs(posicionx - x) == abs(posiciony - y))
		{
			int u, k, cont = 0;
			if (posicionx - x < 0)
				u = -1;
			else u = 1;
			if (posiciony - y < 0)
				k = -1;
			else k = 1;
			for (int i = x, j = y; j != posiciony;i += u, j += k)
			{
				if (tab[i][j].getType() == Object::EMPTY_CELL)
					cont++;
			}
			if ((cont + 1) == abs(posicionx - x))
			{
				if (tab[x][y].getType() == Object::QUEEN_GREENR && turno == 1  && movimientos==1 ) {
					tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREENR);
					movimientos = 0;
					pasoTurno();
					tab[x][y].setCell(x, y, Object::EMPTY_CELL);
					return 1;
				}
				if (tab[x][y].getType() == Object::QUEEN_BLACKR && turno == -1 && movimientos == 1 )
				{
					tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACKR);
					movimientos = 0;
					pasoTurno();
					tab[x][y].setCell(x, y, Object::EMPTY_CELL);
					return 1;
				}
				else return 0;
				
			}
			else return 0;
		}
		else return 0;
		break;
	}
	
}

int Board::comer(int x, int y, int posicionx, int posiciony)
{
	switch (tab[x][y].getType()*turno)
	{
	case 1:
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && (posicionx == (x - 2) || posicionx == (x+2)) && (posiciony == (y - 2) || posiciony == (y + 2)))
		{
			int pmediox, pmedioy;
			pmediox = (posicionx + x) / 2;
			pmedioy = (posiciony + y) / 2;
			if (tab[pmediox][pmedioy].getType() == Object::QUEEN_BLACK || tab[pmediox][pmedioy].getType() == Object::QUEEN_BLACKR)
			{
				tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREEN);
				tab[x][y].setCell(x, y, Object::EMPTY_CELL);
				tab[pmediox][pmedioy].setCell(pmediox, pmedioy, Object::EMPTY_CELL);
				movimientos = 0;
				negras--;
				if (posicionx == 0) {
					reina(posicionx, posiciony);
					pasoTurno();
				}
				
				return 1;
			}
			else return 0;
		}
		else return 0;
		break;
	case -2:
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && (posicionx == (x - 2) || posicionx == (x + 2)) && (posiciony == (y - 2) || posiciony == (y + 2)))
		{
			int pmediox, pmedioy;
			pmediox = (posicionx + x) / 2;
			pmedioy = (posiciony + y) / 2;
			if (tab[pmediox][pmedioy].getType() == Object::QUEEN_GREEN || tab[pmediox][pmedioy].getType() == Object::QUEEN_GREENR)
			{

				tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACK);
				tab[x][y].setCell(x, y, Object::EMPTY_CELL);
				tab[pmediox][pmedioy].setCell(pmediox, pmedioy, Object::EMPTY_CELL);
				movimientos = 0;
				blancas--;
				if (posicionx == (N - 1)) {
					reina(posicionx, posiciony);
					pasoTurno();
				}
				
				return 1;
			}
			else return 0;
		}
		else return 0;
		break;
	case 0:
		return 0;
		break;
	default:// vamos a utilizarlo para las reinas que se mueven las dos igual
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && (abs(posicionx - x) == abs(posiciony - y)) )
		{
			int u, k, cont = 0, aux1 = 0, aux2 = 0;
			if (posicionx - x < 0)
				u = -1;
			else u = 1;
			if (posiciony - y < 0)
				k = -1;
			else k = 1;
			if ((tab[x][y].getType() == Object::QUEEN_GREENR) && (tab[posicionx - u][posiciony - k].getType() % 2 == 0 && tab[posicionx - u][posiciony - k].getType() != 0)|| (tab[x][y].getType() == Object::QUEEN_BLACKR) && (tab[posicionx - u][posiciony - k].getType() % 2 != 0 && tab[posicionx - u][posiciony - k].getType() != 0))
			{
				for (int i = x, j = y; i != (posicionx - u); i += u, j += k)
				{
					if (tab[i][j].getType() == Object::EMPTY_CELL)
						cont++;
				}
				if ((cont + 2) == (abs(posicionx - x)))
				{
					if (tab[x][y].getType() == Object::QUEEN_GREENR && turno == 1) {
						tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREENR);
						tab[posicionx - u][posiciony - k].setCell(posicionx - u, posiciony - k, Object::EMPTY_CELL);
						tab[x][y].setCell(x, y, Object::EMPTY_CELL);
						movimientos = 0;
						negras--;
						return 1;

					}
					if (tab[x][y].getType() == Object::QUEEN_BLACKR && turno == -1)
					{
						tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACKR);
						tab[posicionx - u][posiciony - k].setCell(posicionx - u, posiciony - k, Object::EMPTY_CELL);
						tab[x][y].setCell(x, y, Object::EMPTY_CELL);
						movimientos = 0;
						blancas--;
						
						return 1;
					}
					else return 0;
				}
				else return 0;
			}
			else return 0;
		}
		else return 0;
		
		;
		break;
	}
	
}

est Board::estadoPartida(void) {

	return estado;

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

void Board::actualizarEstado(void)
{
	
	int posDeComer=0;
	int posDeMover=0;
	
	if (blancas == 0) //GANAN NEGRAS
		estado = DERROTAB;
	if (negras == 0)  //GANAN BLANCAS
		estado = VICTORIAB;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {

					Board copia(*this);
					if (copia.comer(i, j, k, l) == 1)
						posDeComer++;
					if (copia.cambiarPosicion(i, j, k, l) == 1)
						posDeMover++;


				}
			}

		}


	}
	if (posDeComer == 0 && posDeMover == 0 && movimientos==1)
		estado = TABLAS;


	cout << "Las posibilidades de comer son: " << posDeComer << endl;
	cout << "Las posibilidades de moverse son: " << posDeMover << endl;
}

void Board::pasoTurno(void) {
	if (movimientos == 0) {
		movimientos = 1;
		turno = -turno;
	}
}
//Prueba 3 de GITHUB