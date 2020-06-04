#pragma once

#include "boardgl.h"
#include "board.h"
#include "piece.h"
#include "Enumeraciones.h"
//enum tipo_juego { ESPAN, PERUANA, RUSA, INGLESA };
 class Coordinador{
 protected:
 public:

	~Coordinador();
	Board* a;     //PUNTERO A PARTE LOGICA SE CREA EN CREAR TABLERO
	BoardGL* scene;// PUNTERO AL DIBUJADO DEL TABLERO, SE CREA EN CREAR TABLERO
	
	 Coordinador():width(0.15), dist(2),center_z(0),tablero(0),estado(INICIO),variante(NONE){
		 a = NULL;
		 scene = NULL;	
		 dimensiones = 8;
	};
	
	friend void OnMouseClick(int b, int state, int x, int y);
	int getHayTablero(void) { return tablero; }
	
	//Initizalization
	void init();						//enable lights
	void Draw();
	void KeyDown(unsigned char key);
	void SpecialKeyDown(unsigned char key);
	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);
	void crearTablero(void);
	void Imagen(const char*);
	int getDimensiones() { return dimensiones; }
	//coord
	void cell2center(int cell_x, int cell_y, float& glx, float& gly) {
		//cell_x, cell_y are the board cell coordinates (upper left hand corner is (0,0))
		//glx, gly refer to the center of the cell(cell_x,cell_y) in world coordinates
		
		glx = cell_y * width + width / 2.0f;
		gly = -cell_x * width - width / 2.0f;
	}

	void world2cell(double x, double y, int& cell_x, int& cell_y) {
		//world coordinates to cell

		cell_x = (int)(abs(y / width));
		cell_y = (int)(x / width);
	}

	
protected:
	//visualization	
	float width;
	double center_x, center_y, center_z;
	double dist;
	
	//mouse	
	int xcell_sel, ycell_sel;			//cell selected with mouse

	//mouse+special-keys combination state events 
	bool controlKey;
	bool shiftKey;
	bool leftButton;
	bool rightButton;
	bool midButton;
	bool IA;
	
	est  estado;
	tipo_juego variante;
	
	int tablero; //1 SI SE HA CREADO EL TABLERO 0 SI NO SE HA CREADO
	int dimensiones;
	//tipo_juego variante;
};

