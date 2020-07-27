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
int fungsitom;
float s, t, p, u, i, o, q, w, e;
float ta;
float tb;


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
	case 's':                                   ///zoom out
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

	case 'K':                                   ///putar kiri ke kanan 
	case 'k':
		if (fungsitom)
		{
			fungsitom = 0;
			glDisable(GL_LIGHTING);
			glDisable(GL_LIGHT0);
			glDisable(GL_COLOR_MATERIAL);
			u = 0.0;
			i = 0.0;
			o = 0.0;
		}
		else
		{
			fungsitom = 1;
			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT6);
			glEnable(GL_COLOR_MATERIAL);
			u = 0.0;
			i = -128;
			o = 0.0;
		}
		break;

	case 'l':                                   ///putar kiri ke kanan 
	case 'L':
		if (fungsitom)
		{
			fungsitom = 0;
			s = 0.0;
			t = 0.0;
			p = 0.0;

			q = 0.0;
			w = 0.0;
			e = 0.0;

		}
		else
		{
			fungsitom = 1;
			s = 0.0;
			t = 128.0;
			p = 0.0;

			q = 0.3;
			w = 128.3;
			e = 0.3;
		}
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

void dasar(int r, int g, int b) {

	glBegin(GL_QUADS);
	glColor3f(0.8, 0.8, 0.8);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-13.0, -20.0, -90.0);
	glVertex3f(13.5, -20.0, -90.0);
	glVertex3f(13.0, -20.0, -105.0);
	glVertex3f(-13.0, -20.0, -105.0);
	glEnd();

	glBegin(GL_QUADS);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, -20.0, -105.0);             ///depan kiri
	glVertex3f(5.0, -20.0, -105.0);              ///kanan depan
	glVertex3f(5.0, -20.0, -115.0);             ///kanan belakang
	glVertex3f(-5.0, -20.0, -115.0);           ///kiri belakang
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(5.0, -20.0, -115.0);
	glVertex3f(5.0, -20.0, -105.0);
	glVertex3f(10.0, -20.0, -113.0);
	glEnd();

	glBegin(GL_QUADS);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0, -20.0, -113.0);		//kiri belakang
	glVertex3f(5.0, -20.0, -105.0);			//kiri depan
	glVertex3f(10.0, -20.0, -100.0);		//depan kanan
	glVertex3f(15.0, -20.0, -108.0);		//belakang kanan
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(15.0, -20.0, -108.0);
	glVertex3f(10.0, -20.0, -100.0);
	glVertex3f(17.0, -20.0, -104.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(17.0, -20.0, -104.0);
	glVertex3f(10.0, -20.0, -100.0);
	glVertex3f(18.5, -20.0, -100.0);
	glEnd();

	glBegin(GL_QUADS);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0, -20.0, -100.0);
	glVertex3f(18.5, -20.0, -100.0);
	glVertex3f(20.0, -20.0, -90.0);
	glVertex3f(13.0, -20.0, -90.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, -20.0, -115.0);
	glVertex3f(-5.0, -20.0, -105.0);
	glVertex3f(-10.0, -20.0, -113.0);
	glEnd();

	glBegin(GL_QUADS);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-10.0, -20.0, -113.0);
	glVertex3f(-5.0, -20.0, -105.0);
	glVertex3f(-10.0, -20.0, -100.0);
	glVertex3f(-15.0, -20.0, -108.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-15.0, -20.0, -108.0);
	glVertex3f(-10.0, -20.0, -100.0);
	glVertex3f(-17.0, -20.0, -104.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-17.0, -20.0, -104.0);
	glVertex3f(-10.0, -20.0, -100.0);
	glVertex3f(-18.5, -20.0, -100.0);
	glEnd();

	glBegin(GL_QUADS);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-10.0, -20.0, -100.0);
	glVertex3f(-18.5, -20.0, -100.0);
	glVertex3f(-20.0, -20.0, -90.0);
	glVertex3f(-13.0, -20.0, -90.0);
	glEnd();

	glBegin(GL_QUADS);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -20.0, 60.0);
	glVertex3f(20.0, -20.0, 60.0);
	glVertex3f(20.0, -20.0, -90.0);
	glVertex3f(-20.0, -20.0, -90.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-20.0, -20.0, 60.0);             ///kiri b
	glVertex3f(0.0, -20.0, 95.0);              ///depan kanan
	glVertex3f(20.0, -20.0, 60.0);             ///kanan belakang
	glEnd();

	glBegin(GL_POLYGON);
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


	/////////////////////////////////////////////						///lantai atas 1 melengkung
	glBegin(GL_POLYGON);
	//glColor3f(0.6, 0.6, 0.6);
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

	glBegin(GL_QUADS);												//lantai atas 1
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

	glBegin(GL_QUADS);												//lantai kedua dari atas 
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-19.0, 28.0, 60.0);             ///depan kiri
	glVertex3f(19.0, 28.0, 60.0);              ///kanan depan
	glVertex3f(19.0, 28.0, -90.0);             ///kanan belakang
	glVertex3f(-19.0, 28.0, -90.0);           ///kiri belakang
	glEnd();


}

void bodybawah(int r, int g, int b) {

	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-5.0, -20.0, -115.0);           ///kiri belakang
	glVertex3f(5.0, -20.0, -115.0);             ///kanan belakang
	glVertex3f(5.0, 0.0, -117.0);             ///kanan belakang
	glVertex3f(-5.0, 0.0, -117.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(5.0, -20.0, -115.0);           ///kiri belakang
	glVertex3f(10.0, -20.0, -113.0);           ///kanan belakang
	glVertex3f(10.0, 0.0, -115.0);            ///kanan belakang
	glVertex3f(5.0, 0.0, -117.0);            ///kiri belakang
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, -20.0, -115.0);
	glVertex3f(-10.0, -20.0, -113.0);
	glVertex3f(-10.0, 0.0, -115.0);
	glVertex3f(-5.0, 0.0, -117.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(10.0, -20.0, -113.0);          ///kiri belakang
	glVertex3f(15.0, -20.0, -108.0);         ///kanan belakang
	glVertex3f(15.0, 0.0, -110.0);              ///kanan belakang
	glVertex3f(10.0, 0.0, -115.0);            ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-10.0, -20.0, -113.0);
	glVertex3f(-15.0, -20.0, -108.0);
	glVertex3f(-15.0, 0.0, -110.0);
	glVertex3f(-10.0, 0.0, -115.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(15.0, -20.0, -108.0);         ///kiri belakang
	glVertex3f(17.0, -20.0, -104.0);       ///kanan belakang
	glVertex3f(17.0, 0.0, -106.0);             ///kanan belakang
	glVertex3f(15.0, 0.0, -110.0);          ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-15.0, -20.0, -108.0);
	glVertex3f(-17.0, -20.0, -104.0);
	glVertex3f(-17.0, 0.0, -106.0);
	glVertex3f(-15.0, 0.0, -110.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(17.0, -20.0, -104.0);         ///kiri belakang
	glVertex3f(18.5, -20.0, -100.0);      ///kanan belakang
	glVertex3f(18.5, 0.0, -102.0);            ///kanan belakang
	glVertex3f(17.0, 0.0, -106.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-17.0, -20.0, -104.0);
	glVertex3f(-18.5, -20.0, -100.0);
	glVertex3f(-18.5, 0.0, -102.0);
	glVertex3f(-17.0, 0.0, -106.0);
	glEnd();
	/////////////////////////////////

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(18.5, -20.0, -100.0);        ///kiri belakang
	glVertex3f(20.0, -20.0, -90.0);      ///kanan belakang
	glVertex3f(20.0, 0.0, -90.0);            ///kanan belakang
	glVertex3f(18.5, 0.0, -102.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-18.5, -20.0, -100.0);
	glVertex3f(-20.0, -20.0, -90.0);
	glVertex3f(-20.0, 0.0, -90.0);
	glVertex3f(-18.5, 0.0, -102.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-20.0, 0.0, 60.0);
	glVertex3f(20.0, 0.0, 60.0);
	glVertex3f(20.0, 3.0, 60.0);
	glVertex3f(-20.0, 3.0, 60.0);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 3.0, 70.0);
	glVertex3f(20.0, 3.0, 70.0);
	glVertex3f(20.0, 4.0, 70.0);
	glVertex3f(-20.0, 4.0, 70.0);
	glEnd();

	glBegin(GL_POLYGON);												///body kanan
	//glColor3f(1.0, 0.0, 0.0);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(20.0, 0.0, 60.0);             ///depan kiri
	glVertex3f(20.0, -20.0, 60.0);              ///depan kanan
	glVertex3f(20.0, -20.0, -90.0);             ///kanan belakang
	glVertex3f(20.0, 0.0, -90.0);           ///kanan kiri
	glEnd();



	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 0.0);
	//glColor3f(1.9, 0.9, 1.9);
	glVertex3f(20.0, 3.0, 60.0);             ///depan kiri
	glVertex3f(20.0, -20.0, 60.0);              ///depan kanan
	glVertex3f(20.0, -6.0, 70.0);
	glVertex3f(20.0, 3.0, 70.0);             ///kanan belakang
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, -6.0, 70.0);             ///depan kiri
	glVertex3f(20.0, 4.3, 70.0);              ///depan kanan
	glVertex3f(20.0, 4.3, 77.0);
	glEnd();

	//////moncong kanan
	glBegin(GL_POLYGON);
	glVertex3f(20.0, -20.0, 60.0);
	glVertex3f(20.0, 4.3, 77.0);
	glVertex3f(0.0, 4.3, 110.0);
	glVertex3f(0.0, -20.0, 95.0);
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
	//////mocong kiri
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-20.0, -20.0, 60.0);
	glVertex3f(-20.0, 4.3, 77.0);
	glVertex3f(0.0, 4.3, 110.0);
	glVertex3f(0.0, -20.0, 95.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(7.8, -13.0, 86.0);
	glVertex3f(8.9, -10.0, 86.0);
	glVertex3f(7.6, -10.0, 88.0);
	glVertex3f(6.5, -13.0, 88.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-7.8, -13.0, 86.0);
	glVertex3f(-8.9, -10.0, 86.0);
	glVertex3f(-7.6, -10.0, 88.0);
	glVertex3f(-6.5, -13.0, 88.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(3.0, 1.0, 103.0);
	glVertex3f(2.8, -0.0, 103.0);
	glVertex3f(0.9, -0.0, 106.0);
	glVertex3f(1.2, 1.0, 106.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-3.0, 1.0, 103.0);
	glVertex3f(-2.8, -0.0, 103.0);
	glVertex3f(-0.9, -0.0, 106.0);
	glVertex3f(-1.2, 1.0, 106.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(9.6, 1.0, 92.0);
	glVertex3f(9.3, -0.0, 92.0);
	glVertex3f(7.5, -0.0, 95.0);
	glVertex3f(7.8, 1.0, 95.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-9.6, 1.0, 92.0);
	glVertex3f(-9.3, -0.0, 92.0);
	glVertex3f(-7.5, -0.0, 95.0);
	glVertex3f(-7.8, 1.0, 95.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(16.3, 1.0, 81.0);
	glVertex3f(16.0, -0.0, 81.0);
	glVertex3f(14.2, -0.0, 84.0);
	glVertex3f(14.5, 1.0, 84.0);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-16.3, 1.0, 81.0);
	glVertex3f(-16.0, -0.0, 81.0);
	glVertex3f(-14.2, -0.0, 84.0);
	glVertex3f(-14.5, 1.0, 84.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glVertex3f(16.3, 1.0, 81.0);
	glVertex3f(16.0, -0.0, 81.0);
	glVertex3f(14.2, -0.0, 84.0);
	glVertex3f(14.5, 1.0, 84.0);
	glEnd();

}

void lantai(int r, int g, int b) {
	/////////////////////////////////////////////						///lantai atas 1 melengkung
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
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

	glBegin(GL_QUADS);												//lantai atas 1
	glVertex3f(-20.0, 0.0, 60.0);             ///depan kiri
	glVertex3f(20.0, 0.0, 60.0);              ///kanan depan
	glVertex3f(20.0, 0.0, -90.0);             ///kanan belakang
	glVertex3f(-20.0, 0.0, -90.0);           ///kiri belakang
	glEnd();

	////////////
}

void bodyatas(int r, int g, int b) {


	/*glBegin(GL_POLYGON);				////bodi tengah depan
	glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-18.0, 0.0, 75.0);
	glVertex3f(18.0, 0.0, 75.0);
	glVertex3f(18.0, 28.0, 58.0);
	glVertex3f(-18.0, 28.0, 58.0);
	glEnd();*/

	glBegin(GL_POLYGON);				////bodi tengah belakang
	glColor3f(1.0, 1.0, 1.0);
	//glColor3f(1.9, 1.9, 0.9);
	glVertex3f(-18.0, 0.0, -90.0);
	glVertex3f(18.0, 0.0, -90.0);
	glVertex3f(18.0, 28.0, -90.0);
	glVertex3f(-18.0, 28.0, -90.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi tengah kanan
	//glColor3f(0.5, 0.5, 0.5);
	glVertex3f(18.0, 0.0, 60.0);
	glVertex3f(18.0, 0.0, -90.0);
	glVertex3f(18.0, 28.0, -90.0);
	glVertex3f(18.0, 28.0, 60.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi tengah kiri
	//glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-18.0, 0.0, 60.0);
	glVertex3f(-18.0, 0.0, -90.0);
	glVertex3f(-18.0, 28.0, -90.0);
	glVertex3f(-18.0, 28.0, 60.0);
	glEnd();

}

void dindingbelakang(int r, int g, int b) {

	glBegin(GL_POLYGON);				////bodi tengah belakang
	glColor3f(1.0, 1.0, 1.0);
	//glColor3f(1.9, 1.9, 0.9);
	glVertex3f(18.0, 0.0, -97.0);
	glVertex3f(18.0, 0.0, -90.0);
	glVertex3f(18.0, 28.0, -90.0);
	glVertex3f(18.0, 28.0, -92.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi tengah belakang
	//glColor3f(1.0, 0.0, 0.0);
	//glColor3f(1.9, 1.9, 0.9);
	glVertex3f(18.0, 0.0, -97);
	glVertex3f(18.0, 28.0, -92.0);
	glVertex3f(16.5, 28.0, -94.0);
	glVertex3f(17.5, 0.0, -103.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi tengah belakang
	//glColor3f(1.0, 0.0, 0.0);
	//glColor3f(1.9, 1.9, 0.9);
	glVertex3f(16.5, 28.0, -94.0);
	glVertex3f(17.5, 0.0, -103.0);
	glVertex3f(17.0, 0.0, -105.0);
	glVertex3f(16.0, 28.0, -95.0);
	glEnd();

	////
	glBegin(GL_POLYGON);				////bodi tengah belakang
	glColor3f(1.0, 1.0, 1.0);
	//glColor3f(1.9, 1.9, 0.9);
	glVertex3f(-18.0, 0.0, -97.0);
	glVertex3f(-18.0, 0.0, -90.0);
	glVertex3f(-18.0, 28.0, -90.0);
	glVertex3f(-18.0, 28.0, -92.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi tengah belakang
	//glColor3f(1.0, 0.0, 0.0);
	//glColor3f(1.9, 1.9, 0.9);
	glVertex3f(-18.0, 0.0, -97);
	glVertex3f(-18.0, 28.0, -92.0);
	glVertex3f(-16.5, 28.0, -94.0);
	glVertex3f(-17.5, 0.0, -103.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi tengah belakang
	//glColor3f(1.0, 0.0, 0.0);
	//glColor3f(1.9, 1.9, 0.9);
	glVertex3f(-16.5, 28.0, -94.0);
	glVertex3f(-17.5, 0.0, -103.0);
	glVertex3f(-17.0, 0.0, -105.0);
	glVertex3f(-16.0, 28.0, -95.0);
	glEnd();

}

void depankapal(int r, int g, int b) {

	glBegin(GL_POLYGON);				////bodi depan tengah
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, 4.6, 82.0);
	glVertex3f(5.0, 4.6, 82.0);
	glVertex3f(5.0, 25.0, 70.0);
	glVertex3f(-5.0, 25.0, 70.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi depan kanan
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(5.0, 4.6, 82.0);
	glVertex3f(5.0, 25.0, 70.0);
	glVertex3f(13.0, 25.0, 68.0);
	glVertex3f(15.0, 4.6, 79.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi depan kiri
	glVertex3f(-5.0, 4.6, 82.0);
	glVertex3f(-5.0, 25.0, 70.0);
	glVertex3f(-13.0, 25.0, 68.0);
	glVertex3f(-15.0, 4.6, 79.0);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON);				////bodi depan kanan2
	glVertex3f(15.0, 4.6, 79.0);
	glVertex3f(20.0, 4.3, 75.0);
	glVertex3f(18.0, 25.0, 65.0);
	glVertex3f(13.0, 25.0, 68.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi depan kiri2
	glVertex3f(-15.0, 4.6, 79.0);
	glVertex3f(-20.0, 4.3, 75.0);
	glVertex3f(-18.0, 25.0, 65.0);
	glVertex3f(-13.0, 25.0, 68.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi depan kanan3
	glVertex3f(20.0, 4.3, 75.0);
	glVertex3f(20.0, 4.3, 70.0);
	glVertex3f(18.0, 25.0, 60.0);
	glVertex3f(18.0, 25.0, 65.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi depan kiri3
	glVertex3f(-20.0, 4.3, 75.0);
	glVertex3f(-20.0, 4.3, 70.0);
	glVertex3f(-18.0, 25.0, 60.0);
	glVertex3f(-18.0, 25.0, 65.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi depan kanan4
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(20.0, 3.0, 70.0);
	glVertex3f(20.0, 4.5, 70.0);
	glVertex3f(18.0, 25.0, 60.0);
	glVertex3f(18.0, 3.0, 60.0);
	glEnd();
	glBegin(GL_POLYGON);				////bodi depan kiri4
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(-20.0, 3.0, 70.0);
	glVertex3f(-20.0, 4.5, 70.0);
	glVertex3f(-18.0, 25.0, 60.0);
	glVertex3f(-18.0, 3.0, 60.0);
	glEnd();

	/////////////// jendela
		//L1 = 8.2;		6.1; 

//tengah 1
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-5.0, 6.5, 81.2);
	glVertex3f(-3.5, 6.5, 81.2);
	glVertex3f(-3.5, 8.2, 80.0);
	glVertex3f(-5.0, 8.2, 80.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-2.2, 6.5, 81.2);
	glVertex3f(-0.7, 6.5, 81.2);
	glVertex3f(-0.7, 8.2, 80.0);
	glVertex3f(-2.2, 8.2, 80.0);
	glEnd();


	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.2, 6.5, 81.2);
	glVertex3f(0.7, 6.5, 81.2);
	glVertex3f(0.7, 8.2, 80.0);
	glVertex3f(2.2, 8.2, 80.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(5.0, 6.5, 81.2);
	glVertex3f(3.5, 6.5, 81.2);
	glVertex3f(3.5, 8.2, 80.0);
	glVertex3f(5.0, 8.2, 80.0);
	glEnd();


	//tengah 2
			//L2 = 12.8;	10.7;

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-5.0, 11.1, 78.6);
	glVertex3f(-3.5, 11.1, 78.6);
	glVertex3f(-3.5, 12.8, 77.5);
	glVertex3f(-5.0, 12.8, 77.5);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-2.2, 11.1, 78.6);
	glVertex3f(-0.7, 11.1, 78.6);
	glVertex3f(-0.7, 12.8, 77.5);
	glVertex3f(-2.2, 12.8, 77.5);
	glEnd();


	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.2, 11.1, 78.6);
	glVertex3f(0.7, 11.1, 78.6);
	glVertex3f(0.7, 12.8, 77.5);
	glVertex3f(2.2, 12.8, 77.5);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(5.0, 11.1, 78.6);
	glVertex3f(3.5, 11.1, 78.6);
	glVertex3f(3.5, 12.8, 77.5);
	glVertex3f(5.0, 12.8, 77.5);
	glEnd();

	//tengah 3
			//L3 = 17.0;	15.3;

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-5.0, 15.3, 76.0);
	glVertex3f(-3.5, 15.3, 76.0);
	glVertex3f(-3.5, 17.0, 75.0);
	glVertex3f(-5.0, 17.0, 75.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-2.2, 15.3, 76.0);
	glVertex3f(-0.7, 15.3, 76.0);
	glVertex3f(-0.7, 17.0, 75.0);
	glVertex3f(-2.2, 17.0, 75.0);
	glEnd();


	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.2, 15.3, 76.0);
	glVertex3f(0.7, 15.3, 76.0);
	glVertex3f(0.7, 17.0, 75.0);
	glVertex3f(2.2, 17.0, 75.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(5.0, 15.3, 76.0);
	glVertex3f(3.5, 15.3, 76.0);
	glVertex3f(3.5, 17.0, 75.0);
	glVertex3f(5.0, 17.0, 75.0);
	glEnd();

	//tengah 4
			//L4 = 22.0;	19.9;
			//L3 = 17.0;	15.3;

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-5.0, 20.3, 73.0);
	glVertex3f(-3.5, 20.3, 73.0);
	glVertex3f(-3.5, 22.0, 72.1);
	glVertex3f(-5.0, 22.0, 72.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-2.2, 20.3, 73.0);
	glVertex3f(-0.7, 20.3, 73.0);
	glVertex3f(-0.7, 22.0, 72.1);
	glVertex3f(-2.2, 22.0, 72.1);
	glEnd();


	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex3f(2.2, 20.3, 73.0);
	glVertex3f(0.7, 20.3, 73.0);
	glVertex3f(0.7, 22.0, 72.1);
	glVertex3f(2.2, 22.0, 72.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(5.0, 20.3, 73.0);
	glVertex3f(3.5, 20.3, 73.0);
	glVertex3f(3.5, 22.0, 72.1);
	glVertex3f(5.0, 22.0, 72.1);
	glEnd();

	///kanan
													//l1

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(19.0, 6.5, 74.7);
	glVertex3f(19.0, 8.2, 73.8);
	glVertex3f(17.5, 8.2, 75.2);
	glVertex3f(17.5, 6.5, 76.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(6.5, 6.5, 80.8);
	glVertex3f(6.5, 8.2, 79.5);
	glVertex3f(8.0, 8.2, 79.1);
	glVertex3f(8.0, 6.5, 80.3);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(10.0, 6.5, 79.7);
	glVertex3f(10.0, 8.2, 78.6);
	glVertex3f(11.5, 8.2, 78.4);
	glVertex3f(11.5, 6.5, 79.4);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(12.9, 6.5, 78.9);
	glVertex3f(12.9, 8.2, 77.8);
	glVertex3f(14.4, 8.2, 77.2);
	glVertex3f(14.4, 6.5, 78.5);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-19.0, 6.5, 74.7);
	glVertex3f(-19.0, 8.2, 73.8);
	glVertex3f(-17.5, 8.2, 75.2);
	glVertex3f(-17.5, 6.5, 76.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-6.5, 6.5, 80.8);
	glVertex3f(-6.5, 8.2, 79.5);
	glVertex3f(-8.0, 8.2, 79.1);
	glVertex3f(-8.0, 6.5, 80.3);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-10.0, 6.5, 79.7);
	glVertex3f(-10.0, 8.2, 78.6);
	glVertex3f(-11.5, 8.2, 78.4);
	glVertex3f(-11.5, 6.5, 79.4);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-12.9, 6.5, 78.9);
	glVertex3f(-12.9, 8.2, 77.8);
	glVertex3f(-14.4, 8.2, 77.2);
	glVertex3f(-14.4, 6.5, 78.5);
	glEnd();


	//l2
//L2 = 12.8;	10.7;
	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(19.0, 11.1, 72.0);
	glVertex3f(19.0, 12.8, 71.1);
	glVertex3f(17.5, 12.8, 72.5);
	glVertex3f(17.5, 11.1, 73.3);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(6.5, 11.1, 78.0);
	glVertex3f(6.5, 12.8, 77.0);
	glVertex3f(8.0, 12.8, 76.8);
	glVertex3f(8.0, 11.1, 77.8);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(10.0, 11.1, 76.9);
	glVertex3f(10.0, 12.8, 75.9);
	glVertex3f(11.5, 12.8, 75.6);
	glVertex3f(11.5, 11.1, 76.4);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(12.4, 11.1, 76.1);
	glVertex3f(12.4, 12.8, 75.2);
	glVertex3f(13.9, 12.8, 75.0);
	glVertex3f(13.9, 11.1, 75.9);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-19.0, 11.1, 72.0);
	glVertex3f(-19.0, 12.8, 71.1);
	glVertex3f(-17.5, 12.8, 72.5);
	glVertex3f(-17.5, 11.1, 73.3);
	glEnd();

	//L2 = 12.8;	10.7;
	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-6.5, 11.1, 78.0);
	glVertex3f(-6.5, 12.8, 77.0);
	glVertex3f(-8.0, 12.8, 76.8);
	glVertex3f(-8.0, 11.1, 77.8);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-10.0, 11.1, 76.9);
	glVertex3f(-10.0, 12.8, 75.9);
	glVertex3f(-11.5, 12.8, 75.6);
	glVertex3f(-11.5, 11.1, 76.4);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-12.4, 11.1, 76.1);
	glVertex3f(-12.4, 12.8, 75.2);
	glVertex3f(-13.9, 12.8, 75.0);
	glVertex3f(-13.9, 11.1, 75.9);
	glEnd();
	//l3
//L4 = 22.0;	19.9;
//L3 = 17.0;	15.3;

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(6.5, 15.7, 75.2);
	glVertex3f(6.5, 17.0, 74.5);
	glVertex3f(8.0, 17.0, 74.0);
	glVertex3f(8.0, 15.7, 75.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(10.0, 15.7, 74.5);
	glVertex3f(10.0, 17.0, 73.5);
	glVertex3f(11.5, 17.0, 73.2);
	glVertex3f(11.5, 15.7, 74.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-6.5, 15.7, 75.2);
	glVertex3f(-6.5, 17.0, 74.5);
	glVertex3f(-8.0, 17.0, 74.0);
	glVertex3f(-8.0, 15.7, 75.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-10.0, 15.7, 74.5);
	glVertex3f(-10.0, 17.0, 73.5);
	glVertex3f(-11.5, 17.0, 73.2);
	glVertex3f(-11.5, 15.7, 74.0);
	glEnd();

	//l4
//L4 = 22.0;	19.9;
//L3 = 17.0;	15.3;

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(6.5, 20.3, 72.5);
	glVertex3f(6.5, 22.0, 71.5);
	glVertex3f(8.0, 22.0, 71.0);
	glVertex3f(8.0, 20.3, 72.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(10.0, 20.3, 71.7);
	glVertex3f(10.0, 22.0, 70.5);
	glVertex3f(11.5, 22.0, 70.2);
	glVertex3f(11.5, 20.3, 71.3);
	glEnd();


	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-6.5, 20.3, 72.5);
	glVertex3f(-6.5, 22.0, 71.5);
	glVertex3f(-8.0, 22.0, 71.0);
	glVertex3f(-8.0, 20.3, 72.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.2, 0.2, 0.2);
	glVertex3f(-10.0, 20.3, 71.7);
	glVertex3f(-10.0, 22.0, 70.5);
	glVertex3f(-11.5, 22.0, 70.2);
	glVertex3f(-11.5, 20.3, 71.3);
	glEnd();

	////////////////////////////////////////////////////// nakoda atas

	glBegin(GL_POLYGON);				////bodi lantai kecil atas
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-22.0, 25.0, 60.0);
	glVertex3f(-22.0, 25.0, 65.0);
	glVertex3f(-13.0, 25.0, 69.0);
	glVertex3f(-5.0, 25.0, 71.0);
	glVertex3f(5.0, 25.0, 71.0);
	glVertex3f(13.0, 25.0, 69.0);
	glVertex3f(22.0, 25.0, 65.0);
	glVertex3f(22.0, 25.0, 60.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi atap kecil atas
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-22.0, 28.0, 60.0);
	glVertex3f(-22.0, 28.0, 65.0);
	glVertex3f(-13.0, 28.0, 69.0);
	glVertex3f(-5.0, 28.0, 71.0);
	glVertex3f(5.0, 28.0, 71.0);
	glVertex3f(13.0, 28.0, 69.0);
	glVertex3f(22.0, 28.0, 65.0);
	glVertex3f(22.0, 28.0, 60.0);
	glEnd();

	//////////////////////////////////////////////////////
	glBegin(GL_POLYGON);				////bodi nyamping
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-22.0, 25.0, 60.0);
	glVertex3f(-22.0, 25.0, 65.0);
	glVertex3f(-22.0, 28.0, 65.0);
	glVertex3f(-22.0, 28.0, 60.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-22.0, 25.0, 65.0);
	glVertex3f(-22.0, 28.0, 65.0);
	glVertex3f(-13.0, 28.0, 69.0);
	glVertex3f(-13.0, 25.0, 69.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-13.0, 25.0, 69.0);
	glVertex3f(-13.0, 28.0, 69.0);
	glVertex3f(-5.0, 28.0, 71.0);
	glVertex3f(-5.0, 25.0, 71.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-5.0, 28.0, 71.0);
	glVertex3f(-5.0, 25.0, 71.0);
	glVertex3f(5.0, 25.0, 71.0);
	glVertex3f(5.0, 28.0, 71.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(5.0, 25.0, 71.0);
	glVertex3f(5.0, 28.0, 71.0);
	glVertex3f(13.0, 28.0, 69.0);
	glVertex3f(13.0, 25.0, 69.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(13.0, 28.0, 69.0);
	glVertex3f(13.0, 25.0, 69.0);
	glVertex3f(22.0, 25.0, 65.0);
	glVertex3f(22.0, 28.0, 65.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(22.0, 25.0, 65.0);
	glVertex3f(22.0, 28.0, 65.0);
	glVertex3f(22.0, 28.0, 60.0);
	glVertex3f(22.0, 25.0, 60.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-22.0, 25.0, 60.0);
	glVertex3f(-22.0, 28.0, 60.0);
	glVertex3f(22.0, 28.0, 60.0);
	glVertex3f(22.0, 25.0, 60.0);
	glEnd();


	///////////////////////////////////////bodi nyamping jendela

	glBegin(GL_POLYGON);				////bodi nyamping
	glColor3f(0.5, 0.5, 0.5);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glVertex3f(-22.1, 25.5, 60.8);
	glVertex3f(-22.1, 25.5, 65.0);
	glVertex3f(-22.1, 27.5, 65.0);
	glVertex3f(-22.1, 27.5, 60.8);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-22.1, 25.5, 65.0);
	glVertex3f(-22.1, 27.5, 65.0);
	glVertex3f(-13.0, 27.5, 69.1);
	glVertex3f(-13.0, 25.5, 69.1);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-13.0, 25.5, 69.1);
	glVertex3f(-13.0, 27.5, 69.1);
	glVertex3f(-5.0, 27.5, 71.1);
	glVertex3f(-5.0, 25.5, 71.1);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-5.0, 27.5, 71.1);
	glVertex3f(-5.0, 25.5, 71.1);
	glVertex3f(5.0, 25.5, 71.1);
	glVertex3f(5.0, 27.5, 71.1);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(5.0, 25.5, 71.1);
	glVertex3f(5.0, 27.5, 71.1);
	glVertex3f(13.0, 27.5, 69.1);
	glVertex3f(13.0, 25.5, 69.1);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(0.7, 0.7, 0.7);
	glVertex3f(22.1, 25.5, 60.8);
	glVertex3f(22.1, 25.5, 65.0);
	glVertex3f(22.1, 27.5, 65.0);
	glVertex3f(22.1, 27.5, 60.8);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(22.1, 25.5, 65.0);
	glVertex3f(22.1, 27.5, 65.0);
	glVertex3f(13.0, 27.5, 69.1);
	glVertex3f(13.0, 25.5, 69.1);
	glEnd();

	glBegin(GL_POLYGON);				////bodi nyamping
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-22.0, 25.0, 60.0);
	glVertex3f(-22.0, 28.0, 60.0);
	glVertex3f(22.0, 28.0, 60.0);
	glVertex3f(22.0, 25.0, 60.0);
	glEnd();

}

void bagianatas(int r, int g, int b) {

	///////////////////////////////////////////kanan
	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(19.0, 28.0, -90.0);           ///kiri belakang
	glVertex3f(19.0, 28.0, 50.0);             ///depan kiri
	glVertex3f(20.0, 32.0, 50.0);              ///kanan depan
	glVertex3f(20.0, 32.0, -90.0);             ///kanan belakang
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.6, 0.6, 0.6);
	glVertex3f(17.0, 28.0, -90.0);           ///kiri belakang
	glVertex3f(17.0, 28.0, 50.0);             ///depan kiri
	glVertex3f(18.0, 32.0, 50.0);              ///kanan depan
	glVertex3f(18.0, 32.0, -90.0);             ///kanan belakang
	glEnd();

	glBegin(GL_POLYGON);											//atap
	//glColor3f(0.6, 0.6, 0.6);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(18.0, 32.0, -90.0);             ///kiri belakang
	glVertex3f(20.0, 32.0, -90.0);			   ///kanan belakang
	glVertex3f(20.0, 32.0, 50.0);              ///kanan depan
	glVertex3f(18.0, 32.0, 50.0);             ///depan kiri
	glEnd();

	///////////////////////////////////////////kiri

	glBegin(GL_POLYGON);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-19.0, 28.0, -90.0);           ///kiri belakang
	glVertex3f(-19.0, 28.0, 50.0);             ///depan kiri
	glVertex3f(-20.0, 32.0, 50.0);              ///kanan depan
	glVertex3f(-20.0, 32.0, -90.0);             ///kanan belakang
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.6, 0.6, 0.6);
	glVertex3f(-17.0, 28.0, -90.0);           ///kiri belakang
	glVertex3f(-17.0, 28.0, 50.0);             ///depan kiri
	glVertex3f(-18.0, 32.0, 50.0);              ///kanan depan
	glVertex3f(-18.0, 32.0, -90.0);             ///kanan belakang
	glEnd();

	glBegin(GL_POLYGON);											//atap
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-18.0, 32.0, -90.0);             ///kiri belakang
	glVertex3f(-20.0, 32.0, -90.0);			   ///kanan belakang
	glVertex3f(-20.0, 32.0, 50.0);              ///kanan depan
	glVertex3f(-18.0, 32.0, 50.0);             ///depan kiri
	glEnd();


	///////////////////////////////jendela
	glBegin(GL_POLYGON);											//jendelakacaliri
	//glColor3f(0.5, 0.5, 0.5);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glVertex3f(19.2, 28.8, -89.0);           ///kiri belakang
	glVertex3f(19.2, 28.8, 49.5);             ///depan kiri
	glVertex3f(19.9, 31.2, 49.5);              ///kanan depan
	glVertex3f(19.9, 31.2, -89.0);             ///kanan belakang
	glEnd();

	glBegin(GL_POLYGON);											//jendelakacakanan
	//glColor3f(0.7, 0.7, 0.7);
	glVertex3f(-19.2, 28.8, -89.0);           ///kiri belakang
	glVertex3f(-19.2, 28.8, 49.5);             ///depan kiri
	glVertex3f(-19.9, 31.2, 49.5);              ///kanan depan
	glVertex3f(-19.9, 31.2, -89.0);             ///kanan belakang
	glEnd();

	///////////////////////////////////////atas depan melengkung

	glBegin(GL_POLYGON);				////bodi atap kecil atas
	//glColor3f(1.6, 1.6, 0.6);		//kiri
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-7.0, 32.0, 59.0);
	glVertex3f(-16.0, 32.0, 56.0);
	glVertex3f(-17.0, 32.0, 51.0);
	glVertex3f(-18.0, 32.0, 50.0);
	glVertex3f(-20.0, 32.0, 50.0);
	glVertex3f(-20.0, 32.0, 52.0);
	glVertex3f(-15.0, 32.0, 57.0);
	glVertex3f(-5.0, 32.0, 61.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);		//kanan
	glVertex3f(7.0, 32.0, 59.0);
	glVertex3f(16.0, 32.0, 56.0);
	glVertex3f(17.0, 32.0, 51.0);
	glVertex3f(18.0, 32.0, 50.0);
	glVertex3f(20.0, 32.0, 50.0);
	glVertex3f(20.0, 32.0, 52.0);
	glVertex3f(15.0, 32.0, 57.0);
	glVertex3f(5.0, 32.0, 61.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);		//tengah
	glVertex3f(7.0, 32.0, 59.0);
	glVertex3f(7.0, 32.0, 61.0);
	glVertex3f(-7.0, 32.0, 61.0);
	glVertex3f(-7.0, 32.0, 59.0);
	glEnd();

	////////////
	glBegin(GL_TRIANGLES);

	glVertex3f(-15.0, 32.0, 57.0);
	glVertex3f(-5.0, 32.0, 61.0);
	glVertex3f(-5.0, 32.0, 63.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex3f(15.0, 32.0, 57.0);
	glVertex3f(5.0, 32.0, 61.0);
	glVertex3f(5.0, 32.0, 63.0);
	glEnd();
	//////////
									///tutup depan
	glBegin(GL_POLYGON);					//paling kiri
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-19.0, 28.1, 49.0);
	glVertex3f(-19.0, 28.1, 52.0);
	glVertex3f(-20.0, 32.0, 52.0);
	glVertex3f(-20.0, 32.0, 50.0);
	glEnd();

	glBegin(GL_POLYGON);					//kiri 1
	glVertex3f(-19.0, 28.1, 52.0);
	glVertex3f(-20.0, 32.0, 52.0);
	glVertex3f(-15.0, 32.0, 57.0);
	glVertex3f(-14.0, 28.1, 56.0);
	glEnd();

	glBegin(GL_POLYGON);					//kiri 2
	glVertex3f(-15.0, 32.0, 57.0);
	glVertex3f(-14.0, 28.1, 56.0);
	glVertex3f(-4.0, 28.1, 60.0);
	glVertex3f(-5.0, 32.0, 63.0);
	glEnd();

	glBegin(GL_POLYGON);				//tengah
	glVertex3f(-4.0, 28.1, 60.0);
	glVertex3f(-5.0, 32.0, 63.0);
	glVertex3f(5.0, 32.0, 63.0);
	glVertex3f(4.0, 28.1, 60.0);
	glEnd();

	glBegin(GL_POLYGON);					//paling kanan
	//glColor3f(0.6, 0.6, 0.6);
	glVertex3f(19.0, 28.1, 49.0);
	glVertex3f(19.0, 28.1, 52.0);
	glVertex3f(20.0, 32.0, 52.0);
	glVertex3f(20.0, 32.0, 50.0);
	glEnd();

	glBegin(GL_POLYGON);					//kanan 1
	glVertex3f(19.0, 28.1, 52.0);
	glVertex3f(20.0, 32.0, 52.0);
	glVertex3f(15.0, 32.0, 57.0);
	glVertex3f(14.0, 28.1, 56.0);
	glEnd();

	glBegin(GL_POLYGON);					//kanan 2
	glVertex3f(15.0, 32.0, 57.0);
	glVertex3f(14.0, 28.1, 56.0);
	glVertex3f(4.0, 28.1, 60.0);
	glVertex3f(5.0, 32.0, 63.0);
	glEnd();


	///tutup depan jendela kaca
	glBegin(GL_POLYGON);					//paling kiri
	glColor3f(0.5, 0.5, 0.5);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glVertex3f(-19.2, 28.8, 50.0);
	glVertex3f(-19.2, 28.8, 52.0);
	glVertex3f(-19.9, 31.2, 52.0);
	glVertex3f(-19.9, 31.2, 50.0);
	glEnd();

	glBegin(GL_POLYGON);					//kiri 1
	glVertex3f(-19.2, 28.8, 52.2);
	glVertex3f(-19.9, 31.2, 52.2);
	glVertex3f(-15.0, 31.2, 57.0);
	glVertex3f(-14.0, 28.8, 56.4);
	glEnd();

	glBegin(GL_POLYGON);					//kiri 2
	glVertex3f(-13.7, 28.8, 56.4);
	glVertex3f(-14.7, 31.2, 57.0);
	glVertex3f(-5.0, 31.2, 62.5);
	glVertex3f(-4.0, 28.8, 60.7);
	glEnd();

	glBegin(GL_POLYGON);				//tengah
	glVertex3f(-4.7, 32.0, 63.0);
	glVertex3f(-3.7, 28.8, 60.7);
	glVertex3f(3.7, 28.8, 60.7);
	glVertex3f(4.7, 32.0, 63.0);
	glEnd();

	glBegin(GL_POLYGON);				//tengah
	glVertex3f(-4.7, 32.0, 61.0);
	glVertex3f(-4.7, 32.0, 63.0);
	glVertex3f(4.7, 32.0, 63.0);
	glVertex3f(4.7, 32.0, 61.0);
	glEnd();

	glBegin(GL_POLYGON);					//paling kanan
	//glColor3f(0.7, 0.7, 0.7);
	glVertex3f(19.2, 28.8, 50.0);
	glVertex3f(19.2, 28.8, 52.0);
	glVertex3f(19.9, 31.2, 52.0);
	glVertex3f(19.9, 31.2, 50.0);
	glEnd();

	glBegin(GL_POLYGON);					//kanan 1
	glVertex3f(19.2, 28.8, 52.2);
	glVertex3f(19.9, 31.2, 52.2);
	glVertex3f(15.0, 31.2, 57.0);
	glVertex3f(14.0, 28.8, 56.4);
	glEnd();

	glBegin(GL_POLYGON);					//kanan 2
	glVertex3f(13.7, 28.8, 56.4);
	glVertex3f(14.7, 31.2, 57.0);
	glVertex3f(5.0, 31.2, 62.5);
	glVertex3f(4.0, 28.8, 60.7);
	glEnd();


	//////////////////////////// melengkung belakang


											///atap lengkunya paling atas
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(-18.0, 32.0, -88.0);
	glVertex3f(-20.0, 32.0, -90.0);
	glVertex3f(-18.0, 32.0, -93.0);
	glVertex3f(-13.0, 32.0, -94.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(-18.0, 32.0, -93.0);
	glVertex3f(-13.0, 32.0, -94.0);
	glVertex3f(-8.0, 32.0, -99.0);
	glVertex3f(-10.0, 32.0, -102.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(-8.0, 32.0, -99.0);
	glVertex3f(-10.0, 32.0, -102.0);
	glVertex3f(-5.0, 32.0, -104.0);
	glVertex3f(-3.0, 32.0, -101.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);			//tengah
	glVertex3f(-5.0, 32.0, -104.0);
	glVertex3f(-3.0, 32.0, -101.0);
	glVertex3f(3.0, 32.0, -101.0);
	glVertex3f(5.0, 32.0, -104.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(8.0, 32.0, -99.0);
	glVertex3f(10.0, 32.0, -102.0);
	glVertex3f(5.0, 32.0, -104.0);
	glVertex3f(3.0, 32.0, -101.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(18.0, 32.0, -93.0);
	glVertex3f(13.0, 32.0, -94.0);
	glVertex3f(8.0, 32.0, -99.0);
	glVertex3f(10.0, 32.0, -102.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(18.0, 32.0, -88.0);
	glVertex3f(20.0, 32.0, -90.0);
	glVertex3f(18.0, 32.0, -93.0);
	glVertex3f(13.0, 32.0, -94.0);
	glEnd();


	//////////////////////////////tutup samping
	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glColor3f(0.9, 0.9, 0.9);
	glVertex3f(-19.0, 28.0, -90.0);
	glVertex3f(-20.0, 32.0, -90.0);
	glVertex3f(-18.0, 32.0, -93.0);
	glVertex3f(-15.0, 28.0, -96.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(-18.0, 32.0, -93.0);
	glVertex3f(-15.0, 28.0, -96.0);
	glVertex3f(-10.0, 28.0, -101.0);
	glVertex3f(-10.0, 32.0, -102.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(-10.0, 28.0, -101.0);
	glVertex3f(-10.0, 32.0, -102.0);
	glVertex3f(-5.0, 32.0, -104.0);
	glVertex3f(-5.0, 28.0, -103.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);			//tengah
	glVertex3f(-5.0, 32.0, -104.0);
	glVertex3f(-5.0, 28.0, -103.0);
	glVertex3f(5.0, 28.0, -103.0);
	glVertex3f(5.0, 32.0, -104.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(10.0, 28.0, -101.0);
	glVertex3f(10.0, 32.0, -102.0);
	glVertex3f(5.0, 32.0, -104.0);
	glVertex3f(5.0, 28.0, -103.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(18.0, 32.0, -93.0);
	glVertex3f(15.0, 28.0, -96.0);
	glVertex3f(10.0, 28.0, -101.0);
	glVertex3f(10.0, 32.0, -102.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(19.0, 28.0, -90.0);
	glVertex3f(20.0, 32.0, -90.0);
	glVertex3f(18.0, 32.0, -93.0);
	glVertex3f(15.0, 28.0, -96.0);
	glEnd();

	//////////////////////////////tutup samping jendela
	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glVertex3f(-19.0, 28.8, -90.1);
	glVertex3f(-20.0, 31.2, -90.1);
	glVertex3f(-18.0, 31.2, -93.1);
	glVertex3f(-15.0, 28.8, -96.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(-18.0, 31.2, -93.1);
	glVertex3f(-15.0, 28.8, -96.1);
	glVertex3f(-10.0, 28.8, -101.1);
	glVertex3f(-10.0, 31.2, -102.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(-10.0, 28.8, -101.1);
	glVertex3f(-10.0, 31.2, -102.1);
	glVertex3f(-5.0, 31.2, -104.1);
	glVertex3f(-5.0, 28.8, -103.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);			//tengah
	glVertex3f(-5.0, 31.2, -104.1);
	glVertex3f(-5.0, 28.8, -103.1);
	glVertex3f(5.0, 28.8, -103.1);
	glVertex3f(5.0, 31.2, -104.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(10.0, 28.8, -101.1);
	glVertex3f(10.0, 31.2, -102.1);
	glVertex3f(5.0, 31.2, -104.1);
	glVertex3f(5.0, 28.8, -103.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(18.0, 31.2, -93.1);
	glVertex3f(15.0, 28.8, -96.1);
	glVertex3f(10.0, 28.8, -101.1);
	glVertex3f(10.0, 31.2, -102.1);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(19.0, 28.8, -90.1);
	glVertex3f(20.0, 31.2, -90.1);
	glVertex3f(18.0, 31.2, -93.1);
	glVertex3f(15.0, 28.8, -96.1);
	glEnd();

}

void lantaikapal(int r, int g, int b) {

	glBegin(GL_POLYGON);												//lantai atas 1
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 4.6, 67.0);             ///depan kiri
	glVertex3f(20.0, 4.6, 67.0);              ///kanan depan
	glVertex3f(20.0, 4.6, -82.0);             ///kanan belakang
	glVertex3f(-20.0, 4.6, -82.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);												//lantai atas 2
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 9.2, 65.0);             ///depan kiri
	glVertex3f(20.0, 9.2, 65.0);              ///kanan depan
	glVertex3f(20.0, 9.2, -85.0);             ///kanan belakang
	glVertex3f(-20.0, 9.2, -85.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);												//lantai atas 3
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 13.8, 62.0);             ///depan kiri
	glVertex3f(20.0, 13.8, 62.0);              ///kanan depan
	glVertex3f(20.0, 13.8, -82.0);             ///kanan belakang
	glVertex3f(-20.0, 13.8, -82.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);												//lantai atas 4
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 18.4, 58.0);             ///depan kiri
	glVertex3f(20.0, 18.4, 58.0);              ///kanan depan
	glVertex3f(20.0, 18.4, -80.0);             ///kanan belakang
	glVertex3f(-20.0, 18.4, -80.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);												//lantai atas 5
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 23.0, 50.0);             ///depan kiri
	glVertex3f(20.0, 23.0, 50.0);              ///kanan depan
	glVertex3f(20.0, 23.0, -78.0);             ///kanan belakang
	glVertex3f(-20.0, 23.0, -78.0);           ///kiri belakang
	glEnd();


	///////////////////////////////////////
	/////////////////////////////////////// teras atas lantai atas 5 sebelah kanan

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(18.0, 27.6, 48.0);             ///depan kiri
	glVertex3f(20.0, 27.6, 48.0);              ///kanan depan
	glVertex3f(20.0, 27.6, -78.0);             ///kanan belakang
	glVertex3f(18.0, 27.6, -78.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);								//teras atas lantai atas 5 sebelah kanan belakang
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(20.0, 27.6, -78.0);
	glVertex3f(18.0, 27.6, -78.0);
	glVertex3f(18.0, 9.2, -85.0);
	glVertex3f(20.0, 9.2, -85.0);
	glEnd();
	glBegin(GL_POLYGON);								//bawahnya
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(18.0, 9.2, -85.0);
	glVertex3f(20.0, 9.2, -85.0);
	glVertex3f(20.0, 4.6, -82.0);
	glVertex3f(18.0, 4.6, -82.0);
	glEnd();

	glBegin(GL_POLYGON);								//depan//lantai atas 1dan2											
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(18.0, 4.6, 67.0);
	glVertex3f(20.0, 4.6, 67.0);
	glVertex3f(20.0, 9.2, 65.0);
	glVertex3f(18.0, 9.2, 65.0);
	glEnd();

	glBegin(GL_POLYGON);								//lantai atas 2 dan 3
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(18.0, 9.2, 64.0);             ///depan kiri
	glVertex3f(20.0, 9.2, 64.0);              ///kanan depan
	glVertex3f(20.0, 13.8, 62.0);
	glVertex3f(18.0, 13.8, 62.0);             ///depan kiri
	glEnd();

	glBegin(GL_POLYGON);								//lantai atas 3 dan 4
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(18.0, 13.8, 60.0);
	glVertex3f(20.0, 13.8, 60.0);
	glVertex3f(20.0, 18.4, 58.0);
	glVertex3f(18.0, 18.4, 58.0);
	glEnd();

	glBegin(GL_POLYGON);								//lantai atas 4 dan 5
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(18.0, 18.4, 52.0);
	glVertex3f(20.0, 18.4, 52.0);
	glVertex3f(20.0, 23.0, 50.0);
	glVertex3f(18.0, 23.0, 50.0);
	glEnd();

	glBegin(GL_POLYGON);								//lantai atas 5 dan terasnya
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(20.0, 23.0, 50.0);
	glVertex3f(18.0, 23.0, 50.0);
	glVertex3f(18.0, 27.6, 48.0);             ///depan kiri
	glVertex3f(20.0, 27.6, 48.0);
	glEnd();

	/////////////////////////////////////// teras atas lantai atas 5 sebelah kanan

	glBegin(GL_POLYGON);
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 27.6, 48.0);             ///depan kiri
	glVertex3f(-20.0, 27.6, 48.0);              ///kanan depan
	glVertex3f(-20.0, 27.6, -78.0);             ///kanan belakang
	glVertex3f(-18.0, 27.6, -78.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);								//teras atas lantai atas 5 sebelah kanan belakang
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 27.6, -78.0);
	glVertex3f(-18.0, 27.6, -78.0);
	glVertex3f(-18.0, 9.2, -85.0);
	glVertex3f(-20.0, 9.2, -85.0);
	glEnd();
	glBegin(GL_POLYGON);								//bawahnya
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 9.2, -85.0);
	glVertex3f(-20.0, 9.2, -85.0);
	glVertex3f(-20.0, 4.6, -82.0);
	glVertex3f(-18.0, 4.6, -82.0);
	glEnd();

	glBegin(GL_POLYGON);								//depan//lantai atas 1dan2											
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 4.6, 67.0);
	glVertex3f(-20.0, 4.6, 67.0);
	glVertex3f(-20.0, 9.2, 65.0);
	glVertex3f(-18.0, 9.2, 65.0);
	glEnd();

	glBegin(GL_POLYGON);								//lantai atas 2 dan 3
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 9.2, 64.0);             ///depan kiri
	glVertex3f(-20.0, 9.2, 64.0);              ///kanan depan
	glVertex3f(-20.0, 13.8, 62.0);
	glVertex3f(-18.0, 13.8, 62.0);             ///depan kiri
	glEnd();

	glBegin(GL_POLYGON);								//lantai atas 3 dan 4
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 13.8, 60.0);
	glVertex3f(-20.0, 13.8, 60.0);
	glVertex3f(-20.0, 18.4, 58.0);
	glVertex3f(-18.0, 18.4, 58.0);
	glEnd();

	glBegin(GL_POLYGON);								//lantai atas 4 dan 5
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 18.4, 52.0);
	glVertex3f(-20.0, 18.4, 52.0);
	glVertex3f(-20.0, 23.0, 50.0);
	glVertex3f(-18.0, 23.0, 50.0);
	glEnd();

	glBegin(GL_POLYGON);								//lantai atas 5 dan terasnya
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 23.0, 50.0);
	glVertex3f(-18.0, 23.0, 50.0);
	glVertex3f(-18.0, 27.6, 48.0);             ///depan kiri
	glVertex3f(-20.0, 27.6, 48.0);
	glEnd();

	///////////////////lantai melengkung

	glBegin(GL_POLYGON);						///lantai 1
	//glColor3f(1.6, 0.6, 0.6);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 4.6, -90.0);
	glVertex3f(-17.0, 4.6, -104.0);
	glVertex3f(-15.0, 4.6, -108.0);
	glVertex3f(-10.0, 4.6, -113.0);
	glVertex3f(-5.0, 4.6, -115.0);
	glVertex3f(5.0, 4.6, -115.0);
	glVertex3f(10.0, 4.6, -113.0);
	glVertex3f(15.0, 4.6, -108.0);
	glVertex3f(17.0, 4.6, -104.0);
	glVertex3f(18.0, 4.6, -90.0);
	glEnd();

	glBegin(GL_POLYGON);						///lantai 2
	//glColor3f(0.6, 0.6, 0.6);
	//glColor3f(1.6, 0.6, 0.6);
	glVertex3f(-18.0, 9.2, -90.0);
	glVertex3f(-17.0, 9.2, -101.0);
	glVertex3f(-15.0, 9.2, -105.0);
	glVertex3f(-10.0, 9.2, -110.0);
	glVertex3f(-5.0, 9.2, -112.0);
	glVertex3f(5.0, 9.2, -112.0);
	glVertex3f(10.0, 9.2, -110.0);
	glVertex3f(15.0, 9.2, -105.0);
	glVertex3f(17.0, 9.2, -101.0);
	glVertex3f(18.0, 9.2, -90.0);
	glEnd();

	glBegin(GL_POLYGON);						///lantai 3
	//glColor3f(0.6, 0.6, 0.6);
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 13.8, -90.0);
	glVertex3f(-17.0, 13.8, -98.0);
	glVertex3f(-15.0, 13.8, -102.0);
	glVertex3f(-10.0, 13.8, -107.0);
	glVertex3f(-5.0, 13.8, -109.0);
	glVertex3f(5.0, 13.8, -109.0);
	glVertex3f(10.0, 13.8, -107.0);
	glVertex3f(15.0, 13.8, -102.0);
	glVertex3f(17.0, 13.8, -98.0);
	glVertex3f(18.0, 13.8, -90.0);
	glEnd();

	glBegin(GL_POLYGON);						///lantai 4
	//glColor3f(0.6, 0.6, 0.6);
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 18.4, -90.0);
	glVertex3f(-17.0, 18.4, -95.0);
	glVertex3f(-15.0, 18.4, -99.0);
	glVertex3f(-10.0, 18.4, -104.0);
	glVertex3f(-5.0, 18.4, -106.0);
	glVertex3f(5.0, 18.4, -106.0);
	glVertex3f(10.0, 18.4, -104.0);
	glVertex3f(15.0, 18.4, -99.0);
	glVertex3f(17.0, 18.4, -95.0);
	glVertex3f(18.0, 18.4, -90.0);
	glEnd();

	glBegin(GL_POLYGON);						///lantai 5
	//glColor3f(0.6, 0.6, 0.6);
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 23.0, -90.0);
	glVertex3f(-17.0, 23.0, -92.0);
	glVertex3f(-15.0, 23.0, -96.0);
	glVertex3f(-10.0, 23.0, -101.0);
	glVertex3f(-5.0, 23.0, -103.0);
	glVertex3f(5.0, 23.0, -103.0);
	glVertex3f(10.0, 23.0, -101.0);
	glVertex3f(15.0, 23.0, -96.0);
	glVertex3f(17.0, 23.0, -92.0);
	glVertex3f(18.0, 23.0, -90.0);
	glEnd();

}

void lantaigreen(int r, int g, int b) {


	glBegin(GL_POLYGON);												//lantai atas 1
	glColor3f(0.5, 128.5, 0.5);
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 4.61, 67.0);             ///depan kiri
	glVertex3f(18.0, 4.61, 67.0);              ///kanan depan
	glVertex3f(18.0, 4.61, -82.0);             ///kanan belakang
	glVertex3f(-18.0, 4.61, -82.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);												//lantai atas 2
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 9.21, 65.0);             ///depan kiri
	glVertex3f(18.0, 9.21, 65.0);              ///kanan depan
	glVertex3f(18.0, 9.21, -85.0);             ///kanan belakang
	glVertex3f(-18.0, 9.21, -85.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);												//lantai atas 3
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 13.81, 62.0);             ///depan kiri
	glVertex3f(18.0, 13.81, 62.0);              ///kanan depan
	glVertex3f(18.0, 13.81, -82.0);             ///kanan belakang
	glVertex3f(-18.0, 13.81, -82.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);												//lantai atas 4
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 18.41, 58.0);             ///depan kiri
	glVertex3f(18.0, 18.41, 58.0);              ///kanan depan
	glVertex3f(18.0, 18.41, -80.0);             ///kanan belakang
	glVertex3f(-18.0, 18.41, -80.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);												//lantai atas 5
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-18.0, 23.01, 50.0);             ///depan kiri
	glVertex3f(18.0, 23.01, 50.0);              ///kanan depan
	glVertex3f(18.0, 23.01, -78.0);             ///kanan belakang
	glVertex3f(-18.0, 23.0, -78.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.5 + u, 128.5 + i, 0.5 + o);
	glVertex3f(-20.0, 3.0, 70.0);
	glVertex3f(20.0, 3.0, 70.0);
	glVertex3f(20.0, 3.0, 75.0);
	glVertex3f(0.0, 3.0, 109.1);
	glVertex3f(-20.0, 3.0, 75.0);
	glEnd();
}

void radarbelakang(int r, int g, int b) {

	//////////////////lantai
	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glColor3f(0.85, 0.85, 0.85);
	glVertex3f(0.0, 28.01, -95.0);
	glVertex3f(0.0, 28.01, -90.0);
	glVertex3f(3.0, 28.01, -94.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(3.0, 28.01, -94.0);
	glVertex3f(0.0, 28.01, -90.0);
	glVertex3f(6.0, 28.01, -92.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(6.0, 28.01, -92.0);
	glVertex3f(0.0, 28.01, -90.0);
	glVertex3f(8.0, 28.01, -90.0);
	glEnd();

	glBegin(GL_TRIANGLES);				//1	/4    80=85			75=70
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(0.0, 28.01, -80.0);
	glVertex3f(0.0, 28.01, -85.0);
	glVertex3f(3.0, 28.01, -81.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(3.0, 28.01, -81.0);
	glVertex3f(0.0, 28.01, -85.0);
	glVertex3f(6.0, 28.01, -82.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(6.0, 28.01, -82.0);
	glVertex3f(0.0, 28.01, -85.0);
	glVertex3f(8.0, 28.01, -85.0);
	glEnd();

	//////////////////tengah

	glBegin(GL_POLYGON);
	glVertex3f(8.0, 28.01, -90.0);
	glVertex3f(8.0, 28.01, -85.0);
	glVertex3f(-8.0, 28.01, -85.0);
	glVertex3f(-8.0, 28.01, -90.0);

	glEnd();

	//////////////////kiri
	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(0.0, 28.01, -95.0);
	glVertex3f(0.0, 28.01, -90.0);
	glVertex3f(-3.0, 28.01, -94.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-3.0, 28.01, -94.0);
	glVertex3f(0.0, 28.01, -90.0);
	glVertex3f(-6.0, 28.01, -92.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-6.0, 28.01, -92.0);
	glVertex3f(-0.0, 28.01, -90.0);
	glVertex3f(-8.0, 28.01, -90.0);
	glEnd();

	glBegin(GL_TRIANGLES);				//1	/4    80=85			75=70
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(0.0, 28.01, -80.0);
	glVertex3f(0.0, 28.01, -85.0);
	glVertex3f(-3.0, 28.01, -81.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-3.0, 28.01, -81.0);
	glVertex3f(0.0, 28.01, -85.0);
	glVertex3f(-6.0, 28.01, -82.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-6.0, 28.01, -82.0);
	glVertex3f(0.0, 28.01, -85.0);
	glVertex3f(-8.0, 28.01, -85.0);
	glEnd();


	//////////////////tutup atas
	glBegin(GL_TRIANGLES);
	//glColor3f(0.9, 0.9, 0.9);
	glVertex3f(0.0, 35.0, -95.0);
	glVertex3f(0.0, 35.0, -90.0);
	glVertex3f(3.0, 35.0, -94.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(3.0, 35.0, -94.0);
	glVertex3f(0.0, 35.0, -90.0);
	glVertex3f(6.0, 35.0, -92.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(6.0, 35.0, -92.0);
	glVertex3f(0.0, 35.0, -90.0);
	glVertex3f(8.0, 35.0, -90.0);
	glEnd();

	glBegin(GL_TRIANGLES);				//1	/4    80=85			75=70
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(0.0, 35.0, -80.0);
	glVertex3f(0.0, 35.0, -85.0);
	glVertex3f(3.0, 35.0, -81.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(3.0, 35.0, -81.0);
	glVertex3f(0.0, 35.0, -85.0);
	glVertex3f(6.0, 35.0, -82.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(6.0, 35.0, -82.0);
	glVertex3f(0.0, 35.0, -85.0);
	glVertex3f(8.0, 35.0, -85.0);
	glEnd();

	//////////////////tengah

	glBegin(GL_POLYGON);
	glVertex3f(8.0, 35.0, -90.0);
	glVertex3f(8.0, 35.0, -85.0);
	glVertex3f(-8.0, 35.0, -85.0);
	glVertex3f(-8.0, 35.0, -90.0);

	glEnd();

	//////////////////kiri
	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(0.0, 35.0, -95.0);
	glVertex3f(0.0, 35.0, -90.0);
	glVertex3f(-3.0, 35.0, -94.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-3.0, 35.0, -94.0);
	glVertex3f(0.0, 35.0, -90.0);
	glVertex3f(-6.0, 35.0, -92.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-6.0, 35.0, -92.0);
	glVertex3f(-0.0, 35.0, -90.0);
	glVertex3f(-8.0, 35.0, -90.0);
	glEnd();

	glBegin(GL_TRIANGLES);				//1	/4    80=85			75=70
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(0.0, 35.0, -80.0);
	glVertex3f(0.0, 35.0, -85.0);
	glVertex3f(-3.0, 35.0, -81.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-3.0, 35.0, -81.0);
	glVertex3f(0.0, 35.0, -85.0);
	glVertex3f(-6.0, 35.0, -82.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-6.0, 35.0, -82.0);
	glVertex3f(0.0, 35.0, -85.0);
	glVertex3f(-8.0, 35.0, -85.0);
	glEnd();
	//////////////////tutup samping bagian kanan
	glBegin(GL_POLYGON);
	//glColor3f(1.8, 1.8, 0.8);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(0.0, 28.01, -95.0);
	glVertex3f(3.0, 28.01, -94.0);
	glVertex3f(3.0, 35.0, -94.0);
	glVertex3f(0.0, 35.0, -95.0);

	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(3.0, 28.01, -94.0);
	glVertex3f(6.0, 28.01, -92.0);
	glVertex3f(6.0, 35.0, -92.0);
	glVertex3f(3.0, 35.0, -94.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(6.0, 28.01, -92.0);
	glVertex3f(8.0, 28.01, -90.0);
	glVertex3f(8.0, 35.0, -90.0);
	glVertex3f(6.0, 35.0, -92.0);
	glEnd();

	glBegin(GL_POLYGON);				//1	/4    80=85			75=70
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(0.0, 28.01, -80.0);
	glVertex3f(3.0, 28.01, -81.0);
	glVertex3f(3.0, 35.0, -81.0);
	glVertex3f(0.0, 35.0, -80.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(8.0, 28.01, -85.0);
	glVertex3f(8.0, 28.01, -90.0);
	glVertex3f(8.0, 35.0, -90.0);
	glVertex3f(8.0, 35.0, -85.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(3.0, 28.01, -81.0);
	glVertex3f(6.0, 28.01, -82.0);
	glVertex3f(6.0, 35.0, -82.0);
	glVertex3f(3.0, 35.0, -81.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(6.0, 28.01, -82.0);
	glVertex3f(6.0, 35.0, -82.0);
	glVertex3f(8.0, 35.0, -85.0);
	glVertex3f(8.0, 28.01, -86.0);
	glEnd();

	///////////////////////////////////////////////bagian kiri

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 1.8, 0.8);
	glVertex3f(0.0, 28.01, -95.0);
	glVertex3f(-3.0, 28.01, -94.0);
	glVertex3f(-3.0, 35.0, -94.0);
	glVertex3f(0.0, 35.0, -95.0);

	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-3.0, 28.01, -94.0);
	glVertex3f(-6.0, 28.01, -92.0);
	glVertex3f(-6.0, 35.0, -92.0);
	glVertex3f(-3.0, 35.0, -94.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-6.0, 28.01, -92.0);
	glVertex3f(-8.0, 28.01, -90.0);
	glVertex3f(-8.0, 35.0, -90.0);
	glVertex3f(-6.0, 35.0, -92.0);
	glEnd();

	glBegin(GL_POLYGON);				//1	/4    80=85			75=70
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(0.0, 28.01, -80.0);
	glVertex3f(-3.0, 28.01, -81.0);
	glVertex3f(-3.0, 35.0, -81.0);
	glVertex3f(0.0, 35.0, -80.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8.0, 28.01, -85.0);
	glVertex3f(-8.0, 28.01, -90.0);
	glVertex3f(-8.0, 35.0, -90.0);
	glVertex3f(-8.0, 35.0, -85.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(-3.0, 28.01, -81.0);
	glVertex3f(-6.0, 28.01, -82.0);
	glVertex3f(-6.0, 35.0, -82.0);
	glVertex3f(-3.0, 35.0, -81.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 1.8);
	glVertex3f(-6.0, 28.01, -82.0);
	glVertex3f(-6.0, 35.0, -82.0);
	glVertex3f(-8.0, 35.0, -85.0);
	glVertex3f(-8.0, 28.01, -86.0);
	glEnd();

	/////////////////////////bagian atasnya

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(2.0, 45.0, -92.0);
	glVertex3f(2.0, 35.0, -85.0);
	glVertex3f(2.0, 35.0, -90.0);
	glVertex3f(2.0, 45.0, -94.0);
	glEnd();

	/////////////////// bagian kiri


	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(-2.0, 45.0, -92.0);
	glVertex3f(-2.0, 35.0, -85.0);
	glVertex3f(-2.0, 35.0, -90.0);
	glVertex3f(-2.0, 45.0, -94.0);
	glEnd();


	/////////////////// bagian tutup
	glBegin(GL_POLYGON);
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(2.0, 35.0, -85.0);
	glVertex3f(2.0, 45.0, -92.0);
	glVertex3f(-2.0, 45.0, -92.0);
	glVertex3f(-2.0, 35.0, -85.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(2.0, 45.0, -92.0);
	glVertex3f(-2.0, 45.0, -92.0);
	glVertex3f(-2.0, 45.0, -94.0);
	glVertex3f(2.0, 45.0, -94.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(-2.0, 45.0, -94.0);
	glVertex3f(2.0, 45.0, -94.0);
	glVertex3f(2.0, 35.0, -90.0);
	glVertex3f(-2.0, 35.0, -90.0);
	glEnd();

}

void objectatasdepan(int r, int g, int b) {

	//bagian 1
	glBegin(GL_POLYGON);				////bodi lantai kecil atasdepan melengkung
	//glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-12.0, 31.0, 38.0);
	glVertex3f(-12.0, 31.0, 47.0);
	glVertex3f(-9.0, 31.0, 51.0);
	glVertex3f(-4.0, 31.0, 55.0);
	glVertex3f(4.0, 31.0, 55.0);
	glVertex3f(9.0, 31.0, 51.0);
	glVertex3f(12.0, 31.0, 47.0);
	glVertex3f(12.0, 31.0, 38.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi lantai kecil atasdepan melengkung atas
	glColor3f(1.0, 0.0, 1.0);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-10.0, 34.0, 38.0);
	glVertex3f(-10.0, 34.0, 45.0);
	glVertex3f(-7.0, 34.0, 49.0);
	glVertex3f(-2.0, 34.0, 53.0);
	glVertex3f(2.0, 34.0, 53.0);
	glVertex3f(7.0, 34.0, 49.0);
	glVertex3f(10.0, 34.0, 45.0);
	glVertex3f(10.0, 34.0, 38.0);
	glEnd();

	/////////////////////////////tutup samping

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-12.0, 31.0, 38.0);
	glVertex3f(-10.0, 34.0, 38.0);
	glVertex3f(10.0, 34.0, 38.0);
	glVertex3f(12.0, 31.0, 38.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12.0, 31.0, 38.0);
	glVertex3f(-12.0, 31.0, 47.0);
	glVertex3f(-10.0, 34.0, 45.0);
	glVertex3f(-10.0, 34.0, 38.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-12.0, 31.0, 47.0);
	glVertex3f(-10.0, 34.0, 45.0);
	glVertex3f(-7.0, 34.0, 49.0);
	glVertex3f(-9.0, 31.0, 51.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-7.0, 34.0, 49.0);
	glVertex3f(-9.0, 31.0, 51.0);
	glVertex3f(-4.0, 31.0, 55.0);
	glVertex3f(-2.0, 34.0, 53.0);
	glEnd();

	glBegin(GL_POLYGON);					//tengah
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-4.0, 31.0, 55.0);
	glVertex3f(-2.0, 34.0, 53.0);
	glVertex3f(2.0, 34.0, 53.0);
	glVertex3f(4.0, 31.0, 55.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.0, 31.0, 38.0);
	glVertex3f(12.0, 31.0, 47.0);
	glVertex3f(10.0, 34.0, 45.0);
	glVertex3f(10.0, 34.0, 38.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(12.0, 31.0, 47.0);
	glVertex3f(10.0, 34.0, 45.0);
	glVertex3f(7.0, 34.0, 49.0);
	glVertex3f(9.0, 31.0, 51.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(7.0, 34.0, 49.0);
	glVertex3f(9.0, 31.0, 51.0);
	glVertex3f(4.0, 31.0, 55.0);
	glVertex3f(2.0, 34.0, 53.0);
	glEnd();

	//////////bagian 2
	glBegin(GL_POLYGON);				////bodi lantai kecil atasdepan melengkung
	glColor3f(1.0, 1.0, 0.0);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-8.0, 37.0, 33.0);
	glVertex3f(-8.0, 37.0, 40.0);
	glVertex3f(-7.0, 37.0, 44.0);
	glVertex3f(-2.0, 37.0, 48.0);
	glVertex3f(2.0, 37.0, 48.0);
	glVertex3f(7.0, 37.0, 44.0);
	glVertex3f(8.0, 37.0, 40.0);
	glVertex3f(8.0, 37.0, 33.0);
	glEnd();

	glBegin(GL_POLYGON);				////atapnya
	//glColor3f(1.0, 0.0, 1.0);
	glColor3f(0.85, 0.85, 0.85);
	glVertex3f(-4.0, 39.0, 36.0);
	glVertex3f(-4.0, 39.0, 39.0);
	glVertex3f(-3.0, 39.0, 41.0);
	glVertex3f(-1.2, 39.0, 44.0);
	glVertex3f(1.2, 39.0, 44.0);
	glVertex3f(3.0, 39.0, 41.0);
	glVertex3f(4.0, 39.0, 39.0);
	glVertex3f(4.0, 39.0, 36.0);
	glEnd();

	////tutup samping
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glColor3f(0.85, 0.85, 0.85);
	glVertex3f(-8.0, 37.0, 33.0);
	glVertex3f(8.0, 37.0, 33.0);
	glVertex3f(4.0, 39.0, 36.0);
	glVertex3f(-4.0, 39.0, 36.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-8.0, 37.0, 33.0);
	glVertex3f(-4.0, 39.0, 36.0);
	glVertex3f(-4.0, 39.0, 39.0);
	glVertex3f(-8.0, 37.0, 40.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8.0, 37.0, 33.0);
	glVertex3f(-4.0, 39.0, 36.0);
	glVertex3f(-4.0, 39.0, 39.0);
	glVertex3f(-8.0, 37.0, 40.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.0, 39.0, 39.0);
	glVertex3f(-8.0, 37.0, 40.0);
	glVertex3f(-7.0, 37.0, 44.0);
	glVertex3f(-3.0, 39.0, 41.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-7.0, 37.0, 44.0);
	glVertex3f(-3.0, 39.0, 41.0);
	glVertex3f(-1.2, 39.0, 44.0);
	glVertex3f(-2.0, 37.0, 48.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-1.2, 39.0, 44.0);
	glVertex3f(-2.0, 37.0, 48.0);
	glVertex3f(2.0, 37.0, 48.0);
	glVertex3f(1.2, 39.0, 44.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(2.0, 37.0, 48.0);
	glVertex3f(1.2, 39.0, 44.0);
	glVertex3f(3.0, 39.0, 41.0);
	glVertex3f(7.0, 37.0, 44.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(3.0, 39.0, 41.0);
	glVertex3f(7.0, 37.0, 44.0);
	glVertex3f(8.0, 37.0, 40.0);
	glVertex3f(4.0, 39.0, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(8.0, 37.0, 40.0);
	glVertex3f(4.0, 39.0, 39.0);
	glVertex3f(4.0, 39.0, 36.0);
	glVertex3f(8.0, 37.0, 33.0);
	glEnd();

	//dindingnya kiri
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-7.0, 37.0, 44.0);
	glVertex3f(-7.0, 28.0, 44.0);
	glVertex3f(-7.0, 28.0, 35.0);
	glVertex3f(-7.0, 37.0, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-5.0, 37.0, 44.0);
	glVertex3f(-5.0, 28.0, 44.0);
	glVertex3f(-5.0, 28.0, 35.0);
	glVertex3f(-5.0, 37.0, 35.0);
	glEnd();

	//tutupnya
	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-7.0, 28.0, 35.0);
	glVertex3f(-7.0, 37.0, 35.0);
	glVertex3f(-5.0, 37.0, 35.0);
	glVertex3f(-5.0, 28.0, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-7.0, 28.0, 44.0);
	glVertex3f(-7.0, 37.0, 44.0);
	glVertex3f(-5.0, 37.0, 44.0);
	glVertex3f(-5.0, 28.0, 44.0);
	glEnd();

	//dindingnya kanan
	glBegin(GL_POLYGON);
	//glColor3f(1.0, 1.0, 0.0);
	glVertex3f(7.0, 37.0, 44.0);
	glVertex3f(7.0, 28.0, 44.0);
	glVertex3f(7.0, 28.0, 35.0);
	glVertex3f(7.0, 37.0, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 1.0);
	glVertex3f(5.0, 37.0, 44.0);
	glVertex3f(5.0, 28.0, 44.0);
	glVertex3f(5.0, 28.0, 35.0);
	glVertex3f(5.0, 37.0, 35.0);
	glEnd();

	//tutupnya
	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(7.0, 28.0, 35.0);
	glVertex3f(7.0, 37.0, 35.0);
	glVertex3f(5.0, 37.0, 35.0);
	glVertex3f(5.0, 28.0, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(7.0, 28.0, 44.0);
	glVertex3f(7.0, 37.0, 44.0);
	glVertex3f(5.0, 37.0, 44.0);
	glVertex3f(5.0, 28.0, 44.0);
	glEnd();


	//////tiang tengah kecil atas
	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(0.5, 50.0, 31.0);
	glVertex3f(2.0, 39.0, 37.0);
	glVertex3f(2.0, 39.0, 40.0);
	glVertex3f(0.5, 50.0, 32.0);
	glEnd();

	/////////////////// bagian kiri
	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(-0.5, 50.0, 31.0);
	glVertex3f(-2.0, 39.0, 37.0);
	glVertex3f(-2.0, 39.0, 40.0);
	glVertex3f(-0.5, 50.0, 32.0);
	glEnd();

	/////////////////// tutupnya
	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(0.5, 50.0, 31.0);
	glVertex3f(2.0, 39.0, 37.0);
	glVertex3f(-2.0, 39.0, 37.0);
	glVertex3f(-0.5, 50.0, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(2.0, 39.0, 40.0);
	glVertex3f(0.5, 50.0, 32.0);
	glVertex3f(-0.5, 50.0, 32.0);
	glVertex3f(-2.0, 39.0, 40.0);
	glEnd();
}

void objectatastengah(int r, int g, int b) {

	//dindingnya kanan
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(10.0, 37.0, -60.0);
	glVertex3f(10.0, 28.0, -60.0);
	glVertex3f(10.0, 28.0, -45.0);
	glVertex3f(10.0, 37.0, -45.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 1.0);
	glVertex3f(8.0, 37.0, -60.0);
	glVertex3f(8.0, 28.0, -60.0);
	glVertex3f(8.0, 28.0, -45.0);
	glVertex3f(8.0, 37.0, -45.0);
	glEnd();

	//tutupnya
	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(10.0, 28.0, -45.0);
	glVertex3f(10.0, 37.0, -45.0);
	glVertex3f(8.0, 37.0, -45.0);
	glVertex3f(8.0, 28.0, -45.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(10.0, 28.0, -60.0);
	glVertex3f(10.0, 37.0, -60.0);
	glVertex3f(8.0, 37.0, -60.0);
	glVertex3f(8.0, 28.0, -60.0);
	glEnd();

	//dindingnya kiri
	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-10.0, 37.0, -60.0);
	glVertex3f(-10.0, 28.0, -60.0);
	glVertex3f(-10.0, 28.0, -45.0);
	glVertex3f(-10.0, 37.0, -45.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-8.0, 37.0, -60.0);
	glVertex3f(-8.0, 28.0, -60.0);
	glVertex3f(-8.0, 28.0, -45.0);
	glVertex3f(-8.0, 37.0, -45.0);
	glEnd();

	//tutupnya
	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-10.0, 28.0, -45.0);
	glVertex3f(-10.0, 37.0, -45.0);
	glVertex3f(-8.0, 37.0, -45.0);
	glVertex3f(-8.0, 28.0, -45.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.6, 1.6, 0.6);
	glVertex3f(-10.0, 28.0, -60.0);
	glVertex3f(-10.0, 37.0, -60.0);
	glVertex3f(-8.0, 37.0, -60.0);
	glVertex3f(-8.0, 28.0, -60.0);
	glEnd();


	//lingkaran hexa dasar
				//////////////////tengah
	glColor3f(0.85, 0.85, 0.85);
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 37.0, -58.0);
	glVertex3f(20.0, 37.0, -47.0);
	glVertex3f(-20.0, 37.0, -47.0);
	glVertex3f(-20.0, 37.0, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 37.0, -35.0);
	glVertex3f(5.0, 37.0, -70.0);
	glVertex3f(-5.0, 37.0, -70.0);
	glVertex3f(-5.0, 37.0, -35.0);
	glEnd();

	//////////////////samping kanan belakang

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 37.0, -70.0);
	glVertex3f(13.0, 37.0, -65.0);
	glVertex3f(5.0, 37.0, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(13.0, 37.0, -65.0);
	glVertex3f(5.0, 37.0, -58.0);
	glVertex3f(20.0, 37.0, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 37.0, -35.0);
	glVertex3f(13.0, 37.0, -40.0);
	glVertex3f(5.0, 37.0, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(13.0, 37.0, -40.0);
	glVertex3f(5.0, 37.0, -47.0);
	glVertex3f(20.0, 37.0, -47.0);
	glEnd();

	//////////////////samping kiri

	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 37.0, -70.0);
	glVertex3f(-13.0, 37.0, -65.0);
	glVertex3f(-5.0, 37.0, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.0, 37.0, -65.0);
	glVertex3f(-5.0, 37.0, -58.0);
	glVertex3f(-20.0, 37.0, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 37.0, -35.0);
	glVertex3f(-13.0, 37.0, -40.0);
	glVertex3f(-5.0, 37.0, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.0, 37.0, -40.0);
	glVertex3f(-5.0, 37.0, -47.0);
	glVertex3f(-20.0, 37.0, -47.0);
	glEnd();

	//lingkaran hexa atap
								//////////////////tengah

	glBegin(GL_POLYGON);
	glVertex3f(20.0, 41.6, -58.0);
	glVertex3f(20.0, 41.6, -47.0);
	glVertex3f(-20.0, 41.6, -47.0);
	glVertex3f(-20.0, 41.6, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 41.6, -35.0);
	glVertex3f(5.0, 41.6, -70.0);
	glVertex3f(-5.0, 41.6, -70.0);
	glVertex3f(-5.0, 41.6, -35.0);
	glEnd();

	//////////////////samping kanan belakang

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 41.6, -70.0);
	glVertex3f(13.0, 41.6, -65.0);
	glVertex3f(5.0, 41.6, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(13.0, 41.6, -65.0);
	glVertex3f(5.0, 41.6, -58.0);
	glVertex3f(20.0, 41.6, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 41.6, -35.0);
	glVertex3f(13.0, 41.6, -40.0);
	glVertex3f(5.0, 41.6, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(13.0, 41.6, -40.0);
	glVertex3f(5.0, 41.6, -47.0);
	glVertex3f(20.0, 41.6, -47.0);
	glEnd();

	//////////////////samping kiri

	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 41.6, -70.0);
	glVertex3f(-13.0, 41.6, -65.0);
	glVertex3f(-5.0, 41.6, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.0, 41.6, -65.0);
	glVertex3f(-5.0, 41.6, -58.0);
	glVertex3f(-20.0, 41.6, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 41.6, -35.0);
	glVertex3f(-13.0, 41.6, -40.0);
	glVertex3f(-5.0, 41.6, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.0, 41.6, -40.0);
	glVertex3f(-5.0, 41.6, -47.0);
	glVertex3f(-20.0, 41.6, -47.0);
	glEnd();

	////bagian tutup samping kanan

	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex3f(20.0, 37.0, -58.0);
	glVertex3f(20.0, 37.0, -47.0);
	glVertex3f(20.0, 41.6, -47.0);
	glVertex3f(20.0, 41.6, -58.0);
	glEnd();
	glColor3f(0.8, 0.8, 0.8);
	glBegin(GL_POLYGON);
	glVertex3f(-20.0, 37.0, -58.0);
	glVertex3f(-20.0, 37.0, -47.0);
	glVertex3f(-20.0, 41.6, -47.0);
	glVertex3f(-20.0, 41.6, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 37.0, -35.0);
	glVertex3f(-5.0, 37.0, -35.0);
	glVertex3f(-5.0, 41.6, -35.0);
	glVertex3f(5.0, 41.6, -35.0);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(5.0, 37.0, -70.0);
	glVertex3f(-5.0, 37.0, -70.0);
	glVertex3f(-5.0, 41.6, -70.0);
	glVertex3f(5.0, 41.6, -70.0);
	glEnd();

	///////////
	glBegin(GL_POLYGON);
	glVertex3f(5.0, 37.0, -70.0);
	glVertex3f(13.0, 37.0, -65.0);
	glVertex3f(13.0, 41.6, -65.0);
	glVertex3f(5.0, 41.6, -70.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(13.0, 37.0, -65.0);
	glVertex3f(13.0, 41.6, -65.0);
	glVertex3f(20.0, 41.6, -58.0);
	glVertex3f(20.0, 37.0, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 41.6, -35.0);
	glVertex3f(5.0, 37.0, -35.0);
	glVertex3f(13.0, 37.0, -40.0);
	glVertex3f(13.0, 41.6, -40.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(13.0, 37.0, -40.0);
	glVertex3f(13.0, 41.6, -40.0);
	glVertex3f(20.0, 41.6, -47.0);
	glVertex3f(20.0, 37.0, -47.0);
	glEnd();

	////bagian tutup samping kiri
					///////////
	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 37.0, -70.0);
	glVertex3f(-13.0, 37.0, -65.0);
	glVertex3f(-13.0, 41.6, -65.0);
	glVertex3f(-5.0, 41.6, -70.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.0, 37.0, -65.0);
	glVertex3f(-13.0, 41.6, -65.0);
	glVertex3f(-20.0, 41.6, -58.0);
	glVertex3f(-20.0, 37.0, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 41.6, -35.0);
	glVertex3f(-5.0, 37.0, -35.0);
	glVertex3f(-13.0, 37.0, -40.0);
	glVertex3f(-13.0, 41.6, -40.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(-13.0, 37.0, -40.0);
	glVertex3f(-13.0, 41.6, -40.0);
	glVertex3f(-20.0, 41.6, -47.0);
	glVertex3f(-20.0, 37.0, -47.0);
	glEnd();

	/////////bagian jendela
					////bagian tutup samping kanan

					//glColor3f(0.6, 0.6, 0.6);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glBegin(GL_POLYGON);
	glVertex3f(20.01, 38.0, -58.0);
	glVertex3f(20.01, 38.0, -47.0);
	glVertex3f(20.01, 41.0, -47.0);
	glVertex3f(20.01, 41.0, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-20.01, 38.0, -58.0);
	glVertex3f(-20.01, 38.0, -47.0);
	glVertex3f(-20.01, 41.0, -47.0);
	glVertex3f(-20.01, 41.0, -58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 38.0, -34.9);
	glVertex3f(-5.0, 38.0, -34.9);
	glVertex3f(-5.0, 41.0, -34.9);
	glVertex3f(5.0, 41.0, -34.9);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(5.0, 38.0, -70.01);
	glVertex3f(-5.0, 38.0, -70.01);
	glVertex3f(-5.0, 41.0, -70.01);
	glVertex3f(5.0, 41.0, -70.01);
	glEnd();

	///////////kanan
	glBegin(GL_POLYGON);
	glVertex3f(5.0, 38.0, -70.01);
	glVertex3f(13.0, 38.0, -65.01);
	glVertex3f(13.0, 41.0, -65.01);
	glVertex3f(5.0, 41.0, -70.01);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(13.0, 38.0, -65.01);
	glVertex3f(13.0, 41.0, -65.01);
	glVertex3f(20.0, 41.0, -58.01);
	glVertex3f(20.0, 38.0, -58.01);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(5.0, 41.0, -34.9);
	glVertex3f(5.0, 38.0, -34.9);
	glVertex3f(13.0, 38.0, -39.9);
	glVertex3f(13.0, 41.0, -39.9);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(13.0, 38.0, -39.9);
	glVertex3f(13.0, 41.0, -39.9);
	glVertex3f(20.0, 41.0, -46.9);
	glVertex3f(20.0, 38.0, -46.9);
	glEnd();

	///////////kiri
	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 38.0, -70.01);
	glVertex3f(-13.0, 38.0, -65.01);
	glVertex3f(-13.0, 41.0, -65.01);
	glVertex3f(-5.0, 41.0, -70.01);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-13.0, 38.0, -65.01);
	glVertex3f(-13.0, 41.0, -65.01);
	glVertex3f(-20.0, 41.0, -58.01);
	glVertex3f(-20.0, 38.0, -58.01);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 41.0, -34.9);
	glVertex3f(-5.0, 38.0, -34.9);
	glVertex3f(-13.0, 38.0, -39.9);
	glVertex3f(-13.0, 41.0, -39.9);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(-13.0, 38.0, -39.9);
	glVertex3f(-13.0, 41.0, -39.9);
	glVertex3f(-20.0, 41.0, -46.9);
	glVertex3f(-20.0, 38.0, -46.9);
	glEnd();

	/////////////////////////bagian atasnya

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(5.0, 55.0, -57.0);
	glVertex3f(5.0, 41.6, -50.0);
	glVertex3f(5.0, 41.6, -60.0);
	glVertex3f(5.0, 55.0, -59.0);
	glEnd();

	/////////////////// bagian kiri

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(-5.0, 55.0, -57.0);
	glVertex3f(-5.0, 41.6, -50.0);
	glVertex3f(-5.0, 41.6, -60.0);
	glVertex3f(-5.0, 55.0, -59.0);
	glEnd();

	/////////////////// bagian tutup
	glBegin(GL_POLYGON);
	//glColor3f(0.8, 0.8, 0.8);
	glVertex3f(5.0, 41.6, -50.0);
	glVertex3f(5.0, 55.0, -57.0);
	glVertex3f(-5.0, 55.0, -57.0);
	glVertex3f(-5.0, 41.6, -50.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(5.0, 55.0, -57.0);
	glVertex3f(-5.0, 55.0, -57.0);
	glVertex3f(-5.0, 55.0, -59.0);
	glVertex3f(5.0, 55.0, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(-5.0, 55.0, -59.0);
	glVertex3f(5.0, 55.0, -59.0);
	glVertex3f(5.0, 41.6, -60.0);
	glVertex3f(-5.0, 41.6, -60.0);
	glEnd();


}

void uplantai(int r, int g, int b) {
	///////////////////////////////////////

	glBegin(GL_POLYGON);												//lantai atas paling atas
	glColor3f(0.5 + u, 128.5 + i, 0.5 + o);
	glVertex3f(-18.0, 28.01, 53.0);             ///depan kiri
	glVertex3f(18.0, 28.01, 53.0);              ///kanan depan
	glVertex3f(18.0, 28.01, -90.0);             ///kanan belakang
	glVertex3f(-18.0, 28.01, -90.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);				////bodi lantai kecil atasdepan melengkung
	//glColor3f(1.0, 0.0, 1.0);
	glVertex3f(-19.0, 28.1, 49.0);
	glVertex3f(-19.0, 28.1, 52.0);
	glVertex3f(-14.0, 28.1, 56.0);
	glVertex3f(-4.0, 28.1, 60.0);
	glVertex3f(4.0, 28.1, 60.0);
	glVertex3f(14.0, 28.1, 56.0);
	glVertex3f(19.0, 28.1, 52.0);
	glVertex3f(19.0, 28.1, 50.0);
	glEnd();

	glBegin(GL_POLYGON);						///lantai lengkung paling atas belakang
	//glColor3f(1.6, 1.6, 1.6);
	//glColor3f(0.95, 0.95, 0.95);
	glVertex3f(-18.0, 28.01, -90.0);
	glVertex3f(-17.5, 28.01, -92.0);
	glVertex3f(-15.0, 28.01, -96.0);
	glVertex3f(-10.0, 28.01, -101.0);
	glVertex3f(-5.0, 28.01, -103.0);	//tengah kiri
	glVertex3f(5.0, 28.01, -103.0);
	glVertex3f(10.0, 28.01, -101.0);
	glVertex3f(15.0, 28.01, -96.0);
	glVertex3f(17.5, 28.01, -92.0);
	glVertex3f(18.0, 28.01, -90.0);
	glEnd();

	glBegin(GL_POLYGON);						///lantai lengkung paling atas belakang
	//glColor3f(1.6, 1.6, 1.6);
	glColor3f(0.95, 0.95, 0.95);
	glVertex3f(-18.0, 28.0, -90.0);
	glVertex3f(-18.0, 28.0, -92.0);
	glVertex3f(-15.0, 28.0, -96.0);
	glVertex3f(-10.0, 28.0, -101.0);
	glVertex3f(-5.0, 28.0, -103.0);	//tengah kiri
	glVertex3f(5.0, 28.0, -103.0);
	glVertex3f(10.0, 28.0, -101.0);
	glVertex3f(15.0, 28.0, -96.0);
	glVertex3f(18.0, 28.0, -92.0);
	glVertex3f(18.0, 28.0, -90.0);
	glEnd();

	///////////////////////////////////////

	glBegin(GL_POLYGON);								////lantai kecil depan
	glColor3f(0.5 + u, 128.5 + i, 0.5 + o);
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

	glBegin(GL_POLYGON);								////lantai kecil depan
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

}

void kolam(int r, int g, int b) {
	///////////////////////////////////////

	glBegin(GL_POLYGON);												//lantai atas paling atas
	glColor3f(1.5, 0.5, 1.5);
	glVertex3f(-12.0, 28.02, 30.0);             ///depan kiri
	glVertex3f(12.0, 28.02, 30.0);              ///kanan depan
	glVertex3f(12.0, 28.02, -30.0);             ///kanan belakang
	glVertex3f(-12.0, 28.02, -30.0);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);												//lantai atas paling atas
	glColor3f(1.5, 0.5, 1.5);
	glVertex3f(-12.0, 27.61, 30.0);             ///depan kiri
	glVertex3f(12.0, 27.61, 30.0);              ///kanan depan
	glVertex3f(12.0, 27.61, -30.0);             ///kanan belakang
	glVertex3f(-12.0, 27.61, -30.0);           ///kiri belakang
	glEnd();

	//tutup
	glBegin(GL_POLYGON);												//lantai atas paling atas
	glColor3f(1.5, 0.5, 1.5);
	glVertex3f(-12.0, 28.02, 30.0);             ///depan kiri
	glVertex3f(12.0, 28.02, 30.0);              ///kanan depan
	glVertex3f(12.0, 28.02, -30.0);             ///kanan belakang
	glVertex3f(-12.0, 28.02, -30.0);           ///kiri belakang
	glEnd();

	///////////////////////////////////////
}

void pendaratan(int r, int g, int b) {

	glBegin(GL_LINE_LOOP);												//lantai atas paling atas
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-3.0, 4.01, 97.0);             ///depan kiri
	glVertex3f(3.0, 4.01, 97.0);              ///kanan depan
	glVertex3f(3.0, 4.01, 104.0);             ///kanan belakang
	glVertex3f(-3.0, 4.01, 104.0);           ///kiri belakang
	glEnd();

	glBegin(GL_LINES);												//lantai atas paling atas
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-1.0, 4.01, 99.0);             ///depan kiri
	glVertex3f(-1.0, 4.01, 102.0);           ///kiri belakang
	glVertex3f(1.0, 4.01, 99.0);              ///kanan depan
	glVertex3f(1.0, 4.01, 102.0);
	glVertex3f(1.0, 4.01, 100.5);              ///kanan depan
	glVertex3f(-1.0, 4.01, 100.5);
	glEnd();

}

void jendela5(int r, int g, int b) {

	float ta = 26.6;
	float tb = 24.5;
	//31
	glBegin(GL_POLYGON);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glVertex3f(18.01, tb, 47.0);
	glVertex3f(18.01, tb, 45.0);
	glVertex3f(18.01, ta, 45.0);
	glVertex3f(18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 43.0);
	glVertex3f(18.01, tb, 41.0);
	glVertex3f(18.01, ta, 41.0);
	glVertex3f(18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 39.0);
	glVertex3f(18.01, tb, 37.0);
	glVertex3f(18.01, ta, 37.0);
	glVertex3f(18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 35.0);
	glVertex3f(18.01, tb, 33.0);
	glVertex3f(18.01, ta, 33.0);
	glVertex3f(18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 31.0);
	glVertex3f(18.01, tb, 29.0);
	glVertex3f(18.01, ta, 29.0);
	glVertex3f(18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 27.0);
	glVertex3f(18.01, tb, 25.0);
	glVertex3f(18.01, ta, 25.0);
	glVertex3f(18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 23.0);
	glVertex3f(18.01, tb, 21.0);
	glVertex3f(18.01, ta, 21.0);
	glVertex3f(18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 19.0);
	glVertex3f(18.01, tb, 17.0);
	glVertex3f(18.01, ta, 17.0);
	glVertex3f(18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 15.0);
	glVertex3f(18.01, tb, 13.0);
	glVertex3f(18.01, ta, 13.0);
	glVertex3f(18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 11.0);
	glVertex3f(18.01, tb, 9.0);
	glVertex3f(18.01, ta, 9.0);
	glVertex3f(18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 7.0);
	glVertex3f(18.01, tb, 5.0);
	glVertex3f(18.01, ta, 5.0);
	glVertex3f(18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 3.0);
	glVertex3f(18.01, tb, 1.0);
	glVertex3f(18.01, ta, 1.0);
	glVertex3f(18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -1.0);
	glVertex3f(18.01, tb, -3.0);
	glVertex3f(18.01, ta, -3.0);
	glVertex3f(18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -7.0);
	glVertex3f(18.01, tb, -5.0);
	glVertex3f(18.01, ta, -5.0);
	glVertex3f(18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -11.0);
	glVertex3f(18.01, tb, -9.0);
	glVertex3f(18.01, ta, -9.0);
	glVertex3f(18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -15.0);
	glVertex3f(18.01, tb, -13.0);
	glVertex3f(18.01, ta, -13.0);
	glVertex3f(18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -19.0);
	glVertex3f(18.01, tb, -17.0);
	glVertex3f(18.01, ta, -17.0);
	glVertex3f(18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -23.0);
	glVertex3f(18.01, tb, -21.0);
	glVertex3f(18.01, ta, -21.0);
	glVertex3f(18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -27.0);
	glVertex3f(18.01, tb, -25.0);
	glVertex3f(18.01, ta, -25.0);
	glVertex3f(18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -31.0);
	glVertex3f(18.01, tb, -29.0);
	glVertex3f(18.01, ta, -29.0);
	glVertex3f(18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -35.0);
	glVertex3f(18.01, tb, -33.0);
	glVertex3f(18.01, ta, -33.0);
	glVertex3f(18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -39.0);
	glVertex3f(18.01, tb, -37.0);
	glVertex3f(18.01, ta, -37.0);
	glVertex3f(18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -43.0);
	glVertex3f(18.01, tb, -41.0);
	glVertex3f(18.01, ta, -41.0);
	glVertex3f(18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -47.0);
	glVertex3f(18.01, tb, -45.0);
	glVertex3f(18.01, ta, -45.0);
	glVertex3f(18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -51.0);
	glVertex3f(18.01, tb, -49.0);
	glVertex3f(18.01, ta, -49.0);
	glVertex3f(18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -55.0);
	glVertex3f(18.01, tb, -53.0);
	glVertex3f(18.01, ta, -53.0);
	glVertex3f(18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -59.0);
	glVertex3f(18.01, tb, -57.0);
	glVertex3f(18.01, ta, -57.0);
	glVertex3f(18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -63.0);
	glVertex3f(18.01, tb, -61.0);
	glVertex3f(18.01, ta, -61.0);
	glVertex3f(18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -67.0);
	glVertex3f(18.01, tb, -65.0);
	glVertex3f(18.01, ta, -65.0);
	glVertex3f(18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -71.0);
	glVertex3f(18.01, tb, -69.0);
	glVertex3f(18.01, ta, -69.0);
	glVertex3f(18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -75.0);
	glVertex3f(18.01, tb, -73.0);
	glVertex3f(18.01, ta, -73.0);
	glVertex3f(18.01, ta, -75.0);
	glEnd();

	//////////KIRI

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 47.0);
	glVertex3f(-18.01, tb, 45.0);
	glVertex3f(-18.01, ta, 45.0);
	glVertex3f(-18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 43.0);
	glVertex3f(-18.01, tb, 41.0);
	glVertex3f(-18.01, ta, 41.0);
	glVertex3f(-18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 39.0);
	glVertex3f(-18.01, tb, 37.0);
	glVertex3f(-18.01, ta, 37.0);
	glVertex3f(-18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 35.0);
	glVertex3f(-18.01, tb, 33.0);
	glVertex3f(-18.01, ta, 33.0);
	glVertex3f(-18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 31.0);
	glVertex3f(-18.01, tb, 29.0);
	glVertex3f(-18.01, ta, 29.0);
	glVertex3f(-18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 27.0);
	glVertex3f(-18.01, tb, 25.0);
	glVertex3f(-18.01, ta, 25.0);
	glVertex3f(-18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 23.0);
	glVertex3f(-18.01, tb, 21.0);
	glVertex3f(-18.01, ta, 21.0);
	glVertex3f(-18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 19.0);
	glVertex3f(-18.01, tb, 17.0);
	glVertex3f(-18.01, ta, 17.0);
	glVertex3f(-18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 15.0);
	glVertex3f(-18.01, tb, 13.0);
	glVertex3f(-18.01, ta, 13.0);
	glVertex3f(-18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 11.0);
	glVertex3f(-18.01, tb, 9.0);
	glVertex3f(-18.01, ta, 9.0);
	glVertex3f(-18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 7.0);
	glVertex3f(-18.01, tb, 5.0);
	glVertex3f(-18.01, ta, 5.0);
	glVertex3f(-18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 3.0);
	glVertex3f(-18.01, tb, 1.0);
	glVertex3f(-18.01, ta, 1.0);
	glVertex3f(-18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -1.0);
	glVertex3f(-18.01, tb, -3.0);
	glVertex3f(-18.01, ta, -3.0);
	glVertex3f(-18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -7.0);
	glVertex3f(-18.01, tb, -5.0);
	glVertex3f(-18.01, ta, -5.0);
	glVertex3f(-18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -11.0);
	glVertex3f(-18.01, tb, -9.0);
	glVertex3f(-18.01, ta, -9.0);
	glVertex3f(-18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -15.0);
	glVertex3f(-18.01, tb, -13.0);
	glVertex3f(-18.01, ta, -13.0);
	glVertex3f(-18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -19.0);
	glVertex3f(-18.01, tb, -17.0);
	glVertex3f(-18.01, ta, -17.0);
	glVertex3f(-18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -23.0);
	glVertex3f(-18.01, tb, -21.0);
	glVertex3f(-18.01, ta, -21.0);
	glVertex3f(-18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -27.0);
	glVertex3f(-18.01, tb, -25.0);
	glVertex3f(-18.01, ta, -25.0);
	glVertex3f(-18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -31.0);
	glVertex3f(-18.01, tb, -29.0);
	glVertex3f(-18.01, ta, -29.0);
	glVertex3f(-18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -35.0);
	glVertex3f(-18.01, tb, -33.0);
	glVertex3f(-18.01, ta, -33.0);
	glVertex3f(-18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -39.0);
	glVertex3f(-18.01, tb, -37.0);
	glVertex3f(-18.01, ta, -37.0);
	glVertex3f(-18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -43.0);
	glVertex3f(-18.01, tb, -41.0);
	glVertex3f(-18.01, ta, -41.0);
	glVertex3f(-18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -47.0);
	glVertex3f(-18.01, tb, -45.0);
	glVertex3f(-18.01, ta, -45.0);
	glVertex3f(-18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -51.0);
	glVertex3f(-18.01, tb, -49.0);
	glVertex3f(-18.01, ta, -49.0);
	glVertex3f(-18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -55.0);
	glVertex3f(-18.01, tb, -53.0);
	glVertex3f(-18.01, ta, -53.0);
	glVertex3f(-18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -59.0);
	glVertex3f(-18.01, tb, -57.0);
	glVertex3f(-18.01, ta, -57.0);
	glVertex3f(-18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -63.0);
	glVertex3f(-18.01, tb, -61.0);
	glVertex3f(-18.01, ta, -61.0);
	glVertex3f(-18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -67.0);
	glVertex3f(-18.01, tb, -65.0);
	glVertex3f(-18.01, ta, -65.0);
	glVertex3f(-18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -71.0);
	glVertex3f(-18.01, tb, -69.0);
	glVertex3f(-18.01, ta, -69.0);
	glVertex3f(-18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -75.0);
	glVertex3f(-18.01, tb, -73.0);
	glVertex3f(-18.01, ta, -73.0);
	glVertex3f(-18.01, ta, -75.0);
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(16.01, tb, -90.1);
	glVertex3f(14.01, tb, -90.1);
	glVertex3f(14.01, ta, -90.1);
	glVertex3f(16.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(12.01, tb, -90.1);
	glVertex3f(10.01, tb, -90.1);
	glVertex3f(10.01, ta, -90.1);
	glVertex3f(12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(8.01, tb, -90.1);
	glVertex3f(6.01, tb, -90.1);
	glVertex3f(6.01, ta, -90.1);
	glVertex3f(8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.01, tb, -90.1);
	glVertex3f(2.01, tb, -90.1);
	glVertex3f(2.01, ta, -90.1);
	glVertex3f(4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.01, tb, -90.1);
	glVertex3f(-2.01, tb, -90.1);
	glVertex3f(-2.01, ta, -90.1);
	glVertex3f(0.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.01, tb, -90.1);
	glVertex3f(-6.01, tb, -90.1);
	glVertex3f(-6.01, ta, -90.1);
	glVertex3f(-4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8.01, tb, -90.1);
	glVertex3f(-10.01, tb, -90.1);
	glVertex3f(-10.01, ta, -90.1);
	glVertex3f(-8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12.01, tb, -90.1);
	glVertex3f(-14.01, tb, -90.1);
	glVertex3f(-14.01, ta, -90.1);
	glVertex3f(-12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-16.01, tb, -90.1);
	glVertex3f(-18.0, tb, -90.1);
	glVertex3f(-18.0, ta, -90.1);
	glVertex3f(-16.01, ta, -90.1);
	glEnd();

}
void jendela4(int r, int g, int b) {

	s = 0.5;
	ta = 22.0;
	tb = 19.9;
	//33 X 2

	glBegin(GL_POLYGON);
	//glColor3f(0 + s, 0 + t, 0 + p);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glVertex3f(18.01, tb, 50.0);
	glVertex3f(18.01, tb, 48.0);
	glVertex3f(18.01, ta, 48.0);
	glVertex3f(18.01, ta, 50.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 47.0);
	glVertex3f(18.01, tb, 45.0);
	glVertex3f(18.01, ta, 45.0);
	glVertex3f(18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 43.0);
	glVertex3f(18.01, tb, 41.0);
	glVertex3f(18.01, ta, 41.0);
	glVertex3f(18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 39.0);
	glVertex3f(18.01, tb, 37.0);
	glVertex3f(18.01, ta, 37.0);
	glVertex3f(18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 35.0);
	glVertex3f(18.01, tb, 33.0);
	glVertex3f(18.01, ta, 33.0);
	glVertex3f(18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 31.0);
	glVertex3f(18.01, tb, 29.0);
	glVertex3f(18.01, ta, 29.0);
	glVertex3f(18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 27.0);
	glVertex3f(18.01, tb, 25.0);
	glVertex3f(18.01, ta, 25.0);
	glVertex3f(18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 23.0);
	glVertex3f(18.01, tb, 21.0);
	glVertex3f(18.01, ta, 21.0);
	glVertex3f(18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 19.0);
	glVertex3f(18.01, tb, 17.0);
	glVertex3f(18.01, ta, 17.0);
	glVertex3f(18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 15.0);
	glVertex3f(18.01, tb, 13.0);
	glVertex3f(18.01, ta, 13.0);
	glVertex3f(18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 11.0);
	glVertex3f(18.01, tb, 9.0);
	glVertex3f(18.01, ta, 9.0);
	glVertex3f(18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 7.0);
	glVertex3f(18.01, tb, 5.0);
	glVertex3f(18.01, ta, 5.0);
	glVertex3f(18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 3.0);
	glVertex3f(18.01, tb, 1.0);
	glVertex3f(18.01, ta, 1.0);
	glVertex3f(18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -1.0);
	glVertex3f(18.01, tb, -3.0);
	glVertex3f(18.01, ta, -3.0);
	glVertex3f(18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -7.0);
	glVertex3f(18.01, tb, -5.0);
	glVertex3f(18.01, ta, -5.0);
	glVertex3f(18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -11.0);
	glVertex3f(18.01, tb, -9.0);
	glVertex3f(18.01, ta, -9.0);
	glVertex3f(18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -15.0);
	glVertex3f(18.01, tb, -13.0);
	glVertex3f(18.01, ta, -13.0);
	glVertex3f(18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -19.0);
	glVertex3f(18.01, tb, -17.0);
	glVertex3f(18.01, ta, -17.0);
	glVertex3f(18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -23.0);
	glVertex3f(18.01, tb, -21.0);
	glVertex3f(18.01, ta, -21.0);
	glVertex3f(18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -27.0);
	glVertex3f(18.01, tb, -25.0);
	glVertex3f(18.01, ta, -25.0);
	glVertex3f(18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -31.0);
	glVertex3f(18.01, tb, -29.0);
	glVertex3f(18.01, ta, -29.0);
	glVertex3f(18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -35.0);
	glVertex3f(18.01, tb, -33.0);
	glVertex3f(18.01, ta, -33.0);
	glVertex3f(18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -39.0);
	glVertex3f(18.01, tb, -37.0);
	glVertex3f(18.01, ta, -37.0);
	glVertex3f(18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -43.0);
	glVertex3f(18.01, tb, -41.0);
	glVertex3f(18.01, ta, -41.0);
	glVertex3f(18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -47.0);
	glVertex3f(18.01, tb, -45.0);
	glVertex3f(18.01, ta, -45.0);
	glVertex3f(18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -51.0);
	glVertex3f(18.01, tb, -49.0);
	glVertex3f(18.01, ta, -49.0);
	glVertex3f(18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -55.0);
	glVertex3f(18.01, tb, -53.0);
	glVertex3f(18.01, ta, -53.0);
	glVertex3f(18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -59.0);
	glVertex3f(18.01, tb, -57.0);
	glVertex3f(18.01, ta, -57.0);
	glVertex3f(18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -63.0);
	glVertex3f(18.01, tb, -61.0);
	glVertex3f(18.01, ta, -61.0);
	glVertex3f(18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -67.0);
	glVertex3f(18.01, tb, -65.0);
	glVertex3f(18.01, ta, -65.0);
	glVertex3f(18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -71.0);
	glVertex3f(18.01, tb, -69.0);
	glVertex3f(18.01, ta, -69.0);
	glVertex3f(18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -75.0);
	glVertex3f(18.01, tb, -73.0);
	glVertex3f(18.01, ta, -73.0);
	glVertex3f(18.01, ta, -75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -79.0);
	glVertex3f(18.01, tb, -77.0);
	glVertex3f(18.01, ta, -77.0);
	glVertex3f(18.01, ta, -79.0);
	glEnd();

	//////////KIRI

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 50.0);
	glVertex3f(-18.01, tb, 48.0);
	glVertex3f(-18.01, ta, 48.0);
	glVertex3f(-18.01, ta, 50.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 47.0);
	glVertex3f(-18.01, tb, 45.0);
	glVertex3f(-18.01, ta, 45.0);
	glVertex3f(-18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 43.0);
	glVertex3f(-18.01, tb, 41.0);
	glVertex3f(-18.01, ta, 41.0);
	glVertex3f(-18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 39.0);
	glVertex3f(-18.01, tb, 37.0);
	glVertex3f(-18.01, ta, 37.0);
	glVertex3f(-18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 35.0);
	glVertex3f(-18.01, tb, 33.0);
	glVertex3f(-18.01, ta, 33.0);
	glVertex3f(-18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 31.0);
	glVertex3f(-18.01, tb, 29.0);
	glVertex3f(-18.01, ta, 29.0);
	glVertex3f(-18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 27.0);
	glVertex3f(-18.01, tb, 25.0);
	glVertex3f(-18.01, ta, 25.0);
	glVertex3f(-18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 23.0);
	glVertex3f(-18.01, tb, 21.0);
	glVertex3f(-18.01, ta, 21.0);
	glVertex3f(-18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 19.0);
	glVertex3f(-18.01, tb, 17.0);
	glVertex3f(-18.01, ta, 17.0);
	glVertex3f(-18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 15.0);
	glVertex3f(-18.01, tb, 13.0);
	glVertex3f(-18.01, ta, 13.0);
	glVertex3f(-18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 11.0);
	glVertex3f(-18.01, tb, 9.0);
	glVertex3f(-18.01, ta, 9.0);
	glVertex3f(-18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 7.0);
	glVertex3f(-18.01, tb, 5.0);
	glVertex3f(-18.01, ta, 5.0);
	glVertex3f(-18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 3.0);
	glVertex3f(-18.01, tb, 1.0);
	glVertex3f(-18.01, ta, 1.0);
	glVertex3f(-18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -1.0);
	glVertex3f(-18.01, tb, -3.0);
	glVertex3f(-18.01, ta, -3.0);
	glVertex3f(-18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -7.0);
	glVertex3f(-18.01, tb, -5.0);
	glVertex3f(-18.01, ta, -5.0);
	glVertex3f(-18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -11.0);
	glVertex3f(-18.01, tb, -9.0);
	glVertex3f(-18.01, ta, -9.0);
	glVertex3f(-18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -15.0);
	glVertex3f(-18.01, tb, -13.0);
	glVertex3f(-18.01, ta, -13.0);
	glVertex3f(-18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -19.0);
	glVertex3f(-18.01, tb, -17.0);
	glVertex3f(-18.01, ta, -17.0);
	glVertex3f(-18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -23.0);
	glVertex3f(-18.01, tb, -21.0);
	glVertex3f(-18.01, ta, -21.0);
	glVertex3f(-18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -27.0);
	glVertex3f(-18.01, tb, -25.0);
	glVertex3f(-18.01, ta, -25.0);
	glVertex3f(-18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -31.0);
	glVertex3f(-18.01, tb, -29.0);
	glVertex3f(-18.01, ta, -29.0);
	glVertex3f(-18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -35.0);
	glVertex3f(-18.01, tb, -33.0);
	glVertex3f(-18.01, ta, -33.0);
	glVertex3f(-18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -39.0);
	glVertex3f(-18.01, tb, -37.0);
	glVertex3f(-18.01, ta, -37.0);
	glVertex3f(-18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -43.0);
	glVertex3f(-18.01, tb, -41.0);
	glVertex3f(-18.01, ta, -41.0);
	glVertex3f(-18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -47.0);
	glVertex3f(-18.01, tb, -45.0);
	glVertex3f(-18.01, ta, -45.0);
	glVertex3f(-18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -51.0);
	glVertex3f(-18.01, tb, -49.0);
	glVertex3f(-18.01, ta, -49.0);
	glVertex3f(-18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -55.0);
	glVertex3f(-18.01, tb, -53.0);
	glVertex3f(-18.01, ta, -53.0);
	glVertex3f(-18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -59.0);
	glVertex3f(-18.01, tb, -57.0);
	glVertex3f(-18.01, ta, -57.0);
	glVertex3f(-18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -63.0);
	glVertex3f(-18.01, tb, -61.0);
	glVertex3f(-18.01, ta, -61.0);
	glVertex3f(-18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -67.0);
	glVertex3f(-18.01, tb, -65.0);
	glVertex3f(-18.01, ta, -65.0);
	glVertex3f(-18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -71.0);
	glVertex3f(-18.01, tb, -69.0);
	glVertex3f(-18.01, ta, -69.0);
	glVertex3f(-18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -75.0);
	glVertex3f(-18.01, tb, -73.0);
	glVertex3f(-18.01, ta, -73.0);
	glVertex3f(-18.01, ta, -75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -79.0);
	glVertex3f(-18.01, tb, -77.0);
	glVertex3f(-18.01, ta, -77.0);
	glVertex3f(-18.01, ta, -79.0);
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(16.01, tb, -90.1);
	glVertex3f(14.01, tb, -90.1);
	glVertex3f(14.01, ta, -90.1);
	glVertex3f(16.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(12.01, tb, -90.1);
	glVertex3f(10.01, tb, -90.1);
	glVertex3f(10.01, ta, -90.1);
	glVertex3f(12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(8.01, tb, -90.1);
	glVertex3f(6.01, tb, -90.1);
	glVertex3f(6.01, ta, -90.1);
	glVertex3f(8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.01, tb, -90.1);
	glVertex3f(2.01, tb, -90.1);
	glVertex3f(2.01, ta, -90.1);
	glVertex3f(4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.01, tb, -90.1);
	glVertex3f(-2.01, tb, -90.1);
	glVertex3f(-2.01, ta, -90.1);
	glVertex3f(0.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.01, tb, -90.1);
	glVertex3f(-6.01, tb, -90.1);
	glVertex3f(-6.01, ta, -90.1);
	glVertex3f(-4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8.01, tb, -90.1);
	glVertex3f(-10.01, tb, -90.1);
	glVertex3f(-10.01, ta, -90.1);
	glVertex3f(-8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12.01, tb, -90.1);
	glVertex3f(-14.01, tb, -90.1);
	glVertex3f(-14.01, ta, -90.1);
	glVertex3f(-12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-16.01, tb, -90.1);
	glVertex3f(-18.0, tb, -90.1);
	glVertex3f(-18.0, ta, -90.1);
	glVertex3f(-16.01, ta, -90.1);
	glEnd();

}
void jendela3(int r, int g, int b) {

	s = 0.5;
	ta = 17.0;
	tb = 15.3;
	//35 X 2

	glBegin(GL_POLYGON);
	//glColor3f(0 + s, 0 + t, 0 + p);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glVertex3f(18.01, tb, 58.0);
	glVertex3f(18.01, tb, 56.0);
	glVertex3f(18.01, ta, 56.0);
	glVertex3f(18.01, ta, 58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 55.0);
	glVertex3f(18.01, tb, 53.0);
	glVertex3f(18.01, ta, 53.0);
	glVertex3f(18.01, ta, 55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 51.0);
	glVertex3f(18.01, tb, 49.0);
	glVertex3f(18.01, ta, 49.0);
	glVertex3f(18.01, ta, 51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 47.0);
	glVertex3f(18.01, tb, 45.0);
	glVertex3f(18.01, ta, 45.0);
	glVertex3f(18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 43.0);
	glVertex3f(18.01, tb, 41.0);
	glVertex3f(18.01, ta, 41.0);
	glVertex3f(18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 39.0);
	glVertex3f(18.01, tb, 37.0);
	glVertex3f(18.01, ta, 37.0);
	glVertex3f(18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 35.0);
	glVertex3f(18.01, tb, 33.0);
	glVertex3f(18.01, ta, 33.0);
	glVertex3f(18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 31.0);
	glVertex3f(18.01, tb, 29.0);
	glVertex3f(18.01, ta, 29.0);
	glVertex3f(18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 27.0);
	glVertex3f(18.01, tb, 25.0);
	glVertex3f(18.01, ta, 25.0);
	glVertex3f(18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 23.0);
	glVertex3f(18.01, tb, 21.0);
	glVertex3f(18.01, ta, 21.0);
	glVertex3f(18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 19.0);
	glVertex3f(18.01, tb, 17.0);
	glVertex3f(18.01, ta, 17.0);
	glVertex3f(18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 15.0);
	glVertex3f(18.01, tb, 13.0);
	glVertex3f(18.01, ta, 13.0);
	glVertex3f(18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 11.0);
	glVertex3f(18.01, tb, 9.0);
	glVertex3f(18.01, ta, 9.0);
	glVertex3f(18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 7.0);
	glVertex3f(18.01, tb, 5.0);
	glVertex3f(18.01, ta, 5.0);
	glVertex3f(18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 3.0);
	glVertex3f(18.01, tb, 1.0);
	glVertex3f(18.01, ta, 1.0);
	glVertex3f(18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -1.0);
	glVertex3f(18.01, tb, -3.0);
	glVertex3f(18.01, ta, -3.0);
	glVertex3f(18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -7.0);
	glVertex3f(18.01, tb, -5.0);
	glVertex3f(18.01, ta, -5.0);
	glVertex3f(18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -11.0);
	glVertex3f(18.01, tb, -9.0);
	glVertex3f(18.01, ta, -9.0);
	glVertex3f(18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -15.0);
	glVertex3f(18.01, tb, -13.0);
	glVertex3f(18.01, ta, -13.0);
	glVertex3f(18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -19.0);
	glVertex3f(18.01, tb, -17.0);
	glVertex3f(18.01, ta, -17.0);
	glVertex3f(18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -23.0);
	glVertex3f(18.01, tb, -21.0);
	glVertex3f(18.01, ta, -21.0);
	glVertex3f(18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -27.0);
	glVertex3f(18.01, tb, -25.0);
	glVertex3f(18.01, ta, -25.0);
	glVertex3f(18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -31.0);
	glVertex3f(18.01, tb, -29.0);
	glVertex3f(18.01, ta, -29.0);
	glVertex3f(18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -35.0);
	glVertex3f(18.01, tb, -33.0);
	glVertex3f(18.01, ta, -33.0);
	glVertex3f(18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -39.0);
	glVertex3f(18.01, tb, -37.0);
	glVertex3f(18.01, ta, -37.0);
	glVertex3f(18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -43.0);
	glVertex3f(18.01, tb, -41.0);
	glVertex3f(18.01, ta, -41.0);
	glVertex3f(18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -47.0);
	glVertex3f(18.01, tb, -45.0);
	glVertex3f(18.01, ta, -45.0);
	glVertex3f(18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -51.0);
	glVertex3f(18.01, tb, -49.0);
	glVertex3f(18.01, ta, -49.0);
	glVertex3f(18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -55.0);
	glVertex3f(18.01, tb, -53.0);
	glVertex3f(18.01, ta, -53.0);
	glVertex3f(18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -59.0);
	glVertex3f(18.01, tb, -57.0);
	glVertex3f(18.01, ta, -57.0);
	glVertex3f(18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -63.0);
	glVertex3f(18.01, tb, -61.0);
	glVertex3f(18.01, ta, -61.0);
	glVertex3f(18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -67.0);
	glVertex3f(18.01, tb, -65.0);
	glVertex3f(18.01, ta, -65.0);
	glVertex3f(18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -71.0);
	glVertex3f(18.01, tb, -69.0);
	glVertex3f(18.01, ta, -69.0);
	glVertex3f(18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -75.0);
	glVertex3f(18.01, tb, -73.0);
	glVertex3f(18.01, ta, -73.0);
	glVertex3f(18.01, ta, -75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -79.0);
	glVertex3f(18.01, tb, -77.0);
	glVertex3f(18.01, ta, -77.0);
	glVertex3f(18.01, ta, -79.0);
	glEnd();

	//////////KIRI


	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 58.0);
	glVertex3f(-18.01, tb, 56.0);
	glVertex3f(-18.01, ta, 56.0);
	glVertex3f(-18.01, ta, 58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 55.0);
	glVertex3f(-18.01, tb, 53.0);
	glVertex3f(-18.01, ta, 53.0);
	glVertex3f(-18.01, ta, 55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 51.0);
	glVertex3f(-18.01, tb, 49.0);
	glVertex3f(-18.01, ta, 49.0);
	glVertex3f(-18.01, ta, 51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 47.0);
	glVertex3f(-18.01, tb, 45.0);
	glVertex3f(-18.01, ta, 45.0);
	glVertex3f(-18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 43.0);
	glVertex3f(-18.01, tb, 41.0);
	glVertex3f(-18.01, ta, 41.0);
	glVertex3f(-18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 39.0);
	glVertex3f(-18.01, tb, 37.0);
	glVertex3f(-18.01, ta, 37.0);
	glVertex3f(-18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 35.0);
	glVertex3f(-18.01, tb, 33.0);
	glVertex3f(-18.01, ta, 33.0);
	glVertex3f(-18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 31.0);
	glVertex3f(-18.01, tb, 29.0);
	glVertex3f(-18.01, ta, 29.0);
	glVertex3f(-18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 27.0);
	glVertex3f(-18.01, tb, 25.0);
	glVertex3f(-18.01, ta, 25.0);
	glVertex3f(-18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 23.0);
	glVertex3f(-18.01, tb, 21.0);
	glVertex3f(-18.01, ta, 21.0);
	glVertex3f(-18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 19.0);
	glVertex3f(-18.01, tb, 17.0);
	glVertex3f(-18.01, ta, 17.0);
	glVertex3f(-18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 15.0);
	glVertex3f(-18.01, tb, 13.0);
	glVertex3f(-18.01, ta, 13.0);
	glVertex3f(-18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 11.0);
	glVertex3f(-18.01, tb, 9.0);
	glVertex3f(-18.01, ta, 9.0);
	glVertex3f(-18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 7.0);
	glVertex3f(-18.01, tb, 5.0);
	glVertex3f(-18.01, ta, 5.0);
	glVertex3f(-18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 3.0);
	glVertex3f(-18.01, tb, 1.0);
	glVertex3f(-18.01, ta, 1.0);
	glVertex3f(-18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -1.0);
	glVertex3f(-18.01, tb, -3.0);
	glVertex3f(-18.01, ta, -3.0);
	glVertex3f(-18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -7.0);
	glVertex3f(-18.01, tb, -5.0);
	glVertex3f(-18.01, ta, -5.0);
	glVertex3f(-18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -11.0);
	glVertex3f(-18.01, tb, -9.0);
	glVertex3f(-18.01, ta, -9.0);
	glVertex3f(-18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -15.0);
	glVertex3f(-18.01, tb, -13.0);
	glVertex3f(-18.01, ta, -13.0);
	glVertex3f(-18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -19.0);
	glVertex3f(-18.01, tb, -17.0);
	glVertex3f(-18.01, ta, -17.0);
	glVertex3f(-18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -23.0);
	glVertex3f(-18.01, tb, -21.0);
	glVertex3f(-18.01, ta, -21.0);
	glVertex3f(-18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -27.0);
	glVertex3f(-18.01, tb, -25.0);
	glVertex3f(-18.01, ta, -25.0);
	glVertex3f(-18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -31.0);
	glVertex3f(-18.01, tb, -29.0);
	glVertex3f(-18.01, ta, -29.0);
	glVertex3f(-18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -35.0);
	glVertex3f(-18.01, tb, -33.0);
	glVertex3f(-18.01, ta, -33.0);
	glVertex3f(-18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -39.0);
	glVertex3f(-18.01, tb, -37.0);
	glVertex3f(-18.01, ta, -37.0);
	glVertex3f(-18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -43.0);
	glVertex3f(-18.01, tb, -41.0);
	glVertex3f(-18.01, ta, -41.0);
	glVertex3f(-18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -47.0);
	glVertex3f(-18.01, tb, -45.0);
	glVertex3f(-18.01, ta, -45.0);
	glVertex3f(-18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -51.0);
	glVertex3f(-18.01, tb, -49.0);
	glVertex3f(-18.01, ta, -49.0);
	glVertex3f(-18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -55.0);
	glVertex3f(-18.01, tb, -53.0);
	glVertex3f(-18.01, ta, -53.0);
	glVertex3f(-18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -59.0);
	glVertex3f(-18.01, tb, -57.0);
	glVertex3f(-18.01, ta, -57.0);
	glVertex3f(-18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -63.0);
	glVertex3f(-18.01, tb, -61.0);
	glVertex3f(-18.01, ta, -61.0);
	glVertex3f(-18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -67.0);
	glVertex3f(-18.01, tb, -65.0);
	glVertex3f(-18.01, ta, -65.0);
	glVertex3f(-18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -71.0);
	glVertex3f(-18.01, tb, -69.0);
	glVertex3f(-18.01, ta, -69.0);
	glVertex3f(-18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -75.0);
	glVertex3f(-18.01, tb, -73.0);
	glVertex3f(-18.01, ta, -73.0);
	glVertex3f(-18.01, ta, -75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -79.0);
	glVertex3f(-18.01, tb, -77.0);
	glVertex3f(-18.01, ta, -77.0);
	glVertex3f(-18.01, ta, -79.0);
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(16.01, tb, -90.1);
	glVertex3f(14.01, tb, -90.1);
	glVertex3f(14.01, ta, -90.1);
	glVertex3f(16.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(12.01, tb, -90.1);
	glVertex3f(10.01, tb, -90.1);
	glVertex3f(10.01, ta, -90.1);
	glVertex3f(12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(8.01, tb, -90.1);
	glVertex3f(6.01, tb, -90.1);
	glVertex3f(6.01, ta, -90.1);
	glVertex3f(8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.01, tb, -90.1);
	glVertex3f(2.01, tb, -90.1);
	glVertex3f(2.01, ta, -90.1);
	glVertex3f(4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.01, tb, -90.1);
	glVertex3f(-2.01, tb, -90.1);
	glVertex3f(-2.01, ta, -90.1);
	glVertex3f(0.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.01, tb, -90.1);
	glVertex3f(-6.01, tb, -90.1);
	glVertex3f(-6.01, ta, -90.1);
	glVertex3f(-4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8.01, tb, -90.1);
	glVertex3f(-10.01, tb, -90.1);
	glVertex3f(-10.01, ta, -90.1);
	glVertex3f(-8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12.01, tb, -90.1);
	glVertex3f(-14.01, tb, -90.1);
	glVertex3f(-14.01, ta, -90.1);
	glVertex3f(-12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-16.01, tb, -90.1);
	glVertex3f(-18.0, tb, -90.1);
	glVertex3f(-18.0, ta, -90.1);
	glVertex3f(-16.01, ta, -90.1);
	glEnd();

}
void jendela2(int r, int g, int b) {

	s = 0.5;
	ta = 12.8;
	tb = 10.7;
	//36 X 2

	glBegin(GL_POLYGON);
	//glColor3f(0 + s, 0 + t, 0 + p);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glVertex3f(18.3, tb, 61.0);
	glVertex3f(18.01, tb, 59.0);
	glVertex3f(18.01, ta, 59.0);
	glVertex3f(18.3, ta, 61.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 58.0);
	glVertex3f(18.01, tb, 56.0);
	glVertex3f(18.01, ta, 56.0);
	glVertex3f(18.01, ta, 58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 55.0);
	glVertex3f(18.01, tb, 53.0);
	glVertex3f(18.01, ta, 53.0);
	glVertex3f(18.01, ta, 55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 51.0);
	glVertex3f(18.01, tb, 49.0);
	glVertex3f(18.01, ta, 49.0);
	glVertex3f(18.01, ta, 51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 47.0);
	glVertex3f(18.01, tb, 45.0);
	glVertex3f(18.01, ta, 45.0);
	glVertex3f(18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 43.0);
	glVertex3f(18.01, tb, 41.0);
	glVertex3f(18.01, ta, 41.0);
	glVertex3f(18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 39.0);
	glVertex3f(18.01, tb, 37.0);
	glVertex3f(18.01, ta, 37.0);
	glVertex3f(18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 35.0);
	glVertex3f(18.01, tb, 33.0);
	glVertex3f(18.01, ta, 33.0);
	glVertex3f(18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 31.0);
	glVertex3f(18.01, tb, 29.0);
	glVertex3f(18.01, ta, 29.0);
	glVertex3f(18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 27.0);
	glVertex3f(18.01, tb, 25.0);
	glVertex3f(18.01, ta, 25.0);
	glVertex3f(18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 23.0);
	glVertex3f(18.01, tb, 21.0);
	glVertex3f(18.01, ta, 21.0);
	glVertex3f(18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 19.0);
	glVertex3f(18.01, tb, 17.0);
	glVertex3f(18.01, ta, 17.0);
	glVertex3f(18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 15.0);
	glVertex3f(18.01, tb, 13.0);
	glVertex3f(18.01, ta, 13.0);
	glVertex3f(18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 11.0);
	glVertex3f(18.01, tb, 9.0);
	glVertex3f(18.01, ta, 9.0);
	glVertex3f(18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 7.0);
	glVertex3f(18.01, tb, 5.0);
	glVertex3f(18.01, ta, 5.0);
	glVertex3f(18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 3.0);
	glVertex3f(18.01, tb, 1.0);
	glVertex3f(18.01, ta, 1.0);
	glVertex3f(18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -1.0);
	glVertex3f(18.01, tb, -3.0);
	glVertex3f(18.01, ta, -3.0);
	glVertex3f(18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -7.0);
	glVertex3f(18.01, tb, -5.0);
	glVertex3f(18.01, ta, -5.0);
	glVertex3f(18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -11.0);
	glVertex3f(18.01, tb, -9.0);
	glVertex3f(18.01, ta, -9.0);
	glVertex3f(18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -15.0);
	glVertex3f(18.01, tb, -13.0);
	glVertex3f(18.01, ta, -13.0);
	glVertex3f(18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -19.0);
	glVertex3f(18.01, tb, -17.0);
	glVertex3f(18.01, ta, -17.0);
	glVertex3f(18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -23.0);
	glVertex3f(18.01, tb, -21.0);
	glVertex3f(18.01, ta, -21.0);
	glVertex3f(18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -27.0);
	glVertex3f(18.01, tb, -25.0);
	glVertex3f(18.01, ta, -25.0);
	glVertex3f(18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -31.0);
	glVertex3f(18.01, tb, -29.0);
	glVertex3f(18.01, ta, -29.0);
	glVertex3f(18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -35.0);
	glVertex3f(18.01, tb, -33.0);
	glVertex3f(18.01, ta, -33.0);
	glVertex3f(18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -39.0);
	glVertex3f(18.01, tb, -37.0);
	glVertex3f(18.01, ta, -37.0);
	glVertex3f(18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -43.0);
	glVertex3f(18.01, tb, -41.0);
	glVertex3f(18.01, ta, -41.0);
	glVertex3f(18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -47.0);
	glVertex3f(18.01, tb, -45.0);
	glVertex3f(18.01, ta, -45.0);
	glVertex3f(18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -51.0);
	glVertex3f(18.01, tb, -49.0);
	glVertex3f(18.01, ta, -49.0);
	glVertex3f(18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -55.0);
	glVertex3f(18.01, tb, -53.0);
	glVertex3f(18.01, ta, -53.0);
	glVertex3f(18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -59.0);
	glVertex3f(18.01, tb, -57.0);
	glVertex3f(18.01, ta, -57.0);
	glVertex3f(18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -63.0);
	glVertex3f(18.01, tb, -61.0);
	glVertex3f(18.01, ta, -61.0);
	glVertex3f(18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -67.0);
	glVertex3f(18.01, tb, -65.0);
	glVertex3f(18.01, ta, -65.0);
	glVertex3f(18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -71.0);
	glVertex3f(18.01, tb, -69.0);
	glVertex3f(18.01, ta, -69.0);
	glVertex3f(18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -75.0);
	glVertex3f(18.01, tb, -73.0);
	glVertex3f(18.01, ta, -73.0);
	glVertex3f(18.01, ta, -75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -79.0);
	glVertex3f(18.01, tb, -77.0);
	glVertex3f(18.01, ta, -77.0);
	glVertex3f(18.01, ta, -79.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -83.0);
	glVertex3f(18.01, tb, -81.0);
	glVertex3f(18.01, ta, -81.0);
	glVertex3f(18.01, ta, -83.0);
	glEnd();

	//////////KIRI

	glBegin(GL_POLYGON);
	glVertex3f(-18.3, tb, 61.0);
	glVertex3f(-18.01, tb, 59.0);
	glVertex3f(-18.01, ta, 59.0);
	glVertex3f(-18.3, ta, 61.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 58.0);
	glVertex3f(-18.01, tb, 56.0);
	glVertex3f(-18.01, ta, 56.0);
	glVertex3f(-18.01, ta, 58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 55.0);
	glVertex3f(-18.01, tb, 53.0);
	glVertex3f(-18.01, ta, 53.0);
	glVertex3f(-18.01, ta, 55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 51.0);
	glVertex3f(-18.01, tb, 49.0);
	glVertex3f(-18.01, ta, 49.0);
	glVertex3f(-18.01, ta, 51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 47.0);
	glVertex3f(-18.01, tb, 45.0);
	glVertex3f(-18.01, ta, 45.0);
	glVertex3f(-18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 43.0);
	glVertex3f(-18.01, tb, 41.0);
	glVertex3f(-18.01, ta, 41.0);
	glVertex3f(-18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 39.0);
	glVertex3f(-18.01, tb, 37.0);
	glVertex3f(-18.01, ta, 37.0);
	glVertex3f(-18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 35.0);
	glVertex3f(-18.01, tb, 33.0);
	glVertex3f(-18.01, ta, 33.0);
	glVertex3f(-18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 31.0);
	glVertex3f(-18.01, tb, 29.0);
	glVertex3f(-18.01, ta, 29.0);
	glVertex3f(-18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 27.0);
	glVertex3f(-18.01, tb, 25.0);
	glVertex3f(-18.01, ta, 25.0);
	glVertex3f(-18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 23.0);
	glVertex3f(-18.01, tb, 21.0);
	glVertex3f(-18.01, ta, 21.0);
	glVertex3f(-18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 19.0);
	glVertex3f(-18.01, tb, 17.0);
	glVertex3f(-18.01, ta, 17.0);
	glVertex3f(-18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 15.0);
	glVertex3f(-18.01, tb, 13.0);
	glVertex3f(-18.01, ta, 13.0);
	glVertex3f(-18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 11.0);
	glVertex3f(-18.01, tb, 9.0);
	glVertex3f(-18.01, ta, 9.0);
	glVertex3f(-18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 7.0);
	glVertex3f(-18.01, tb, 5.0);
	glVertex3f(-18.01, ta, 5.0);
	glVertex3f(-18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 3.0);
	glVertex3f(-18.01, tb, 1.0);
	glVertex3f(-18.01, ta, 1.0);
	glVertex3f(-18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -1.0);
	glVertex3f(-18.01, tb, -3.0);
	glVertex3f(-18.01, ta, -3.0);
	glVertex3f(-18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -7.0);
	glVertex3f(-18.01, tb, -5.0);
	glVertex3f(-18.01, ta, -5.0);
	glVertex3f(-18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -11.0);
	glVertex3f(-18.01, tb, -9.0);
	glVertex3f(-18.01, ta, -9.0);
	glVertex3f(-18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -15.0);
	glVertex3f(-18.01, tb, -13.0);
	glVertex3f(-18.01, ta, -13.0);
	glVertex3f(-18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -19.0);
	glVertex3f(-18.01, tb, -17.0);
	glVertex3f(-18.01, ta, -17.0);
	glVertex3f(-18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -23.0);
	glVertex3f(-18.01, tb, -21.0);
	glVertex3f(-18.01, ta, -21.0);
	glVertex3f(-18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -27.0);
	glVertex3f(-18.01, tb, -25.0);
	glVertex3f(-18.01, ta, -25.0);
	glVertex3f(-18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -31.0);
	glVertex3f(-18.01, tb, -29.0);
	glVertex3f(-18.01, ta, -29.0);
	glVertex3f(-18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -35.0);
	glVertex3f(-18.01, tb, -33.0);
	glVertex3f(-18.01, ta, -33.0);
	glVertex3f(-18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -39.0);
	glVertex3f(-18.01, tb, -37.0);
	glVertex3f(-18.01, ta, -37.0);
	glVertex3f(-18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -43.0);
	glVertex3f(-18.01, tb, -41.0);
	glVertex3f(-18.01, ta, -41.0);
	glVertex3f(-18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -47.0);
	glVertex3f(-18.01, tb, -45.0);
	glVertex3f(-18.01, ta, -45.0);
	glVertex3f(-18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -51.0);
	glVertex3f(-18.01, tb, -49.0);
	glVertex3f(-18.01, ta, -49.0);
	glVertex3f(-18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -55.0);
	glVertex3f(-18.01, tb, -53.0);
	glVertex3f(-18.01, ta, -53.0);
	glVertex3f(-18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -59.0);
	glVertex3f(-18.01, tb, -57.0);
	glVertex3f(-18.01, ta, -57.0);
	glVertex3f(-18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -63.0);
	glVertex3f(-18.01, tb, -61.0);
	glVertex3f(-18.01, ta, -61.0);
	glVertex3f(-18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -67.0);
	glVertex3f(-18.01, tb, -65.0);
	glVertex3f(-18.01, ta, -65.0);
	glVertex3f(-18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -71.0);
	glVertex3f(-18.01, tb, -69.0);
	glVertex3f(-18.01, ta, -69.0);
	glVertex3f(-18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -75.0);
	glVertex3f(-18.01, tb, -73.0);
	glVertex3f(-18.01, ta, -73.0);
	glVertex3f(-18.01, ta, -75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -79.0);
	glVertex3f(-18.01, tb, -77.0);
	glVertex3f(-18.01, ta, -77.0);
	glVertex3f(-18.01, ta, -79.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -83.0);
	glVertex3f(-18.01, tb, -81.0);
	glVertex3f(-18.01, ta, -81.0);
	glVertex3f(-18.01, ta, -83.0);
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(16.01, tb, -90.1);
	glVertex3f(14.01, tb, -90.1);
	glVertex3f(14.01, ta, -90.1);
	glVertex3f(16.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(12.01, tb, -90.1);
	glVertex3f(10.01, tb, -90.1);
	glVertex3f(10.01, ta, -90.1);
	glVertex3f(12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(8.01, tb, -90.1);
	glVertex3f(6.01, tb, -90.1);
	glVertex3f(6.01, ta, -90.1);
	glVertex3f(8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.01, tb, -90.1);
	glVertex3f(2.01, tb, -90.1);
	glVertex3f(2.01, ta, -90.1);
	glVertex3f(4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.01, tb, -90.1);
	glVertex3f(-2.01, tb, -90.1);
	glVertex3f(-2.01, ta, -90.1);
	glVertex3f(0.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.01, tb, -90.1);
	glVertex3f(-6.01, tb, -90.1);
	glVertex3f(-6.01, ta, -90.1);
	glVertex3f(-4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8.01, tb, -90.1);
	glVertex3f(-10.01, tb, -90.1);
	glVertex3f(-10.01, ta, -90.1);
	glVertex3f(-8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12.01, tb, -90.1);
	glVertex3f(-14.01, tb, -90.1);
	glVertex3f(-14.01, ta, -90.1);
	glVertex3f(-12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-16.01, tb, -90.1);
	glVertex3f(-18.0, tb, -90.1);
	glVertex3f(-18.0, ta, -90.1);
	glVertex3f(-16.01, ta, -90.1);
	glEnd();

}
void jendela1(int r, int g, int b) {

	s = 0.5;
	ta = 8.2;
	tb = 6.1;
	//37 X 2

	glBegin(GL_POLYGON);
	//glColor3f(0 + s, 0 + t, 0 + p);
	glColor3f(0.5 + s, 0.5 + t, 0.5 + p);
	glVertex3f(19.0, tb, 64.0);
	glVertex3f(18.6, tb, 62.0);
	glVertex3f(18.6, ta, 62.0);
	glVertex3f(19.0, ta, 64.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.3, tb, 61.0);
	glVertex3f(18.01, tb, 59.0);
	glVertex3f(18.01, ta, 59.0);
	glVertex3f(18.3, ta, 61.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 58.0);
	glVertex3f(18.01, tb, 56.0);
	glVertex3f(18.01, ta, 56.0);
	glVertex3f(18.01, ta, 58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 55.0);
	glVertex3f(18.01, tb, 53.0);
	glVertex3f(18.01, ta, 53.0);
	glVertex3f(18.01, ta, 55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 51.0);
	glVertex3f(18.01, tb, 49.0);
	glVertex3f(18.01, ta, 49.0);
	glVertex3f(18.01, ta, 51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 47.0);
	glVertex3f(18.01, tb, 45.0);
	glVertex3f(18.01, ta, 45.0);
	glVertex3f(18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 43.0);
	glVertex3f(18.01, tb, 41.0);
	glVertex3f(18.01, ta, 41.0);
	glVertex3f(18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 39.0);
	glVertex3f(18.01, tb, 37.0);
	glVertex3f(18.01, ta, 37.0);
	glVertex3f(18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 35.0);
	glVertex3f(18.01, tb, 33.0);
	glVertex3f(18.01, ta, 33.0);
	glVertex3f(18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 31.0);
	glVertex3f(18.01, tb, 29.0);
	glVertex3f(18.01, ta, 29.0);
	glVertex3f(18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 27.0);
	glVertex3f(18.01, tb, 25.0);
	glVertex3f(18.01, ta, 25.0);
	glVertex3f(18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 23.0);
	glVertex3f(18.01, tb, 21.0);
	glVertex3f(18.01, ta, 21.0);
	glVertex3f(18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 19.0);
	glVertex3f(18.01, tb, 17.0);
	glVertex3f(18.01, ta, 17.0);
	glVertex3f(18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 15.0);
	glVertex3f(18.01, tb, 13.0);
	glVertex3f(18.01, ta, 13.0);
	glVertex3f(18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 11.0);
	glVertex3f(18.01, tb, 9.0);
	glVertex3f(18.01, ta, 9.0);
	glVertex3f(18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 7.0);
	glVertex3f(18.01, tb, 5.0);
	glVertex3f(18.01, ta, 5.0);
	glVertex3f(18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, 3.0);
	glVertex3f(18.01, tb, 1.0);
	glVertex3f(18.01, ta, 1.0);
	glVertex3f(18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -1.0);
	glVertex3f(18.01, tb, -3.0);
	glVertex3f(18.01, ta, -3.0);
	glVertex3f(18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -7.0);
	glVertex3f(18.01, tb, -5.0);
	glVertex3f(18.01, ta, -5.0);
	glVertex3f(18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -11.0);
	glVertex3f(18.01, tb, -9.0);
	glVertex3f(18.01, ta, -9.0);
	glVertex3f(18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -15.0);
	glVertex3f(18.01, tb, -13.0);
	glVertex3f(18.01, ta, -13.0);
	glVertex3f(18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -19.0);
	glVertex3f(18.01, tb, -17.0);
	glVertex3f(18.01, ta, -17.0);
	glVertex3f(18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -23.0);
	glVertex3f(18.01, tb, -21.0);
	glVertex3f(18.01, ta, -21.0);
	glVertex3f(18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -27.0);
	glVertex3f(18.01, tb, -25.0);
	glVertex3f(18.01, ta, -25.0);
	glVertex3f(18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -31.0);
	glVertex3f(18.01, tb, -29.0);
	glVertex3f(18.01, ta, -29.0);
	glVertex3f(18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -35.0);
	glVertex3f(18.01, tb, -33.0);
	glVertex3f(18.01, ta, -33.0);
	glVertex3f(18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -39.0);
	glVertex3f(18.01, tb, -37.0);
	glVertex3f(18.01, ta, -37.0);
	glVertex3f(18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -43.0);
	glVertex3f(18.01, tb, -41.0);
	glVertex3f(18.01, ta, -41.0);
	glVertex3f(18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -47.0);
	glVertex3f(18.01, tb, -45.0);
	glVertex3f(18.01, ta, -45.0);
	glVertex3f(18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -51.0);
	glVertex3f(18.01, tb, -49.0);
	glVertex3f(18.01, ta, -49.0);
	glVertex3f(18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -55.0);
	glVertex3f(18.01, tb, -53.0);
	glVertex3f(18.01, ta, -53.0);
	glVertex3f(18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -59.0);
	glVertex3f(18.01, tb, -57.0);
	glVertex3f(18.01, ta, -57.0);
	glVertex3f(18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -63.0);
	glVertex3f(18.01, tb, -61.0);
	glVertex3f(18.01, ta, -61.0);
	glVertex3f(18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -67.0);
	glVertex3f(18.01, tb, -65.0);
	glVertex3f(18.01, ta, -65.0);
	glVertex3f(18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -71.0);
	glVertex3f(18.01, tb, -69.0);
	glVertex3f(18.01, ta, -69.0);
	glVertex3f(18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -75.0);
	glVertex3f(18.01, tb, -73.0);
	glVertex3f(18.01, ta, -73.0);
	glVertex3f(18.01, ta, -75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -79.0);
	glVertex3f(18.01, tb, -77.0);
	glVertex3f(18.01, ta, -77.0);
	glVertex3f(18.01, ta, -79.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(18.01, tb, -83.0);
	glVertex3f(18.01, tb, -81.0);
	glVertex3f(18.01, ta, -81.0);
	glVertex3f(18.01, ta, -83.0);
	glEnd();

	//////////KIRI

	glBegin(GL_POLYGON);
	glVertex3f(-19.0, tb, 64.0);
	glVertex3f(-18.6, tb, 62.0);
	glVertex3f(-18.6, ta, 62.0);
	glVertex3f(-19.0, ta, 64.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.3, tb, 61.0);
	glVertex3f(-18.01, tb, 59.0);
	glVertex3f(-18.01, ta, 59.0);
	glVertex3f(-18.3, ta, 61.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 58.0);
	glVertex3f(-18.01, tb, 56.0);
	glVertex3f(-18.01, ta, 56.0);
	glVertex3f(-18.01, ta, 58.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 55.0);
	glVertex3f(-18.01, tb, 53.0);
	glVertex3f(-18.01, ta, 53.0);
	glVertex3f(-18.01, ta, 55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 51.0);
	glVertex3f(-18.01, tb, 49.0);
	glVertex3f(-18.01, ta, 49.0);
	glVertex3f(-18.01, ta, 51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 47.0);
	glVertex3f(-18.01, tb, 45.0);
	glVertex3f(-18.01, ta, 45.0);
	glVertex3f(-18.01, ta, 47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 43.0);
	glVertex3f(-18.01, tb, 41.0);
	glVertex3f(-18.01, ta, 41.0);
	glVertex3f(-18.01, ta, 43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 39.0);
	glVertex3f(-18.01, tb, 37.0);
	glVertex3f(-18.01, ta, 37.0);
	glVertex3f(-18.01, ta, 39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 35.0);
	glVertex3f(-18.01, tb, 33.0);
	glVertex3f(-18.01, ta, 33.0);
	glVertex3f(-18.01, ta, 35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 31.0);
	glVertex3f(-18.01, tb, 29.0);
	glVertex3f(-18.01, ta, 29.0);
	glVertex3f(-18.01, ta, 31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 27.0);
	glVertex3f(-18.01, tb, 25.0);
	glVertex3f(-18.01, ta, 25.0);
	glVertex3f(-18.01, ta, 27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 23.0);
	glVertex3f(-18.01, tb, 21.0);
	glVertex3f(-18.01, ta, 21.0);
	glVertex3f(-18.01, ta, 23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 19.0);
	glVertex3f(-18.01, tb, 17.0);
	glVertex3f(-18.01, ta, 17.0);
	glVertex3f(-18.01, ta, 19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 15.0);
	glVertex3f(-18.01, tb, 13.0);
	glVertex3f(-18.01, ta, 13.0);
	glVertex3f(-18.01, ta, 15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 11.0);
	glVertex3f(-18.01, tb, 9.0);
	glVertex3f(-18.01, ta, 9.0);
	glVertex3f(-18.01, ta, 11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 7.0);
	glVertex3f(-18.01, tb, 5.0);
	glVertex3f(-18.01, ta, 5.0);
	glVertex3f(-18.01, ta, 7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, 3.0);
	glVertex3f(-18.01, tb, 1.0);
	glVertex3f(-18.01, ta, 1.0);
	glVertex3f(-18.01, ta, 3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -1.0);
	glVertex3f(-18.01, tb, -3.0);
	glVertex3f(-18.01, ta, -3.0);
	glVertex3f(-18.01, ta, -1.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -7.0);
	glVertex3f(-18.01, tb, -5.0);
	glVertex3f(-18.01, ta, -5.0);
	glVertex3f(-18.01, ta, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -11.0);
	glVertex3f(-18.01, tb, -9.0);
	glVertex3f(-18.01, ta, -9.0);
	glVertex3f(-18.01, ta, -11.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -15.0);
	glVertex3f(-18.01, tb, -13.0);
	glVertex3f(-18.01, ta, -13.0);
	glVertex3f(-18.01, ta, -15.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -19.0);
	glVertex3f(-18.01, tb, -17.0);
	glVertex3f(-18.01, ta, -17.0);
	glVertex3f(-18.01, ta, -19.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -23.0);
	glVertex3f(-18.01, tb, -21.0);
	glVertex3f(-18.01, ta, -21.0);
	glVertex3f(-18.01, ta, -23.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -27.0);
	glVertex3f(-18.01, tb, -25.0);
	glVertex3f(-18.01, ta, -25.0);
	glVertex3f(-18.01, ta, -27.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -31.0);
	glVertex3f(-18.01, tb, -29.0);
	glVertex3f(-18.01, ta, -29.0);
	glVertex3f(-18.01, ta, -31.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -35.0);
	glVertex3f(-18.01, tb, -33.0);
	glVertex3f(-18.01, ta, -33.0);
	glVertex3f(-18.01, ta, -35.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -39.0);
	glVertex3f(-18.01, tb, -37.0);
	glVertex3f(-18.01, ta, -37.0);
	glVertex3f(-18.01, ta, -39.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -43.0);
	glVertex3f(-18.01, tb, -41.0);
	glVertex3f(-18.01, ta, -41.0);
	glVertex3f(-18.01, ta, -43.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -47.0);
	glVertex3f(-18.01, tb, -45.0);
	glVertex3f(-18.01, ta, -45.0);
	glVertex3f(-18.01, ta, -47.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -51.0);
	glVertex3f(-18.01, tb, -49.0);
	glVertex3f(-18.01, ta, -49.0);
	glVertex3f(-18.01, ta, -51.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -55.0);
	glVertex3f(-18.01, tb, -53.0);
	glVertex3f(-18.01, ta, -53.0);
	glVertex3f(-18.01, ta, -55.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -59.0);
	glVertex3f(-18.01, tb, -57.0);
	glVertex3f(-18.01, ta, -57.0);
	glVertex3f(-18.01, ta, -59.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -63.0);
	glVertex3f(-18.01, tb, -61.0);
	glVertex3f(-18.01, ta, -61.0);
	glVertex3f(-18.01, ta, -63.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -67.0);
	glVertex3f(-18.01, tb, -65.0);
	glVertex3f(-18.01, ta, -65.0);
	glVertex3f(-18.01, ta, -67.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -71.0);
	glVertex3f(-18.01, tb, -69.0);
	glVertex3f(-18.01, ta, -69.0);
	glVertex3f(-18.01, ta, -71.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -75.0);
	glVertex3f(-18.01, tb, -73.0);
	glVertex3f(-18.01, ta, -73.0);
	glVertex3f(-18.01, ta, -75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -79.0);
	glVertex3f(-18.01, tb, -77.0);
	glVertex3f(-18.01, ta, -77.0);
	glVertex3f(-18.01, ta, -79.0);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-18.01, tb, -83.0);
	glVertex3f(-18.01, tb, -81.0);
	glVertex3f(-18.01, ta, -81.0);
	glVertex3f(-18.01, ta, -83.0);
	glEnd();

	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(16.01, tb, -90.1);
	glVertex3f(14.01, tb, -90.1);
	glVertex3f(14.01, ta, -90.1);
	glVertex3f(16.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(12.01, tb, -90.1);
	glVertex3f(10.01, tb, -90.1);
	glVertex3f(10.01, ta, -90.1);
	glVertex3f(12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(8.01, tb, -90.1);
	glVertex3f(6.01, tb, -90.1);
	glVertex3f(6.01, ta, -90.1);
	glVertex3f(8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.01, tb, -90.1);
	glVertex3f(2.01, tb, -90.1);
	glVertex3f(2.01, ta, -90.1);
	glVertex3f(4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.01, tb, -90.1);
	glVertex3f(-2.01, tb, -90.1);
	glVertex3f(-2.01, ta, -90.1);
	glVertex3f(0.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.01, tb, -90.1);
	glVertex3f(-6.01, tb, -90.1);
	glVertex3f(-6.01, ta, -90.1);
	glVertex3f(-4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8.01, tb, -90.1);
	glVertex3f(-10.01, tb, -90.1);
	glVertex3f(-10.01, ta, -90.1);
	glVertex3f(-8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12.01, tb, -90.1);
	glVertex3f(-14.01, tb, -90.1);
	glVertex3f(-14.01, ta, -90.1);
	glVertex3f(-12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-16.01, tb, -90.1);
	glVertex3f(-18.0, tb, -90.1);
	glVertex3f(-18.0, ta, -90.1);
	glVertex3f(-16.01, ta, -90.1);
	glEnd();

}
void jendelabelakang0(int r, int g, int b) {

	s = 0.5;
	ta = 3.6;
	tb = 0.6;
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(16.01, tb, -90.1);
	glVertex3f(14.01, tb, -90.1);
	glVertex3f(14.01, ta, -90.1);
	glVertex3f(16.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(12.01, tb, -90.1);
	glVertex3f(10.01, tb, -90.1);
	glVertex3f(10.01, ta, -90.1);
	glVertex3f(12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(8.01, tb, -90.1);
	glVertex3f(6.01, tb, -90.1);
	glVertex3f(6.01, ta, -90.1);
	glVertex3f(8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(4.01, tb, -90.1);
	glVertex3f(2.01, tb, -90.1);
	glVertex3f(2.01, ta, -90.1);
	glVertex3f(4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(0.01, tb, -90.1);
	glVertex3f(-2.01, tb, -90.1);
	glVertex3f(-2.01, ta, -90.1);
	glVertex3f(0.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-4.01, tb, -90.1);
	glVertex3f(-6.01, tb, -90.1);
	glVertex3f(-6.01, ta, -90.1);
	glVertex3f(-4.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-8.01, tb, -90.1);
	glVertex3f(-10.01, tb, -90.1);
	glVertex3f(-10.01, ta, -90.1);
	glVertex3f(-8.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-12.01, tb, -90.1);
	glVertex3f(-14.01, tb, -90.1);
	glVertex3f(-14.01, ta, -90.1);
	glVertex3f(-12.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-16.01, tb, -90.1);
	glVertex3f(-18.0, tb, -90.1);
	glVertex3f(-18.0, ta, -90.1);
	glVertex3f(-16.01, ta, -90.1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-3.0, -4.5, -116.8);           ///kiri belakang
	glVertex3f(3.0, -4.5, -116.8);             ///kanan belakang
	glVertex3f(3.0, -2.0, -116.8);             ///kanan belakang
	glVertex3f(-3.0, -2.0, -116.8);           ///kiri belakang
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-3.0, -8.5, -116.8);           ///kiri belakang
	glVertex3f(3.0, -8.5, -116.8);             ///kanan belakang
	glVertex3f(3.0, -6.0, -116.8);             ///kanan belakang
	glVertex3f(-3.0, -6.0, -116.8);           ///kiri belakang
	glEnd();
}
///////////////////
void jendelabawah(int r, int g, int b) {

	int tsb = 3.0;
	int tsa = 4.5;
	float posisi = 20.01;
	float poss = 0.0;
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 54.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 54.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 53.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 53.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 41.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 40.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 40.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 39.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 39.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 38.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 38.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 37.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 37.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 34.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 34.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 33.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 33.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

	/////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-posisi, -tsb, 60.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 60.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 59.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 59.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 58.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 58.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 57.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 57.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 56.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 56.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 55.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 55.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 54.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 54.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 53.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 53.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 52.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 52.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 51.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 51.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 50.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 50.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 49.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 49.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 48.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 48.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 47.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 47.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 46.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 46.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 45.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 45.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 44.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 44.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 43.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 43.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 42.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 42.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 41.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 41.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 40.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 40.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 39.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 39.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 38.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 38.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 37.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 37.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 36.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 36.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 35.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 35.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 34.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 34.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 33.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 33.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 32.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 32.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 31.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 31.0);           ///kanan kiri
	glEnd();
}
void jendelabawahb(int r, int g, int b) {

	int tsb = 3.0;
	int tsa = 4.5;
	float posisi = 20.01;
	float poss = -100.0;
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 54.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 54.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 53.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 53.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 41.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 40.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 40.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 39.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 39.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 38.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 38.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 37.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 37.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 34.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 34.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 33.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 33.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

	/////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 54.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 54.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 53.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 53.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 41.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 40.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 40.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 39.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 39.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 38.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 38.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 37.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 37.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 34.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 34.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 33.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 33.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

}
void jendelabawahc(int r, int g, int b) {

	int tsb = 3.0;
	int tsa = 4.5;
	float posisi = 20.01;
	float poss = -70.0;
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 54.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 54.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 53.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 53.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 41.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 40.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 40.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 39.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 39.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 38.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 38.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 37.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 37.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 34.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 34.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 33.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 33.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

	//////////kiri
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 54.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 54.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 53.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 53.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 41.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 40.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 40.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 39.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 39.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 38.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 38.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 37.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 37.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 34.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 34.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 33.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 33.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

}
void jendelabawahd(int r, int g, int b) {

	int tsb = 3.0;
	int tsa = 4.5;
	float posisi = 20.01;
	float poss = -40.0;
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 41.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

	////////////kiri
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 41.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

}
void jendelabawah2(int r, int g, int b) {

	int tsb = 7.0;
	int tsa = 6.5;
	float posisi = 20.01;
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(posisi, -tsb, 60.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 60.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 59.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 59.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 58.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 58.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 57.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 57.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 56.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 56.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 55.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 55.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 54.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 54.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 53.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 53.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 52.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 52.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 51.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 51.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 50.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 50.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 49.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 49.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 48.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 48.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 47.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 47.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 46.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 46.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 45.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 45.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 44.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 44.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 43.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 43.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 42.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 42.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 41.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 41.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 40.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 40.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 39.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 39.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 38.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 38.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 37.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 37.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 36.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 36.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 35.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 35.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 34.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 34.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 33.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 33.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 32.0);             ///depan kiri
	glVertex3f(posisi, -tsa, 32.0);              ///depan kanan
	glVertex3f(posisi, -tsa, 31.0);             ///kanan belakang
	glVertex3f(posisi, -tsb, 31.0);           ///kanan kiri
	glEnd();


	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-posisi, -tsb, 60.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 60.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 59.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 59.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 58.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 58.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 57.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 57.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 56.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 56.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 55.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 55.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 54.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 54.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 53.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 53.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 52.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 52.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 51.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 51.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 50.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 50.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 49.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 49.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 48.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 48.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 47.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 47.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 46.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 46.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 45.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 45.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 44.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 44.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 43.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 43.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 42.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 42.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 41.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 41.0);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 40.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 40.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 39.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 39.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 38.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 38.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 37.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 37.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 36.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 36.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 35.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 35.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 34.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 34.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 33.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 33.0);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 32.0);             ///depan kiri
	glVertex3f(-posisi, -tsa, 32.0);              ///depan kanan
	glVertex3f(-posisi, -tsa, 31.0);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 31.0);           ///kanan kiri
	glEnd();

}
void jendelabawah2b(int r, int g, int b) {

	int tsb = 7.0;
	int tsa = 6.5;
	float posisi = 20.01;
	float poss = -100.0;
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 54.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 54.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 53.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 53.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 41.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 40.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 40.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 39.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 39.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 38.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 38.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 37.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 37.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 34.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 34.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 33.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 33.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

	/////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 54.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 54.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 53.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 53.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 41.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 40.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 40.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 39.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 39.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 38.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 38.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 37.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 37.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 34.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 34.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 33.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 33.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

}
void jendelabawah2c(int r, int g, int b) {

	int tsb = 7.0;
	int tsa = 6.5;
	float posisi = 20.01;
	float poss = -70.0;
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 54.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 54.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 53.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 53.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 41.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 40.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 40.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 39.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 39.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 38.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 38.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 37.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 37.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 34.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 34.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 33.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 33.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

	//////////kiri
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 54.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 54.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 53.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 53.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 41.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 40.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 40.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 39.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 39.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 38.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 38.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 37.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 37.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 34.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 34.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 33.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 33.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

}
void jendelabawah2d(int r, int g, int b) {

	int tsb = 7.0;
	int tsa = 6.5;
	float posisi = 20.01;
	float poss = -40.0;
	//////////////////////////////////////////////////
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 41.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

	////////////kiri
	glBegin(GL_POLYGON);
	glColor3f(0.2, 0.2, 0.2);
	glColor3f(0.2 + q, 0.2 + w, 0.2 + e);
	glVertex3f(-posisi, -tsb, 60.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 60.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 59.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 59.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 58.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 58.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 57.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 57.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 56.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 56.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 55.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 55.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 52.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 52.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 51.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 51.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 50.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 50.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 49.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 49.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 48.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 48.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 47.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 47.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 46.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 46.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 45.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 45.0 + poss);           ///kanan kiri

	glEnd(); glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 44.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 44.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 43.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 43.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 42.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 42.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 41.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 41.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 36.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 36.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 35.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 35.0 + poss);           ///kanan kiri
	glEnd();

	glBegin(GL_POLYGON);
	glVertex3f(-posisi, -tsb, 32.0 + poss);             ///depan kiri
	glVertex3f(-posisi, -tsa, 32.0 + poss);              ///depan kanan
	glVertex3f(-posisi, -tsa, 31.0 + poss);             ///kanan belakang
	glVertex3f(-posisi, -tsb, 31.0 + poss);           ///kanan kiri
	glEnd();

}
///////////////////
void jendela() {
	jendela5(255, 255, 255);
	jendela4(255, 255, 255);
	jendela3(255, 255, 255);
	jendela2(255, 255, 255);
	jendela1(255, 255, 255);
	jendelabelakang0(255, 255, 255);

	jendelabawah(255, 255, 255);
	jendelabawahb(255, 255, 255);
	jendelabawahc(255, 255, 255);
	jendelabawahd(255, 255, 255);
	jendelabawah2(255, 255, 255);
	jendelabawah2b(255, 255, 255);
	jendelabawah2c(255, 255, 255);
	jendelabawah2d(255, 255, 255);
}


int gerak = 0;
bool atas = true;
float bir;
float teb, tin;

void bird1(int r, int g, int b) {
	bir = 0;

	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5, 60.0, 30.0);
	glVertex3f(0.5, 61.0, 30.0);
	glVertex3f(3.0, 62.0, 30.0);
	glEnd();
	glBegin(GL_TRIANGLES);
	//glColor3f(1.5, 0.5, 1.5);
	glVertex3f(0.5, 60.0, 30.0);
	glVertex3f(-0.5, 61.0, 30.0);
	glVertex3f(-3.0, 62.0, 30.0);
	glEnd();

}
void bird2(int r, int g, int b) {
	bir = 3.0;
	teb = -3;
	tin = 0;
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5 + bir, 60.0 + tin, 30.0 + teb);
	glVertex3f(0.5 + bir, 61.0 + tin, 30.0 + teb);
	glVertex3f(3.0 + bir, 62.0 + tin, 30.0 + teb);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5 + bir, 60.0 + tin, 30.0 + teb);
	glVertex3f(-0.5 + bir, 61.0 + tin, 30.0 + teb);
	glVertex3f(-3.0 + bir, 62.0 + tin, 30.0 + teb);
	glEnd();

}
void bird3(int r, int g, int b) {
	bir = 6.0;
	teb = -2;
	tin = 2;
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5 + bir, 60.0 + tin, 30.0 + teb);
	glVertex3f(0.5 + bir, 61.0 + tin, 30.0 + teb);
	glVertex3f(3.0 + bir, 62.0 + tin, 30.0 + teb);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5 + bir, 60.0 + tin, 30.0 + teb);
	glVertex3f(-0.5 + bir, 61.0 + tin, 30.0 + teb);
	glVertex3f(-3.0 + bir, 62.0 + tin, 30.0 + teb);
	glEnd();

}
void bird4(int r, int g, int b) {
	bir = -6.0;
	teb = 2;
	tin = 2;
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5 + bir, 60.0 + tin, 30.0 + teb);
	glVertex3f(0.5 + bir, 61.0 + tin, 30.0 + teb);
	glVertex3f(3.0 + bir, 62.0 + tin, 30.0 + teb);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5 + bir, 60.0 + tin, 30.0 + teb);
	glVertex3f(-0.5 + bir, 61.0 + tin, 30.0 + teb);
	glVertex3f(-3.0 + bir, 62.0 + tin, 30.0 + teb);
	glEnd();

}
void bird5(int r, int g, int b) {
	bir = -4.0;
	teb = 3;
	tin = -1;
	glBegin(GL_TRIANGLES);
	glColor3f(0.5, 0.5, 0.5);
	glVertex3f(-0.5 + bir, 60.0 + tin, 30.0 + teb);
	glVertex3f(0.5 + bir, 61.0 + tin, 30.0 + teb);
	glVertex3f(3.0 + bir, 62.0 + tin, 30.0 + teb);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5 + bir, 60.0 + tin, 30.0 + teb);
	glVertex3f(-0.5 + bir, 61.0 + tin, 30.0 + teb);
	glVertex3f(-3.0 + bir, 62.0 + tin, 30.0 + teb);
	glEnd();

}
void pol(int r, int g, int b) {
	//TWEENING
	glPushMatrix();
	glTranslatef(gerak, 0, 0);
	bird1(0.5, 0.5, 0.5);
	bird2(0.5, 0.5, 0.5);
	bird3(0.5, 0.5, 0.5);
	bird4(0.5, 0.5, 0.5);
	bird5(0.5, 0.5, 0.5);

	glPushMatrix();
	glPopMatrix();
}

void timer(int t)//TWEENING
{
	if (atas) {
		gerak += 1;
	}
	else {
		gerak -= 1;
	}
	if (gerak > 20) {
		atas = false;
	}
	else if (gerak < -20) {
		atas = true;
	}
	glutPostRedisplay();
	glutTimerFunc(50, timer, 0);
}

void display() {

	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	bodybawah(255, 255, 255);
	dasar(255, 255, 255);
	bodyatas(0.9, 0.9, 0.9);
	depankapal(255, 255, 255);
	bagianatas(255, 255, 255);
	lantai(255, 255, 255);
	lantaikapal(255, 255, 255);
	radarbelakang(255, 255, 255);
	objectatasdepan(255, 255, 255);
	objectatastengah(255, 255, 255);
	uplantai(255, 255, 255);
	kolam(255, 255, 255);
	pendaratan(255, 255, 255);
	lantaigreen(255, 255, 255);
	dindingbelakang(255, 255, 255);
	jendela();
	pol(0.5, 0.5, 0.5);

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
	glutCreateWindow("FREEDOM OF THE SEAS");

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
	glutTimerFunc(1, timer, 0);

	glutIdleFunc(display);
	glutMainLoop();

	return 0;
}

