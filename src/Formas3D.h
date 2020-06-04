
#pragma once
#include <stdlib.h>
#include "glut.h"

class Formas3D
{
public:
    Formas3D();
    virtual~Formas3D();
    static void Cilindro(float, float,int ,int);
    static void Disco(float);
    static void Box(float x, float y, float z);
    static void Reina(int a, int  b, int);
    static void Esfera(float); 
    static void Base(float, int a, int b);
};


