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
	Coordinador();
	virtual ~Coordinador();

	void estadoPartida(est a) {
		estado = a;
	}
	est estadoPartida(void)
	{
		return estado;
	}


	void cambiarPantallas(void);

};

