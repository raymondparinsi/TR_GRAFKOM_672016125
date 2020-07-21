#include <iostream>
#include <GL/freeglut.h>
#include <math.h>

void display();
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
void keyboard(unsigned char, int, int);

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		std::cout << "KLIK KIRI" << " = anda menekan LEFT_BUTTON" << std::endl;
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
		mouseDown = false;
	display();
}

void mouseMotion(int x, int y) {
	if (mouseDown) {
		yrot = x - xdiff;
		xrot = y + ydiff;

		glLoadIdentity();
		gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f); //mengatur penglihatan objek
		glRotatef(xrot, 1.0, 0.0, 0.0);
		glRotatef(yrot, 0.0, 1.0, 0.0);
		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'g':
	case 'G':
		glTranslatef(0.0, 0.0, -3.0);
		break;
	case 'h':
	case 'H':
		glTranslatef(0.0, 0.0, 3.0);
		break;

	case 'w':                                   ////zoom in
	case 'W':
		glScalef(0.75, 0.75, 0.75);
		break;
	case 'd':                                   ////geser kanan
	case 'D':
		glTranslatef(3.0, 0.0, 0.0);
		break;
	case 's':                                    ///zoom out
	case 'S':
		glScalef(1.75, 1.75, 1.75);
		break;
	case 'a':                                   ////geser kiri
	case 'A':
		glTranslatef(-3.0, 0.0, 0.0);
		break;
	case'q':                                    ////gser atas
	case'Q':
		glTranslatef(0.0, 3.0, 0.0);
		break;
	case 'e':
	case 'E':
		glTranslatef(0.0, -3.0, 0.0);
		break;
	case 'x':                                   ///putar kanan ke kiri
	case 'X':
		glRotatef(2.0, 0.0, 0.0, 1.0);
		break;
	case 'z':                                   ///putar kiri ke kanan 
	case 'Z':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;

	case 'f':
	case 'F':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
	}
	display();
}

void specialKeyboard(int key, int x, int y)
{
	switch (key) {
	case 100:
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case 101:
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case 102:
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case 103:
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	}
	glutPostRedisplay();
}


////////////												Object
void bodybawah(int r, int g, int b) {

	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-13.0, -20.0, -90.0);
	glVertex3f(13.5, -20.0, -90.0);
	glVertex3f(13.0, -20.0, -105.0);
	glVertex3f(-13.0, -20.0, -105.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, -20.0, -105.0);             ///depan kiri
	glVertex3f(5.0, -20.0, -105.0);              ///kanan depan
	glVertex3f(5.0, -20.0, -115.0);             ///kanan belakang
	glVertex3f(-5.0, -20.0, -115.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, -20.0, -115.0);           ///kiri belakang
	glVertex3f(5.0, -20.0, -115.0);             ///kanan belakang
	glVertex3f(5.0, 0.0, -117.0);             ///kanan belakang
	glVertex3f(-5.0, 0.0, -117.0);           ///kiri belakang
	glEnd();

	/////////////////////////////////////////////						///lantai atas 1 melengkung
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-20.0, 0.0, -90.0);
	glVertex3f(-18.5, 0.0, -102.0);
	glVertex3f(-18.5, 0.0, -102.0);
	glVertex3f(-17.0, 0.0, -106.0);
	glVertex3f(-17.0, 0.0, -106.0);
	glVertex3f(-15.0, 0.0, -110.0);
	glVertex3f(-15.0, 0.0, -110.0);
	glVertex3f(-10.0, 0.0, -115.0);
	glVertex3f(-10.0, 0.0, -115.0);
	glVertex3f(-5.0, 0.0, -117.0);
	glVertex3f(-5.0, 0.0, -117.0);
	glVertex3f(5.0, 0.0, -117.0);
	glVertex3f(5.0, 0.0, -117.0);
	glVertex3f(10.0, 0.0, -115.0);
	glVertex3f(10.0, 0.0, -115.0);
	glVertex3f(15.0, 0.0, -110.0);
	glVertex3f(15.0, 0.0, -110.0);
	glVertex3f(17.0, 0.0, -106.0);
	glVertex3f(17.0, 0.0, -106.0);
	glVertex3f(18.5, 0.0, -102.0);
	glVertex3f(18.5, 0.0, -102.0);
	glVertex3f(20.0, 0.0, -90.0);

	glEnd();

	///////////////////////////////// 

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(5.0, -20.0, -115.0);
	glVertex3f(5.0, -20.0, -105.0);
	glVertex3f(10.0, -20.0, -113.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(5.0, -20.0, -115.0);           ///kiri belakang
	glVertex3f(10.0, -20.0, -113.0);           ///kanan belakang
	glVertex3f(10.0, 0.0, -115.0);            ///kanan belakang
	glVertex3f(5.0, 0.0, -117.0);            ///kiri belakang
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, -20.0, -115.0);
	glVertex3f(-10.0, -20.0, -113.0);
	glVertex3f(-10.0, 0.0, -115.0);
	glVertex3f(-5.0, 0.0, -117.0);
	glEnd();

	///////////////////////////////// 
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0, -20.0, -113.0);		//kiri belakang
	glVertex3f(5.0, -20.0, -105.0);			//kiri depan
	glVertex3f(10.0, -20.0, -100.0);		//depan kanan
	glVertex3f(15.0, -20.0, -108.0);		//belakang kanan
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0, -20.0, -113.0);          ///kiri belakang
	glVertex3f(15.0, -20.0, -108.0);         ///kanan belakang
	glVertex3f(15.0, 0.0, -110.0);              ///kanan belakang
	glVertex3f(10.0, 0.0, -115.0);            ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-10.0, -20.0, -113.0);
	glVertex3f(-15.0, -20.0, -108.0);
	glVertex3f(-15.0, 0.0, -110.0);
	glVertex3f(-10.0, 0.0, -115.0);
	glEnd();
	///////////////////////////////// 

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(15.0, -20.0, -108.0);
	glVertex3f(10.0, -20.0, -100.0);
	glVertex3f(17.0, -20.0, -104.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(15.0, -20.0, -108.0);         ///kiri belakang
	glVertex3f(17.0, -20.0, -104.0);       ///kanan belakang
	glVertex3f(17.0, 0.0, -106.0);             ///kanan belakang
	glVertex3f(15.0, 0.0, -110.0);          ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-15.0, -20.0, -108.0);
	glVertex3f(-17.0, -20.0, -104.0);
	glVertex3f(-17.0, 0.0, -106.0);
	glVertex3f(-15.0, 0.0, -110.0);
	glEnd();
	/////////////////////////////////
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(17.0, -20.0, -104.0);
	glVertex3f(10.0, -20.0, -100.0);
	glVertex3f(18.5, -20.0, -100.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(17.0, -20.0, -104.0);         ///kiri belakang
	glVertex3f(18.5, -20.0, -100.0);      ///kanan belakang
	glVertex3f(18.5, 0.0, -102.0);            ///kanan belakang
	glVertex3f(17.0, 0.0, -106.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-17.0, -20.0, -104.0);
	glVertex3f(-18.5, -20.0, -100.0);
	glVertex3f(-18.5, 0.0, -102.0);
	glVertex3f(-17.0, 0.0, -106.0);
	glEnd();
	/////////////////////////////////
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0, -20.0, -100.0);
	glVertex3f(18.5, -20.0, -100.0);
	glVertex3f(20.0, -20.0, -90.0);
	glVertex3f(13.0, -20.0, -90.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(18.5, -20.0, -100.0);        ///kiri belakang
	glVertex3f(20.0, -20.0, -90.0);      ///kanan belakang
	glVertex3f(20.0, 0.0, -90.0);            ///kanan belakang
	glVertex3f(18.5, 0.0, -102.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-18.5, -20.0, -100.0);
	glVertex3f(-20.0, -20.0, -90.0);
	glVertex3f(-20.0, 0.0, -90.0);
	glVertex3f(-18.5, 0.0, -102.0);
	glEnd();
	///////////////// kiri
	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, -20.0, -115.0);
	glVertex3f(-5.0, -20.0, -105.0);
	glVertex3f(-10.0, -20.0, -113.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-10.0, -20.0, -113.0);
	glVertex3f(-5.0, -20.0, -105.0);
	glVertex3f(-10.0, -20.0, -100.0);
	glVertex3f(-15.0, -20.0, -108.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-15.0, -20.0, -108.0);
	glVertex3f(-10.0, -20.0, -100.0);
	glVertex3f(-17.0, -20.0, -104.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-17.0, -20.0, -104.0);
	glVertex3f(-10.0, -20.0, -100.0);
	glVertex3f(-18.5, -20.0, -100.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-10.0, -20.0, -100.0);
	glVertex3f(-18.5, -20.0, -100.0);
	glVertex3f(-20.0, -20.0, -90.0);
	glVertex3f(-13.0, -20.0, -90.0);
	glEnd();

	///////////////////////////////////
																		//dasar
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -20.0, 60.0);
	glVertex3f(20.0, -20.0, 60.0);
	glVertex3f(20.0, -20.0, -90.0);
	glVertex3f(-20.0, -20.0, -90.0);
	glEnd();

	/////////////////////////////////////
	glBegin(GL_QUADS);												//lantai atas 1
	//glColor3f(1.5, 1.5, 1.5);
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-20.0, 0.0, 60.0);             ///depan kiri
	glVertex3f(20.0, 0.0, 60.0);              ///kanan depan
	glVertex3f(20.0, 0.0, -90.0);             ///kanan belakang
	glVertex3f(-20.0, 0.0, -90.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(20.0, 3.0, 60.0);
	glVertex3f(20.0, 3.0, 70.0);
	glVertex3f(-20.0, 3.0, 70.0);
	glVertex3f(-20.0, 3.0, 60.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 0.0, 60.0);
	glVertex3f(20.0, 0.0, 60.0);
	glVertex3f(20.0, 3.0, 60.0);
	glVertex3f(-20.0, 3.0, 60.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0, 128, 0);
	glVertex3f(-20.0, 3.0, 70.0);
	glVertex3f(20.0, 3.0, 70.0);
	glVertex3f(20.0, 3.0, 75.0);
	glVertex3f(0.0, 3.0, 118.0);
	glVertex3f(-20.0, 3.0, 75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 3.0, 70.0);
	glVertex3f(20.0, 3.0, 70.0);
	glVertex3f(20.0, 4.0, 70.0);
	glVertex3f(-20.0, 4.0, 70.0);
	glEnd();

	glBegin(GL_POLYGON);				////lantai kecil depan
	glColor3f(0.3, 128.3, 0.3);
	glVertex3f(15.0, 4.0, 69.0);
	glVertex3f(15.0, 4.0, 75.0);
	glVertex3f(13.0, 4.0, 80.0);
	glVertex3f(10.0, 4.0, 85.0);
	glVertex3f(5.0, 4.0, 90.0);			//tengah
	glVertex3f(-5.0, 4.0, 90.0);		//tengah
	glVertex3f(-10.0, 4.0, 85.0);
	glVertex3f(-13.0, 4.0, 80.0);
	glVertex3f(-15.0, 4.0, 75.0);
	glVertex3f(-15.0, 4.0, 69.0);
	glEnd();

	glBegin(GL_POLYGON);				////lantai kecil depan
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(15.0, 4.0, 69.0);
	glVertex3f(15.0, 4.0, 75.0);
	glVertex3f(13.0, 4.0, 80.0);
	glVertex3f(10.0, 4.0, 85.0);
	glVertex3f(5.0, 4.0, 90.0);			//tengah
	glVertex3f(-5.0, 4.0, 90.0);		//tengah
	glVertex3f(-10.0, 4.0, 85.0);
	glVertex3f(-13.0, 4.0, 80.0);
	glVertex3f(-15.0, 4.0, 75.0);
	glVertex3f(-15.0, 4.0, 69.0);
	//
	glVertex3f(-15.0, 3.0, 69.0);
	glVertex3f(-15.0, 3.0, 75.0);
	glVertex3f(-13.0, 3.0, 80.0);
	glVertex3f(-10.0, 3.0, 85.0);
	glVertex3f(-5.0, 3.0, 90.0);
	glVertex3f(5.0, 3.0, 90.0);
	glVertex3f(10.0, 3.0, 85.0);
	glVertex3f(13.0, 3.0, 80.0);
	glVertex3f(15.0, 3.0, 75.0);
	glVertex3f(15.0, 3.0, 69.0);
	glEnd();

	/////////////////////////////////////

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -20.0, 60.0);             ///kiri b
	glVertex3f(0.0, -20.0, 100.0);              ///depan kanan
	glVertex3f(20.0, -20.0, 60.0);             ///kanan belakang
	glEnd();

	glBegin(GL_POLYGON);												///body kanan
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(20.0, 0.0, 60.0);             ///depan kiri
	glVertex3f(20.0, -20.0, 60.0);              ///depan kanan
	glVertex3f(20.0, -20.0, -90.0);             ///kanan belakang
	glVertex3f(20.0, 0.0, -90.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 0.0);
	glVertex3f(20.0, 3.0, 60.0);             ///depan kiri
	glVertex3f(20.0, -20.0, 60.0);              ///depan kanan
	glVertex3f(20.0, -6.0, 70.0);
	glVertex3f(20.0, 3.0, 70.0);             ///kanan belakang
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, -6.0, 70.0);             ///depan kiri
	glVertex3f(20.0, 4.3, 70.0);              ///depan kanan
	glVertex3f(20.0, 4.3, 77.0);
	glEnd();

	//////moncong kanan
	glBegin(GL_POLYGON);
	glVertex3f(20.0, -20.0, 60.0);
	glVertex3f(20.0, 4.3, 77.0);
	glVertex3f(0.0, 4.3, 120.0);
	glVertex3f(0.0, -20.0, 100.0);
	glEnd();

	glBegin(GL_POLYGON);												///body kiri
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-20.0, 0.0, 60.0);             ///depan kiri
	glVertex3f(-20.0, -20.0, 60.0);              ///depan kanan
	glVertex3f(-20.0, -20.0, -90.0);             ///kanan belakang
	glVertex3f(-20.0, 0.0, -90.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-20.0, 3.0, 60.0);             ///depan kiri
	glVertex3f(-20.0, -20.0, 60.0);              ///depan kanan
	glVertex3f(-20.0, -6.0, 70.0);
	glVertex3f(-20.0, 3.0, 70.0);             ///kanan belakang
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-20.0, -6.0, 70.0);             ///depan kiri
	glVertex3f(-20.0, 4.3, 70.0);              ///depan kanan
	glVertex3f(-20.0, 4.3, 77.0);
	glEnd();
	//////mocong kanan
	glBegin(GL_POLYGON);
	glVertex3f(-20.0, -20.0, 60.0);
	glVertex3f(-20.0, 4.3, 77.0);
	glVertex3f(0.0, 4.3, 120.0);
	glVertex3f(0.0, -20.0, 100.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -20.0, -90.0);
	glVertex3f(-18.5, -20.0, -107.0);
	glVertex3f(-18.5, -20.0, -107.0);
	glVertex3f(-17.0, -20.0, -111.0);
	glVertex3f(-17.0, -20.0, -111.0);
	glVertex3f(-15.0, -20.0, -115.0);
	glVertex3f(-15.0, -20.0, -115.0);
	glVertex3f(-10.0, -20.0, -120.0);
	glVertex3f(-10.0, -20.0, -120.0);
	glVertex3f(-5.0, -20.0, -122.0);
	glVertex3f(-5.0, -20.0, -122.0);
	glVertex3f(5.0, -20.0, -122.0);
	glVertex3f(5.0, -20.0, -122.0);
	glVertex3f(10.0, -20.0, -120.0);
	glVertex3f(10.0, -20.0, -120.0);
	glVertex3f(15.0, -20.0, -115.0);
	glVertex3f(15.0, -20.0, -115.0);
	glVertex3f(17.0, -20.0, -111.0);
	glVertex3f(17.0, -20.0, -111.0);
	glVertex3f(18.5, -20.0, -107.0);
	glVertex3f(18.5, -20.0, -107.0);
	glVertex3f(20.0, -20.0, -90.0);
	glEnd();
}

void bodyatas(int r, int g, int b) {


	glBegin(GL_POLYGON);				////bodi tengah depan
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-18.0, 0.0, 75.0);
	glVertex3f(18.0, 0.0, 75.0);
	glVertex3f(18.0, 28.0, 62.0);
	glVertex3f(-18.0, 28.0, 62.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi tengah belakang
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-18.0, 0.0, -90.0);
	glVertex3f(18.0, 0.0, -90.0);
	glVertex3f(18.0, 28.0, -90.0);
	glVertex3f(-18.0, 28.0, -90.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi tengah kanan
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(18.0, 0.0, 75.0);
	glVertex3f(18.0, 0.0, -90.0);
	glVertex3f(18.0, 28.0, -90.0);
	glVertex3f(18.0, 28.0, 62.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi tengah kiri
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-18.0, 0.0, 75.0);
	glVertex3f(-18.0, 0.0, -90.0);
	glVertex3f(-18.0, 28.0, -90.0);
	glVertex3f(-18.0, 28.0, 62.0);
	glEnd();

}

void depankapal(int r, int g, int b) {

	glBegin(GL_POLYGON);				////bodi depan tengah
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-5.0, 4.6, 82.0);
	glVertex3f(5.0, 4.6, 82.0);
	glVertex3f(5.0, 23.0, 70.0);
	glVertex3f(-5.0, 23.0, 70.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi depan kanan
	glVertex3f(5.0, 4.6, 82.0);
	glVertex3f(5.0, 23.0, 70.0);
	glVertex3f(13.0, 23.0, 68.0);
	glVertex3f(15.0, 4.6, 79.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi depan kanan
	glVertex3f(-5.0, 4.6, 82.0);
	glVertex3f(-5.0, 23.0, 70.0);
	glVertex3f(-13.0, 23.0, 68.0);
	glVertex3f(-15.0, 4.6, 79.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi depan kanan2
	glVertex3f(15.0, 4.6, 79.0);
	glVertex3f(20.0, 4.3, 75.0);
	glVertex3f(18.0, 23.0, 65.0);
	glVertex3f(13.0, 23.0, 68.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi depan kiri2
	glVertex3f(-15.0, 4.6, 79.0);
	glVertex3f(-20.0, 4.3, 75.0);
	glVertex3f(-18.0, 23.0, 65.0);
	glVertex3f(-13.0, 23.0, 68.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi depan kanan3
	glVertex3f(20.0, 4.3, 75.0);
	glVertex3f(20.0, 4.3, 70.0);
	glVertex3f(18.0, 23.0, 60.0);
	glVertex3f(18.0, 23.0, 65.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi depan kiri3
	glVertex3f(-20.0, 4.3, 75.0);
	glVertex3f(-20.0, 4.3, 70.0);
	glVertex3f(-18.0, 23.0, 60.0);
	glVertex3f(-18.0, 23.0, 65.0);
	glEnd();

	////////////////////////////////////////////////////////////

}

////////////

void display() {

	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);


	bodybawah(255, 255, 255);
	bodyatas(255, 255, 255);
	depankapal(255, 255, 255);


	glPushMatrix();
	glPopMatrix();
	glutSwapBuffers();
}


void idle() {
	if (!mouseDown) {
		xrot += 0.3f;
		yrot += 0.4f;
	}

	glutPostRedisplay();
}


void ukuran(int lebar, int tinggi) {
	if (tinggi == 0)
		tinggi = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(55.0, lebar / tinggi, 50.0, 500.0);
	glTranslatef(-5.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1020, 680);
	glutInitWindowPosition(200, 20);
	glutCreateWindow("TR_GRAFKOM_672018209");

	//inisialisasi glut
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_COLOR_MATERIAL);
	glPointSize(5);
	glLineWidth(4);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glLoadIdentity();

	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialKeyboard);
	glutReshapeFunc(ukuran);
	glutIdleFunc(display);
	glutMainLoop();
	return 0;
}

