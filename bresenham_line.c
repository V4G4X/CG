#include<stdio.h>
#include<math.h>
#include<GL/freeglut.h>
#include<GL/gl.h>

typedef struct point{
	int x;
	int y;
	void scanner(){
		printf("Enter X-Coordinate: ");
		scanf("%d",&x);
		printf("Enter Y-Coordinate: ");
		scanf("%d",&y);
	}
	void midof(point p1, point p2){
		x=(p1.x + p2.x)/2;
		y=(p1.y + p2.y)/2;
	}
}point;



void swap(int *x,int *x1){
	int c = *x;
	*x = *x1;
	*x1 = c;
}

void axis(){
/*
	dda(-750,0,750,0);
	dda(0,-750,0,750);
	*/
}

void render(){
	gluOrtho2D(750,-750,750,-750);
	axis();
	point p1,p2,p3;
	printf("Point1:\n");
	p1.scanner();
	printf("Point2:\n");
	p2.scanner();
	printf("Point3:\n");
	p3.scanner();
	
	point p4,p5,p6;
	p4.midof(p1,p2);
	p5.midof(p2,p3);
	p6.midof(p3,p1);
	
	
	
	glFlush();
}

void bresen(point p1, point p2){

	
	
	
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glEnd();
}



int main(int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Bresenham Line");
	
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(render);
	 
	 glutMainLoop();
}	
