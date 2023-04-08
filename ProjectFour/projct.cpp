// #include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <stdio.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"
// Game Speed
int FPS = 50;
// Game Track
int start = 0;
int gv = 0;
int level = 0;
// Track Score
int score = 0;
// Form move track
int roadDivTopMost = 0;
int roadDivTop = 0;
int roadDivMdl = 0;
int roadDivBtm = 0;
// For Card Left / RIGHT
int lrIndex = 0;
// Car Coming
int car1 = 0;
int lrIndex1 = 0;
int car2 = +35;
int lrIndex2 = 0;
int car3 = +70;
int lrIndex3 = 0;

// For Display TEXT
char s[60];
void renderBitmapString(float x, float y, void *font, const char *string)
{
    const char *c;
    glRasterPos2f(x, y);
    for (c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}
void startGame()
{
    // Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_QUADS);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();
    // Road Left Border
    glColor3f(0.94, 0.94, 0.94);
    glBegin(GL_QUADS);
    glVertex2f(20, 0);
    glVertex2f(20, 100);
    glVertex2f(23, 100);
    glVertex2f(23, 0);
    glEnd();
    // Road Right Border
    glColor3f(0.94, 0.94, 0.94);
    glBegin(GL_QUADS);
    glVertex2f(77, 0);
    glVertex2f(77, 100);
    glVertex2f(80, 100);
    glVertex2f(80, 0);
    glEnd();
    // Road Middel Border
    // LEFT
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(60, roadDivMdl + 0);
    glVertex2f(60, roadDivMdl + 20);
    glVertex2f(62, roadDivMdl + 20);
    glVertex2f(62, roadDivMdl + 0);
    glEnd();
    roadDivMdl--;
    if (roadDivMdl < -60)
    {
        roadDivMdl = 60;
        score++;
    }
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(60, roadDivMdl + 40);
    glVertex2f(60, roadDivMdl + 70);
    glVertex2f(62, roadDivMdl + 70);
    glVertex2f(62, roadDivMdl + 40);
    glEnd();
    roadDivMdl--;
    if (roadDivMdl < -60)
    {
        roadDivMdl = 60;
        score++;
    }
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(60, roadDivTop + 80);
    glVertex2f(60, roadDivTop + 100);
    glVertex2f(62, roadDivTop + 100);
    glVertex2f(62, roadDivTop + 80);
    glEnd();
    roadDivTop--;
    if (roadDivTop < -100)
    {
        roadDivTop = 20;
        score++;
    }
    // LEFT END
    // RIGHT
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(38, roadDivTop + 80);
    glVertex2f(38, roadDivTop + 100);
    glVertex2f(40, roadDivTop + 100);
    glVertex2f(40, roadDivTop + 80);
    glEnd();
    roadDivTop--;
    if (roadDivTop < -100)
    {
        roadDivTop = 20;
        score++;
    }
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(38, roadDivMdl + 40);
    glVertex2f(38, roadDivMdl + 70);
    glVertex2f(40, roadDivMdl + 70);
    glVertex2f(40, roadDivMdl + 40);
    glEnd();
    roadDivMdl--;
    if (roadDivMdl < -60)
    {
        roadDivMdl = 60;
        score++;
    }

    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(38, roadDivBtm + 0);
    glVertex2f(38, roadDivBtm + 20);
    glVertex2f(40, roadDivBtm + 20);
    glVertex2f(40, roadDivBtm + 0);
    glEnd();
    roadDivBtm--;
    if (roadDivBtm < -20)
    {
        roadDivBtm = 100;
        score++;
    }
    // RIGHT END

    // Score Board
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2f(80, 89);
    glVertex2f(100, 89);
    glVertex2f(100, 98);
    glVertex2f(80, 98);
    glEnd();
    // Print Score
    char buffer[50];
    sprintf(buffer, "SCORE: %d", score);
    glColor3f(0.0, 0.0, 0.0);
    renderBitmapString(80.5, 95, (void *)GLUT_BITMAP_HELVETICA_18, buffer);
    // Speed Print
    char buffer1[50];
    sprintf(buffer1, "SPEED:%dKm/h", FPS - 40);
    glColor3f(0.0, 0.0, 0.0);
    renderBitmapString(80.5, 95 - 2.5, (void *)GLUT_BITMAP_HELVETICA_18, buffer1);
    // level Print
    if (score % 20 == 0)
    {
        int last = score / 20;
        if (last != level)
        {
            level = score / 20;
            FPS = FPS + 2;
        }
    }
    char level_buffer[50];
    sprintf(level_buffer, "LEVEL: %d", level);
    glColor3f(0.0, 0.0, 0.0);
    renderBitmapString(80.5, 95 - 5, (void *)GLUT_BITMAP_HELVETICA_18, level_buffer);
    // Increse Speed With level
    // MAIN car
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26 - 2, 10);
    glVertex2f(lrIndex + 26 - 2, 11);
    glVertex2f(lrIndex + 29 + 2, 11);
    glVertex2f(lrIndex + 29 + 2, 10);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 24.5, 9.5);
    glVertex2f(lrIndex + 24.5, 11.5);
    glVertex2f(lrIndex + 25.5, 11.5);
    glVertex2f(lrIndex + 25.5, 9.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 30.5, 9.5);
    glVertex2f(lrIndex + 30.5, 11.5);
    glVertex2f(lrIndex + 29.5, 11.5);
    glVertex2f(lrIndex + 29.5, 9.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 25 - 2, 4);
    glVertex2f(lrIndex + 25 - 2, 5);
    glVertex2f(lrIndex + 30 + 2, 5);
    glVertex2f(lrIndex + 30 + 2, 4);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 23.5, 3.5);
    glVertex2f(lrIndex + 23.5, 5.5);
    glVertex2f(lrIndex + 24.5, 5.5);
    glVertex2f(lrIndex + 24.5, 3.5);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 30.5, 3.5);
    glVertex2f(lrIndex + 30.5, 5.5);
    glVertex2f(lrIndex + 31.5, 5.5);
    glVertex2f(lrIndex + 31.5, 3.5);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex + 26.5, 12);
    glVertex2f(lrIndex + 25.5, 12);
    glVertex2f(lrIndex + 27, 13);
    glVertex2f(lrIndex + 28, 13);
    glVertex2f(lrIndex + 29.5, 12);
    glVertex2f(lrIndex + 28.5, 12);
    glVertex2f(lrIndex + 28.5, 6);
    glVertex2f(lrIndex + 26.5, 6);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(lrIndex + 26, 3);
    glVertex2f(lrIndex + 26, 7);
    glVertex2f(lrIndex + 29, 7);
    glVertex2f(lrIndex + 29, 3);
    glEnd();
    // main Car End

    // Opposite car 1
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1 + 26, car1 + 100);
    glVertex2f(lrIndex1 + 26, car1 + 100 - 10);
    glVertex2f(lrIndex1 + 32, car1 + 100 - 10);
    glVertex2f(lrIndex1 + 32, car1 + 100);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex1 + 28 - 1.5, car1 + 100 - 10);
    glVertex2f(lrIndex1 + 28 - 1.5, car1 + 100 - 14);
    glVertex2f(lrIndex1 + 30 + 1.5, car1 + 100 - 14);
    glVertex2f(lrIndex1 + 30 + 1.5, car1 + 100 - 10);
    glEnd();
    car1--;
    if (car1 < -100)
    {
        car1 = 0;
        lrIndex1 = lrIndex;
    }
    // KIll check car1
    if ((abs(lrIndex - lrIndex1) < 8) && (car1 + 100 < 10))
    {
        start = 0;
        gv = 1;
    }
    // Opposite car 2
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26, car2 + 100 - 1);
    glVertex2f(lrIndex2 + 27, car2 + 100);
    glVertex2f(lrIndex2 + 32, car2 + 100);
    glVertex2f(lrIndex2 + 33, car2 + 100 - 1);
    glVertex2f(lrIndex2 + 33, car2 + 85);
    glVertex2f(lrIndex2 + 31.5, car2 + 84);
    glVertex2f(lrIndex2 + 27.5, car2 + 84);
    glVertex2f(lrIndex2 + 26, car2 + 85);
    glEnd();
    // spo
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26, car2 + 86);
    glVertex2f(lrIndex2 + 26, car2 + 87);
    glVertex2f(lrIndex2 + 25 + 0.5, car2 + 88);
    glVertex2f(lrIndex2 + 25 + 0.5, car2 + 88.5);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(lrIndex2 + 24 + 0.5, car2 + 88.5);
    glVertex2f(lrIndex2 + 24 + 0.5, car2 + 87);
    glVertex2f(lrIndex2 + 25 + 0.5, car2 + 87);
    glEnd();
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 33, car2 + 86);
    glVertex2f(lrIndex2 + 33, car2 + 87);
    glVertex2f(lrIndex2 + 34 - 0.5, car2 + 88);
    glVertex2f(lrIndex2 + 34 - 0.5, car2 + 88.5);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(lrIndex2 + 35 - 0.5, car2 + 88.5);
    glVertex2f(lrIndex2 + 35 - 0.5, car2 + 87);
    glVertex2f(lrIndex2 + 34 - 0.5, car2 + 87);
    glEnd();
    // end spo
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26.5, car2 + 87);
    glVertex2f(lrIndex2 + 32.5, car2 + 87);
    glVertex2f(lrIndex2 + 32.5, car2 + 86);
    glVertex2f(lrIndex2 + 31, car2 + 84.5);
    glVertex2f(lrIndex2 + 28, car2 + 84.5);
    glVertex2f(lrIndex2 + 26.5, car2 + 86);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(lrIndex2 + 26.5, car2 + 90 - 2.5);
    glVertex2f(lrIndex2 + 32.5, car2 + 90 - 2.5);
    glVertex2f(lrIndex2 + 32.5, car2 + 97);
    glVertex2f(lrIndex2 + 26.5, car2 + 97);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex2 + 26.5, car2 + 97.5);
    glVertex2f(lrIndex2 + 32.5, car2 + 97.5);
    glVertex2f(lrIndex2 + 32.5, car2 + 98.5);
    glVertex2f(lrIndex2 + 32, car2 + 100 - 0.5);
    glVertex2f(lrIndex2 + 27, car2 + 100 - 0.5);
    glVertex2f(lrIndex2 + 26.5, car2 + 98.5);
    glEnd();
    car2--;
    if (car2 < -100)
    {
        car2 = 0;
        lrIndex2 = lrIndex;
    }
    // KIll check car2
    if ((abs(lrIndex - lrIndex2) < 8) && (car2 + 100 < 10))
    {
        start = 0;
        gv = 1;
    }
    // Opposite car 3
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3 + 26, car3 + 100 - 1);
    glVertex2f(lrIndex3 + 27, car3 + 100);
    glVertex2f(lrIndex3 + 32, car3 + 100);
    glVertex2f(lrIndex3 + 33, car3 + 100 - 1);
    glVertex2f(lrIndex3 + 33, car3 + 85);
    glVertex2f(lrIndex3 + 31.5, car3 + 84);
    glVertex2f(lrIndex3 + 27.5, car3 + 84);
    glVertex2f(lrIndex3 + 26, car3 + 85);
    glEnd();
    // spo
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3 + 26, car3 + 86);
    glVertex2f(lrIndex3 + 26, car3 + 87);
    glVertex2f(lrIndex3 + 25 + 0.5, car3 + 88);
    glVertex2f(lrIndex3 + 25 + 0.5, car3 + 88.5);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(lrIndex3 + 24 + 0.5, car3 + 88.5);
    glVertex2f(lrIndex3 + 24 + 0.5, car3 + 87);
    glVertex2f(lrIndex3 + 25 + 0.5, car3 + 87);
    glEnd();
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3 + 33, car3 + 86);
    glVertex2f(lrIndex3 + 33, car3 + 87);
    glVertex2f(lrIndex3 + 34 - 0.5, car3 + 88);
    glVertex2f(lrIndex3 + 34 - 0.5, car3 + 88.5);
    glColor3f(0.9, 0.9, 0.9);
    glVertex2f(lrIndex3 + 35 - 0.5, car3 + 88.5);
    glVertex2f(lrIndex3 + 35 - 0.5, car3 + 87);
    glVertex2f(lrIndex3 + 34 - 0.5, car3 + 87);
    glEnd();
    // end spo
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3 + 26.5, car3 + 87);
    glVertex2f(lrIndex3 + 32.5, car3 + 87);
    glVertex2f(lrIndex3 + 32.5, car3 + 86);
    glVertex2f(lrIndex3 + 31, car3 + 84.5);
    glVertex2f(lrIndex3 + 28, car3 + 84.5);
    glVertex2f(lrIndex3 + 26.5, car3 + 86);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(lrIndex3 + 26.5, car3 + 90 - 2.5);
    glVertex2f(lrIndex3 + 32.5, car3 + 90 - 2.5);
    glVertex2f(lrIndex3 + 32.5, car3 + 97);
    glVertex2f(lrIndex3 + 26.5, car3 + 97);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(lrIndex3 + 26.5, car3 + 97.5);
    glVertex2f(lrIndex3 + 32.5, car3 + 97.5);
    glVertex2f(lrIndex3 + 32.5, car3 + 98.5);
    glVertex2f(lrIndex3 + 32, car3 + 100 - 0.5);
    glVertex2f(lrIndex3 + 27, car3 + 100 - 0.5);
    glVertex2f(lrIndex3 + 26.5, car3 + 98.5);
    glEnd();
    car3--;
    if (car3 < -100)
    {
        car3 = 0;
        lrIndex3 = lrIndex;
    }
    // KIll check car3
    if ((abs(lrIndex - lrIndex3) < 8) && (car3 + 100 < 10))
    {
        start = 0;
        gv = 1;
    }
    /*//Opposite car 4
        glColor3f(1.0, 0.0, 0.0);
      glBegin(GL_POLYGON);
      glVertex2f(lrIndex4+26,car4+100);
      glVertex2f(lrIndex4+26,car4+100-10);
      glVertex2f(lrIndex4+32,car4+100-10);
      glVertex2f(lrIndex4+32,car4+100);
       glEnd();
            glColor3f(0.0, 1.0, 0.0);
      glBegin(GL_POLYGON);
      glVertex2f(lrIndex4+28-1.5,car4+100-10);
      glVertex2f(lrIndex4+28-1.5,car4+100-14);
      glVertex2f(lrIndex4+30+1.5,car4+100-14);
      glVertex2f(lrIndex4+30+1.5,car4+100-10);
      glEnd();
      car4--;
      if(car4<-140){
          car4=0;
          lrIndex4=lrIndex;
      }
      //KIll check car4
      if((abs(lrIndex-lrIndex4)<8) && (car4+100<10)){
              start = 0;
              gv=1;
      }*/
}

void fristDesign()
{
    if (gv == 0)
    {
        // Background road
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2f(30, 0);
        glVertex2f(100, 40);
        glVertex2f(100, 80);
        glVertex2f(0, 30);
        glVertex2f(0, 0);
        glEnd();
        // center
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex2f(0, 6);
        glVertex2f(0, 0);
        glVertex2f(29, 20);
        glVertex2f(27, 24);
        glEnd();
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex2f(40, 27);
        glVertex2f(80, 51);
        glVertex2f(78, 55);
        glVertex2f(38, 31);
        glEnd();
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        glVertex2f(90, 57);
        glVertex2f(100, 63);
        glVertex2f(100, 68);
        glVertex2f(88, 61);
        glEnd();
        // left road
        glColor3f(0.94, 0.94, 0.94);
        glBegin(GL_QUADS);
        glVertex2f(30, 0);
        glVertex2f(100, 40);
        glVertex2f(100, 37);
        glVertex2f(35, 0);
        glEnd();
        // right road
        glColor3f(0.94, 0.94, 0.94);
        glBegin(GL_QUADS);
        glVertex2f(0, 30);
        glVertex2f(100, 80);
        glVertex2f(100, 82);
        glVertex2f(0, 32);
        glEnd();
        // Text Information in Frist Page
        glColor3f(1.0, 1.0, 0.0);
        renderBitmapString(0, 95, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "************************************************************");
        glColor3f(1.0, 1.0, 0.0);
        renderBitmapString(20, 90, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "ARBA MINCH UNIVERSITY");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(15, 90, (void *)GLUT_BITMAP_HELVETICA_18, "______________________________________");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(30, 85, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "COMPUTER GRAPHICS");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(35, 80, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "PROJECT");
        glColor3f(0.000, 1.000, 0.000);
        renderBitmapString(15, 70, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "2D");
        glColor3f(0.000, 1.000, 0.000);
        renderBitmapString(25, 70, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "Car Game");
        glColor3f(0.200, 1.000, 0.900);
        renderBitmapString(5, 58, (void *)GLUT_BITMAP_HELVETICA_18, "SPACE BUTTON TO START");
        renderBitmapString(5, 55, (void *)GLUT_BITMAP_HELVETICA_18, "ESC BUTTON TO EXIT");
    }
    else if (gv == 1)
    {
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(25, 75, (void *)GLUT_BITMAP_HELVETICA_18, "**********************************************************");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(40, 72, (void *)GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER");
        glColor3f(1.0, 0.0, 0.0);
        char buffer2[50];
        sprintf(buffer2, "Score: %d", score);
        renderBitmapString(33, 68, (void *)GLUT_BITMAP_HELVETICA_18, buffer2);
        char buffer[50];
        sprintf(buffer, "Level: %d", level);
        renderBitmapString(50, 68, (void *)GLUT_BITMAP_HELVETICA_18, buffer);
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(38, 65, (void *)GLUT_BITMAP_HELVETICA_10, "* Press UP Arrow Button to increase Speed");
        renderBitmapString(38, 63, (void *)GLUT_BITMAP_HELVETICA_10, "* Press DWON Arrow Button to decrease Speed");
        renderBitmapString(38, 61, (void *)GLUT_BITMAP_HELVETICA_10, "* Press RIGHT Arrow Button to turn Right");
        renderBitmapString(38, 59, (void *)GLUT_BITMAP_HELVETICA_10, "* Press LEFT Arrow Button to turn Left");
        glColor3f(0.2, 1.0, 0.9);
        renderBitmapString(33, 55, (void *)GLUT_BITMAP_HELVETICA_18, "***DO YOU WANT TO CONTINUE?***");
        glColor3f(0.2, 1.0, 0.9);
        renderBitmapString(30, 52, (void *)GLUT_BITMAP_HELVETICA_10, "* SPACE BUTTON TO START NEW GAME");
        renderBitmapString(30, 50, (void *)GLUT_BITMAP_HELVETICA_10, "* ESC BUTTON TO EXIT");
        glColor3f(1.0, 1.0, 1.0);
        renderBitmapString(25, 46, (void *)GLUT_BITMAP_HELVETICA_18, "**********************************************************");
    }
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if (start == 1)
    {
        glClearColor(0.0, 0.0, 0.0, 0.0);
        startGame();
    }
    else
    {
        fristDesign();
    }
    glFlush();
    glutSwapBuffers();
}
void spe_key(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_DOWN:
        if (FPS > (50 + (level * 2)))
            FPS = FPS - 20;
        break;
    case GLUT_KEY_UP:
        FPS = FPS + 20;
        break;

    case GLUT_KEY_LEFT:
        if (lrIndex >= 0)
        {
            lrIndex = lrIndex - (FPS / 10);
            if (lrIndex < 0)
            {
                lrIndex = -1;
            }
        }
        break;
    case GLUT_KEY_RIGHT:
        if (lrIndex <= 44)
        {
            lrIndex = lrIndex + (FPS / 10);
            if (lrIndex > 44)
            {
                lrIndex = 45;
            }
        }
        break;
    default:
        break;
    }
}
void processKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':
        if (start == 0)
        {
            start = 1;
            gv = 0;
            FPS = 50;
            roadDivTopMost = 0;
            roadDivTop = 0;
            roadDivMdl = 0;
            roadDivBtm = 0;
            lrIndex = 0;
            car1 = 0;
            lrIndex1 = 0;
            car2 = +35;
            lrIndex2 = 0;
            car3 = +80;
            lrIndex3 = 0;
            score = 0;
            level = 0;
        }
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}
void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / FPS, timer, 0);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(700, 600);
    glutInitWindowPosition(200, 20);
    glutCreateWindow("2D CAR GAME");
    // PlaySound(TEXT("Its_Gonna_Take_Some_Time.wav"), NULL, SND_ASYNC);
    // PlaySound(TEXT("avion1.wav"), NULL, SND_ASYNC);
    glutDisplayFunc(display);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys);
    gluOrtho2D(0, 100, 0, 100);
    glClearColor(0.184, 0.310, 0.310, 1);
    glutTimerFunc(1000, timer, 0);
    glutMainLoop();
    return 0;
}