#include<stdio.h>
#include<GL/freeglut.h>
#include<GL/gl.h>

int event;
void myInit(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);
	gluOrtho2D(0,800,450,0);
}

void initrect(){
	//Co-ordinate Lines
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2d(0,225);
	glVertex2d(800,225);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(1.0,1.0,1.0);
	glVertex2d(400,0);
	glVertex2d(400,450);
	glEnd();

	glColor3f(1.0f, 0.0f, 1.0f);
	glFlush();
}

void setpixel(int x,int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void swap(int *i, int *j){
	int c = *i;
	*i = *j;
	*j= c;
}

int rround(float v){
	return (int)(v+0.5);
}

void dda(int x1,int yy1,int x2,int y2 ){
	int dx,dy,steps,k;
	float xinc,yinc,x,y;
	dx=x2-x1;
	dy=y2-yy1;
	x=x1;
	y=yy1;
	if(abs(dx)>abs(dy)){		
		steps=abs(dx);
	}	
	else{	
		steps=abs(dy);
	}
	xinc=dx/(float)steps;
	yinc=dy/(float)steps;
	int c1=0;
	for(k=0;k<steps;k++){
		c1 = c1==24 ? 0 : c1 ;
		x=x+xinc;
		y=y+yinc;
		glBegin(GL_POINTS);
			if((c1>=0 && c1<13) || (c1>=18 && c1<20))
				glColor3f(1.0, 1.0, 1.0);
			else	glColor3f(0.0, 0.0, 0.0);
			glVertex2i(rround(x),rround(y));
			c1++;
		glEnd();
	}		
	glFlush();
}

void bres(int x1,int yy1,int x2,int y2){
	// printf("\n4\n");
	if(abs(x2-x1)<abs(y2-yy1)){	//Steep Slope
		dda(x1,yy1,x2,y2);
	}
	else{
		int a1,b1,a2,b2,da,db,p,a,b,ai,bi;
		if(abs(x2-x1)>abs(y2-yy1))	{
			a1=x1;
			a2=x2;
			b1=yy1;
			b2=y2;
		}
		else{
			a1=yy1;
			a2=y2;
			b1=x1;
			b2=x2;
			}
		if((a2-a1)<0){
			ai=-1;
		}
		if((a2-a1)>0){
			ai=1;
		}
		if((b2-b1)<0){
			bi=-1;
		}
		if((b2-b1)>0){
			bi=1;
		}
		da=abs(a2-a1);
		db=abs(b2-b1);
		p=2*db-da;
		int i=0;
		a=x1;
		b=yy1;
		// printf("\n%d\n",da-1);
		int c1=0;
		while(i<(da-1)){
			c1 = c1==24 ? 0 : c1 ;
			if((c1>=0 && c1<13) || (c1>=18 && c1<20))
				glColor3f(1.0, 1.0, 1.0);
			else	glColor3f(0.0, 0.0, 0.0);
			if(p<0){
				a+=ai;
				setpixel(a,b);
				p=p+(2*db);
			}
			else{
				a+=ai;
				b+=bi;
				setpixel(a,b);
				p=p+(2*db-2*da);
			}
			i++;
			c1++;
		}
	}
	glFlush();
}

void mouseDemo(int btn,int st,int x,int y){
	event++;
	if(event%2==0){
		// printf("\nEvent:%d\n",(event/2));
		// printf("x:%d\ty:%d\n",x,y);
		// printf("btn:%d\tst:%d\n",btn,st);
	}
	static int xst,yst,pt=0;

	
	if(btn==GLUT_LEFT_BUTTON&&st==GLUT_DOWN){
		if(pt==0){
			xst=x;
			yst=y;
			pt++;
		}
		else{
			bres(xst,yst,x,y);
			// glBegin(GL_LINES);
			// glVertex2i(xst,yst);
			// glVertex2i(x,y);
			// glEnd();
			xst=x;
			yst=y;
		}
	}
	else if(btn==GLUT_RIGHT_BUTTON&&st==GLUT_DOWN){
		pt=0;
	}
	glFlush();	
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800,450);
	glutInitWindowPosition(400,225);
	glutCreateWindow("Mock Mouse");
	myInit();
	glutDisplayFunc(initrect);
	glutMouseFunc(mouseDemo);
	glutMainLoop();
	return 0;
}
//g++ Mouse.c -lglut -lGL -lGLEW -lGLU -o OpenGLExample
