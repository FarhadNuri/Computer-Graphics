#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>


int r=0, xc=0, yc=0;

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


void display(void) {
    glBegin(GL_POINTS);
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
    //printf("Enter the value of the points: ");
    //scanf("%f %f %f %f", &X1,&Y1,&X2,&Y2);
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
