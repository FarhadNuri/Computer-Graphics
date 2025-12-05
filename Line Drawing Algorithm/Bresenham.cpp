#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>

int X1, Y1, X2, Y2;
void line(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx;
    if (x2>x1) sx=1;
    else sx=-1;

    int sy;
    if (y2>y1) sy=1;
    else sy=-1;


    glVertex2f((float)x1,(float)y1);

    if (dx >= dy) {
        int di=2*dy-dx;

        int x=x1;
        int y=y1;

        for (int i=0;i<dx;i++) {
            if (di<0) {
                x+=sx;
                di+=(2*dy);
            } else {
                x+=sx;
                y+=sy;
                di+=(2*(dy-dx));
            }
            glVertex2f((float)x,(float)y);
        }
    } else {
        int di=2*dx-dy;

        int x=x1;
        int y=y1;

        for (int i=0;i<dy;i++) {
            if (di<0) {
                y+=sy;
                di+=(2*dx);
            } else {
                x+=sx;
                y+=sy;
                di+=(2*(dx-dy));
            }
            glVertex2f((float)x,(float)y);
        }
    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POINTS);

    line(X1, Y1, X2, Y1);
    line(X2, Y1, X2, Y2);
    line(X2, Y2, X1, Y2);
    line(X1, Y2, X1, Y1);
    glEnd();
    glFlush();
}

void init(void) {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250, 250);
}

int main(int argc, char** argv) {
    printf("Enter the value of the points (X1 Y1 X2 Y2): ");
    if (scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2) != 4) {
        printf("Error reading input.\n");
        return 1;
    }

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Bresenham's Integer Line Algorithm (Fixed Structure)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

// -150 -100 100 50
/*

1 1 2 1
2 1 2 1
2 2 1 2
1 2 1 2

*/
