#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>


int r=0, xc=0, yc=0;

int X1=0, Y1=0, X2=0, Y2=0;
void midcirc(int r,int xc,int yc) {
    int p=1-r;
    int x=0,y=r;
    while(x<=y) {
        glVertex2f((float)xc+x,(float)yc+y);
        glVertex2f((float)xc+y,(float)yc+x);
        glVertex2f((float)xc-y,(float)yc+x);
        glVertex2f((float)xc-x,(float)yc+y);
        glVertex2f((float)xc-x,(float)yc-y);
        glVertex2f((float)xc-y,(float)yc-x);
        glVertex2f((float)xc+y,(float)yc-x);
        glVertex2f((float)xc+x,(float)yc-y);
        if(p<0) {
            x++;
            p=p+(2*x)+3;
        } else {
            x++;
            y--;
            p=p+2*(x-y)+5;
        }
    }
}

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
    glBegin(GL_POINTS);
    line(X1, Y1, X2, Y1);
    line(X2, Y1, X2, Y2);
    line(X2, Y2, X1, Y2);
    line(X1, Y2, X1, Y1);
    midcirc(r,xc,yc);

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
    printf("Enter the value of the circle: ");
    scanf("%d %d %d", &r,&xc,&yc);
    X1 = xc - r/2;
    Y1 = yc - r/2;
    X2 = xc + r/2;
    Y2 = yc + r/2;
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
/*

30 -5 -5
-20 -10  20 10

*/
