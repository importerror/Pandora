#include<glut.h>
//#include<stdlib.h>
bool* keystates=new bool[256];
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
void cube()
{
	glColor3f(1,1,0.5);
	glTranslatef(0,0,-3.0);
	glutWireTeapot(3);
	glTranslatef(0,-10,0);

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,1,0);
	square(-7,-5);
	glColor3f(1,0,0);
	drawstring(0,0,"Welcome");
	cube();
	glFlush();
}
void idle()
{
}
void key(unsigned char keys,int x,int y)
{
	keystates[keys]=true;
	if(keys=='a')
	glClearColor(0,0,0,1);
	glutPostRedisplay();
}
void mouse(int button,int state,int x,int y)
{
	// float i;
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,0,1);
	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
	glClearColor(0.6,1,1,1);
	LineLoop(x,y);
	}
	glTranslatef(0,0,5.0);
	glutPostRedisplay();

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
	//gluPerspective(60, (float)w / (float)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char ** argv)
{
	glutInitWindowSize(1024,1024);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowPosition(0,10);
	glutInit(&argc,argv);
	glutCreateWindow("Welcome Screen");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	glutReshapeFunc(reshape);
	glutMainLoop();
}
}