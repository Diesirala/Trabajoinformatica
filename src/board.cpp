#include "board.h"
#include <math.h>
#include "ETSIDI.h"


int Board::cambiarPosicion(int x, int y, int posicionx, int posiciony)
{
	switch (tab[x][y].getType()*movimientos*turno)// Enumeracion por el turno
	{
	case 1://Turno de las blancas, tienes un movimiento y has selecionado una blanca
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x - 1) && (posiciony == (y - 1) || posiciony == (y + 1)))
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
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x + 1) && (posiciony == (y - 1) || posiciony == (y + 1)))
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
				if (tab[x][y].getType() == Object::QUEEN_BLACKR && turno == -1 && movimientos == 1 )
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

int Board::comer(int x, int y, int posicionx, int posiciony)
{
	
	if (movimientos == 1 || pmovida==tab[x][y]) {
		switch (tab[x][y].getType() * turno)
		{
		case 1:
			if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && (posicionx == (x - 2) || posicionx == (x + 2)) && (posiciony == (y - 2) || posiciony == (y + 2)))
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
					estadSoplido();
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
					ETSIDI::play("sonidos/comer.wav");
					tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACK);
					tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
					tab[pmediox][pmedioy].setCell(-1, -1, Object::EMPTY_CELL);
					pmovida = tab[posicionx][posiciony];
					movimientos = 0;
					blancas--;
					estadSoplido();
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
			if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && (abs(posicionx - x) == abs(posiciony - y)))
			{
				int u, k, cont = 0, aux1 = 0, aux2 = 0;
				if (posicionx - x < 0)
					u = -1;
				else u = 1;
				if (posiciony - y < 0)
					k = -1;
				else k = 1;
				if ((tab[x][y].getType() == Object::QUEEN_GREENR) && (tab[posicionx - u][posiciony - k].getType() % 2 == 0 && tab[posicionx - u][posiciony - k].getType() != 0) || (tab[x][y].getType() == Object::QUEEN_BLACKR) && (tab[posicionx - u][posiciony - k].getType() % 2 != 0 && tab[posicionx - u][posiciony - k].getType() != 0))
				{
					for (int i = x, j = y; i != (posicionx - u); i += u, j += k)
					{
						if (tab[i][j].getType() == Object::EMPTY_CELL)
							cont++;
					}
					if ((cont + 2) == (abs(posicionx - x)))
					{
						if (tab[x][y].getType() == Object::QUEEN_GREENR && turno == 1) {
							ETSIDI::play("sonidos/comer.wav");
							tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREENR);
							tab[posicionx - u][posiciony - k].setCell(-1, -1, Object::EMPTY_CELL);
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
							tab[posicionx - u][posiciony - k].setCell(-1, -1, Object::EMPTY_CELL);
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

	
	
	if (blancas == 0) //GANAN NEGRAS
		estado = DERROTAB;
	if (negras == 0)  //GANAN BLANCAS
		estado = VICTORIAB;
	
}

void Board::pasoTurno(void) {

	if (movimientos == 0) {
	
		movimientos = 1;
		turno = -turno;
		actualizarEstado();
		//estadSoplido();
	}
	
	
}
int Board::soplido(int x, int y)
{
	for (int i = 0; i < 20; i++) {
		int c, d;
		
		if ((turno == 1 && movimientos==1 && tab[x][y].getType() == Object::QUEEN_BLACK) || (turno == 1 && movimientos == 1 && tab[x][y].getType() == Object::QUEEN_BLACKR)) {
			PiezasSoplido[1][i].getCellNumber(c, d);
			if (c == x && d == y) {
				tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
				estadSoplido();
				negras--;
				return 1;
			}
			
		}
		if ((turno == -1 && movimientos == 1 && tab[x][y].getType() == Object::QUEEN_GREEN) || (turno == -1 && movimientos == 1 && tab[x][y].getType() == Object::QUEEN_GREENR)) {
			PiezasSoplido[0][i].getCellNumber(c, d);
			if (c == x && d == y) {
				tab[x][y].setCell(x-1, -1, Object::EMPTY_CELL);
				estadSoplido();
				//PiezasSoplido[0][i].setCell(-1, -1, Object::EMPTY_CELL);
				blancas--;
				return 1;
			}
		}
	}
	return 0;
}


void Board::estadSoplido(void)
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
		int aux0=0,aux1=0;
		int posDeComer = 0;
		int posDeMover = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					for (int l = 0; l < N; l++) {

						Board copia(*this);
						if (copia.comer(i, j, k, l) == 1) {


							if ((turno == 1 && posDeComer > 0) && PiezasSoplido[0][posDeComer - 1] == tab[i][j]) {
								posDeComer++;
								aux0 ++;
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
								PiezasSoplido[1][posDeComer-aux1] = tab[i][j];
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
			cout << "Piezas que pueden soplar las blancas: " << c << d << endl;

			cout << "Piezas que pueden soplar las negras: " << e << f << endl;

		}


		if (posDeComer == 0 && posDeMover == 0 && movimientos == 1)
			tablas(); 
		cout << "Las posibilidades de comer son: " << posDeComer << endl;
		cout << "Las posibilidades de moverse son: " << posDeMover << endl;
	}




}
void Board::tablas(){
	estado = TABLAS;
}





//FUNCIONES SOBRECARGADAS DE LAS CHECKERS
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////


 int BoardCheckers::cambiarPosicion(int x, int y, int posicionx, int posiciony)
{
	switch (tab[x][y].getType() * movimientos * turno)// Enumeracion por el turno
	{
	case 1://Turno de las blancas, tienes un movimiento y has selecionado una blanca
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x - 1) && (posiciony == (y - 1) || posiciony == (y + 1)))
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
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x + 1) && (posiciony == (y - 1) || posiciony == (y + 1)))
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
		if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && abs(posicionx - x) == abs(posiciony - y)&& abs(posicionx - x)==1)
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
		
		break;
	}

}

int BoardCheckers::comer(int x, int y, int posicionx, int posiciony)
{

	if (movimientos == 1 || pmovida == tab[x][y]) {
		switch (tab[x][y].getType() * turno)
		{
		case 1:
			if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x - 2)  && (posiciony == (y - 2) || posiciony == (y + 2)))
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
					estadSoplido();
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
			if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && posicionx == (x + 2) && (posiciony == (y - 2) || posiciony == (y + 2)))
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
					estadSoplido();
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
			if (tab[posicionx][posiciony].getType() == Object::EMPTY_CELL && (posicionx == (x - 2) || posicionx == (x + 2)) && (posiciony == (y - 2) || posiciony == (y + 2)))
			{
				int pmediox, pmedioy;
				pmediox = (posicionx + x) / 2;
				pmedioy = (posiciony + y) / 2;
				if (tab[x][y].getType() == Object::QUEEN_GREENR && turno == 1)
				{
					if (tab[pmediox][pmedioy].getType() == Object::QUEEN_BLACK || tab[pmediox][pmedioy].getType() == Object::QUEEN_BLACKR)
					{
						ETSIDI::play("sonidos/comer.wav");
						tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREENR);
						tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
						tab[pmediox][pmedioy].setCell(-1, -1, Object::EMPTY_CELL);
						pmovida = tab[posicionx][posiciony];
						movimientos = 0;
						blancas--;
						estadSoplido();
						if (posicionx == (N - 1)) {
							reina(posicionx, posiciony);
							pasoTurno();
						}

						return 1;
					}
					else return 0;

				}
				if (tab[x][y].getType() == Object::QUEEN_BLACKR && turno == -1)
						{
							if (tab[pmediox][pmedioy].getType() == Object::QUEEN_GREEN || tab[pmediox][pmedioy].getType() == Object::QUEEN_GREENR)
							{
								ETSIDI::play("sonidos/comer.wav");
								tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACKR);
								tab[x][y].setCell(-1, -1, Object::EMPTY_CELL);
								tab[pmediox][pmedioy].setCell(-1, -1, Object::EMPTY_CELL);
								pmovida = tab[posicionx][posiciony];
								movimientos = 0;
								blancas--;
								estadSoplido();
								if (posicionx == (N - 1)) {
									reina(posicionx, posiciony);
									pasoTurno();
								}

								return 1;
							}
							else return 0;
						}
				else return 0;
			}
			else return 0;
			break;
		}
		return 0;
	}
	return 0;
}



//Prueba 3 de GITHUB