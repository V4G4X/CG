#include<stdio.h>
#include<GL/freeglut.h>
#include<GL/gl.h>
#include<math.h>

int x1,yy1,x2,y2,x3,y3;

float round(float v)
{
	return (v+0.5);
}

void dda(int x1,int yy1,int x2,int y2 )
{
	int dx,dy,steps,k;
	float xinc,yinc,x,y;
	dx=x2-x1;
	dy=y2-yy1;
	x=x1;
	y=yy1;
	if(abs(dx)>abs(dy))
	{		
		steps=abs(dx);
	}	
	else
	{	
		steps=abs(dy);
	}
	xinc=dx/(float)steps;
	yinc=dy/(float)steps;
	
	for(k=0;k<steps;k++)
	{
		x=x+xinc;
		y=y+yinc;
		glBegin(GL_POINTS);
			glColor3f(k/500, 1.0, 1.0);
			glVertex2i(round(x),round(y));
		glEnd();
	}		
	glFlush();
}

void setpixel(int x,int y)
{
	glBegin(GL_POINTS);
	glColor3f(1.0, 1.0, 1.0);
	printf("\n10\n");
	glVertex2i(x,y);
	glEnd();
}

void bres(int x1,int yy1,int x2,int y2)
{
	printf("\n4\n");
	int a1,b1,a2,b2,da,db,p,a,b,ai,bi;
	if(abs(x2-x1)>abs(y2-yy1))
	{
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
	printf("\n5\n");
	if((a2-a1)<0)
	{
		ai=-1;
	}
	if((a2-a1)>0)
	{
		ai=1;
	}
	if((b2-b1)<0)
	{
		bi=-1;
	}
	if((b2-b1)>0)
	{
		bi=1;
	}
	da=abs(a2-a1);
	db=abs(b2-b1);
	p=2*db-da;
	int i=0;
	a=x1;
	b=yy1;
printf("\n6\n");
printf("\n%d\n",da-1);
	while(i<(da-1))
	{
		
		if(p<0)
		{
			printf("\n8\n");
			a+=ai;
			setpixel(a,b);
			p=p+(2*db);
			i++;
		}
		else
		{
			printf("\n9\n");
			a+=ai;
			b+=bi;
			setpixel(a,b);
			p=p+(2*db-2*da);
			i++;
		}
	}
glFlush();
printf("\n7\n");
}

void draw(int x1,int yy1,int x2,int y2)
{
	if(x1==x2||yy1==y2||abs(x2-x1)==abs(y2-yy1))
	{
		dda(x1,yy1,x2,y2);
	}
	else
	{
		bres(x1,yy1,x2,y2);
	}
}
void display()
{
	int x12,y12,x13,y13,x23,y23;
	x12=(x1+x2)/2;
	x13=(x1+x3)/2;
	x23=(x2+x3)/2;
	y12=(yy1+y2)/2;
	y13=(yy1+y3)/2;
	y23=(y2+y3)/2;
	draw(x1,yy1,x2,y2);
	draw(x2,y2,x3,y3);
	draw(x3,y3,x1,yy1);	
	draw(x12,y12,x23,y23);
	draw(x23,y23,x13,y13);
	draw(x13,y13,x12,y12);
	glFlush();
}
void myInit(void)
{
	printf("\n3\n");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,640,0,480);
}

int main(int argc, char** argv)
{
	printf("\nENTER THE VALUES FOR FIRST POINT:\nX co ordinate= ");	
	scanf("%d",&x1);
	printf("\nY co ordiante= \n");
	scanf("%d",&yy1);
	printf("\nENTER THE VALUES FOR SECOND POINT:\nX co ordinate= ");	
	scanf("%d",&x2);
	printf("\nY co ordiante= \n");
	scanf("%d",&y2);
	printf("\nENTER THE VALUES FOR THIRD POINT:\nX co ordinate= ");	
	scanf("%d",&x3);
	printf("\nY co ordiante= \n");
	scanf("%d",&y3);
	glutInit(&argc, argv);
	printf("\n1\n");
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(0,0);
	glutCreateWindow("IDIOCY");
	glutDisplayFunc(display);
	printf("\n2\n");	
	myInit();
	glutMainLoop();
	return 0;
}


//g++ bres.c -lglut -lGL -lGLEW -lGLU -o OpenGLExample
