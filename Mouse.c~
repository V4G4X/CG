#include<stdio.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>

void myInit(void)
{
		
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	gluOrtho2D(0,640,480,0);
}

void display()
{
	printf("\n2\n");
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void mouseDemo(int btn,int st,int x,int y)
{
	printf("\n%d  %d\n",x,y);
	static int xst,yst,pt=0;
	if(btn==GLUT_LEFT_BUTTON&&st==GLUT_DOWN)
	{
		if(pt==0)
		{
			xst=x;
			yst=y;
			pt++;
			printf("\n3\n");		
		}
		else{
			glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 1.0f);
			printf("\n4\n");			
			glVertex2i(xst,yst);
			glVertex2i(x,y);
			glEnd();
			xst=x;
			yst=y;
		}
	}
	else if(btn==GLUT_RIGHT_BUTTON&&st==GLUT_DOWN)
	{
		pt=0;
	}
glFlush();	
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(750,750);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Tom & Jerry");
	printf("\n1\n");
	glutDisplayFunc(display);
	glutMouseFunc(mouseDemo);
	myInit();
	glutMainLoop();
	return 0;
}


//g++ mouse.c -lglut -lGL -lGLEW -lGLU -o OpenGLExample
