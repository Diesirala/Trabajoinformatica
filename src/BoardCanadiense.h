#pragma once
#include "board.h"
#include <stdlib.h>
class BoardCanadiense :public Board {
public:
	BoardCanadiense() :Board(12) {
		variante = CANADIENSE;
	}



};