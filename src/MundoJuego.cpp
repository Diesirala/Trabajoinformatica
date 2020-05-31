#include "MundoJuego.h"
#include<stdlib.h>
#include "glut.h"
#include <cmath>
#include <iostream>

using namespace std;
Mundo::Mundo() {

}

Mundo::~Mundo()
{
    //piezas.destruirContenido();
    //tablero.destruir
}

void Mundo::rotarOjo()
{
    float dist = sqrt(x_ojo * x_ojo + z_ojo * z_ojo);
    float ang = atan2(z_ojo, x_ojo);
    ang += 0.05f;
    x_ojo = dist * cos(ang);
    z_ojo = dist * sin(ang);
}

void Mundo::dibuja()
{
    gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
        0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
        0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

//aqui es donde hay que poner el codigo de dibujo
    Piezas.dibuja();
    tab.Draw();
}

void Mundo::mueve()
{
}

void Mundo::Limpiar() {
    Piezas.destruirContenido();
}

void Mundo::inicializa(int x)
{
    x_ojo = 0;
    y_ojo = 30;
    z_ojo = 20;


    int k = 0, b = 0, c = 0;

    //fichas en tablero 8*8, formacion básica
    for (int i = 0; i < Piezas.getMax(); i++) {//se pudiera generlizar entre uno de 10x10

        c = i + 1;
        if (i < 12) {//condición de fichas jugador
            if (x == ESPAN) {
                PiezaEspañola* e1 = new PiezaEspañola(1);
                e1->setCell(-7 + k, b - 8,1);
                Piezas.agregar(e1);
            }
            if (x == PERUANA) {
                PiezaPeruana* e1 = new PiezaPeruana(1);
                e1->setCell(-7 + k, b - 8,1);
                Piezas.agregar(e1);
            }
        }

        else {//condición fichas máquina
            if (x == ESPAN) {
                PiezaEspañola* e1 = new PiezaEspañola(2);
                e1->setCell(-7 + k, b - 8,2);
                Piezas.agregar(e1);
            }
            if (x == PERUANA) {
                PiezaPeruana* e1 = new PiezaPeruana(2);
                e1->setPos(-7 + k, b - 8,2);
                Piezas.agregar(e1);
            }
        }

        k = k + 4;

        if (c == 4 || c == 20) {
            k = 2;
            b = b + 2;
        }
        if (c == 8 || c == 16) {
            k = 0;
            b = b + 2;
        }
        if (c == 12) {
            k = 2;
            b = b + 6;
        }
    }
}

void Mundo::tecla(unsigned char key)
{
    /*switch (key)
    {
    case ' ':
    {

    }
    case 'z':
    {

    }
    case '1':

    case '2':

    case '3':

    case '4':

    }*/

}
void Mundo::teclaEspecial(unsigned char key)
{
    /*switch (key)
    {
    case GLUT_KEY_LEFT:

    case GLUT_KEY_RIGHT:

    }*/
}

bool Mundo::getImpacto() {
    return impacto;
}