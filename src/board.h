//board.h: interface for the board class: contains only the logic of the game

#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include "piece.h"
#include "Enumeraciones.h"
#include <stdlib.h>
#include <time.h>
#include "ETSIDI.h"

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
	Board(int n):turno(1),movimientos(1) ,N(n),estado(JUGANDO),blancas((n / 2) * 3), negras((n / 2) * 3),variante(INTERNACIONAL),cop(0){
	
		
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
				tab[3][j].setCell(3, j, Piece::QUEEN_BLACK);
			}
			if (N >= 12) {
				tab[N - 5][j].setCell(N - 5, j, Piece::QUEEN_GREEN);
			}
		}

				
		for(int j=0; j<N; j+=2){
			tab[0][j].setCell(0, j, Piece::QUEEN_BLACK);
			tab[N - 2][j].setCell(N - 2, j, Piece::QUEEN_GREEN);
			tab[2][j].setCell(2, j, Piece::QUEEN_BLACK);
			if (N >= 10) {
				tab[N - 4][j].setCell(N-4, j, Piece::QUEEN_GREEN);
			}
			if (N >= 12) {
				tab[ 4][j].setCell( 4, j, Piece::QUEEN_BLACK);
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

#endif
