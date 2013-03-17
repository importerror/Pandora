#include<glut.h>
//#include<stdlib.h>

void LineLoop(float x,float y)
{
	glColor3f(0.6,0.4,0.4);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x,y);
	glVertex2f(x+1,y);
	glVertex2f(x+1,y+1);
	glVertex2f(x,y+1);
	glEnd();
}

void square(float x,float y)
{
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
	glVertex2f(x+13,y);
	glVertex2f(x+13,y+13);
	glVertex2f(x,y+13);
	glEnd();
}

void drawstring(float x,float y,char *string)
{
	int i;
	glRasterPos2f(x,y);
	for(i=0;string[i]!='\0';i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	square(-7,-5);
	glColor3f(1,0,0);
	drawstring(0,0,"Welcome");
	glFlush();
}

void idle()
{
	glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)
{
	// float i;
	if(button==GLUT_LEFT_BUTTON) //&& state==GLUT_DOWN)
	{
		glClearColor(1,1,0,1);
		glColor3f(0.6,0.4,0.5);
		square(x,y);
	}
	else
	{	
		LineLoop(x,y);
	}
}

void reshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-10,10,-10*(float)h/(float)w,10*(float)h/(float)w,-10,10);
	else
		glOrtho(-10*(float)h/(float)w,10*(float)h/(float)w,-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
}

void main()
{
	glutInitWindowSize(1280,1024);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(0,10);
	glutCreateWindow("Welcome Screen");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutMainLoop();
}