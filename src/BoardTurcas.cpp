
//////////////////////////////////////////
/////////////////////////// DAMAS TURCAS CAPTURAN EN LINEA RECTA HACIA DELANTE O HACIA LOS LADOS, LAS DAMAS TAMBIEN CAPTURAN EN LINEA RECTA SI UN JUGADOR NO PUEDE MOVER FICHA PIERDE
//////////////////////////////////////////
#include "BoardTurcas.h"
int BoardTurcas::cambiarPosicion(int x, int y, int posicionx, int posiciony)
{

	switch (tab[x][y].getType() * movimientos * turno)// Enumeracion por el turno
	{
	case 1://Turno de las blancas, tienes un movimiento y has selecionado una blanca
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && ((posicionx == (x - 1) && posiciony == y) ^ (posiciony == (y - 1) && posicionx == x) ^ (posiciony == (y + 1) && posicionx == x)))
		{
			estadSoplido();
			for (int i = 0; i < 20; i++) {
				if (PiezasSoplido[0][i] == tab[x][y])
					PiezasSoplido[0][i].setCell(posicionx, posiciony, Object::QUEEN_GREEN);

			}
			ETSIDI::play("sonidos/mover.wav");
			tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREEN);
			tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
			movimientos = 0;
			pasoTurno();
			if (posicionx == 0)
				reina(posicionx, posiciony);
			return 1;
		}
		else return 0;
		break;
	case -2://turno de las negras tienes un movimiento y la pieza seleccionada es una negra
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && ((posicionx == (x + 1) && posiciony == y) ^ (posiciony == (y - 1) && posicionx == x) ^ (posiciony == (y + 1) && posicionx == x)))
		{
			estadSoplido();
			for (int i = 0; i < 20; i++) {
				if (PiezasSoplido[1][i] == tab[x][y])
					PiezasSoplido[1][i].setCell(posicionx, posiciony, Object::QUEEN_BLACK);

			}
			ETSIDI::play("sonidos/mover.wav");
			tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACK);
			tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
			movimientos = 0;
			pasoTurno();
			if (posicionx == (N - 1))
				reina(posicionx, posiciony);
			return 1;
		}
		else return 0;
		break;
	case 0:
		return 0;
		break;

	default: // vamos a utilizarlo para las reinas que se mueven las dos igual
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && ((posiciony == y) ^ (posicionx == x)))
		{
			int u, k, cont = 0;
			if (posicionx - x < 0)
				u = -1;
			else u = 1;
			if (posiciony - y < 0)
				k = -1;
			else k = 1;
			if (posiciony == y)
				for (int i = x; i != posicionx; i += u)
				{
					if (tab[i][y].getType() == Object::EMPTY_CELL)
						cont++;
				}
			if (posicionx == x)
				for (int j = y; j != posiciony; j += k)
				{
					if (tab[x][j].getType() == Object::EMPTY_CELL)
						cont++;
				}
			if ((cont + 1) == ((abs(posicionx - x) ^ (abs(posiciony - y)))))
			{
				if (tab[x][y].getType() == Object::QUEEN_GREENR && turno == 1 && movimientos == 1) {
					estadSoplido();
					for (int i = 0; i < 20; i++) {
						if (PiezasSoplido[0][i] == tab[x][y])
							PiezasSoplido[0][i].setCell(posicionx, posiciony, Object::QUEEN_GREENR);

					}
					ETSIDI::play("sonidos/mover.wav");
					tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREENR);
					movimientos = 0;
					pasoTurno();
					tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
					return 1;
				}
				if (tab[x][y].getType() == Object::QUEEN_BLACKR && turno == -1 && movimientos == 1)
				{
					estadSoplido();
					for (int i = 0; i < 20; i++) {
						if (PiezasSoplido[1][i] == tab[x][y])
							PiezasSoplido[1][i].setCell(posicionx, posiciony, Object::QUEEN_BLACK);

					}
					ETSIDI::play("sonidos/mover.wav");
					tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACKR);
					movimientos = 0;
					pasoTurno();
					tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
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
int BoardTurcas::comer(int x, int y, int posicionx, int posiciony)
{
	if (movimientos == 1 || pmovida == tab[x][y]) {
		switch (tab[x][y].getType() * turno)
		{
		case 1:
			if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && ((posicionx == (x - 2) && posiciony == y) ^ (posiciony == (y - 2) && posicionx == x) ^ (posiciony == (y + 2) && posicionx == x)))
			{
				int pmediox, pmedioy;
				pmediox = (posicionx + x) / 2;
				pmedioy = (posiciony + y) / 2;
				if (tab[pmediox][pmedioy].getType() == Object::QUEEN_BLACK || tab[pmediox][pmedioy].getType() == Object::QUEEN_BLACKR)
				{

					ETSIDI::play("sonidos/comer.wav");
					tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREEN);
					tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
					tab[pmediox][pmedioy].setCell(-1, -1, Object::EMPTY_CELL);
					pmovida = tab[posicionx][posiciony];
					movimientos = 0;
					negras--;

					if (posicionx == 0) {
						reina(posicionx, posiciony);

					}
					estadSoplido();
					return 1;
				}
				else return 0;
			}
			else return 0;
			break;
		case -2:
			if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && ((posicionx == (x + 2) && posiciony == y) ^ (posiciony == (y - 2) && posicionx == x) ^ (posiciony == (y + 2) && posicionx == x)))
			{
				int pmediox, pmedioy;
				pmediox = (posicionx + x) / 2;
				pmedioy = (posiciony + y) / 2;
				if (tab[pmediox][pmedioy].getType() == Object::QUEEN_GREEN || tab[pmediox][pmedioy].getType() == Object::QUEEN_GREENR)
				{
					ETSIDI::play("sonidos/comer.wav");
					tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACK);
					tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
					tab[pmediox][pmedioy].setCell(-1, -1, Object::EMPTY_CELL);
					pmovida = tab[posicionx][posiciony];
					movimientos = 0;
					blancas--;

					if (posicionx == (N - 1)) {
						reina(posicionx, posiciony);

					}
					estadSoplido();
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
			if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && ((posiciony == y) ^ (posicionx == x)))
			{
				int u = 0, k = 0, cont = 0, aux1 = 0, aux2 = 0;
				if (posicionx - x < 0)
					u = -1;
				else if (posicionx - x > 0) u = 1;
				if (posiciony - y < 0)
					k = -1;
				else if (posiciony - y > 0) k = 1;
				if ((tab[x][y].getType() == Object::QUEEN_GREENR) && (tab[posicionx - u][posiciony - k].getType() % 2 == 0 && tab[posicionx - u][posiciony - k].getType() != 0) || (tab[x][y].getType() == Object::QUEEN_BLACKR) && (tab[posicionx - u][posiciony - k].getType() % 2 != 0 && tab[posicionx - u][posiciony - k].getType() != 0))
				{
					int u, k, cont = 0;
					if (posicionx - x < 0)
						u = -1;
					else u = 1;
					if (posiciony - y < 0)
						k = -1;
					else k = 1;
					if (posiciony == y)
						for (int i = x; i != (posicionx - u); i += u)
						{
							if (tab[i][y].getType() == Object::EMPTY_CELL)
								cont++;
						}
					if (posicionx == x)
						for (int j = y; j != (posiciony - k); j += k)
						{
							if (tab[x][j].getType() == Object::EMPTY_CELL)
								cont++;
						}
					if ((cont + 2) == ((abs(posicionx - x) ^ (abs(posiciony - y)))))
					{
						if (tab[x][y].getType() == Object::QUEEN_GREENR && turno == 1) {
							ETSIDI::play("sonidos/comer.wav");
							tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREENR);
							if (x == posicionx)
								tab[posicionx][posiciony - k].setCell(-1, -1, Object::EMPTY_CELL);
							if (posiciony == y)
								tab[posicionx - u][posiciony].setCell(-1, -1, Object::EMPTY_CELL);
							tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
							pmovida = tab[posicionx][posiciony];
							movimientos = 0;
							negras--;
							estadSoplido();
							return 1;

						}
						if (tab[x][y].getType() == Object::QUEEN_BLACKR && turno == -1)
						{
							ETSIDI::play("sonidos/comer.wav");
							tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACKR);
							if (x == posicionx)
								tab[posicionx][posiciony - k].setCell(-1, -1, Object::EMPTY_CELL);
							if (posiciony == y)
								tab[posicionx - u][posiciony].setCell(-1, -1, Object::EMPTY_CELL);
							tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
							pmovida = tab[posicionx][posiciony];
							movimientos = 0;
							blancas--;
							estadSoplido();
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
		return 0;
	}
	return 0;
}
void BoardTurcas::estadSoplido(void)
{
	if (cop == 0) {
		Piece vacio[20];
		if (turno == 1) {
			for (int i = 0; i < 20; i++)
				PiezasSoplido[0][i] = vacio[i];

		}
		if (turno == -1) {
			for (int i = 0; i < 20; i++)
				PiezasSoplido[1][i] = vacio[i];

		}
		int aux0 = 0, aux1 = 0;
		int posDeComer = 0;
		int posDeMover = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {

						BoardTurcas copia(*this);
						if (copia.comer(i, j, k, l) == 1) {


							if ((turno == 1 && posDeComer > 0) && PiezasSoplido[0][posDeComer - 1] == tab[i][j]) {
								posDeComer++;
								aux0++;
								continue;
							}

							if ((turno == -1 && posDeComer > 0) && PiezasSoplido[1][posDeComer - 1] == tab[i][j]) {
								posDeComer++;
								aux1++;
								continue;
							}
							if (turno == 1)
								PiezasSoplido[0][posDeComer - aux0] = tab[i][j];
							if (turno == -1)
								PiezasSoplido[1][posDeComer - aux1] = tab[i][j];
							posDeComer++;
							//j++;

						}
						if (copia.cambiarPosicion(i, j, k, l) == 1)
							posDeMover++;


					}
				}

			}


		}

		for (int i = 0; i < 20; i++) {
			int c = -1, d = -1, e = -1, f = -1;


			PiezasSoplido[1][i].getCellNumber(c, d);

			PiezasSoplido[0][i].getCellNumber(e, f);


		}
	}
}
void BoardTurcas::actualizarEstado(void)
{
	if (cop == 0) {
		int posDeComer = 0;
		int posDeMover = 0;


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {

						BoardTurcas copia(*this);
						if (copia.comer(i, j, k, l) == 1)
							posDeComer++;
						if (copia.cambiarPosicion(i, j, k, l) == 1)
							posDeMover++;


					}
				}

			}


		}
		if (posDeComer == 0 && posDeMover == 0 && movimientos == 1 && turno == 1)
			estado = DERROTAB;
		if (posDeComer == 0 && posDeMover == 0 && movimientos == 1 && turno == -1)
			estado = VICTORIAB;

		if (blancas == 0) //GANAN NEGRAS
			estado = DERROTAB;
		if (negras == 0)  //GANAN BLANCAS
			estado = VICTORIAB;


	}
}
void BoardTurcas::pasoTurno(void)
{
	if (movimientos == 0) {

		movimientos = 1;
		turno = -turno;

		actualizarEstado();
	}


}
//Prueba 3 de GITHUB