//Sabeel Kazi | Computer Graphics | Project 1-4
//mac command: g++ graphics.cpp -framework OpenGL -framework GLUT -Wno-deprecated-declarations
//#include <gl.h/glut.h>
#include <GLUT/glut.h>
    void myinit(void)
    {
        glClearColor(0.40, 0.40, 0.40, 0.40);
        glMatrixMode(GL_PROJECTION);
        gluOrtho2D (0.0,1000.0,0.0,940.0);
    }

    void squares(int height, int rShift, int j){
        //shift color based on odd or even
        if(j % 2 == 1)
            glColor3f(0.0, 0.0, 0.0);
        else 
            glColor3f(1.0, 1.0, 1.0);

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

        for(int i=0; i < 9; i++){
            for(int j=0; j < 11; j++){
                squares(height, rShift, j);
                rShift += 100;
            }
            //change right shift for each row (hardcoded)
            switch(i){
                case 0:
                    rShift = -30;
                    break;
                case 1:
                    rShift = -60;
                    break;
                case 2:
                    rShift = -30;
                    break;
                 case 4:
                    rShift = -30;
                    break;
                case 5:
                    rShift = -60;
                    break;
                case 6:
                    rShift = -30;
                    break;
                default: 
                    rShift = 0;
            }
            height += 105;                         //height incremented on every outer loop
        }
        glEnd();
        glFlush();
    }

    int main(int argc, char** argv)
    {
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowPosition(50,100);
        glutInitWindowSize(1000,940);            //box size 100 px, space is 5px
        glutCreateWindow("Cafe Wall | Image 4");
        myinit();
        glutDisplayFunc(render);
        glutMainLoop();
    }