#pragma once

#include "boardgl.h"
#include "board.h"


 class Coordinador{
 protected:
	enum est { INICIO, VARIANTES, JUGANDO, VICTORIAB, DERROTAB, TABLAS };
	
public:
	 Board* a;

	 Coordinador():width(0.15), dist(2),center_z(0){
		 a = NULL;
		  est a = INICIO;
		 estado =a;
		
	};
	
	friend void OnMouseClick(int b, int state, int x, int y);

	//void estadoPartida(est a);
	//est estadoPartida(void);
	//void cambiarPantallas(void);
	//Initizalization
	 void init();						//enable lights
	 void Draw();
	 void KeyDown(unsigned char key);
	void SpecialKeyDown(unsigned char key);
	void MouseButton(int x, int y, int button, bool down, bool shiftKey, bool ctrlKey);
	/*static void OnMouseClick(int b, int state, int x, int y);
	static void OnDraw(void);
	static void OnKeyboardDown(unsigned char key, int x_t, int y_t);*/
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





	
protected:
	 est  estado;
	
	
	

};

