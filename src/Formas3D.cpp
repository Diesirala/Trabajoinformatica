#include "Formas3D.h"
#include "glut.h"
#include "gltools.h"
// Construye un Cilindro



Formas3D::Formas3D() {

}



Formas3D::~Formas3D() {

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
        Disco(radio-0.002);
        glPopMatrix();
    
}



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