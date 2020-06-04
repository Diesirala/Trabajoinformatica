///////////////////////////////////////////////////
//////////////////////////////FUNCIONES SOBRECARGADAS DAMAS RUSAS, IGUALES QUE LAS CHECKERS SOLO QUE AL LLEGAR UN PEON A CONVERTIRSE EN DAMA NO PIERDE EL TURNO Y PUEDE SEGUIR REALIZANDO CAPTURAS O MOVIENDOSE
#include "BoardRusas.h"
void BoardRusas::reina(int posicionx, int posiciony)
{

	switch (tab[posicionx][posiciony].getType())
	{
	case Object::QUEEN_GREEN:
		tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_GREENR);


		break;
	case Object::QUEEN_BLACK:
		tab[posicionx][posiciony].setCell(posicionx, posiciony, Object::QUEEN_BLACKR);

		break;
	default:
		;
	}
	movimientos = 1;


}