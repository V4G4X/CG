#include<stdio.h>
#include<math.h>
#include<GL/freeglut.h>
#include<GL/gl.h>

int main(int argc, char** argv){
	glutInit(argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bresenham Line");
	
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	 
}
