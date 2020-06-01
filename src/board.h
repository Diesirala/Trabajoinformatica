//board.h: interface for the board class: contains only the logic of the game

#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include "piece.h"
#include "Enumeraciones.h"
#include <stdlib.h>
#include <time.h>


using namespace std;

class Board{
public:
	
	//enum tipo_juego { ESPAN, PERUANA, RUSA, INGLESA };
protected:
	const int N;		//NxN board
	Piece ** tab;
	int turno;
	int movimientos;
	est estado;
	int blancas;
	int negras;
	tipo_juego variante;


	void reina(int posicionx, int posiciony);
	

public:
	Board(int n, tipo_juego est):turno(1),movimientos(1) ,N(n),estado(JUGANDO),blancas((n / 2) * 3), negras((n / 2) * 3),variante(est){
		
		tab=new Piece*[N];
		for (int i=0; i<N; i++){
			tab[i]=new Piece[N];			//initially empty
		}

		//set initial position
		for(int j=1; j<N; j+=2){
			tab[0][j].setCell(0,j, Piece::QUEEN_BLACK);
			tab[N-2][j].setCell(0, j, Piece::QUEEN_GREEN);
			tab[2][j].setCell(0, j, Piece::QUEEN_BLACK);
		}

				
		for(int j=0; j<N; j+=2){
			tab[N-1][j].setCell(0,j, Piece::QUEEN_GREEN);
			tab[1][j].setCell(0, j, Piece::QUEEN_BLACK);
			tab[N-3][j].setCell(0, j, Piece::QUEEN_GREEN);
		}
		Piece vacio[20];
		
			for (int i = 0; i < 20; i++)
				PiezasSoplido[0][i] = vacio[i];
			for (int i = 0; i < 20; i++)
				PiezasSoplido[1][i] = vacio[i];




	}

	~Board(){
		for(int i=0; i<N; i++)
			delete [] tab[i];
		delete [] tab;
	}

	Board(Board& a):turno(a.turno), movimientos(a.movimientos), N(a.N), estado(a.estado), blancas(a.blancas), negras(a.negras) {
		
		tab = new Piece * [N];                 //Reservo memoria para la copia
		for (int i = 0; i < N; i++) {
			tab[i] = new Piece[N];			
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tab[i][j] = a.tab[i][j];


			}
		}


	}

	
	void setFicha(tipo_juego p) { this->variante = p; }
	virtual tipo_juego getTipo() { return variante; }
	void Board::tablas(int x, int y, int posicionx, int posiciony, int& posDeComer, int& posDeMover);
	int cambiarPosicion(int x,int y,int posicionx, int posiciony);
	void pasoTurno(void);
	int comer(int x, int y, int posicionx, int posiciony);
	int getSize(){return N;}
	Piece** getTab(){return tab;}
	est  estadoPartida(void);
	void actualizarEstado(void);
};
class BoardIA :public Board {
protected:
	//int IA;
	Piece posiblesMovimientos[20];
	int posDeMover;
public:
	BoardIA(int a, tipo_juego b) :Board(a, b) {
		Piece vacio[20];

		for (int i = 0; i < 20; i++)
			posiblesMovimientos[i] = vacio[i];

	}
	BoardIA(BoardIA& a) :Board(a), posDeMover(a.posDeMover) {
		for (int i = 0; i < 20; i++) {
			posiblesMovimientos[i] = a.posiblesMovimientos[i];
		}
	}









	virtual void moverIA(void) {
		if (turno == -1) {
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
					int aleatorio=0;
					if(posDeMover>1)
					 aleatorio= rand() % (posDeMover-1 );

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
			if (movimientos == 0)
				pasoTurno();

			
			


		}



	}

	  virtual void Movimientos(void) {





		if (cop == 0) {
			Piece vacio[20];
			if (turno == -1) {
				for (int i = 0; i < 20; i++)
					posiblesMovimientos[i] = vacio[i];
			}
			int aux = 0;
			posDeMover = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						for (int l = 0; l < N; l++) {

							BoardIA copia(*this);

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
			//estadSoplido();
		}
		if (turno == -1)
			moverIA();

	}


};






#endif
