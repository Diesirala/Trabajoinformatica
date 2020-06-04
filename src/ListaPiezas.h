#pragma once
#pragma once

#define MAX_ESFERAS 24 // desde la pieza 12 se considerar� pieza m�quina, las anteriores ser� el jugador

#include "Piece.h"
#include "PiezaEspa�ola.h"
#include "PiezaPeruana.h"

class ListaPiezas
{
public:
    ListaPiezas(void);
    ~ListaPiezas(void);

    void mueve(float t);
    void dibuja();

    bool agregar(Piece* e);
    void eliminar(Piece* e);
    void eliminar(int index);
    void destruirContenido();
    void inicicializa(int x);
    int getNumero() { return numero; }
    Piece* operator[] (int index);
    int getMax() { return MAX_ESFERAS; }
private:

    Piece* lista[MAX_ESFERAS];
    //PiezaEspa�ola* PiezasEsp[MAX_ESFERAS];
    //PiezaPeruana* PiezasPer[MAX_ESFERAS];
    int numero;
};

