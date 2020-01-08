//Sabeel Kazi | Computer Graphics | Project 1-1
//mac command: g++ graphics.cpp -framework OpenGL -framework GLUT -Wno-deprecated-declarations
//#include <gl.h/glut.h>
#include <GLUT/glut.h>
    void myinit(void)
    {
        glClearColor(1.0,1.0,1.0,0.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D (0.0,400.0,0.0,200.0);
    }
    
    void render(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLineWidth(1);
        glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINES);
            //draw the lines for the top of illUsion
            for(int i=-200; i <= 600; i += 20){         //INDEX IS OUTSIDE OF BOUNDARY FOR BETTER ILLUSION +/- 200px
                glVertex2i(199, 99);
                glVertex2i(i, 199);
            }
            //draw lines for the bottom of the illusion
            for(int i=-200; i <= 600; i += 20){
                glVertex2i(199, 99);
                glVertex2i(i, 0);
            }
            //change color of next lines to red
            glColor3f(1.0,0.0,0.0);

            //draw the 2 center lines 40 pixels above and below
                glVertex2i(0, 139);
                glVertex2i(399, 139);
                glVertex2i(0, 59);
                glVertex2i(399, 59);

        glEnd();
        glFlush();
    }

    int main(int argc,char** argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(50,100);
        glutInitWindowSize(400,200);
        glutCreateWindow("Hering | Image 1");
        myinit();
        glutDisplayFunc(render);
        glutMainLoop();
    }