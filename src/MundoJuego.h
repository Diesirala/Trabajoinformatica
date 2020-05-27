#pragma once

#pragma once
#include "ListaPiezas.h"
//#include "Tablero.h"
class Mundo
    {
    private:
        enum tipodejuego { CHINA, ESPAN, PERUANA };
        tipodejuego tipo;
        ListaPiezas Piezas;
        //Tablero tab;
        float x_ojo;
        float y_ojo;
        float z_ojo;
        bool impacto;
        int nivel;
        int NumFichas;

    public:
        Mundo();
        ~Mundo();
        void tecla(unsigned char key);
        void teclaEspecial(unsigned char key);
        void inicializa(int);
        void rotarOjo();
        void mueve();
        void dibuja();
        bool getImpacto();
        void Limpiar();
 };







