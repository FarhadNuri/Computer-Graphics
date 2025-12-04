#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float X1=0.0f,Y1=0.0f,X2=0.0f,Y2=0.0f;

void line(float x0, float y0, float x1, float y1) {
    float m=(y1-y0)/(x1-x0);
    float x =x0,y = y0;

    if (abs(m)<= 1) {
        while (x<x1) {
            x+=1;
            y+=m;
            glVertex2f(x,y);
        }
    } else {
        while (y<y1) {
            y+=1;
            x+=(1.0 /m);
            glVertex2f(x, y);
        }
    }
}

void display(void) {
    glBegin(GL_POINTS);
    line(X1, Y1, X2, Y2);
    glEnd();
    glFlush();
}

void init(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {
    printf("Enter the value of the points");
    scanf("%f %f %f %f", &X1,&Y1,&X2,&Y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("___");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

return 0;
}
// -10 -20 35 32
