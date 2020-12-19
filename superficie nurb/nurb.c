/* 
ALUNOS:
	Giulianno Giancarlo Latorraca
	Vinicius Henrique da Silva Souza
	
	Ciência da Computação
	
programa nurb.c
*/

/* 
	Este programa tem como objetivo desenhar uma matriz de superficie nurb
	igual a uma imagem que foi pedida no exercicio
*/

#include <stdlib.h>
#include <GL/glut.h>

//coordernadas para modelar a superficie nurb
GLfloat pontosNurb[4][4][3] = {
 {{-1.0, 1.3, -1.5}, {-0.5, 1.5,-1.5 }, {0.5, 1.5, -1.5 }, {1.5, 1.5,-1.0}}, 
 {{-1.0, 1.0, -0.5}, {-0.5, 1.5,-0.5 }, {0.5, 1.5, -0.5 }, {1.5, 1.0,-0.5}}, 
 {{-1.0, 1.0,  0.5}, {-0.5, 1.5, 0.5 }, {0.5, 1.5,  0.5 }, {1.5, 1.0, 0.5}},
 {{-1.0, 0.5,  1.5}, {-0.5, 1.0, 1.5 }, {0.5, 1.0,  1.5 }, {1.5, 0.5, 1.0}}
};

//for para criar as linhas da matriz da superficie nurb 5x8
void display(void)
{
   int a, b;

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glColor3f(0.0, 0.0, 0.0);
   glPushMatrix();
   glRotatef(25.0, 1.0, 1.0, 1.0);
   for (b = 0; b <= 5; b++) {
   	  glBegin(GL_LINE_STRIP);
      for (a = 0; a <= 30; a++)
         glEvalCoord2f((GLfloat)a/30, (GLfloat)b/5);
      glEnd();}
      for (b = 0; b <= 8; b++) {
      glBegin(GL_LINE_STRIP);
      for (a = 0; a <= 30; a++)
         glEvalCoord2f((GLfloat)b/8, (GLfloat)a/30);
      glEnd();
   }
   glPopMatrix();
   glFlush();
}

void init(void)
{
   glClearColor(1.0, 1.0, 1.0, 0.0);
   glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4,
           0, 1, 12, 4, &pontosNurb[0][0][0]);
   glEnable(GL_MAP2_VERTEX_3);
   glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_FLAT);
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= h)
      glOrtho(-4.0, 4.0, -4.0*(GLfloat)h/(GLfloat)w, 
               4.0*(GLfloat)h/(GLfloat)w, -4.0, 4.0);
   else
      glOrtho(-4.0*(GLfloat)w/(GLfloat)h, 
               4.0*(GLfloat)w/(GLfloat)h, -4.0, 4.0, -4.0, 4.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
