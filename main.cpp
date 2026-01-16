#include <windows.h> // For Windows-specific functions
#include <GL/glut.h> // GLUT, includes glu.h and gl.h
#include<bits/stdc++.h>
using namespace std;

const float pi = 3.14159265358979323846;

const int width = 1280;
const int height = 720;


void init() {
    // Set up 2D orthographic viewing region
    glMatrixMode(GL_PROJECTION);      // Switch to the projection matrix
    glLoadIdentity();                 // Reset projection matrix
    gluOrtho2D(0.0, width, 0.0, height); // Set the 2D clipping area
}


///------GROUND------///
void ground() {
    double groundArr[28][2]={
        {0  ,0.0},
        {0  ,83.17},
        {50 ,93.38},
        {100,79.22},
        {200,79.53},
        {250,96.24},
        {300,103.68},
        {350,91.98},
        {400,83.08},
        {450,79.22},
        {500,77.93},
        {550,84.43},
        {600,99.19},
        {650,84.37},
        {700,94.66},
        {750,89.52},
        {800,84.75},
        {850,84.37},
        {900,95.95},
        {950,88.23},
        {1000,95.89},
        {1050,88.23},
        {1100,84.37},
        {1150,106.255},
        {1200,104.55},
        {1250,92.09},
        {1280,89.52},
        {1280,0}
    };

    // Grass layer (thin strip on top)
    glColor3f(0.0f, 0.6f, 0.0f);
    glBegin(GL_POLYGON);
        for(int x=0;x<28;x++){
            glVertex2d(groundArr[x][0],groundArr[x][1]+5);
        }
    glEnd();

    // Soil
    glColor3ub(74, 54, 30);
    glBegin(GL_POLYGON);
        for(int x=0;x<28;x++){
            glVertex2d(groundArr[x][0],groundArr[x][1]);
        }
    glEnd();
}

///----SKY----///
void sky(){
    double mnt1[28][2]={
        {0  ,0},
        {0  ,314},
        {50 ,332},
        {100,364},
        {200,398},
        {250,426},
        {300,415},
        {350,396},
        {400,373},
        {450,360},
        {500,352},
        {550,358},
        {600,378},
        {650,377},
        {700,364},
        {750,352},
        {800,346},
        {850,331},
        {900,321},
        {950,329},
        {1000,355},
        {1050,374},
        {1100,383},
        {1150,375},
        {1200,362},
        {1250,339},
        {1280,320},
        {1280,0}
    };

    double mnt2[28][2]={
        {0  ,0},
        {0  ,345},
        {50 ,353},
        {100,346},
        {200,358},
        {250,379},
        {300,377},
        {350,388},
        {400,412},
        {450,403},
        {500,387},
        {550,373},
        {600,350},
        {650,363},
        {700,373},
        {750,377},
        {800,367},
        {850,358},
        {900,336},
        {950,326},
        {1000,342},
        {1050,346},
        {1100,346},
        {1150,346},
        {1200,355},
        {1250,375},
        {1280,376},
        {1280,0}
    };
    // Gradient sky using horizontal strips
    glBegin(GL_QUADS);
        // Top band: from 720 down to 680
        glColor3ub(216, 224, 238); // very light blue
        glVertex2i(0, 720);
        glVertex2i(width, 720);

        glColor3ub(196, 209, 235); // slightly darker
        glVertex2i(width, 680);
        glVertex2i(0, 680);

        // Bottom band: from 680 down to 250
        glColor3ub(196, 209, 235); // lighter mid-tone
        glVertex2i(0, 680);
        glVertex2i(width, 680);

        glColor3ub(92, 144, 184);  // darker bottom
        glVertex2i(width, 250);
        glVertex2i(0, 250);

    glEnd();

     glColor3ub(169, 206, 235);
    glBegin(GL_POLYGON);
        for(int x=0;x<28;x++){
            glVertex2d(mnt2[x][0],mnt2[x][1]-10);
        }
    glEnd();

    glColor3ub(64, 93, 115);
    glBegin(GL_POLYGON);
        for(int x=0;x<28;x++){
            glVertex2d(mnt1[x][0],mnt1[x][1]-10);
        }
    glEnd();


}

///-----Building-----///
void building(){
}

void display() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);   // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT);  // Clear the color buffer (background)

    sky();
    ground();
    glFlush(); // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);

    /* Get screen size */
    int screenWidth  = glutGet(GLUT_SCREEN_WIDTH);
    int screenHeight = glutGet(GLUT_SCREEN_HEIGHT);

    /* Calculate center position */
    int posX = (screenWidth  - width)  / 2;
    int posY = (((screenHeight - height) / 2)-50);

    glutInitWindowSize(width, height);          // Set the window's initial width & height
    glutInitWindowPosition(posX, posY);        // Set the window's initial position
    glutCreateWindow("Air Attack"); // Create a window with the given title
    init();                                // Call your initialization function
    glutDisplayFunc(display);              // Register display callback handler
    glutMainLoop();                        // Enter the event-processing loop
    return 0;
}
