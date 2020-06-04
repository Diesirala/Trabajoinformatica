#include "Formas3D.h"
#include "glut.h"
#include "gltools.h"
// Construye un Cilindro



Formas3D::Formas3D() {

}



Formas3D::~Formas3D() {

}

/////////////////////////////////
// Construye la pieza Reina
void Formas3D::Reina(int a,int  b, int masoscuro)
{
    glPushMatrix();
    glScalef(0.020, 0.020, 0.040);
        Base(4.5,a,masoscuro);
        glTranslatef(0.0, 0.0, -1.0);
        Esfera(2);
        glPushMatrix();
            glTranslatef(0.0,0.0, -1.0);
            Cilindro(2.1, 0.5,a,b);
            glTranslatef(0.0, 0.0, -4.0);
            Cilindro(2.20,0.5,a,b);
            GLTools::Color(b);
            Esfera(1.6);
            glTranslatef(0.0, 0.0, -1.5);
            GLTools::Color(a);
            Esfera(0.5);
        glPopMatrix();
    glPopMatrix();
}



////////////////////

// Construye una Esfera
void Formas3D::Esfera(float radio)
{
    GLUquadricObj* qobj;
    qobj = gluNewQuadric();
    gluSphere(qobj, radio, 10, 10);
    gluDeleteQuadric(qobj);
}


// Construye la Base de las piezas
void Formas3D::Base(float altura, int a, int b)
{
   // glTranslatef(0.0, 0.0, -4.0);
    Cilindro(3.0, 1.0, a, b);
    glPushMatrix();
    glTranslatef(0.0, 0.0, -1.0);
    Cilindro(1.2, altura,a,b);
    glPopMatrix();
}

void Formas3D::Cilindro(float radio, float altura, int superior, int paredes)
{
    
        //color de las esferas solidas
        GLUquadricObj* qobj;
        // cilindro 
        
        GLTools::Color(paredes);
        glPushMatrix();
        glTranslatef(0.0, 0.0, -1.0);
        glPushMatrix();
        qobj = gluNewQuadric();
        glRotatef(180.0, 1.0, 0.0, 0.0);
        glTranslatef(0.0, 0.0, -1.0);
        gluCylinder(qobj, radio, radio , altura, 10, 10);
        gluDeleteQuadric(qobj);
        glPopMatrix();
        glPopMatrix();
       
        // tapa superior
        GLTools::Color(superior);
        glPushMatrix();
        glTranslatef(0.0, 0.0 ,-altura+.01);
        glRotatef(-90.0, 0.0, 0.0, 1.0);
        Disco(radio-.003);
        glPopMatrix();

        // tapa superior
        GLTools::Color(superior);
        glPushMatrix();
        glTranslatef(0.0, 0.0, -0.01);
        glRotatef(-90.0, 0.0, 0.0, 1.0);
        Disco(radio-0.003);
        glPopMatrix();
    
}






//// formas básicas

void Formas3D::Disco(float radio)
{
    GLUquadricObj* qobj;
    qobj = gluNewQuadric();
    gluDisk(qobj, 0.0, radio, 10, 10);
    gluDeleteQuadric(qobj);
}

///////////Construye una caja con un vertice en origen y otro en (x,y,z)
void Formas3D::Box(float x, float y, float z)
{
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glVertex3f(0.0f, 2.0f, 1.0f);
    glVertex3f(0.0f, 0, -1.0f);
    glEnd();
    glEnable(GL_LIGHTING);
}
///////////////////////////////////////////////