//Sabeel Kazi | Computer Graphics | Project 1-3
//mac command: g++ graphics.cpp -framework OpenGL -framework GLUT -Wno-deprecated-declarations
//#include <gl.h/glut.h>
#include <GLUT/glut.h>
    void myinit(void)
    {
        glClearColor(1.0,1.0,1.0,0.0);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D (0.0,580.0,0.0,580.0);
    }

    void squares(int height, int rShift){
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_QUADS);
            glVertex2i(rShift, height);                 //bottom left vertex
            glVertex2i(rShift, height+100);             //top left vertex
            glVertex2i(rShift+100, height+100);         //top right vertex
            glVertex2i(rShift+100, height);             //bottom right vertex
    }
    
    void render(void)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        glLineWidth(2);

        //draw squares accross a row & Column
        int rShift = 0;                             //pixels to shift to the right
        int height = 0;                             //pixel shifts in heights

        for(int i=0; i < 5; i++){
            for(int j=0; j < 5; j++){
                squares(height, rShift);
                rShift += 120;
            }
            rShift = 0;                                    //pixels to shift to the right, resets after ever outer loop
            height = height + 120;                         //height incremented on every outer loop
        }
        glEnd();
        glFlush();
    }

    int main(int argc, char** argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(50,100);
        glutInitWindowSize(580,580);            //box size 100 px, space is 20px
        glutCreateWindow("Hermann | Image 3");
        myinit();
        glutDisplayFunc(render);
        glutMainLoop();
    }