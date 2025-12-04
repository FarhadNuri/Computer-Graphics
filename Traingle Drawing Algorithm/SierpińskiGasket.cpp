#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

float X1,Y1,X2,Y2,X3,Y3;
int order;

void drawT(float x1,float y1,float x2,float y2,float x3,float y3){
    glColor3f(0.0f,0.0f,0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glEnd();
}


void SG(float x1,float y1,float x2,float y2,float x3,float y3,int n) {
    if (n>0) {
        float x12=(x1+x2)/2;
        float y12=(y1+y2)/2;
        float x13=(x1+x3)/2;
        float y13=(y1+y3)/2;
        float x23=(x2+x3)/2;
        float y23=(y2+y3)/2;

        SG(x1,y1,x12,y12,x13,y13,n-1);
        SG(x12,y12,x2,y2,x23,y23,n-1);
        SG(x13,y13,x23,y23,x3,y3,n-1);

    } else drawT(x1,y1,x2,y2,x3,y3);
}


void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    SG(X1,Y1,X2,Y2,X3,Y3,order);
    glEnd();
    glFlush();
}

void init(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv) {

    printf("Enter points (x1 y1 x2 y2 x3 y3): ");
    scanf("%f %f %f %f %f %f", &X1, &Y1, &X2, &Y2, &X3, &Y3);

    printf("Enter order n: ");
    scanf("%d", &order);

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
// -80 -60   80 -60   0 90
