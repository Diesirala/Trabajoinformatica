
#include "gltools.h"

#include <iostream>
#include <string>

#include <glut.h>

 
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
using namespace gltools;


void GLTools::Color(int i,float transparency)
{	
	if (i == BLACK)		glColor4f(0, 0, 0, transparency);
	else if (i == WHITEP)glColor4f(0.86f, 0.86f, 0.86f, transparency);
	else if (i == WHITE)	glColor4f(1.0f, 1.0f, 1.0f, transparency);
	else if (i == RED)		glColor4f(0.65f, 0.2, 0.2, transparency);
	else if (i == RED_DARK)glColor4f(0.45, 0.2f, 0.2, transparency);
	else if (i == RED_DARK2)glColor4f(0.15, 0.0f, 0, transparency);
	else if (i == GREEN)	glColor4f(0.25, 0.4f, 0.1, transparency);
	else if (i == BLUE)	glColor4f(0.25, 0.25, 0.95f, transparency);
	else if (i == BLUE_DARK) glColor4f(0.2f, 0.2f, 0.70f, transparency);
	else if (i == BLUE_DARK2) glColor4f(0.12f, 0.12f, 0.7f, transparency);
	else if (i == MAGENTA)	glColor4f(1.0f, 0, 1.0f, transparency);
	else if (i == CYAN)	glColor4f(0.0f, 1.0f, 1.0f, transparency);
	else if (i == GREY)	glColor4f(0.78f, 0.78f, 0.78f, transparency);
	else if (i == GRIS_AZUL)	glColor4f(0.20f, 0.9f, 0.60f, transparency);
	else if (i == GRIS_AZUL_2)	glColor4f(0.20f, 0.75f, 0.60f, transparency);
	else if (i == GREEN_DARK) glColor4f(0.25, 0.7f, 0.1, transparency);
	else if (i == GREEN_DARK2) glColor4f(0.25, 0.25f, 0.1, transparency);
	else if (i == YELLOW)  glColor4f(0.75f, 0.75f, 0.25f, transparency);
	else if (i == ORANGE)  glColor4f(0.68f, 0.68f, 0.25f, transparency);
	else if (i == ORANGE_dark)  glColor4f(0.60f, 0.60f, 0.25f, transparency);
	else if (i == PURPLE)  glColor4f(0.3, 0.3, 1.0f, transparency);
	else if (i == PINK) 	glColor4f(0.0f, 0.3, 0.3f, transparency);
	else if (i == PINK_dark) 	glColor4f(0.8f, 0.3, 0.3f, transparency);
	else if (i == Grey_dark) glColor4f(0.15f, 0.15f, 0.15f, transparency);
	else if (i == Grey_dark2) glColor4f(0.08f, 0.08f, 0.08f, transparency);
	else if (i == MARRON) glColor4f(0.85f, 0.60f, 0.25f, transparency);
	else if (i == MARRON_DARK) glColor4f(0.70f, 0.50f, 0.25f, transparency);

}

void GLTools::BackgroundColor(int i)
{	
	if(i==BLACK)		glClearColor(0,0,0,0);
	else if(i==WHITE)	glClearColor(1.0f,1.0f,1.0f,0);
	else if(i==RED)		glClearColor(1.0f,0,0,0);
	else if(i==GREEN)	glClearColor(0,1.0f,0,0);
	else if(i==BLUE)	glClearColor(0,0,1.0f,0);
}

void GLTools::DrawGrid(int num_cells,float size)
{
	glEnable(GL_LIGHTING);

		Color(MAGENTA);


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

}

