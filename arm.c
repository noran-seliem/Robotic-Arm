/*

 * Copyright (c) 1993-1997, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED 
 * Permission to use, copy, modify, and distribute this software for 
 * any purpose and without fee is hereby granted, provided that the above
 * copyright notice appear in all copies and that both the copyright notice
 * and this permission notice appear in supporting documentation, and that 
 * the name of Silicon Graphics, Inc. not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission. 
 *
 * THE MATERIAL EMBODIED ON THIS SOFTWARE IS PROVIDED TO YOU "AS-IS"
 * AND WITHOUT WARRANTY OF ANY KIND, EXPRESS, IMPLIED OR OTHERWISE,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF MERCHANTABILITY OR
 * FITNESS FOR A PARTICULAR PURPOSE.  IN NO EVENT SHALL SILICON
 * GRAPHICS, INC.  BE LIABLE TO YOU OR ANYONE ELSE FOR ANY DIRECT,
 * SPECIAL, INCIDENTAL, INDIRECT OR CONSEQUENTIAL DAMAGES OF ANY
 * KIND, OR ANY DAMAGES WHATSOEVER, INCLUDING WITHOUT LIMITATION,
 * LOSS OF PROFIT, LOSS OF USE, SAVINGS OR REVENUE, OR THE CLAIMS OF
 * THIRD PARTIES, WHETHER OR NOT SILICON GRAPHICS, INC.  HAS BEEN
 * ADVISED OF THE POSSIBILITY OF SUCH LOSS, HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, ARISING OUT OF OR IN CONNECTION WITH THE
 * POSSESSION, USE OR PERFORMANCE OF THIS SOFTWARE.
 * 
 * US Government Users Restricted Rights 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions set forth in FAR 52.227.19(c)(2) or subparagraph
 * (c)(1)(ii) of the Rights in Technical Data and Computer Software
 * clause at DFARS 252.227-7013 and/or in similar or successor
 * clauses in the FAR or the DOD or NASA FAR Supplement.
 * Unpublished-- rights reserved under the copyright laws of the
 * United States.  Contractor/manufacturer is Silicon Graphics,
 * Inc., 2011 N.  Shoreline Blvd., Mountain View, CA 94039-7311.
 *
 * OpenGL(R) is a registered trademark of Silicon Graphics, Inc.
 */

/*
 * robot.c
 * This program shows how to composite modeling transformations
 * to draw translated and rotated hierarchical models.
 * Interaction:  pressing the s and e keys (shoulder and elbow)
 * alters the rotation of the robot arm.
 */
#include <GL/glut.h>
#include <stdlib.h>

static int shoulder = 0, elbow = 0, fingerBase = 0, fingerUp = 0, fingerBase2 = 0, fingerUp2 = 0, 
fingerBase3 = 0, fingerUp3 = 0, fingerBase4 = 0, fingerUp4 = 0;
int moving, startx, starty;


GLfloat angle = 0.0;   /* in degrees */
GLfloat angle2 = 0.0;   /* in degrees */


void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
}

void display(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPushMatrix();
   glRotatef(angle2, 1.0, 0.0, 0.0);
   glRotatef(angle, 0.0, 1.0, 0.0);

   glTranslatef (-1.0, 0.0, 0.0);
   glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.8, 0.8);
   glutWireCube (1.0);
   glPopMatrix();

   glTranslatef (1.0, 0.0, 0.0);
   glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);
   glTranslatef (1.0, 0.0, 0.0);
   glPushMatrix();
   glScalef (2.0, 0.8, 0.8);
   glutWireCube (1.0);
   glPopMatrix();

   glPushMatrix();
   //Draw finger flang 1 
   glTranslatef(1.0, 0.3 , 0.0);
   glRotatef((GLfloat)fingerBase, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.20, 0.20);
   glutWireCube(1);
   glPopMatrix();

 
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)fingerUp, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.20, 0.20);
   glutWireCube(1);
   glPopMatrix();

   glPopMatrix();

   glPushMatrix();
      //Draw finger flang 2 
   glTranslatef(1.0, -0.3, 0.0);
   glRotatef((GLfloat)fingerBase2, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.20, 0.20);
   glutWireCube(1);
   glPopMatrix();



   glTranslatef(0.15,0.0, 0.0);
   glRotatef((GLfloat)fingerUp2, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.20, 0.20);
   glutWireCube(1);
   glPopMatrix();

 glPopMatrix();

glPushMatrix();
      //Draw finger flang 3
   glTranslatef(1.0, 0.3, 0.3);
   glRotatef((GLfloat)fingerBase3, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.20, 0.20);
   glutWireCube(1);
   glPopMatrix();

 
   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)fingerUp3, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.20, 0.20);
   glutWireCube(1);
   glPopMatrix();

     glPopMatrix();

    glPushMatrix();
      //Draw finger flang 4
   glTranslatef(1.0, 0.3, -0.3);
   glRotatef((GLfloat)fingerBase4, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.20, 0.20);
   glutWireCube(1);
   glPopMatrix();



   glTranslatef(0.15, 0.0, 0.0);
   glRotatef((GLfloat)fingerUp4, 0.0, 0.0, 1.0);
   glTranslatef(0.15, 0.0, 0.0);
   glPushMatrix();
   glScalef(0.3, 0.20, 0.20);
   glutWireCube(1);
   glPopMatrix();

    glPopMatrix();

   //end
   glPopMatrix();
   glutSwapBuffers();
}

void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei)w, (GLsizei)h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(85.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key)
   {
   case 's':
      shoulder = (shoulder + 5) % 360;
      glutPostRedisplay();
      break;
   case 'S':
      shoulder = (shoulder - 5) % 360;
      glutPostRedisplay();
      break;
   case 'e':
    if (elbow < 180)
         
      elbow = (elbow + 5) % 360;
      glutPostRedisplay();
      break;
   case 'E':
   if (elbow > 0)
      elbow = (elbow - 5) % 360;
      glutPostRedisplay();
      break;
   case 'f':
   if (fingerBase > -90 )
      fingerBase = (fingerBase - 5) % 360;
      glutPostRedisplay();
      break;
   case 'F':
   if ( fingerBase < 0  )
      fingerBase = (fingerBase + 5) % 360;
      glutPostRedisplay();
      break;
    case 'g':
      if (fingerUp > -90)
      fingerUp = (fingerUp - 5) % 360;
      glutPostRedisplay();
      break;
   case 'G':
   if (fingerUp < 0 )
      fingerUp = (fingerUp + 5) % 360;
      glutPostRedisplay();
      break;
// finger2 the opposite
   case 'k':
   if (fingerBase2 < 90)
      fingerBase2 = (fingerBase2 + 5) % 360;
      glutPostRedisplay();
      break;
   case 'K':
   if ( fingerBase2 > 0)
      fingerBase2 = (fingerBase2 - 5) % 360;
      glutPostRedisplay();
      break;
    case 'l':
      if (fingerUp2 < 90)
      fingerUp2 = (fingerUp2 + 5) % 360;
      glutPostRedisplay();
      break;
   case 'L':
   if (fingerUp2 >0)
      fingerUp2 = (fingerUp2 - 5) % 360;
      glutPostRedisplay();
      break;
//finger3
   case 'm':
   if (fingerBase3 > -90)
      fingerBase3 = (fingerBase3 - 5) % 360;
      glutPostRedisplay();
      break;
   case 'M':
   if ( fingerBase3 < 0)
      fingerBase3 = (fingerBase3 + 5) % 360;
      glutPostRedisplay();
      break;
    case 'n':
      if (fingerUp3 > -90)
      fingerUp3 = (fingerUp3 - 5) % 360;
      glutPostRedisplay();
      break;
   case 'N':
   if (fingerUp3 < 0 )
      fingerUp3 = (fingerUp3 + 5) % 360;
      glutPostRedisplay();
      break;

//finger4
   case 'o':
   if (fingerBase4 > -90)
      fingerBase4 = (fingerBase4 - 5) % 360;
      glutPostRedisplay();
      break;
   case 'O':
   if ( fingerBase4 < 0)
      fingerBase4 = (fingerBase4 + 5) % 360;
      glutPostRedisplay();
      break;
    case 'q':
      if (fingerUp4 > -90)
      fingerUp4 = (fingerUp4 - 5) % 360;
      glutPostRedisplay();
      break;
   case 'Q':
   if (fingerUp4 < 0 )
      fingerUp4 = (fingerUp4 + 5) % 360;
      glutPostRedisplay();
      break;


   case 27:
      exit(0);
      break;
   default:
      break;
   }
}

static void mouse(int button, int state, int x, int y)
{
  if (button == GLUT_LEFT_BUTTON) {
    if (state == GLUT_DOWN) {
      moving = 1;
      startx = x;
      starty = y;
    }
    if (state == GLUT_UP) {
      moving = 0;
    }
  }
}


static void motion(int x, int y)
{
  if (moving) {
    angle = angle + (x - startx);
    angle2 = angle2 + (y - starty);
    startx = x;
    starty = y;
    glutPostRedisplay();
  }
}



int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100);
   glutCreateWindow(argv[0]);
   init();
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}