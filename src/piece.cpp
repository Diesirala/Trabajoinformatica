
#include "piece.h"


enum { WHITE, RED, GREEN, 
	GREEN_DARK, BLUE, 
	MAGENTA, CYAN, YELLOW, 
	ORANGE, PURPLE, PINK, GREY,
	BLACK, Grey_dark, BLUE_DARK, RED_DARK, GRIS_AZUL,GRIS_AZUL_2};

///esta será la encargada de dibujar la pieza segun la elección desde la pantalla inicial. Necesita de un Int 
//para ver que tipo es: 1.Pieza Jugador, 2. Pieza Máquina, 3. Reina Jugador, 4. Reina Máquina
void Piece::dibuja(int n) {
	if (n == 1) {
		if (pieza == ESPAN) {
			
			Formas3D::Cilindro(0.06, 0.05,WHITE,GREY);
			GLTools::Color(gltools::WHITE, 1.0f);//Cambiamos el color del tableroal poner esta declaración
		}
	
		else if (pieza == PERUANA) {
			Formas3D::Cilindro(0.06, 0.05,BLUE,BLUE_DARK);
			GLTools::Color(gltools::WHITE, 1.0f);
		}
		else if (pieza == INGLESA) {
			Formas3D::Cilindro(0.06, 0.05, RED,RED_DARK);
			GLTools::Color(gltools::WHITE, 1.0f);//Cambiamos el color del tableroal poner esta declaración
		}
		else if (pieza == RUSA) {
			Formas3D::Cilindro(0.06, 0.05,GRIS_AZUL,GRIS_AZUL_2 );
			GLTools::Color(gltools::WHITE, 1.0f);//Cambiamos el color del tableroal poner esta declaración
		}
	}
	else if (n == 2) {
		Formas3D::Cilindro(0.06, 0.05, 12, 13);
	}
	else if (n==3) {
		if (pieza == ESPAN) {
			Formas3D::Cilindro(0.06, 0.05, 0, 11);
		}
		else if (pieza == PERUANA) {
			Formas3D::Cilindro(0.06, 0.05, 4, 14);
		}
		else if (pieza == INGLESA) {
			Formas3D::Cilindro(0.06, 0.05, 1, 15);
		}
		else if (pieza == RUSA) {
			//Formas3D::Cilindro(0.06, 0.05);
		}
	} // caso reina JUGADOR

	else if(n==4)Formas3D::Cilindro(0.06, 0.05,1 , 15);//Reina negra
}