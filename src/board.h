//board.h: interface for the board class: contains only the logic of the game

#ifndef __BOARD_H__
#define __BOARD_H__

#include <iostream>
#include "piece.h"
#include "Enumeraciones.h"

using namespace std;

class Board{
public:
	
	//enum tipo_juego { ESPAN, PERUANA, RUSA, INGLESA };
protected:
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
	}

	~Board(){
		//delete[] PiezasSoplido;
		for(int i=0; i<N; i++)
			delete [] tab[i];
		delete [] tab;
		
	}

	Board(Board& a ):turno(a.turno), movimientos(a.movimientos), N(a.N), estado(a.estado), blancas(a.blancas), negras(a.negras),pmovida(a.pmovida) {

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

	
	void setFicha(tipo_juego p) { this->variante = p; }
	virtual tipo_juego getTipo() { return variante; }
	//void Board::tablas(int x, int y, int posicionx, int posiciony, int& posDeComer, int& posDeMover);
	int cambiarPosicion(int x,int y,int posicionx, int posiciony);
	void pasoTurno(void);
	int comer(int x, int y, int posicionx, int posiciony);
	int getSize(){return N;}
	Piece** getTab(){return tab;}
	est  estadoPartida(void);
	void actualizarEstado(void);
	int soplido(int ,int );
};

#endif