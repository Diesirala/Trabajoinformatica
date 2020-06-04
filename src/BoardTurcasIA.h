#pragma once
#include "BoardTurcas.h"
#include <stdlib.h>
class BoardTurcasIA : public BoardTurcas {
protected:
	//int IA;
	Piece posiblesMovimientos[50];
	int posDeMover;
public:
	BoardTurcasIA() :BoardTurcas() {
		Piece vacio[50];

		for (int i = 0; i < 50; i++)
			posiblesMovimientos[i] = vacio[i];
	}
	virtual void moverIA(void) {

		for (int i = 0; i < 20; i++) {
			int a, b;
			if (PiezasSoplido[0][i].getType() != Object::EMPTY_CELL) {
				PiezasSoplido[0][i].getCellNumber(a, b);
				soplido(a, b);
			}

		}

		int comida;
		do {
			comida = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						for (int l = 0; l < N; l++) {
							if (comer(i, j, k, l))
								comida++;

						}
					}
				}
			}

		} while (comida > 0);


		if (movimientos == 1) {
			Movimientos();
			int a, b;
			srand(time(NULL));
			if (posDeMover) {
				int aleatorio = 0;
				if (posDeMover > 1)
					aleatorio = rand() % (posDeMover - 1);

				int izqder = rand() % (2);
				posiblesMovimientos[aleatorio].getCellNumber(a, b);
				if (posiblesMovimientos[aleatorio].getType() != Object::EMPTY_CELL)
				{

					for (int i = 0; i < N; i++) {
						if (izqder)
							for (int j = (N - 1); j >= 0; j--) {
								cambiarPosicion(a, b, i, j);

							}
						if (izqder == 0)
							for (int j = 0; j < N; j++) {
								cambiarPosicion(a, b, i, j);

							}

					}
				}
			}
		}
		if (movimientos == 0 && turno == -1)
			pasoTurno();









	}

	virtual void Movimientos(void) {





		if (cop == 0) {
			Piece vacio[50];
			if (turno == -1) {
				for (int i = 0; i < 50; i++)
					posiblesMovimientos[i] = vacio[i];
			}
			int aux = 0;
			posDeMover = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						for (int l = 0; l < N; l++) {

							BoardTurcas copia(*this);

							if (copia.cambiarPosicion(i, j, k, l) == 1) {

								if ((turno == -1 && posDeMover > 0) && posiblesMovimientos[posDeMover - 1] == tab[i][j]) {
									posDeMover++;
									aux++;
									continue;
								}
								if (turno == -1)
									posiblesMovimientos[posDeMover - aux] = tab[i][j];
								posDeMover++;




							}


						}
					}

				}


			}

		}

	}



	virtual void pasoTurno(void) {

		if (movimientos == 0) {

			movimientos = 1;
			turno = -turno;
			actualizarEstado();
			//estadSoplido();
		}
		if (turno == -1)
			moverIA();

	}




};