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
	glColor3f(0, 128, 0);
	glVertex3f(-20.0, 3.0, 70.0);
	glVertex3f(20.0, 3.0, 70.0);
	glVertex3f(20.0, 3.0, 75.0);
	glVertex3f(0.0, 3.0, 109.1);
	glVertex3f(-20.0, 3.0, 75.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.8, 0.8, 0.8);
	glVertex3f(-20.0, 3.0, 70.0);
	glVertex3f(20.0, 3.0, 70.0);
	glVertex3f(20.0, 4.0, 70.0);
	glVertex3f(-20.0, 4.0, 70.0);
	glEnd();

	glBegin(GL_POLYGON);								////lantai kecil depan
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

	//////////////////////////////////////////////////

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
	glVertex3f(-20.0, -20.0, 60.0);
	glVertex3f(-20.0, 4.3, 77.0);
	glVertex3f(0.0, 4.3, 110.0);
	glVertex3f(0.0, -20.0, 95.0);
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

void depankapal(int r, int g, int b) {

	glBegin(GL_POLYGON);				////bodi depan tengah
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(-5.0, 4.6, 82.0);
	glVertex3f(5.0, 4.6, 82.0);
	glVertex3f(5.0, 25.0, 70.0);
	glVertex3f(-5.0, 25.0, 70.0);
	glEnd();

	glBegin(GL_POLYGON);				////bodi depan kanan
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
	glColor3f(0.5, 0.5, 0.5);
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
	glColor3f(0.5, 0.5, 0.5);
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

	glColor3f(0.6, 0.6, 0.6);
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
	glVertex3f(5.0, 55.0, -57.0);
	glVertex3f(5.0, 41.6, -50.0);
	glVertex3f(5.0, 41.6, -55.0);
	glVertex3f(5.0, 55.0, -59.0);
	glEnd();

	/////////////////// bagian kiri

	glBegin(GL_POLYGON);
	//glColor3f(1.8, 0.8, 0.8);
	glVertex3f(-5.0, 55.0, -57.0);
	glVertex3f(-5.0, 41.6, -50.0);
	glVertex3f(-5.0, 41.6, -55.0);
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
	glVertex3f(5.0, 41.6, -55.0);
	glVertex3f(-5.0, 41.6, -55.0);
	glEnd();


}

void uplantai(int r, int g, int b) {
	///////////////////////////////////////

	glBegin(GL_POLYGON);												//lantai atas paling atas
	glColor3f(0.5, 128.5, 0.5);
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
	glVertex3f(-19.0, 28.0, -90.0);
	glVertex3f(-18.0, 28.0, -92.0);
	glVertex3f(-15.0, 28.0, -96.0);
	glVertex3f(-10.0, 28.0, -101.0);
	glVertex3f(-5.0, 28.0, -103.0);	//tengah kiri
	glVertex3f(5.0, 28.0, -103.0);
	glVertex3f(10.0, 28.0, -101.0);
	glVertex3f(15.0, 28.0, -96.0);
	glVertex3f(18.0, 28.0, -92.0);
	glVertex3f(19.0, 28.0, -90.0);
	glEnd();

	///////////////////////////////////////
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
	glVertex3f(-12.0, 27.7, 30.0);             ///depan kiri
	glVertex3f(12.0, 27.7, 30.0);              ///kanan depan
	glVertex3f(12.0, 27.7, -30.0);             ///kanan belakang
	glVertex3f(-12.0, 27.7, -30.0);           ///kiri belakang
	glEnd();

	///////////////////////////////////////
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
	lantaigreen(255, 255, 255);
	dindingbelakang(255, 255, 255);

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
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);


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

