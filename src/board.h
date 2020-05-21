//board.h: interface for the board class: contains only the logic of the game

#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include "piece.h"

using namespace std;

class Board{
public:
	enum est { JUGANDO, VICTORIAB, DERROTAB, TABLAS };

protected:
	const int N;		//NxN board
	Piece ** tab;
	int turno;
	int movimientos;
	est estado;
	int blancas = (N / 2) * 3;
	int negras = (N / 2) * 3;



	void reina(int posicionx, int posiciony);
	void cambiarEstado(void);

public:
	Board(int n):turno(1),movimientos(1) ,N(n),estado(JUGANDO){
		
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
	}

	~Board(){
		for(int i=0; i<N; i++)
			delete [] tab[i];
		delete [] tab;
	}





	void cambiarPosicion(int x,int y,int posicionx, int posiciony);
	void pasoTurno(void);
	void comer(int x, int y, int posicionx, int posiciony);
	int getSize(){return N;}
	Piece** getTab(){return tab;}
	est  estadoPartida(void);
};

#endif