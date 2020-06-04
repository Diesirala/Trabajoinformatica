#include "ListaPiezas.h"


ListaPiezas::ListaPiezas(void)
{
    numero = 0;
    for (int i = 0; i < MAX_ESFERAS; i++)lista[i] = 0;
}


ListaPiezas::~ListaPiezas(void)
{

}

bool ListaPiezas::agregar(Piece* e)
{
    for (int i = 0; i < numero; i++)//para evitar que se añada una esfera ya existente
        if (lista[i] == e)
            return false;

    if (numero < MAX_ESFERAS)
        lista[numero++] = e;
    else
        return false;
    return true;
}

void ListaPiezas::dibuja()
{
    for (int i = 0; i < numero; i++)
        lista[i]->dibuja();
}

void ListaPiezas::mueve(float t)
{
    for (int i = 0; i < numero; i++)
       // lista[i]->mueve(t);
}


void ListaPiezas::eliminar(int index)
{
    if ((index < 0) || (index >= numero))
        return;

    delete lista[index];

    numero--;
    for (int i = index; i < numero; i++)
        lista[i] = lista[i + 1];

}

void ListaPiezas::eliminar(Piece* e)
{
    for (int i = 0; i < numero; i++)
        if (lista[i] == e)
        {
            eliminar(i);
            return;
        }

}

void ListaPiezas::destruirContenido()
{
    for (int i = 0; i < numero; i++) delete lista[i];
    numero = 0;
}

void ListaPiezas::inicicializa(int x) {
    //bool n;
    /*if (x == CHINA) {
        tipo = CHINA;

        Pieza* e1 = new Pieza();
        e1->setColor(0, 0, 255);
        n=lista->agregar(e1);
    }

    else if (x == ESPAN) {
        FichaDeJuego.setPos(0, 0);
        tipo = ESPAN;
        cout << "espann" << endl;
    }
    else if (x == PERUANA) {
        tipo = PERUANA;
        FichaPeruana;
    }*/
}