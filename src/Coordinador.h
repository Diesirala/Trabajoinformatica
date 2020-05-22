#pragma once
#include <iostream>
#include "boardgl.h"
#include "glut.h"


class Coordinador{
public:
	enum est { INICIO=0, VARIANTES, JUGANDO, VICTORIAB, DERROTAB, TABLAS };
protected:
	est estado;






public:
	Coordinador() :estado(INICIO) {}

	void estadoPartida(est a) {
		estado = a;

	}


	est  estadoPartida(void){

		return estado;

	}
	void cambiarPantallas(void) {
		switch (estado)





		VARIANTES: {
		//if peruanas
		Board Logica(8);
		BoardGL (*Logica);



		}






	}

};

