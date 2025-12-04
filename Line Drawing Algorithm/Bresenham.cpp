#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>


float X1=0.0f,Y1=0.0f,X2=0.0f,Y2=0.0f;

void line(float x1, float y1, float x2, float y2) {
    float m=(y2-y1)/(x2-x1);

    if(abs(m)<=1) {
        float dx=x2-x1;
        float dy=y2-y1;
        float di=2*dy-dx;

        glVertex2f(x1,y1);
        float x=x1;
        float y=y1;

        for (int i=0;i<dx;i++) {
            if (di<0) {
                x+=1;
                glVertex2f(x,y);
                di+=(2*dy);
            } else {
                x+=1;
                y+=1;
                glVertex2f(x,y);
                di+=(2*(dy-dx));
            }
            x1=x;
            y1=y;
        }
    } else {
        float dx=x2-x1;
        float dy=y2-y1;
        float di=2*dx-dy;

        glVertex2f(x1,y1);
        float x=x1;
        float y=y1;

        for (int i=0;i<dy;i++) {
            if (di<0) {
                y+=1;
                glVertex2f(x,y);
                di+=(2*dx);
            } else {
                x+=1;
                y+=1;
                glVertex2f(x,y);
                di+=(2*(dx-dy));
            }
            x1=x;
            y1=y;
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
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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
