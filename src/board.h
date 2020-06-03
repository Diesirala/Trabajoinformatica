//board.h: interface for the board class: contains only the logic of the game

#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include "piece.h"
#include "Enumeraciones.h"
#include <stdlib.h>
#include <time.h>


using namespace std;
//DAMAS INTERNACIONALES
class Board{
public:
	
	//enum tipo_juego { ESPAN, PERUANA, RUSA, INGLESA };
protected:
	int cop;
	const int N;		//NxN board
	Piece ** tab;
	Piece   pmovida;
	Piece   PiezasSoplido[2][20];
	int turno;
	int movimientos;
	est estado;
	int blancas;
	int negras;
	tipo_juego variante;
	

	virtual void reina(int posicionx, int posiciony);
	

public:
	Board(int n, tipo_juego est):turno(1),movimientos(1) ,N(n),estado(JUGANDO),blancas((n / 2) * 3), negras((n / 2) * 3),variante(est),cop(0){
	
		
		tab=new Piece*[N];
		for (int i=0; i<N; i++){
			tab[i]=new Piece[N];			//initially empty
		}

		//set initial position
		for(int j=1; j<N; j+=2){
			tab[1][j].setCell(1, j, Piece::QUEEN_BLACK);
			tab[N - 1][j].setCell(N - 1, j, Piece::QUEEN_GREEN);
			tab[N - 3][j].setCell(N - 3, j, Piece::QUEEN_GREEN);
			if (N >= 10) {
				tab[N-7][j].setCell(N-7, j, Piece::QUEEN_BLACK);
			}
		}

				
		for(int j=0; j<N; j+=2){
			tab[0][j].setCell(0, j, Piece::QUEEN_BLACK);
			tab[N - 2][j].setCell(N - 2, j, Piece::QUEEN_GREEN);
			tab[2][j].setCell(2, j, Piece::QUEEN_BLACK);
			if (N >= 10) {
				tab[N - 4][j].setCell(N-4, j, Piece::QUEEN_GREEN);
			}
			
		}
		Piece vacio[20];
		
			for (int i = 0; i < 20; i++)
				PiezasSoplido[0][i] = vacio[i];
			for (int i = 0; i < 20; i++)
				PiezasSoplido[1][i] = vacio[i];




	}
	virtual ~Board(){
		//delete[] PiezasSoplido;
		for(int i=0; i<N; i++)
			delete [] tab[i];
		delete [] tab;
		
	}

	Board(Board& a ):turno(a.turno), movimientos(a.movimientos), N(a.N), estado(a.estado), blancas(a.blancas), negras(a.negras),pmovida(a.pmovida),cop(1) {

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 20; j++) {
				PiezasSoplido[i][j] = a.PiezasSoplido[i][j];
				}
			}

		
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

	
	virtual void setFicha(tipo_juego p) { this->variante = p; }
	virtual virtual tipo_juego getTipo() { return variante; }
	virtual int cambiarPosicion(int x,int y,int posicionx, int posiciony);
	virtual void pasoTurno(void);
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual int getSize(){return N;}
	virtual Piece** getTab(){return tab;}
	virtual est  estadoPartida(void);
	virtual void actualizarEstado(void);
	virtual int soplido(int ,int );
	virtual void estadSoplido(void);
	virtual Object::type_t getPieceType(int x, int y) { return tab[x][y].getType(); }
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
	virtual ~BoardIA(){}








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
			if (movimientos == 0 && turno==-1)
				pasoTurno();

			
			


		



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
			actualizarEstado();
			//estadSoplido();
		}
		if (turno == -1)
			moverIA();

	}


};
class BoardCheckers : public Board {
public:
	BoardCheckers(int a, tipo_juego b) :Board(a, b) {
		turno = -1;


	}
	
	virtual int cambiarPosicion(int x, int y, int posicionx, int posiciony);
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual void actualizarEstado(void);
	virtual void estadSoplido(void);
};




class BoardCheckersIA :public BoardCheckers {
protected:
	//int IA;
	Piece posiblesMovimientos[20];
	int posDeMover;
public:
	BoardCheckersIA(int a, tipo_juego b):BoardCheckers(a,b) {
			}
	/*BoardCheckersIA(BoardCheckersIA& a) :BoardCheckers(a) {
	}*/

	virtual void moverIA(void) {
	
			for (int i = 0; i < 20; i++) {
				int a, b;
				if (PiezasSoplido[1][i].getType() != Object::EMPTY_CELL) {
					PiezasSoplido[1][i].getCellNumber(a, b);
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
			if (movimientos == 0 && turno==1)
				pasoTurno();





		



	}

	virtual void Movimientos(void) {





		if (cop == 0) {
			Piece vacio[20];
			if (turno == 1) {
				for (int i = 0; i < 20; i++)
					posiblesMovimientos[i] = vacio[i];
			}
			int aux = 0;
			posDeMover = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < N; k++) {
						for (int l = 0; l < N; l++) {

							BoardCheckersIA copia(*this);

							if (copia.cambiarPosicion(i, j, k, l) == 1) {

								if ((turno == 1 && posDeMover > 0) && posiblesMovimientos[posDeMover - 1] == tab[i][j]) {
									posDeMover++;
									aux++;
									continue;
								}
								if (turno == 1)
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
		if (turno == 1)
			moverIA();

	}







};
class BoardItalianas : public BoardCheckers {
public:
	BoardItalianas(int a, tipo_juego b) :BoardCheckers(a, b) {
		turno = 1;
	}
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual void actualizarEstado(void);
	virtual void estadSoplido(void);

};
class BoardItalianasIA : public BoardItalianas {
	protected:
		//int IA;
		Piece posiblesMovimientos[20];
		int posDeMover;
	public:
		BoardItalianasIA(int a, tipo_juego b) :BoardItalianas(a, b) {
		}
		/*BoardItalianasIA(BoardItalianasIA& a) :BoardItalianas(a) {
		}*/

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
				if (movimientos == 0 && turno==-1)
					pasoTurno();
			
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

								BoardItalianasIA copia(*this);

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

class BoardPeruanas : public Board {
public:
	BoardPeruanas(int a, tipo_juego b) :Board(a, b) {
	}
	virtual ~BoardPeruanas() {};
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual void actualizarEstado(void);
	virtual void estadSoplido(void);


};
class BoardPeruanasIA : public BoardIA {
public:
	BoardPeruanasIA(int a, tipo_juego b) :BoardIA(a, b) {
	}

		virtual int comer(int x, int y, int posicionx, int posiciony);
		virtual void actualizarEstado(void);
		virtual void estadSoplido(void);














};

class BoardRusas : public Board {
protected: 
	virtual void reina(int posicionx, int posiciony);

public:
	BoardRusas(int a, tipo_juego b) :Board(a, b) {
	}

	



};
class BoardRusasIA : public BoardIA {
protected:
	virtual void reina(int posicionx, int posiciony);

public:
	BoardRusasIA(int a, tipo_juego b) :BoardIA(a, b) {
	}





};


class BoardEspañolas : public Board {
public:
	BoardEspañolas(int n, tipo_juego b) :Board(n, b) {
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

class BoardEspañolasIA:public BoardIA{
public:
	BoardEspañolasIA(int a, tipo_juego b) :BoardIA(a, b) {
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
class BoardTurcas: public Board {
public:
	BoardTurcas(int a, tipo_juego b) :Board(a, b) {}
	//BoardTurcas(BoardTurcas& a):Board(a){}
	virtual int comer(int x, int y, int posicionx, int posiciony);
	virtual int cambiarPosicion(int x, int y, int posicionx, int posiciony);
	virtual void estadSoplido(void);
	



};

#endif
