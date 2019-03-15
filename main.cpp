#include<windows.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <GL/glut.h>
#include <mmsystem.h>
#include <sstream>

using namespace std;

char name;
int goal=0;
bool end_game = false;
bool loadGame = true;
float _cameraAngle = 0.0;
float _angle = 0.0;
float _ang_tri = 0.0;
float yellowAudience=0.0;
float blueAudience = 0.0;
float danceMove = 0.0;
float triTemp = 0.0;
float triget = 0.0;
float ball_x= 0;
float ball_y=-6;
float ball_z=0;
float keeper_x =0;
float keeper_y=0;
float keeper_z=0;
float tricker_x=0;
float tricker_y=0;
float tricker_z=0;
bool kickRightCorner = false;
bool kickRight  = false;
bool kickLeftCorner = false;
bool kickLeft = false;
bool kickUp = false;
int counterSec = 0;
int keepercounterSec = 0;
int i;
int p1=0,p2=0;

bool goalsaveshow = false;
bool goalshow    = false;
bool greenLight1 = false;
bool greenLight2 = false;
bool greenLight3 = false;
bool greenLight4 = false;
bool greenLight5 = false;
bool redLight1 = false;
bool redLight2 = false;
bool redLight3 = false;
bool redLight4 = false;
bool redLight5 = false;
bool startgame = true;
bool greenLight2_1 = false;
bool greenLight2_2 = false;
bool greenLight2_3 = false;
bool greenLight2_4 = false;
bool greenLight2_5 = false;
bool redLight2_1 = false;
bool redLight2_2 = false;
bool redLight2_3 = false;
bool redLight2_4 = false;
bool redLight2_5 = false;

int countshoot = 0;
int movement =0;
int sound = 0;
int total_game[10]={0,0,0,0,0,0,0,0,0,0},t_G = 0;
bool turn = true;

void endGame();



//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float trickerRound = 0.0;


void drawText(char ch[],float xpos, float ypos,float zpos)//draw the text for score and game over
{
    int numofchar = strlen(ch);
    glLoadIdentity ();
    glRasterPos3f( xpos , ypos, zpos);
    for (i = 0; i <= numofchar - 1; i++)
    {

    glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ch[i]);//font used here, may use other font also
    }

}



//SKY SKY SKY SKY

//void score(){drawText("Score:", 1.5,0.8,-2.5);}
//audience

void player()
{
    //jersey
    glBegin(GL_QUADS);

    glVertex3f(-0.2,1.5,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(0.2,1.1,-1.5);
    glVertex3f(-0.2,1.1,-1.5);
    glEnd();


    ///////////mid//////////////
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
      glVertex3f(-0.1,1.5,-1.4);
    glVertex3f(0.1,1.5,-1.4);
    glVertex3f(0.1,1.0,-1.4);
    glVertex3f(-0.1,1.0,-1.4);
    glEnd();

    /////////////////////////
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
      glVertex3f(-0.01,1.5,-1.5);
    glVertex3f(0.01,1.5,-1.5);
    glVertex3f(0.01,1.2,-1.5);
    glVertex3f(-0.01,1.2,-1.5);
    glEnd();

    //face
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(-0.2,1.7,-1.5);
    glVertex3f(0.2,1.7,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(-0.2,1.5,-1.5);
    glEnd();

    //mouth
     glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.09,1.55,-1.4);
    glVertex3f(0.09,1.55,-1.4);
    glVertex3f(0.09,1.53,-1.4);
    glVertex3f(-0.09,1.53,-1.4);
    glEnd();

    //left sided eye
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.1,1.6,-1.4);
    glVertex3f(-0.05,1.6,-1.4);
    glVertex3f(-0.05,1.65,-1.4);
    glVertex3f(-0.1,1.65,-1.4);
    glEnd();

    //right sided eye

    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(0.1,1.6,-1.4);
    glVertex3f(0.05,1.6,-1.4);
    glVertex3f(0.05,1.65,-1.4);
    glVertex3f(0.1,1.65,-1.4);
    glEnd();

    //hair
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.2,1.7,-1.5);
    glVertex3f(0.2,1.7,-1.5);
    glVertex3f(0.2,1.9,-1.5);
    glVertex3f(-0.2,1.9,-1.5);
    glEnd();

    //left sided hand
  glBegin(GL_QUADS);
    glColor3f(0.576, 0.439, 0.859);
    glVertex3f(-0.2,1.10,-1.5);
    glVertex3f(-0.2,1.5,-1.5);
    glVertex3f(-0.3,1.5,-1.5);
    glVertex3f(-0.3,1.10,-1.5);
    glEnd();



    //left sided hand gloves
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(-0.2,1.1,-1.5);
    glVertex3f(-0.2,0.95,-1.5);
    glVertex3f(-0.3,0.95,-1.5);
    glVertex3f(-0.3,1.1,-1.5);
    glEnd();

    //right sided hand
    glBegin(GL_QUADS);
    glColor3f(0.576, 0.439, 0.859);
    glVertex3f(0.2,1.10,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(0.3,1.5,-1.5);
    glVertex3f(0.3,1.10,-1.5);
    glEnd();

    //right sided hand gloves
        glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(0.2,1.1,-1.5);
    glVertex3f(0.2,0.95,-1.5);
    glVertex3f(0.3,0.95,-1.5);
    glVertex3f(0.3,1.1,-1.5);
    glEnd();


    //pants
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-0.2,1.2,-1.5);
    glVertex3f(0.2,1.2,-1.5);
    glVertex3f(0.2,.9,-1.5);
    glVertex3f(-0.2,.9,-1.5);
    glEnd();

    //left sided leg

    glBegin(GL_QUADS);
    glColor3f(0.294, 0.000, 0.510);
    glVertex3f(-0.2,1.0,-1.5);
    glVertex3f(-0.1,1.0,-1.5);
    glVertex3f(-0.1,0.8,-1.5);
    glVertex3f(-0.2,0.8,-1.5);
    glEnd();

    //right sided leg
    glBegin(GL_QUADS);
    glColor3f(0.294, 0.000, 0.510);
    glVertex3f(0.2,1.0,-1.5);
    glVertex3f(0.1,1.0,-1.5);
    glVertex3f(0.1,0.8,-1.5);
    glVertex3f(0.2,0.8,-1.5);
    glEnd();

    //right sided boot
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(0.2,0.8,-1.5);
    glVertex3f(0.1,0.8,-1.5);
    glVertex3f(0.1,0.7,-1.5);
    glVertex3f(0.2,0.7,-1.5);
    glEnd();

    //left sided boot
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.2,0.8,-1.5);
    glVertex3f(-0.1,0.8,-1.5);
    glVertex3f(-0.1,0.7,-1.5);
    glVertex3f(-0.2,0.7,-1.5);
    glEnd();
    //glFlush();
}

void player1()
{
    //jersey
    glBegin(GL_QUADS);

    glVertex3f(-0.2,1.5,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(0.2,1.1,-1.5);
    glVertex3f(-0.2,1.1,-1.5);
    glEnd();




    /////////////////////////
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
      glVertex3f(-0.01,1.5,-1.5);
    glVertex3f(0.01,1.5,-1.5);
    glVertex3f(0.01,1.2,-1.5);
    glVertex3f(-0.01,1.2,-1.5);
    glEnd();

    //face
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(-0.2,1.7,-1.5);
    glVertex3f(0.2,1.7,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(-0.2,1.5,-1.5);
    glEnd();

    //mouth
     glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.09,1.55,-1.3);
    glVertex3f(0.09,1.55,-1.3);
    glVertex3f(0.09,1.53,-1.3);
    glVertex3f(-0.09,1.53,-1.3);
    glEnd();

    //left sided eye
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.1,1.6,-1.4);
    glVertex3f(-0.05,1.6,-1.4);
    glVertex3f(-0.05,1.65,-1.4);
    glVertex3f(-0.1,1.65,-1.4);
    glEnd();

    //right sided eye

    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(0.1,1.6,-1.4);
    glVertex3f(0.05,1.6,-1.4);
    glVertex3f(0.05,1.65,-1.4);
    glVertex3f(0.1,1.65,-1.4);
    glEnd();

    //hair
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.2,1.7,-1.5);
    glVertex3f(0.2,1.7,-1.5);
    glVertex3f(0.2,1.9,-1.5);
    glVertex3f(-0.2,1.9,-1.5);
    glEnd();

    //left sided hand
  glBegin(GL_QUADS);
    glColor3f(0.576, 0.439, 0.859);
    glVertex3f(-0.2,1.10,-1.5);
    glVertex3f(-0.2,1.5,-1.5);
    glVertex3f(-0.3,1.5,-1.5);
    glVertex3f(-0.3,1.10,-1.5);
    glEnd();



    //left sided hand gloves
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(-0.2,1.1,-1.5);
    glVertex3f(-0.2,0.95,-1.5);
    glVertex3f(-0.3,0.95,-1.5);
    glVertex3f(-0.3,1.1,-1.5);
    glEnd();

    //right sided hand
    glBegin(GL_QUADS);
    glColor3f(0.576, 0.439, 0.859);
    glVertex3f(0.2,1.10,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(0.3,1.5,-1.5);
    glVertex3f(0.3,1.10,-1.5);
    glEnd();

    //right sided hand gloves
        glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(0.2,1.1,-1.5);
    glVertex3f(0.2,0.95,-1.5);
    glVertex3f(0.3,0.95,-1.5);
    glVertex3f(0.3,1.1,-1.5);
    glEnd();


    //pants
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-0.2,1.2,-1.5);
    glVertex3f(0.2,1.2,-1.5);
    glVertex3f(0.2,.9,-1.5);
    glVertex3f(-0.2,.9,-1.5);
    glEnd();

    //left sided leg

    glBegin(GL_QUADS);
    glColor3f(0.294, 0.000, 0.510);
    glVertex3f(-0.2,1.0,-1.5);
    glVertex3f(-0.1,1.0,-1.5);
    glVertex3f(-0.1,0.8,-1.5);
    glVertex3f(-0.2,0.8,-1.5);
    glEnd();

    //right sided leg
    glBegin(GL_QUADS);
    glColor3f(0.294, 0.000, 0.510);
    glVertex3f(0.2,1.0,-1.5);
    glVertex3f(0.1,1.0,-1.5);
    glVertex3f(0.1,0.8,-1.5);
    glVertex3f(0.2,0.8,-1.5);
    glEnd();

    //right sided boot
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(0.2,0.8,-1.5);
    glVertex3f(0.1,0.8,-1.5);
    glVertex3f(0.1,0.7,-1.5);
    glVertex3f(0.2,0.7,-1.5);
    glEnd();

    //left sided boot
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.2,0.8,-1.5);
    glVertex3f(-0.1,0.8,-1.5);
    glVertex3f(-0.1,0.7,-1.5);
    glVertex3f(-0.2,0.7,-1.5);
    glEnd();
    //glFlush();
}


void audience()
{


    ////////////////////////////



    ////////////////////////////

    for( float s=-40.2;s<40;s+=.53)
    {
        float x=s+.01;
     s += .1;

    glPushMatrix();
    glColor3f(1.000, 0.871-x, 0.678+x);
    glScalef(.21,.21,.21);
    glTranslatef(s,13.0,-3.5);
    player1();
    glPopMatrix();

    s+=.1;
    }



}

void greenAudience()
{
     ////////////////////////////





    for( float s=-40.2;s<40;s+=.53)
    {
        float x=s+.01;
     s += .1;

    glPushMatrix();
    glColor3f(1.000-x, 0.871, 0.678+x);
    glScalef(.5,.5,.5);
    glTranslatef(s,5.8,-6.5);
    player1();
    glPopMatrix();

    s+=.1;
    }


    ////////////////////////////

}
void dancer()
{
       ////////////////////////////




    for( float s=-8.2;s<8;s+=.53)
    {
        float x=s+.01;
     s += .1;

    glPushMatrix();
    glColor3f(1.000-x, 0.871+x, 0.678);
    glScalef(.6,.6,.6);
    glTranslatef(s,3,-4.5);
    player1();
    glPopMatrix();

    s+=.1;
    }
}

//banner
void banner()
{

    //red banner
     glBegin(GL_QUADS);
    glColor3f(1, 0.000, 0.000);
    glVertex3f(-20,2,-2.5);
    glVertex3f(-15,2,-2.5);
    glVertex3f(-15,1.3,-2.5);
    glVertex3f(-20,1.3,-2.5);
    glEnd();
/*glPushMatrix();
glColor3f(1,1,1);
drawText("Press n to new game", -20,1.5,-2);
glPopMatrix();*/
    //blue banner
    glBegin(GL_QUADS);
    glColor3f(0.76, 0.559, 0.859);
    glVertex3f(-15,2,-2.5);
    glVertex3f(0,2,-2.5);
    glVertex3f(0,1.3,-2.5);
    glVertex3f(-15,1.3,-2.5);
    glEnd();

    //yellow banner
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0.000);
    glVertex3f(-2,2,-2.5);
    glVertex3f(12,2,-2.5);
    glVertex3f(12,1.3,-2.5);
    glVertex3f(-2,1.3,-2.5);
    glEnd();
    glFlush();


}


//SKY SKY SKY SKY
void sky()
{
       //sky starts here
    glBegin(GL_QUADS);
    glColor3f(0.251, 0.351, 0.451);
    glVertex3f(-10,5,-5.0);
    glVertex3f(12,5,-5.0);
    glVertex3f(12,1.7,-4.5);
    glVertex3f(-10,1.7,-4.5);
    glEnd();
    glFlush();

    //ends here sky
}

void field()
{



    glBegin(GL_QUADS);
    glColor3f(0.196, 0.804, 0.196);
    glVertex3f(-8.1,2.0,-3);
    glVertex3f(8.1,2.0,-3);
    glVertex3f(6,-3,0);
    glVertex3f(-6,-3,0);
    glEnd();



//white line on 2nd shape
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-8,0.85,-1.6);
    glVertex3f(8,0.85,-1.6);
    glVertex3f(8,0.9,-1.6);
    glVertex3f(-8,0.9,-1.6);
    glEnd();

//2nd shape
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-8,0,-1.6);
    glVertex3f(8,0,-1.6);
    glVertex3f(8,0.9,-1.6);
    glVertex3f(-8,0.9,-1.6);
    glEnd();


//white line on 3rd shape
    glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-4.0,-0.5,0);
    glVertex3f(4.0,-0.5,0);
    glVertex3f(4.0,-0.6,0);
    glVertex3f(-4.0,-0.6,0);
    glEnd();

//right line white
     glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex3f(4,-0.8,0);
    glVertex3f(4,0.88,-1.3);
    glVertex3f(4.1,0.88,-1.3);
    glVertex3f(4.1,-0.8,0);
    glEnd();

//left line white
     glBegin(GL_QUADS);
    glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-4,-0.8,0);
    glVertex3f(-4,0.88,-1.3);
    glVertex3f(-4.1,0.88,-1.3);
    glVertex3f(-4.1,-0.8,0);
    glEnd();

//3rd shape

    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-6,-0.5,0);
    glVertex3f(6,-0.5,0);
    glVertex3f(6,-1.7,0);
    glVertex3f(-6,-1.7,0);
    glEnd();

//4th shape
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-6,-2.4,0);
    glVertex3f(6,-2.4,0);
    glVertex3f(6,-3,0);
    glVertex3f(-6,-3,0);
    glEnd();

    glFlush ();

}


void goalpost()
{
    /////////Vertical fence

     for(float s=-7.15;s<7;s+=.8)
    {
    s += .1;

      glBegin(GL_LINES);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(s,4.5,-4.5);
    glVertex3f(s,4.1,-4.5);
    glEnd();
    glFlush();
    s+=.1;
    }

    //////Horizontal fence

      glBegin(GL_LINES);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-9.2,4.5,-4.5);
    glVertex3f(9.2,4.5,-4.5);
    glEnd();
    glFlush();


//////////////////



/////////////////

    //////SUN

    glPushMatrix();

    glTranslatef(-5.19,4.7,-4.4);
    glColor3f(.995,.25,0);
    glutSolidSphere(.1,50,50);
    glPopMatrix();
//1st row seat
 glBegin(GL_LINES);
     glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-9.2,4.2,-4.5);
    glVertex3f(9.2,4.2,-4.5);
    glEnd();
    glFlush();

//2nd row seat
 glBegin(GL_LINES);
     glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-9.2,3.5,-4.5);
    glVertex3f(9.2,3.5,-4.5);
    glEnd();
    glFlush();
    //3nd row seat
 glBegin(GL_LINES);
     glColor3f(1.000, 1.000, 1.000);
    glVertex3f(-9.2,2.8,-4.5);
    glVertex3f(9.2,2.8,-4.5);
    glEnd();
    glFlush();
    //banner
     glBegin(GL_QUADS);
    glColor3f(1, 0.000, 0.000);
    glVertex3f(-9.5,2,-2.5);
    glVertex3f(9.5,2,-2.5);
    glVertex3f(9.5,1.3,-2.5);
    glVertex3f(-9.5,1.3,-2.5);
    glEnd();
    //banner2


    //sky
      glBegin(GL_QUADS);
    glColor3f(0.650, 0.750, .960);
    glVertex3f(-9.5,6,-4.5);
    glVertex3f(9.5,6,-4.5);
    glVertex3f(9.5,4.2,-4.5);
    glVertex3f(-9.5,4.2,-4.5);
    glEnd();

    //boarder 1
     glBegin(GL_QUADS);
    glColor3f(0.380, 0.490, .430);
    glVertex3f(-9.5,3.5,-4.55);
    glVertex3f(9.5,3.5,-4.55);
    glVertex3f(9.5,4,-4.55);
    glVertex3f(-9.5,4,-4.55);
    glEnd();
     //boarder 2
     glBegin(GL_QUADS);
    glColor3f(0.380, 0.490, .430);
    glVertex3f(-9.5,2.8,-4.55);
    glVertex3f(9.5,2.8,-4.55);
    glVertex3f(9.5,2.4,-4.55);
    glVertex3f(-9.5,2.4,-4.55);
    glEnd();



//left behind stand
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-2.9,2.7,-2);
    glVertex3f(-3,2.7,-2);
    glVertex3f(-3,1.2,-2);
    glVertex3f(-2.9,1.2,-2);
    glEnd();
//right behind stand

     glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(2.9,2.7,-2);
    glVertex3f(3,2.7,-2);
    glVertex3f(3,1.2,-2);
    glVertex3f(2.9,1.2,-2);
    glEnd();
//top behind stand
        glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-3,2.7,-2);
    glVertex3f(3,2.7,-2);
    glVertex3f(3,2.8,-2);
    glVertex3f(-3,2.8,-2);
    glEnd();
//left front side bar
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
//glPointSize(100.0);
    glVertex3f(-3,2.8,-1.5);
    glVertex3f(-3.12,2.8,-1.5);
    glVertex3f(-3.12,0.9,-1.5);
    glVertex3f(-3,0.9,-1.5);
    glEnd();

//right front side bar

    glBegin(GL_QUADS);
    glColor3f(0,0,0);
//glPointSize(100.0);
    glVertex3f(3,2.8,-1.5);
    glVertex3f(3.12,2.8,-1.5);
    glVertex3f(3.12,0.9,-1.5);
    glVertex3f(3,0.9,-1.5);
    glEnd();

//top front bar
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
//glPointSize(100.0);
    glVertex3f(-3.12,2.8,-1.5);
    glVertex3f(3.12,2.8,-1.5);
    glVertex3f(3.12,2.9,-1.5);
    glVertex3f(-3.12,2.9,-1.5);
    glEnd();

//right upper corner
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
//glPointSize(100.0);
    glVertex3f(3,2.9,-1.5);
    glVertex3f(3.12,2.9,-1.5);
    glVertex3f(3,2.7,-2);
    glVertex3f(2.9,2.7,-2);
    glEnd();
// left upper corner
      glBegin(GL_QUADS);
    glColor3f(0,0,0);
//glPointSize(100.0);
    glVertex3f(-3,2.9,-1.5);
    glVertex3f(-3.12,2.9,-1.5);
    glVertex3f(-3,2.7,-2);
    glVertex3f(-2.9,2.7,-2);
    glEnd();
//left lower corner
      glBegin(GL_QUADS);
    glColor3f(0,0,0);
//glPointSize(100.0);
    glVertex3f(-3,0.9,-1.5);
    glVertex3f(-3.12,0.9,-1.5);
    glVertex3f(-3,1.2,-2);
    glVertex3f(-2.9,1.2,-2);
    glEnd();

         glBegin(GL_QUADS);
    glColor3f(0,0,0);
//glPointSize(100.0);
    glVertex3f(3,0.9,-1.5);
    glVertex3f(3.12,0.9,-1.5);
    glVertex3f(3,1.2,-2);
    glVertex3f(2.9,1.2,-2);
    glEnd();
 //upper net


    float t=-1.5;
    float y=-1.5;

    {
    y=t-.01;
      glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3,2.8,t);
    glVertex3f(3,2.8,t);
    glVertex3f(3,2.81,y);
    glVertex3f(-3,2.81,y);
    glEnd();
    glFlush();
    t-=.01;
    }
 //left net



//ends upper net

    glFlush();

}
void net()
{
  //net behind vertical
      float c=-2.9;
    float v=-2.9;
    for(v;v<2.9;v += 0.2)
    {
        c=v+0.01;
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(v,2.7,-2);
    glVertex3f(c,2.7,-2);
    glVertex3f(c,1.2,-2);
    glVertex3f(v,1.2,-2);

    glEnd();
    glFlush();
      v=v+.01;
    }

    float b=1.2;
    float n=1.2;

    //net horizental
    for(b;b<2.69;b += 0.1)
    {

    n=b+0.01;

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3,b,-2);
    glVertex3f(3,b,-2);
    glVertex3f(3,n,-2);
    glVertex3f(-3,n,-2);
    glEnd();
    glFlush();
    b=b+0.01;

    }

       glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3,1.1,-1.5);
    glVertex3f(-3.01,1.1,-1.5);
    glVertex3f(-3.01,1.3,-2);
    glVertex3f(-3,1.3,-2);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3,1.4,-1.5);
    glVertex3f(-3.01,1.4,-1.5);
    glVertex3f(-3.01,1.6,-2);
    glVertex3f(-3,1.6,-2);
    glEnd();


    //
        glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(-3,1.7,-1.5);
    glVertex3f(-3.01,1.7,-1.5);
    glVertex3f(-3.01,1.9,-2);
    glVertex3f(-3,1.9,-2);
    glEnd();

    //
        glBegin(GL_QUADS);
    glColor3f(01,1,1);

    glVertex3f(-3,1.13,-1.5);
    glVertex3f(-3.01,1.13,-1.5);
    glVertex3f(-3.01,1.13,-2);
    glVertex3f(-3,1.13,-2);
    glEnd();

    //
        glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(-3,2.1,-1.5);
    glVertex3f(-3.01,2.1,-1.5);
    glVertex3f(-3.01,2.1,-2);
    glVertex3f(-3,2.1,-2);
    glEnd();

         glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(-3,2.3,-1.5);
    glVertex3f(-3.01,2.3,-1.5);
    glVertex3f(-3.01,2.3,-2);
    glVertex3f(-3,2.3,-2);
    glEnd();

             glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3,2.5,-1.5);
    glVertex3f(-3.01,2.5,-1.5);
    glVertex3f(-3.01,2.5,-2);
    glVertex3f(-3,2.5,-2);
    glEnd();

    /////////////left net ends////////////


    //////////////Right net starts//////////

           glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(3,1.1,-1.5);
    glVertex3f(3.01,1.1,-1.5);
    glVertex3f(3.01,1.3,-2);
    glVertex3f(3,1.3,-2);
    glEnd();

        glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(3,1.4,-1.5);
    glVertex3f(3.01,1.4,-1.5);
    glVertex3f(3.01,1.6,-2);
    glVertex3f(3,1.6,-2);
    glEnd();


    //
        glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(3,1.7,-1.5);
    glVertex3f(3.01,1.7,-1.5);
    glVertex3f(3.01,1.9,-2);
    glVertex3f(3,1.9,-2);
    glEnd();

    //
        glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(3,1.13,-1.5);
    glVertex3f(3.01,1.13,-1.5);
    glVertex3f(3.01,1.13,-2);
    glVertex3f(3,1.13,-2);
    glEnd();

    //
        glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(3,2.1,-1.5);
    glVertex3f(3.01,2.1,-1.5);
    glVertex3f(3.01,2.1,-2);
    glVertex3f(3,2.1,-2);
    glEnd();

         glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(3,2.3,-1.5);
    glVertex3f(3.01,2.3,-1.5);
    glVertex3f(3.01,2.3,-2);
    glVertex3f(3,2.3,-2);
    glEnd();

             glBegin(GL_QUADS);
    glColor3f(0,0,0);

    glVertex3f(3,2.5,-1.5);
    glVertex3f(3.01,2.5,-1.5);
    glVertex3f(3.01,2.5,-2);
    glVertex3f(3,2.5,-2);
    glEnd();
    ////////////////right net ends//////////////////////


    glFlush();

}

void football()
{
     glPushMatrix();
    glColor3f(0,0,0);
    glutSolidSphere(1.02,10,10);
    glPopMatrix();
     glPushMatrix();
     glColor3f(1,1,1);
    glutSolidSphere(1.1,5,5);
    glPopMatrix();
}

void football1()
{
     glPushMatrix();
    glColor3f(0.76, 0.559, 0.859);
    glutSolidSphere(1.02,10,10);
    glPopMatrix();
     glPushMatrix();
     glColor3f(1,1,0);
    glutSolidSphere(1.1,5,5);
    glPopMatrix();


}
void lightBar()
{
    glPushMatrix();
     glColor3f(1,1,0);

       drawText("Player ----1", 1,.5,-2);
    glPopMatrix();
     glBegin(GL_QUADS);
    glColor3f(1, 1, 1);

    glVertex3f(4,2.8,-1.5);
    glVertex3f(5.7,2.8,-1.5);
    glVertex3f(5.7,2.4,-1.5);
    glVertex3f(4,2.4,-1.5);
    glEnd();
    glFlush();

}
//1rst green light
void greenLight11()
{

   glPushMatrix();
   glTranslatef(4.1,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}

//2nd green light
void greenLight22()
{

   glPushMatrix();
   glTranslatef(4.4,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();

}
//3rd greenlight
void greenLight33()
{
      glPushMatrix();
   glTranslatef(4.7,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//4th greenlight
void greenLight44()
{
       glPushMatrix();
   glTranslatef(5,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//5th greenlight

void greenLight55()
{
       glPushMatrix();
   glTranslatef(5.3,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}

void redLight11()
{
       glPushMatrix();
   glTranslatef(4.1,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}

//red
void redLight22()
{
     glPushMatrix();
   glTranslatef(4.4,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//3rd redlight
void redLight33()
{
      glPushMatrix();
   glTranslatef(4.7,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//4th redlight
void redLight44()
{
       glPushMatrix();
   glTranslatef(5,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//5th redlight

void redLight55()
{
        glPushMatrix();
   glTranslatef(5.3,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}

void lightBar_2()
{
      glPushMatrix();
     glColor3f(0.576, 0.439, 0.859);
      drawText("Player ----2", -1.3,.5,-2);
       glPopMatrix();
     glBegin(GL_QUADS);
    glColor3f(1,1,1);

    glVertex3f(-4,2.8,-1.5);
    glVertex3f(-5.7,2.8,-1.5);
    glVertex3f(-5.7,2.4,-1.5);
    glVertex3f(-4,2.4,-1.5);
    glEnd();
    glFlush();

}
//1rst green light
void greenLight11_2()
{
          glPushMatrix();
   glTranslatef(-4.1,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}

//2nd green light
void greenLight22_2()
{
         glPushMatrix();
   glTranslatef(-4.4,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//3rd greenlight
void greenLight33_2()
{
           glPushMatrix();
   glTranslatef(-4.7,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//4th greenlight
void greenLight44_2()
{
           glPushMatrix();
   glTranslatef(-5,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//5th greenlight

void greenLight55_2()
{
          glPushMatrix();
   glTranslatef(-5.3,2.6,-1.4);
    glColor3f(0, 1, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}

void redLight11_2()
{
           glPushMatrix();
   glTranslatef(-4.1,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}

//red
void redLight22_2()
{
           glPushMatrix();
   glTranslatef(-4.4,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//3rd redlight
void redLight33_2()
{
         glPushMatrix();
   glTranslatef(-4.7,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//4th redlight
void redLight44_2()
{
           glPushMatrix();
   glTranslatef(-5,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}
//5th redlight

void redLight55_2()
{
          glPushMatrix();
   glTranslatef(-5.3,2.6,-1.4);
    glColor3f(1, 0, 0);
    glutSolidSphere(.1,100,100);


    glPopMatrix();
}

void goalkeeper()
{
    //jersey
    glBegin(GL_QUADS);
    if((countshoot%2==0 && movement ==0) || (countshoot%2 == 1 && movement == 1))
        {
            glColor3f(0.576, 0.439, 0.859);
          // if(countshoot%2 != 0 && movement==1){ glColor3f(0.000, 1, 0);}
        }
    else if ((countshoot%2 != 0 && movement == 0) || (countshoot%2 == 0 && movement == 1))
        {
            glColor3f(1.000, 1.000, 0.000);
          //  if(movement==1 && countshoot%2 == 0){glColor3f(1.000, 1.000, 0.000);}
        }
    glVertex3f(-0.2,1.5,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(0.2,1.1,-1.5);
    glVertex3f(-0.2,1.1,-1.5);
    glEnd();


    ///////////mid//////////////
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
      glVertex3f(-0.1,1.5,-1.4);
    glVertex3f(0.1,1.5,-1.4);
    glVertex3f(0.1,1.0,-1.4);
    glVertex3f(-0.1,1.0,-1.4);
    glEnd();
    /////////////////////////
     glBegin(GL_QUADS);
    glColor3f(0,0,0);
      glVertex3f(-0.01,1.5,-1.5);
    glVertex3f(0.01,1.5,-1.5);
    glVertex3f(0.01,1.2,-1.5);
    glVertex3f(-0.01,1.2,-1.5);
    glEnd();

    //face
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(-0.2,1.7,-1.5);
    glVertex3f(0.2,1.7,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(-0.2,1.5,-1.5);
    glEnd();

    //mouth
     glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.09,1.55,-1.4);
    glVertex3f(0.09,1.55,-1.4);
    glVertex3f(0.09,1.53,-1.4);
    glVertex3f(-0.09,1.53,-1.4);
    glEnd();

    //left sided eye
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.15,1.6,-1.4);
    glVertex3f(-0.1,1.6,-1.4);
    glVertex3f(-0.1,1.65,-1.4);
    glVertex3f(-0.15,1.65,-1.4);
    glEnd();

    //right sided eye

    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(0.15,1.6,-1.4);
    glVertex3f(0.1,1.6,-1.4);
    glVertex3f(0.1,1.65,-1.4);
    glVertex3f(0.15,1.65,-1.4);
    glEnd();

    //hair
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.2,1.7,-1.5);
    glVertex3f(0.2,1.7,-1.5);
    glVertex3f(0.2,1.9,-1.5);
    glVertex3f(-0.2,1.9,-1.5);
    glEnd();

    //left sided hand
  glBegin(GL_QUADS);
    glColor3f(0.576, 0.439, 0.859);
    glVertex3f(-0.5,1.5,-1.5);
    glVertex3f(-0.2,1.5,-1.5);
    glVertex3f(-0.2,1.4,-1.5);
    glVertex3f(-0.5,1.4,-1.5);
    glEnd();

    //left sided hand gloves
 glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(-0.5,1.5,-1.5);
    glVertex3f(-0.6,1.5,-1.5);
    glVertex3f(-0.6,1.4,-1.5);
    glVertex3f(-0.5,1.4,-1.5);
    glEnd();

    //right sided hand
    glBegin(GL_QUADS);
    glColor3f(0.576, 0.439, 0.859);
    glVertex3f(0.5,1.5,-1.5);
    glVertex3f(0.2,1.5,-1.5);
    glVertex3f(0.2,1.4,-1.5);
    glVertex3f(0.5,1.4,-1.5);
    glEnd();

    //right sided hand gloves
    glBegin(GL_QUADS);
    glColor3f(1.000, 0.855, 0.725);
    glVertex3f(0.5,1.5,-1.5);
    glVertex3f(0.6,1.5,-1.5);
    glVertex3f(0.6,1.4,-1.5);
    glVertex3f(0.5,1.4,-1.5);
    glEnd();

    //pants
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(-0.2,1.2,-1.5);
    glVertex3f(0.2,1.2,-1.5);
    glVertex3f(0.2,.9,-1.5);
    glVertex3f(-0.2,.9,-1.5);
    glEnd();

    //left sided leg

    glBegin(GL_QUADS);
    glColor3f(0.294, 0.000, 0.510);
    glVertex3f(-0.2,1.0,-1.5);
    glVertex3f(-0.1,1.0,-1.5);
    glVertex3f(-0.1,0.8,-1.5);
    glVertex3f(-0.2,0.8,-1.5);
    glEnd();

    //right sided leg
    glBegin(GL_QUADS);
    glColor3f(0.294, 0.000, 0.510);
    glVertex3f(0.2,1.0,-1.5);
    glVertex3f(0.1,1.0,-1.5);
    glVertex3f(0.1,0.8,-1.5);
    glVertex3f(0.2,0.8,-1.5);
    glEnd();

    //right sided boot
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(0.2,0.8,-1.5);
    glVertex3f(0.1,0.8,-1.5);
    glVertex3f(0.1,0.7,-1.5);
    glVertex3f(0.2,0.7,-1.5);
    glEnd();

    //left sided boot
    glBegin(GL_QUADS);
    glColor3f(0.000, 0.000, 0.000);
    glVertex3f(-0.2,0.8,-1.5);
    glVertex3f(-0.1,0.8,-1.5);
    glVertex3f(-0.1,0.7,-1.5);
    glVertex3f(-0.2,0.7,-1.5);
    glEnd();

    glFlush();
}

///////////////////////////winning///////////////////////////////////////////

void GoalDisplay()
{

    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-0.19,-0.01,-1.5);
    glVertex3f(-0.1,-0.01,-1.5);
    glVertex3f(-0.1,-0.04,-1.5);
    glVertex3f(-0.19,-0.04,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(.0,1,0);
    glVertex3f(-0.19,-0.05,-1.5);
    glVertex3f(-0.11,-0.05,-1.5);
    glVertex3f(-0.11,-0.09,-1.5);
    glVertex3f(-0.19,-0.09,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-0.2,0,-1.5);
    glVertex3f(-0.1,0,-1.5);
    glVertex3f(-0.1,-0.1,-1.5);
    glVertex3f(-0.2,-0.1,-1.5);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-0.08,-0.01,-1.5);
    glVertex3f(0.01,-0.01,-1.5);
    glVertex3f(0.01,-0.09,-1.5);
    glVertex3f(-0.08,-0.09,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-0.09,0,-1.5);
    glVertex3f(0.02,0,-1.5);
    glVertex3f(0.02,-0.1,-1.5);
    glVertex3f(-0.09,-0.1,-1.5);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(0.04,-0.06,-1.5);
    glVertex3f(0.11,-0.06,-1.5);
    glVertex3f(0.11,-0.1,-1.5);
    glVertex3f(0.04,-0.1,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(0.04,-0.01,-1.5);
    glVertex3f(0.11,-0.01,-1.5);
    glVertex3f(0.11,-0.05,-1.5);
    glVertex3f(0.04,-0.05,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(0.03,0,-1.5);
    glVertex3f(0.12,0,-1.5);
    glVertex3f(0.12,-0.1,-1.5);
    glVertex3f(0.03,-0.1,-1.5);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(0.03,0,-1.5);
    glVertex3f(0.12,0,-1.5);
    glVertex3f(0.12,-0.1,-1.5);
    glVertex3f(0.03,-0.1,-1.5);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(0.15,0,-1.5);
    glVertex3f(0.21,0,-1.5);
    glVertex3f(0.21,-0.08,-1.5);
    glVertex3f(0.15,-0.08,-1.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(0.13,0,-1.5);
    glVertex3f(0.21,0,-1.5);
    glVertex3f(0.21,-0.1,-1.5);
    glVertex3f(0.13,-0.1,-1.5);
    glEnd();


    glFlush();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	_ang_tri += 2.0f;
	if (_ang_tri > 360) {
		_ang_tri -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

void drawScene1() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity();


	 //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units



}

void LoadScreen()
{

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity();
	 //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, -1, -7.0);



          glPushMatrix();
glRotatef( -_ang_tri,0.0, 1.0, 0.0);
       glPushMatrix();
       glTranslatef(-.9,.5,0);
       glRotatef(-_ang_tri,0,1,0);
       glScalef(.15,.15,.15);
         football1();
        glPopMatrix();


        glPushMatrix();
       glTranslatef(-.9,.5,1);
       glRotatef(-_ang_tri,0,1,0);
       glScalef(.15,.15,.15);
         football1();
        glPopMatrix();
         glPushMatrix();
       glTranslatef(.9,.5,-1);
       glRotatef(-_ang_tri,0,1,0);
       glScalef(.15,.15,.15);
         football1();
        glPopMatrix();


      glPushMatrix();
       glTranslatef(.9,.5,0);
       glRotatef(-_ang_tri,0,1,0);
       glScalef(.15,.15,.15);

         football1();
        glPopMatrix();
          glPopMatrix();

             glPushMatrix();

 glPushMatrix();
       glTranslatef(1.2,3.5,-1);
       glRotatef(_ang_tri,1,1,1);
       glScalef(.15,.15,.15);

         football1();
        glPopMatrix();
         glPushMatrix();
       glTranslatef(-1.9,3.5,-1);
       glRotatef(_ang_tri,1,1,1);
       glScalef(.15,.15,.15);

         football1();
        glPopMatrix();
   glColor3f(1.000, 0.000, 0.000);
          drawText("Press esc to exit", -.7,-0.30,-1);
            glPopMatrix();
          glPushMatrix();


   glColor3f(0.000, 1.000, 0.000);
        drawText("Press p to start the game", -.7,-0.35,-1);


              drawText("Welcome To The P.S.O 2K18 Game", -.2,.3,-1);
        glPopMatrix();


  glPopMatrix();
    //////////stand green player//////////
    glPushMatrix();
      glTranslatef(0,danceMove,0);
    glScalef(1.0,0.85,0.9);
    glTranslatef(-5.9,0.5,-0.5);
    glColor3f(0.76, 0.559, 0.859);
    player();
    glPopMatrix();

banner();
    glPushMatrix();
      glTranslatef(0,danceMove,0);
    glScalef(1.0,0.85,0.9);
    glTranslatef(-4.8,0.5,-0.5);
    glColor3f(0.76, 0.559, 0.859);
    player();
    glPopMatrix();

///////////stand yellow player//////////

glPushMatrix();
  glTranslatef(0,danceMove,0);
    glScalef(1.0,0.85,0.9);
    glTranslatef(5.9,0.5,-0.5);
    glColor3f(1, 1, 0);
    player();
    glPopMatrix();


    glPushMatrix();
      glTranslatef(0,danceMove,0);
    glScalef(1.0,0.85,0.9);
    glTranslatef(4.8,0.5,-0.5);
    glColor3f(1, 1, 0);
    player();
    glPopMatrix();


////////////////////
glPushMatrix();
glTranslatef(0,-.2,0);
glScalef(.9,.9,.9);
//left behind stand
     glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-2.9,2.7,-2);
    glVertex3f(-3,2.7,-2);
    glVertex3f(-3,1.2,-2);
    glVertex3f(-2.9,1.2,-2);
    glEnd();
//right behind stand

     glBegin(GL_QUADS);
     glColor3f(1,1,1);
    glVertex3f(2.9,2.7,-2);
    glVertex3f(3,2.7,-2);
    glVertex3f(3,1.2,-2);
    glVertex3f(2.9,1.2,-2);
    glEnd();
//top behind stand
        glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-3,2.7,-2);
    glVertex3f(3,2.7,-2);
    glVertex3f(3,2.8,-2);
    glVertex3f(-3,2.8,-2);
    glEnd();
//left front side bar
     glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3,2.8,-1.5);
    glVertex3f(-3.12,2.8,-1.5);
    glVertex3f(-3.12,0.9,-1.5);
    glVertex3f(-3,0.9,-1.5);
    glEnd();

//right front side bar

    glBegin(GL_QUADS);
     glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(3,2.8,-1.5);
    glVertex3f(3.12,2.8,-1.5);
    glVertex3f(3.12,0.9,-1.5);
    glVertex3f(3,0.9,-1.5);
    glEnd();

//top front bar
    glBegin(GL_QUADS);
     glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3.12,2.8,-1.5);
    glVertex3f(3.12,2.8,-1.5);
    glVertex3f(3.12,2.9,-1.5);
    glVertex3f(-3.12,2.9,-1.5);
    glEnd();

//right upper corner
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(3,2.9,-1.5);
    glVertex3f(3.12,2.9,-1.5);
    glVertex3f(3,2.7,-2);
    glVertex3f(2.9,2.7,-2);
    glEnd();
// left upper corner
      glBegin(GL_QUADS);
   glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3,2.9,-1.5);
    glVertex3f(-3.12,2.9,-1.5);
    glVertex3f(-3,2.7,-2);
    glVertex3f(-2.9,2.7,-2);
    glEnd();
//left lower corner
      glBegin(GL_QUADS);
   glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3,0.9,-1.5);
    glVertex3f(-3.12,0.9,-1.5);
    glVertex3f(-3,1.2,-2);
    glVertex3f(-2.9,1.2,-2);
    glEnd();

         glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(3,0.9,-1.5);
    glVertex3f(3.12,0.9,-1.5);
    glVertex3f(3,1.2,-2);
    glVertex3f(2.9,1.2,-2);
    glEnd();
 //upper net


    float t=-1.5;
    float y=-1.5;
    for(t;t>-2;t-=.1)
    {
    y=t-.01;
      glBegin(GL_QUADS);
    glColor3f(1,1,1);
//glPointSize(100.0);
    glVertex3f(-3,2.8,t);
    glVertex3f(3,2.8,t);
    glVertex3f(3,2.81,y);
    glVertex3f(-3,2.81,y);
    glEnd();
    glFlush();
    t-=.01;
    }
 //left net
net();


//ends upper net

    glFlush();


glPopMatrix();
  glutSwapBuffers();

  }

////////////Animation load


void Cup()

{

    drawScene1();



        glPushMatrix();
        glScalef(.8,.8,.8);
        glPushMatrix();
	glRotatef( -185,1.0, 0.0, 0.0);
	glPushMatrix();
	glColor3f(0,1,0);
	glRotatef( _ang_tri,0.0, 1.0, 0.0);
	glPushMatrix();
	glColor3f(1,0,0); //Save the transformations performed thus far

	glRotatef(90 ,-1.0, 0.0, 0.0);


	glutSolidCone(1,2,50,50);




	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


        glPushMatrix();
glRotatef( 90,0.0, 0.0, 1.0);
glTranslatef(2.0, -2.0, 0.0);
	glPushMatrix();
	glColor3f(1,1,0);
		glTranslatef(-1.0, 2.0, 0.0);
		glRotatef(- _ang_tri,1.0, 0.0, 0.0);
	glPushMatrix(); //Save the transformations performed thus far

	glRotatef(90 ,-1.0, 0.0, 0.0);

	glutSolidSphere(1.2,100,3);
	glColor3f(0,0,.333);
	glutSolidCube(1.55);



    glPopMatrix();
     glPopMatrix();

  glPopMatrix();
  //torus
   glPushMatrix();
	glRotatef( -4,1.0, 0.0, 0.0);



	glTranslatef(0.0, 0, 0.0);

	glPushMatrix();

glRotatef(- _ang_tri,0.0, 1.0, 0.0);
	glPushMatrix();
    glColor3f(0,0,.333);
	glRotatef(90 ,-1.0, 0.0, 0.0);
	glutSolidTorus(.4,.7,60,5);
    glPopMatrix();
     glPopMatrix();
       glPopMatrix();


//torus1
 glPushMatrix();
	glRotatef( -4,1.0, 0.0, 0.0);



	glTranslatef(0.0, -1.7, 0.0);

	glPushMatrix();

glRotatef(- _ang_tri,0.0, 1.0, 0.0);
	glPushMatrix();
    glColor3f(0,1,1);
	glRotatef(90 ,-1.0, 0.0, 0.0);
	//glutWireTorus(.1,.2,50,50);
    glPopMatrix();
     glPopMatrix();
       glPopMatrix();
        glPushMatrix();
	glRotatef( -4,1.0, 0.0, 0.0);



	glTranslatef(0.0, -1.8, 0.0);

	glPushMatrix();
	glColor3f(1,1,0);
glRotatef(- _ang_tri,0.0, 1.0, 0.0);
	glPushMatrix();
   // glColor3f(1,1,0);
	glRotatef(90 ,-1.0, 0.0, 0.0);
	glutSolidTorus(.19,.35,50,50);
    glPopMatrix();
     glPopMatrix();
       glPopMatrix();

       //torus+Tri  glPushMatrix();
	glRotatef( -4,1.0, 0.0, 0.0);



	glTranslatef(0.0, -1.0, 0.0);

	glPushMatrix();
	glColor3f(1,1,0);
glRotatef(- _ang_tri,0.0, 1.0, 0.0);
	glPushMatrix();
	glColor3f(0,0,0.333);


	glRotatef(90 ,-1.0, 0.0, 0.0);
	glutSolidTorus(.71,.45,5,3);
    glPopMatrix();
     glPopMatrix();

 glPopMatrix();






  glPushMatrix();

   glColor3f(1.000, 0.000, 0.000);
        drawText("Congratulations ! ! ! ", -0.25,-0.30,-1);


  glPopMatrix();

    }





/////////////////////////END////////////////////////////////////////////////





void movekeeperup()
{

    keeper_y +=0.5;
    keeper_z += 0.5;
    if(keeper_y<2.8)
    {

        keeper_y += keeper_y;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }
    glutPostRedisplay();
}

void movekeeperRightUppercorner()
{
    keeper_x +=1.0;
    keeper_y +=0.5;
    keeper_z += 0.5;
    if(keeper_x<1.5 && keeper_y<1)
    {
        keeper_x += keeper_x;
        keeper_y += keeper_y;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }

    glutPostRedisplay();
}
void movekeeperLeftUppercorner()
{
    keeper_x =keeper_x-1.3;
    keeper_y +=0.5;
    keeper_z += 0.5;
    if(keeper_x>-1.5 && keeper_y<1)
    {
        keeper_x = keeper_x-1.0;
        keeper_y += keeper_y;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }
    glutPostRedisplay();
}

void movekeeperRight()
{
    keeper_x +=1.2;
    keeper_y +=0.0;
    keeper_z += 0.5;
    if(keeper_x<2.2 )
    {
        keeper_x += keeper_x;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }
    glutPostRedisplay();
}

void movekeeperLeft()
{
    keeper_x =keeper_x - 1.2;
    keeper_y +=0.0;
    keeper_z += 0.5;
    if(keeper_x<2.2 )
    {
        keeper_x = keeper_x-1.2;
        keeper_z += keeper_z;
        glutIdleFunc(NULL);

    }
    glutPostRedisplay();
}

void moveFootballRightUppercorner()
{

        ball_x  += 0.85;
        ball_z -= 0.10;
        ball_y +=1.6;
        if(ball_x>5 && ball_y>5.9 && ball_z>-2)
        {
            ball_x += ball_x;
            ball_y += ball_y;
            ball_z -= ball_z;
            kickRightCorner = false;
        }
        glutPostRedisplay();
}

void moveFootballLeftCorner()
{
        ball_x -= 1.6;
        ball_z -= 0.10;
        ball_y += 1.6;
        if(ball_x<-2 && ball_y>5.9 && ball_z>-2)
        {
            ball_x = ball_x-1.6;
            ball_y += ball_y;
            ball_z -= ball_z;
            kickLeftCorner = false;
        }



        glutPostRedisplay();
}


void moveFootballRight()
{

        ball_x  += 0.80;
        ball_z -= 0.10;
        ball_y +=1.0;
        if(ball_x>2 && ball_y>2.8 &&  ball_z>-5)
        {
            ball_x += ball_x;
            ball_y += ball_y;
            ball_z -= ball_z;
            kickRight = false;
        }
        glutPostRedisplay();
}



void moveFootballLeft()
{
        ball_x  -= 1.4;
        ball_z -= 0.10;
        ball_y +=1.0;
        if(ball_x<8 && ball_y>2.8 &&  ball_z>-2)
        {
            ball_x = ball_x-1.4;
            ball_y += ball_y;
            ball_z -= ball_z;
            kickLeft = false;
        }



        glutPostRedisplay();

}

void moveFootballUp()
{
    ball_y += 1.8;
    if(ball_y>6 && ball_z >-2)
    {
            ball_y += ball_y;
            ball_z -= ball_z;
            kickUp = false;
    }
      glutPostRedisplay();
}

void reset()
{
     ball_x= 0;
     ball_y=-6;
     ball_z=0;
     keeper_x =0;
     keeper_y=0;
     keeper_z=0;
     trickerRound =0;
     goalsaveshow = false;
     goalshow = false;
     movement =0;
     glutPostRedisplay();
}

void newgame()
{
     ball_x= 0;
     ball_y=-6;
     ball_z=0;
     keeper_x =0;
     keeper_y=0;
     keeper_z=0;
     movement =0;
     trickerRound =0;
     goalsaveshow = false;
     goalshow = false;
     greenLight1 = false;
     greenLight2 = false;
     greenLight3 = false;
     greenLight4 = false;
     greenLight5 = false;
     redLight1 = false;
     redLight2 = false;
     redLight3 = false;
     redLight4 = false;
     redLight5 = false;
     greenLight2_1 = false;
     greenLight2_2 = false;
     greenLight2_3 = false;
     greenLight2_4 = false;
     greenLight2_5 = false;
     redLight2_1 = false;
     redLight2_2 = false;
     redLight2_3 = false;
     redLight2_4 = false;
     redLight2_5 = false;
     tricker_x=0;
     tricker_y=0;
     tricker_z=0;
     countshoot =0;
     end_game = false;
     t_G = 0;
     for(int x=0;x<10;x++){
        total_game[x] = 0;
     }
     glutPostRedisplay();
}





void endGame()
{
    end_game = false;
    if(countshoot==10){
        end_game = true;

    }
}


void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, -0.16, -7.0); //Move forward 5 units

    glPushMatrix();
    glTranslatef(triTemp, triget, 0.0);
    glScalef(1,1,1);

    banner();

    glPopMatrix();


    glPushMatrix();
    glTranslatef(0,yellowAudience,0);
    glScalef(1,1,1);
    audience();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,blueAudience,0);
    glScalef(1,1,1);
    greenAudience();
    glPopMatrix();

     glPushMatrix();
    glTranslatef(0,danceMove,0);
    glScalef(1,1,1);
    dancer();
    glPopMatrix();





    field();
    lightBar();
    lightBar_2();



    if(greenLight1)
    {
    greenLight11();

    }
    if(greenLight2)
    {
        greenLight22();

    }
    if(greenLight3)
    {
        greenLight33();

    }
    if(greenLight4)

    {

        greenLight44();

    }
    if(greenLight5)

    {

        greenLight55();


    }

    if(redLight1)
    {
        redLight11();
    }
    if(redLight2)
    {
        redLight22();
    }
    if(redLight3)
    {
        redLight33();
    }
    if(redLight4)
    {
        redLight44();
    }
    if(redLight5)
    {
        redLight55();
    }

     if(greenLight2_1)
    {
    greenLight11_2();
    }
    if(greenLight2_2)
    {
        greenLight22_2();
    }
    if(greenLight2_3)
    {
        greenLight33_2();
    }
    if(greenLight2_4)
    {
        greenLight44_2();
    }
    if(greenLight2_5)
    {
        greenLight55_2();
    }
    if(redLight2_1)
    {
        redLight11_2();
    }
    if(redLight2_2)
    {
        redLight22_2();
    }
    if(redLight2_3)
    {
        redLight33_2();
    }
    if(redLight2_4)
    {
        redLight44_2();
    }
    if(redLight2_5)
    {
        redLight55_2();

    }

    goalpost();
    net();
sky();

    glPushMatrix();
    glScalef(.15,.15,.15);
     glTranslatef(-1,-1,1);
    glTranslatef(ball_x,ball_y,ball_z);
    football();
    glPopMatrix();


//goalkeeper
    glPushMatrix();
    glScalef(1.1,1.1,1.1);
    glTranslatef(keeper_x,keeper_y,keeper_z+.1);
    goalkeeper();
    glPopMatrix();

///////////stand green player//////////
    glPushMatrix();
    glScalef(1.0,0.85,0.9);
    glTranslatef(-5.9,0.5,-0.5);
    glColor3f(0.76, 0.559, 0.859);
    player();
    glPopMatrix();


    glPushMatrix();
    glScalef(1.0,0.85,0.9);
    glTranslatef(-4.8,0.5,-0.5);
    glColor3f(0.76, 0.559, 0.859);
    player();
    glPopMatrix();

///////////stand yellow player//////////

glPushMatrix();
    glScalef(1.0,0.85,0.9);
    glTranslatef(5.9,0.5,-0.5);
    glColor3f(1, 1, 0);
    player();
    glPopMatrix();


    glPushMatrix();
    glScalef(1.0,0.85,0.9);
    glTranslatef(4.8,0.5,-0.5);
    glColor3f(1, 1, 0);
    player();
    glPopMatrix();


////////////////////







   if(goalsaveshow)
    {
        glPushMatrix();
        glColor3f(1.000, 0.000, 0.000);
         glTranslatef(triTemp, triget, 0.0);
        drawText("                Nice Save !!!             ", -0.2,-.10,-1);
        glPopMatrix();
    }
    else if(goalshow)
    {

      glPushMatrix();

    glTranslatef(0,0,trickerRound);
    if(greenLight1==true || greenLight2==true || greenLight3==true || greenLight4==true)
    {
        glPushMatrix();

        GoalDisplay();
        glPopMatrix();
    }
    glPopMatrix();
    }

       if(end_game){
        for(int x=0;x<10;x++){
            if(x%2==0){
                p1+=total_game[x];
            }
            else{
                p2+=total_game[x];
            }
//            cout << total_game[x];
        }
//        cout << p1 << p2;
        if(p1>p2){
//            stringstream str;
//            str << "Player 1 WINS by "<<p1<<" - "<<p2;
//            string str2 = str.str();

            glColor3f(0.000, 0.000, 0.545);
            Cup();



////////////////////
///////////stand yellow player//////////


glPushMatrix();
  glTranslatef(0,danceMove,0);
    glScalef(1.0,0.85,0.9);
    glTranslatef(5.9,0.5,-0.5);
    glColor3f(1, 1, 0);
    player();
    glPopMatrix();


    glPushMatrix();
      glTranslatef(0,danceMove,0);
    glScalef(1.0,0.85,0.9);
    glTranslatef(4.8,0.5,-0.5);
    glColor3f(1, 1, 0);
    player();
    glPopMatrix();


////////////////////
            glPushMatrix();
glColor3f(0,1,0);
drawText("Press n to new game",  -.7,-0.35,-1);
      glPopMatrix();
            glPushMatrix();
            glColor3f(0,1,0);
             drawText(" Project Members,", 0.5,-0.13,-1);
    drawText("Rajib Abdur Razzaque", 0.5,-0.16,-1);
     drawText("Arif Rabbani", 0.5,-0.19,-1);
    drawText("Rafin Ishraq", 0.5,-0.22,-1);
   drawText("Faysal Md.", 0.5,-0.25,-1);
   glPopMatrix();

              glPushMatrix();
            glColor3f(1,1,0);
            drawText("Player 1 WINS",-0.024,-0.30,-1);
             glPopMatrix();
            p1 = 0;
            p2 = 0;
        }
        else if(p1<p2){
//            stringstream str;
//            str << "Player 2 WINS by "<<p1<<" - "<<p2;

            glColor3f(0.000, 0.000, 0.545);
            Cup();
            ///////////stand green player//////////
    glPushMatrix();
      glTranslatef(0,danceMove,0);
    glScalef(1.0,0.85,0.9);
    glTranslatef(-5.9,0.5,-0.5);
    glColor3f(0.76, 0.559, 0.859);
    player();
    glPopMatrix();


    glPushMatrix();
      glTranslatef(0,danceMove,0);
    glScalef(1.0,0.85,0.9);
    glTranslatef(-4.8,0.5,-0.5);
    glColor3f(0.76, 0.559, 0.859);
    player();
    glPopMatrix();
            glPushMatrix();
glColor3f(0,1,0);
drawText("Press n to new game",  -.7,-0.35,-1);
      glPopMatrix();
            glPushMatrix();
            glColor3f(0,1,0);
             drawText(" Project Members,", 0.5,-0.13,-1);
    drawText("Rajib Abdur Razzaque", 0.5,-0.16,-1);
     drawText("Arif Rabbani", 0.5,-0.19,-1);
    drawText("Rafin Ishraq", 0.5,-0.22,-1);
   drawText("Faysal Md.", 0.5,-0.25,-1);
   glPopMatrix();
              glPushMatrix();
            glColor3f(0.576, 0.439, 0.859);
            drawText("Player 2 WINS",-0.024,-0.30,-1);
             glPopMatrix();
              p1 = 0;
            p2 = 0;
        }
        else if(p1 == p2){

            stringstream str;

//            str << "Match Draw "<<p1<<" - "<<p2;

            glColor3f(1.000, 0.000, 0.000);
            drawScene1();

            glPushMatrix();

glRotatef(-_ang_tri,0.0, 1.0, 0.0);
	glPushMatrix();
	glColor3f(0,1,0);


	glRotatef(90 ,0, 1, 0.0);


glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=1.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

	//left eye
	glPushMatrix();
	glTranslatef(.9,.5,0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();

     glPopMatrix();
     //Right eye

     glPushMatrix();
	glTranslatef(-.9,.5,0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/100;
		float r=.3;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}

	glEnd();

     glPopMatrix();
       glPopMatrix();



       glPopMatrix();

          glPushMatrix();
glRotatef( _ang_tri,0.0, 1.0, 0.0);
       glPushMatrix();
       glTranslatef(-.9,.5,0);
       glRotatef(_ang_tri,0,1,0);
       glScalef(.15,.15,.15);

         football1();
        glPopMatrix();


      glPushMatrix();
       glTranslatef(.9,.5,0);
       glRotatef(_ang_tri,0,1,0);
       glScalef(.15,.15,.15);

         football1();
        glPopMatrix();
          glPopMatrix();

      glPushMatrix();


   glColor3f(1.000, 0.000, 0.000);
        drawText(" Game Over ! ! ! The result of this match is draw ! ! !", -.14,-.27,-1);



  glPopMatrix();

glPushMatrix();
glColor3f(0,1,0);
drawText("Press n to new game",  -.7,-0.35,-1);
      glPopMatrix();
      glPushMatrix();
            glColor3f(0,1,0);
             drawText(" Project Members,", 0.5,-0.13,-1);
    drawText("Rajib Abdur Razzaque", 0.5,-0.16,-1);
     drawText("Arif Rabbani", 0.5,-0.19,-1);
    drawText("Rafin Ishraq", 0.5,-0.22,-1);
   drawText("Faysal Md.", 0.5,-0.25,-1);
   glPopMatrix();


              p1 = 0;
            p2 = 0;
        }

    }


//   speedmeter();
 if(startgame)
    {
         glColor3f(0,0,0);
      drawText("Press esc to exit", -.70,-.10,-1);
    //drawText("Press esc to exit", -.70,-0.11,-2);
    drawText("Press n to new game", -.70,-0.13,-1);
    drawText("Press 6 to move the ball Right", -.70,-0.16,-1);
    drawText("Press 4 to move the ball Left", -.70,-0.19,-1);
    drawText("Press 9 to move the ball Right upper corner", -.70,-0.22,-1);
    drawText("Press 8 to move the ball Up", -.70,-0.25,-1);
    drawText("Press 7 to move the ball Left upper corner", -.70,-0.28,-1);
    drawText("Press v to (Hide/Show)", -.70,-0.31,-1);
    drawText("Press Fn+Left/Right for brightness", -.70,-.34,-1);
    drawText("Press Fn+F8 for mute/sound", -.70,-.37,-1);
    /*glPushMatrix();
    glColor3f(1,0,0);
    drawText("  Score  Goals To Win  ", -.70,-0.,-2);
    glPopMatrix();*/
    }





	glutSwapBuffers();
}

void start()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity();
	  glColor3f(0.000, 0.000, 0.000);



    drawText("Press esc to exit", -1.5,-0.30,-2);


    drawText("Press n to new game",  -1.5,-0.40,-2);
    drawText("Press d to move the ball Right",  -1.5,-0.45,-2);
    drawText("Press a to move the ball Left",  -1.5,-0.50,-2);
    drawText("Press e to move the ball Right upper corner",  -1.5,-0.55,-2);
    drawText("Press w to move the ball Up",  -1.5,-0.60,-2);
    drawText("Press q to move the ball Left upper corner",  -1.5,-0.65,-2);
    drawText("Press v to (Hide/Show)", -1.5,-0.7,-2);
     drawText("Press Fn+Up/Down for brightness", -1.5,-.67,-2);

    drawScene() ;

}





void updated(int value) {


	triTemp += 0.1;

	if(triTemp > 11)
        {

        triTemp = -4;

        }
        counterSec++;
        if(counterSec>5)
        {
           danceMove +=.09;
            if(danceMove>=.18)
            {
                danceMove =0;
            }
            counterSec =0;
        }


    if(goalshow)
        {
            trickerRound +=.1;
            if(trickerRound > 8)
            {
                    trickerRound=0;
            }

            yellowAudience +=.09;
            if(yellowAudience>=.18)
            {
                yellowAudience =0;
            }

        }
    if(goalsaveshow)
    {
        blueAudience += .09;
        if(blueAudience >=.18)
        {
            blueAudience =0;
        }
    }





     if(kickRightCorner)
        {

        if(counterSec >= 0)
            moveFootballRightUppercorner();





        }

        if(kickRight)
        {
        counterSec += 1;
        if(counterSec > 0)
            moveFootballRight();

        }

    if(kickLeftCorner)
    {
       counterSec += 1;

        if(counterSec > 0)
            moveFootballLeftCorner();

    }

     if(kickLeft)
    {
       counterSec += 1;

        if(counterSec > 0)
            moveFootballLeft();



    }

         if(kickUp)
    {
       counterSec += 1;

        if(counterSec > 0)
            moveFootballUp();


    }



	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(30, updated, 0);
}

void keyboard(unsigned char key, int x, int y)
{
     //if(key=='m'){

   int r;
   switch(key)
   {

    case 's':
        if(!startgame)
        {
            startgame = true;
        }
        else if(startgame)
        {
            startgame = false;
        }
        break;

     case 'S':
        if(!startgame)
        {
            startgame = true;
        }
        else if(startgame)
        {
            startgame = false;
        }
        break;



  //  case 'e':
    case '9':
if(movement==0)
{
    if(countshoot==10){newgame();}
    kickRightCorner = true;
    //PlaySound(TEXT("Ball_Kicked"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
    srand(time(NULL));//required for "randomness"


        r=rand()%5;//generate a number between 0 and 5
       // printf("%i",r);
    if(r==0)
        {
       //first green light if red not blink
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
         goalshow = true;
         total_game[t_G] = 1;
         glutIdleFunc(movekeeperRight);
          PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
         //countshoot++;
        }
    else if(r==1)
       {

        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
        goalsaveshow = true;

        glutIdleFunc(movekeeperRightUppercorner);
       // countshoot++;

       }
    else if(r==2)
    {
     //first green light if red not blink
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeft);
      //countshoot++;
    }
    else if(r==3)
    {
    //first green light if red not blink
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeftUppercorner);
     // countshoot++;
    }
    else if(r==4)
    {
//first green light if red not blink
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

       goalshow = true;
         total_game[t_G] = 1;
       glutIdleFunc(movekeeperup);
       //countshoot++;
    }

    countshoot++;
    movement++;
      t_G++;
    turn = !turn;

}
else
    {
        reset();

    }
        //turn = !turn;
       // t_G++;
    break;

    //case 'q':
    case '7':

if(movement==0)
{

      if(countshoot==10){newgame();}

      kickLeftCorner = true;
      srand(time(NULL));//required for "randomness"


        r=rand()%5;//generate a number between 0 and 5

    if(r==0)
        {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
        goalshow = true;
         total_game[t_G] = 1;
         glutIdleFunc(movekeeperRight);
        }
    else if(r==1)
       {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

        goalshow = true;
         total_game[t_G] = 1;
        glutIdleFunc(movekeeperRightUppercorner);
       }
    else if(r==2)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeft);
    }
    else if(r==3)
    {
        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
      goalsaveshow=true;
      glutIdleFunc(movekeeperLeftUppercorner);
    }
    else if(r==4)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

       goalshow = true;
         total_game[t_G] = 1;
       glutIdleFunc(movekeeperup);
    }
    countshoot++;
    movement++;
      t_G++;
    turn = !turn;

}
else{reset();}


//t_G++;
//turn = !turn;
    break;

    //case 'a':
    case '4':
if(movement==0)
{
    if(countshoot==10){newgame();}
    kickLeft = true;
     srand(time(NULL));//required for "randomness"



       // int r;
        r=rand()%5;//generate a number between 0 and 5
       // printf("%i",r);
    if(r==0)
        {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

         goalshow = true;
         total_game[t_G] = 1;
         glutIdleFunc(movekeeperRight);
        }
    else if(r==1)
       {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

        goalshow = true;
         total_game[t_G] = 1;
        glutIdleFunc(movekeeperRightUppercorner);
       }
    else if(r==2)
    {
        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
      goalsaveshow = true;
      glutIdleFunc(movekeeperLeft);
    }
    else if(r==3)
    {
      PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
      if(countshoot==0){greenLight1 = true;}
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeftUppercorner);
    }
    else if(r==4)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

       goalshow = true;
         total_game[t_G] = 1;
       glutIdleFunc(movekeeperup);
    }
    countshoot++;
    movement++;
      t_G++;
    turn = !turn;

}
else{reset();}
   // t_G++;
   // turn = !turn;
    break;
    //case 'w':
    case '8':
if(movement==0)
{
       if(countshoot==10){newgame();}
       kickUp = true;
       srand(time(NULL));//required for "randomness"

        //int r;
        r=rand()%5;//generate a number between 0 and 5
       // printf("%i",r);
    if(r==0)
        {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

         goalshow = true;
         total_game[t_G] = 1;
         glutIdleFunc(movekeeperRight);
        }
    else if(r==1)
       {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

        goalshow = true;
         total_game[t_G] = 1;
        glutIdleFunc(movekeeperRightUppercorner);
       }
    else if(r==2)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeft);
    }
    else if(r==3)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeftUppercorner);
    }
    else if(r==4)
    {
        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
       goalsaveshow = true;
       glutIdleFunc(movekeeperup);
    }
    countshoot++;
    movement++;
      t_G++;
    turn = !turn;

}
else{reset();}
//t_G++;
//turn = !turn;
        break;


    //case 'd':
    case '6':
 if(movement==0)
{
    if(countshoot==10){newgame();}
    kickRight = true;
    srand(time(NULL));//required for "randomness"

        //int r;
        r=rand()%5;//generate a number between 0 and 5
       // printf("%i",r);
    if(r==0)
        {
        PlaySound(TEXT("SAVE"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){redLight1 = true;}
        if(countshoot==1){redLight2_1 = true;}
        if(countshoot==2){redLight2 = true;}
        if(countshoot==3){redLight2_2 = true;}
        if(countshoot==4){redLight3 = true;}
        if(countshoot==5){redLight2_3 = true;}
        if(countshoot==6){redLight4 = true;}
        if(countshoot==7){redLight2_4 = true;}
        if(countshoot==8){redLight5 = true;}
        if(countshoot==9){redLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}
         goalsaveshow = true;
         glutIdleFunc(movekeeperRight);
       //  drawText("!!!!!!!!!!!!!!!!Nice Save!!!!!!!!!!!!!!!!", 2, 2);//
        }
    else if(r==1)
       {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

        goalshow = true;
         total_game[t_G] = 1;
        glutIdleFunc(movekeeperRightUppercorner);
       }
    else if(r==2)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeft);
    }
    else if(r==3)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

      goalshow = true;
         total_game[t_G] = 1;
      glutIdleFunc(movekeeperLeftUppercorner);
    }
    else if(r==4)
    {
        PlaySound(TEXT("GOAL"), NULL, SND_ASYNC|SND_FILENAME);
        if(countshoot==0){greenLight1 = true;}
        if(countshoot==1){greenLight2_1 = true;}
        if(countshoot==2){greenLight2 = true;}
        if(countshoot==3){greenLight2_2 = true;}
        if(countshoot==4){greenLight3 = true;}
        if(countshoot==5){greenLight2_3 = true;}
        if(countshoot==6){greenLight4 = true;}
        if(countshoot==7){greenLight2_4 = true;}
        if(countshoot==8){greenLight5 = true;}
        if(countshoot==9){greenLight2_5 = true;         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

       goalshow = true;
         total_game[t_G] = 1;
       glutIdleFunc(movekeeperup);
    }
     countshoot++;
     movement++;
    t_G++;
    turn = !turn;
}
else{reset();}
  //  t_G++;
   // turn = !turn;

    break;


    // case 'h':

     case 'H':

       reset();
    break;

     case 'n':
               PlaySound(TEXT("Cheering background.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        newgame();
        break;
      case 'N':
PlaySound(TEXT("Cheering background.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        newgame();
        break;
        case 'p':
            loadGame=false;
PlaySound(TEXT("Cheering background.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
         glutDisplayFunc(drawScene);
        break;
      case 'P':
          loadGame=false;
PlaySound(TEXT("Cheering background.wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
        glutDisplayFunc(drawScene);
      case 27:
        exit(0);
        break;


   }
   endGame();
   //cout << "p1:" p1 << endl;
   //cout << "p2:"  << endl;
}







int main(int argc, char** argv) {
	//Initialize GLUT

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1360, 768);

	//Create the window
	glutCreateWindow("The P.S.O 2K18 Game");
	glutFullScreen();
	initRendering();
    //Set handler functions
    if(loadGame)
        {
             glutDisplayFunc(LoadScreen);
        }

	glutReshapeFunc(handleResize);
    glutKeyboardFunc(keyboard);
         PlaySound(TEXT("Cinematic game Background Music .wav"), NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);




	glutTimerFunc(20, update, 0);   //Add a timer1
	glutTimerFunc(30, updated, 0); //Add a timer2

	glutMainLoop();

	return 0;
}

