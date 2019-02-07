#include<stdio.h>
#include<math.h>
#include<GL/freeglut.h>
#include<GL/gl.h>

void dda(int x0, int y0, int x1, int y1){
	int steps;
	float Xinc; float Yinc; float X,Y;
//DDA Calculation start
	int dx = x1-x0;
	int dy = y1-y0;
	steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	Xinc = dx/(float)steps;	
	Yinc = dy/(float)steps;
	X=x0;
	Y=y0;
//DDA Calculation end
	int i;
	glColor3f(0.0, 0.0, 0.0);
//	glOrtho(-1.0,1.0,-1.0, 1.0,1.0,-1.0);
   	glBegin(GL_POINTS);
	for(i=0 ; i<steps ; i++){
 		glVertex2i((int)X,(int)Y);
		X+=Xinc;
		Y+=Yinc;
	}
 	glEnd();
}

void axis(){
	dda(-750,0,750,0);
	dda(0,-750,0,750);
}

void renderF(void){
	gluOrtho2D(750,-750,750,-750);
	axis();
	
	//Diagonal Vertex 1
	int x1 = 500;
	int y1 = 500;
	//Diagonal Vertex 2
	int x2 = -500;
	int y2 = -500;
	
	int v = x1;
	int u = v/2;

	dda(-v,v,-v,-v);
	dda(-v,-v,v,-v);
	dda(v,-v,v,v);
	dda(v,v,-v,v);
	
	dda(-v,0,0,-v);
	dda(0,-v,v,0);
	dda(v,0,0,v);
	dda(0,v,-v,0);
	
	dda(-u,u,-u,-u);
	dda(-u,-u,u,-u);
	dda(u,-u,u,u);
	dda(u,u,-u,u);
	
	glFlush();
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Hello");

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(renderF);
	
	glutMainLoop();
	return 0;
}
