#pragma once

#include "boardgl.h"


class Coordinador{
public:
	
	Coordinador();
	virtual ~Coordinador();
	

	//void estadoPartida(est a);
	//est estadoPartida(void);
	//void cambiarPantallas(void);

	void Draw();
	void DrawGrid();
	void DrawCell(int i, int j);
	void KeyDown(unsigned char key);
	void SpecialKeyDown(unsigned char key);
	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);
	void cargarFondo();

	
protected:
	enum est { INICIO, VARIANTES, JUGANDO, VICTORIAB, DERROTAB, TABLAS };
	est estado;
	BoardGL boardgll;
	

};

