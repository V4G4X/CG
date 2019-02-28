#include<stdio.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>

int event;

void myInit(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	gluOrtho2D(0,800,450,0);
	
}

void initrect(){
	//Rectangle 1	RED
	glBegin(GL_POLYGON);
	glColor3f(1.0,0.0,0.0);
	glVertex2i(0,0);
	glVertex2i(50,0);
	glVertex2i(50,50);
	glVertex2i(0,50);
	glEnd();
	//Rectangle 2	GREEN
	glBegin(GL_POLYGON);
	glColor3f(0.0,1.0,0.0);
	glVertex2i(60,0);
	glVertex2i(110,0);
	glVertex2i(110,50);
	glVertex2i(60,50);
	glEnd();
	//Rectangle 3	BLUE
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,1.0);
	glVertex2i(120,0);
	glVertex2i(170,0);
	glVertex2i(170,50);
	glVertex2i(120,50);
	glEnd();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	initrect();
	glFlush();
}

void mouseDemo(int btn,int st,int x,int y){
	event++;
	if(event%2==0){
		printf("\nEvent:%d\n",(event/2));
		printf("x:%d\ty:%d\n",x,y);
		printf("btn:%d\tst:%d\n",btn,st);
	}
	static int xst,yst,pt=0;
	//Change colour incase of palette event
	//Red Box
	if((x>0 && x<50)&& (y>0 && y<50))
		glColor3f(1.0,0.0,0.0);
	//Green Box
	else if((x>60 && x<110)&& (y>0 && y<50))
		glColor3f(0.0,1.0,0.0);
	//Blue Box
	else if((x>120 && x<170)&& (y>0 && y<50))
		glColor3f(0.0,0.0,1.0);
	
	else if(btn==GLUT_LEFT_BUTTON&&st==GLUT_DOWN){
		if(pt==0){
			xst=x;
			yst=y;
			pt++;
		//	glColor3f(1.0f, 0.0f, 1.0f);
		}
		else{
			glBegin(GL_LINES);
			glVertex2i(xst,yst);
			glVertex2i(x,y);
			glEnd();
			xst=x;
			yst=y;
		}
	}
	else if(btn==GLUT_RIGHT_BUTTON&&st==GLUT_DOWN){
		pt=0;
	}
	else if(btn==GLUT_MIDDLE_BUTTON && st==GLUT_DOWN){
		static int c=0;
		if(c==0){
			glColor3f(0.0f, 1.0f, 1.0f);
			c=1;
		}
		else{
			glColor3f(1.0f, 0.0f, 1.0f);
			c=0;
		}
	}
glFlush();	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,450);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Testing Mouse");
	myInit();
	glutDisplayFunc(display);
	glutMouseFunc(mouseDemo);
	glutMainLoop();
	return 0;
}


//g++ mouse.c -lglut -lGL -lGLEW -lGLU -o OpenGLExample
