#include <GL/freeglut.h>
#include <GL/gl.h>
#include <math.h>
 
/*void renderFunction()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.75, 0.10, 0.25);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
	glVertex2f(0.75, 0.0);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}*/
/*
void drawarc(){
    //glColor3f(0.75, 0.10, 0.25);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
    	int i;
    	
    	for(i=0 ; i<120 ; i++){
		if(i==0)
			glColor3f(1.0, 01.0, 1.0);  
		else	if(i==118)  		
				glColor3f(1.0, 0.0, 0.0);  
		else
		    	glColor3f(0.75, 0.10, 0.25);
    		float x = cos(2.0 * 3.1415 * i/720.0);
    		float y = sin(2.0 * 3.1415 * i/720.0);
    		glVertex2f(x,y);
    	}
    	
    	glColor3f(0.25, 0.90, 0.75);
    	for(i=120 ; i<240 ; i++){
    		float x = cos(2.0 * 3.1415 * i/720.0);
    		float y = sin(2.0 * 3.1415 * i/720.0);
    		glVertex2f(x,y);
    	}
    glEnd();
    glFlush();
}*/

void drawcircle()
{
    glColor3f(0.75, 0.10, 0.25);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_POLYGON);
    	int i;
    	for(i=0 ; i<720 ; i++){
    	glColor3f(0.75, 0.10, 0.25);
    		float x = cos(2.0 * 3.1415 * i/720.0);
    		float y = sin(2.0 * 3.1415 * i/720.0);
    		if(i/240==0){
    			glColor3f(1.0, 0.0, 0.0);
    		}
    		else if(i/240==1){
    				glColor3f(0.0, 0.0, 1.0);
    		}
    		else if(i/240==2){
    				glColor3f(0.0,1.0,0.0);
    		}
    		glVertex2f(x,y);
    	}
    glEnd();
}

/*
void drawcircleborder()
{
    glColor3f(1.0, 1.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin(GL_LINE_LOOP);
 	int i;
    	for(i=0 ; i<720 ; i++){
    		float x = cos(2.0 * 3.1415 * i/720.0);
    		float y = sin(2.0 * 3.1415 * i/720.0);
    		glVertex2f(x,y);
    	}
    glEnd();
}

void drawmain(){
 	glClearColor(0.0, 0.0, 0.0, 0.0);
  	glClear(GL_COLOR_BUFFER_BIT);
	drawcircle();
	drawcircleborder();
	glFlush(); 	
}
*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - First window demo");
    glutDisplayFunc(drawcircle);
    glutMainLoop();    
    return 0;
}
