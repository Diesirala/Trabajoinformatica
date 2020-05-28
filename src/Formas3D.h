
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
};


