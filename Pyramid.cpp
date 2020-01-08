//Sabeel Kazi | Computer Graphics | Project 1-2
//mac command: g++ graphics.cpp -framework OpenGL -framework GLUT -Wno-deprecated-declarations
//#include <gl.h/glut.h>
#include <GLUT/glut.h>
    void myinit(void)
    {
        glClearColor(1.0,1.0,1.0,0.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D (0.0,1000.0,0.0,1000.0);
    }

    void squares(int start, int end, double color){
        glColor3f(color, color, color);
        glBegin(GL_QUADS);
            //length of square provided by the for loop
            glVertex2i(start, start);
            glVertex2i(end, start);
            glVertex2i(end, end);
            glVertex2i(start, end);
    }
    
    void render(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLineWidth(2);

        //draw squares until the sides have a length of one
        int i = 0;                                  //stores coordinate needed to draw square
        int j = 1000;                               //stores coordinate needed to draw square
        double k = 0.0;                             //will store the color of the square
        while(i< 500 && j > 0 ){                    //illusion is optimal with 500 iterations
            squares(i, j, k);
            i++;
            j--;
            k = k + (1.0/500.0);                   //squares will go from color black to white
        }
        glEnd();
        glFlush();
    }

    int main(int argc, char** argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(50,100);
        glutInitWindowSize(1000,1000);
        glutCreateWindow("Pyramid | Image 2");
        myinit();
        glutDisplayFunc(render);
        glutMainLoop();
    }