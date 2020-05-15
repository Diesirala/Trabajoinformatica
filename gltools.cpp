/**********************************************************************
 *
 * This code is part of the MRcore projec
 * Author:  -----------anyone
 *
 * MRcore is licenced under the Common Creative License,
 * Attribution-NonCommercial-ShareAlike 3.0
 *
 * You are free:
 *   - to Share - to copy, distribute and transmit the work
 *   - to Remix - to adapt the work
 *
 * Under the following conditions:
 *   - Attribution. You must attribute the work in the manner specified
 *     by the author or licensor (but not in any way that suggests that
 *     they endorse you or your use of the work).
 *   - Noncommercial. You may not use this work for commercial purposes.
 *   - Share Alike. If you alter, transform, or build upon this work,
 *     you may distribute the resulting work only under the same or
 *     similar license to this one.
 *
 * Any of the above conditions can be waived if you get permission
 * from the copyright holder.  Nothing in this license impairs or
 * restricts the author's moral rights.
 *
 * It is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied 
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  
 **********************************************************************/
#include "gltools.h"

#include <iostream>
#include <string>

#include <glut.h>

 
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
using namespace gltools;

std::vector<std::string> GLTools::textures_names;
std::vector<unsigned int> GLTools::textures_ids;

void GLTools::Color(int i,float transparency)
{	
	if(i==BLACK)		glColor4f(0,0,0,transparency);
	else if(i==WHITE)	glColor4f(1.0f,1.0f,1.0f,transparency);
	else if(i==RED)		glColor4f(1.0f,0,0,transparency);
	else if(i==GREEN)	glColor4f(0,1.0f,0,transparency);
	else if(i==BLUE)	glColor4f(0,0,1.0f,transparency);
	else if(i==MAGENTA)	glColor4f(1.0f,0,1.0f,transparency);
	else if(i==CYAN)	glColor4f(0.0f,1.0f,1.0f,transparency);
	else if(i==GREY)	glColor4f(0.5f,0.5f,0.5f,transparency);
	else if(i==YELLOW)  glColor4f(1.0f,1.0f,0.0f,transparency);
	else if(i==ORANGE)  glColor4f(1.0f,0.5f,0.0f,transparency);
	else if(i==PURPLE)  glColor4f(0.3,0.3,1.0f,transparency);
	else if(i==PINK) 	glColor4f(1.0f,0.3,0.3f,transparency);
	//if(i==VERDE)glColor3ub(0,255,0);
/*	if(i==VERDE)glColor3ub(155,75,70);//naranja
	if(i==AZUL)	glColor3ub(0,0,255);//magenta
	if(i==CYAN)	glColor3ub(0,255,255);//azul
	if(i==MAGENTA)glColor3ub(255,0,255);//blanco
	if(i==MAGENTA_SUAVE)glColor3ub(185,185,185);

	if(i==AMARILLO)glColor3ub(0,0,0);//blanco
	if(i==NARANJA)glColor3ub(50,255,100);//blanco
	if(i==GRIS1)glColor3ub(100,100,100);
	if(i==GRIS2)glColor3ub(150,150,150);*/
}

void GLTools::BackgroundColor(int i)
{	
	if(i==BLACK)		glClearColor(0,0,0,0);
	else if(i==WHITE)	glClearColor(1.0f,1.0f,1.0f,0);
	else if(i==RED)		glClearColor(1.0f,0,0,0);
	else if(i==GREEN)	glClearColor(0,1.0f,0,0);
	else if(i==BLUE)	glClearColor(0,0,1.0f,0);
}

void GLTools::Print(string msg, float x,float y,float z,int fuente){
//only considers two fonts, use switch for different fonts
//prints letters as bitmaps in HELVETICA FORMAT using basic
//glut size types (10,12,18)

	glDisable(GL_LIGHTING);
	int i;	int len=(int) msg.size();
	glRasterPos3f(x, y,z);

	switch(fuente){
	case 1:
		for (i = 0; i < len; i++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, msg[i]);
		}
	break;
	case 2:
		for (i = 0; i < len; i++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, msg[i]);
		}
	break;
	case 3:
		for (i = 0; i < len; i++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[i]);
		}
	break;
	default: //largest type
		for (i = 0; i < len; i++){
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, msg[i]);
		}
	}
	
	glEnable (GL_LIGHTING);

		
		//Texto
/*	glDisable (GL_LIGHTING);
	glColor3ub(255,255,255);
  	glRasterPos3f(x,y,z);
	glListBase (1000);
	glCallLists ((GLsizei)msg.size(), GL_UNSIGNED_BYTE, msg.c_str()); 
	glEnable (GL_LIGHTING);*/

/*	

	glMatrixMode(GL_TEXTURE);
	glPushMatrix();
	glLoadIdentity();

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
//	gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), 0, glutGet(GLUT_WINDOW_HEIGHT) );

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
	glColor3ub(r,g,b);
//	glRasterPos3f(x, glutGet(GLUT_WINDOW_HEIGHT)-18-y, 0);
	int len = strlen (mensaje );
//	for (int i = 0; i < len; i++) 
//		glutBitmapCharacter (GLUT_BITMAP_HELVETICA_18, mensaje[i] );
	
	
	glMatrixMode(GL_TEXTURE);
	glPopMatrix();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable( GL_DEPTH_TEST );*/
}
unsigned int GLTools::LoadTexture(string nombre)
{
	for(unsigned int i=0;i<textures_ids.size();i++)
	{
		if(textures_names[i]==nombre)
		{ 
			return textures_ids[i];
		}
	}

	unsigned int textura=-1;
	glGenTextures(1, &textura);
    glBindTexture(GL_TEXTURE_2D, textura);
/*	glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE );
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);    
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); */  
	
	int wrap=1;
	 // select modulate to mix texture with color for shading
   // glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE );
    glTexEnvf( GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    // when texture area is small, bilinear filter the closest mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST );
    // when texture area is large, bilinear filter the first mipmap
    glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,wrap ? GL_REPEAT : GL_CLAMP );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,wrap ? GL_REPEAT : GL_CLAMP );


	FILE *File=NULL;
#ifdef WIN32	
/*	File=fopen(nombre.c_str(),"r"); 
	AUX_RGBImageRec * mitex=NULL;
	if (File!=NULL) 
	{
		fclose(File);
		cout<<nombre<<" texture loaded"<<endl;
		mitex=auxDIBImageLoadA(nombre.c_str());	
	}
	else
	{
		cout<<"Texture file "<<nombre<<" not found"<<endl;
	}

	if(mitex!=NULL)
	{
		int ret=gluBuild2DMipmaps( GL_TEXTURE_2D, 4,
						mitex->sizeX, mitex->sizeY,GL_RGBA, GL_UNSIGNED_BYTE,mitex->data );
		delete mitex->data; 
		delete data;
        delete mitex; 
		textures_ids.push_back(textura);
		std::string cad(nombre);
		textures_names.push_back(cad);
	}*/
#endif
	return textura;
}

void GLTools::DeleteTextures()
{
	for(unsigned int i=0;i<textures_ids.size();i++)
	{
		glDeleteTextures(1,&textures_ids[i]); 
	}
	textures_ids.clear();
	textures_names.clear();
    glBindTexture(GL_TEXTURE_2D,NULL); 
}
void GLTools::DrawFrame()
{
	glDisable(GL_LIGHTING);
	glLineWidth(2);
	glBegin(GL_LINES);
		GLTools::Color(RED);
		glVertex3f(0,0,0);	glVertex3f(0.5,0,0);
		GLTools::Color(GREEN);
		glVertex3f(0,0,0);	glVertex3f(0,0.25,0);
		GLTools::Color(BLUE);
		glVertex3f(0,0,0);	glVertex3f(0,0,0.25);		
	glEnd();
	//label axis
	GLTools::Color(WHITE);
	GLTools::Print("x",0.6F,0,0);
	GLTools::Print("y",0.0,0.35F,0);
	GLTools::Print("z",0.0,0,0.35F);
	glEnable(GL_LIGHTING);
}

void GLTools::DrawGrid(int num_cells,float size)
{
	glEnable(GL_LIGHTING);
/*	static float an=2;
	static int nu=50;
	static int list=0;

	if(glIsList(list) && nu==num_celdas && an==ancho_celdas)
	{
		glCallList(list);
		return;
	}

	if(glIsList(list))
		glDeleteLists(list,1);

	list=glGenLists(1);	
	nu=num_celdas;
	an=ancho_celdas;

	glNewList(list,GL_COMPILE_AND_EXECUTE);*/
		//WORLD FRAME
		Color(MAGENTA);
	//	glNormal3i(0,0,1);
	/*	glLineWidth(3);
		glBegin(GL_LINE_STRIP);
					glVertex3i(0,2,0);	
					glVertex3i(0,0,0);
					glVertex3i(1,0,0);	
		glEnd();*/

		glLineWidth(1);		
		glBegin(GL_LINES); 
			glNormal3f(0,0,1);
			for(int i=0;i<num_cells;i++)
			{
				glVertex3f(i*size,-num_cells*size,0);
				glVertex3f(i*size,num_cells*size,0);			
				glVertex3f(-i*size,-num_cells*size,0);
				glVertex3f(-i*size,num_cells*size,0);			
		
				glVertex3f(-num_cells*size,i*size,0);
				glVertex3f(num_cells*size,i*size,0);				
				glVertex3f(-num_cells*size,-i*size,0);
				glVertex3f(num_cells*size,-i*size,0);				
			}
		glEnd();		
	
//	glEndList();
}

void GLTools::DrawGrid(int num_cells,float size, int col, float transparency)
{
	glEnable(GL_LIGHTING);
/*	static float an=2;
	static int nu=50;
	static int list=0;

	if(glIsList(list) && nu==num_celdas && an==ancho_celdas)
	{
		glCallList(list);
		return;
	}

	if(glIsList(list))
		glDeleteLists(list,1);

	list=glGenLists(1);	
	nu=num_celdas;
	an=ancho_celdas;

	glNewList(list,GL_COMPILE_AND_EXECUTE);*/
		//WORLD FRAME
		Color(col, transparency);
		//glNormal3i(0,0,1);
	/*	glLineWidth(3);
		glBegin(GL_LINE_STRIP);
					glVertex3i(0,2,0);	
					glVertex3i(0,0,0);
					glVertex3i(1,0,0);	
		glEnd();*/
		glLineWidth(1);
		glBegin(GL_LINES); 
			glNormal3f(0,0,1);
			for(int i=0;i<num_cells;i++){
				glVertex3f(i*size,-num_cells*size,0);
				glVertex3f(i*size,num_cells*size,0);	
							
				glVertex3f(-i*size,-num_cells*size,0);
				glVertex3f(-i*size,num_cells*size,0);	
						
				glVertex3f(-num_cells*size,i*size,0);
				glVertex3f(num_cells*size,i*size,0);	
					

				glVertex3f(-num_cells*size,-i*size,0);
				glVertex3f(num_cells*size,-i*size,0);		

			}
		glEnd();		
	
//	glEndList();
}

void GLTools::DrawExactGrid(int N, float size, int col, float transparency){
//////////////
// Draws an exact NxN grid centered in (0,0)
// N should be an even number

	glEnable(GL_LIGHTING);
	Color(col, transparency);

	glLineWidth(1);
	glBegin(GL_LINES); 
	int lim=N/2;

	for(int i=0;i<=lim;i++){
		//horizontales
		glVertex3f(lim*size,i*size,0);
		glVertex3f(-lim*size,i*size,0);

		glVertex3f(lim*size,-i*size,0);
		glVertex3f(-lim*size,-i*size,0);

		//verticales
		glVertex3f(i*size,-lim*size,0);
		glVertex3f(i*size,lim*size,0);

		glVertex3f(-i*size,-lim*size,0);
		glVertex3f(-i*size,lim*size,0);

	}
	glEnd();		
}