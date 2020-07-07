#include "stdafx.h"
#include <windows.h>
#include "glut.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

#define D (PI/1250.0)
#define e 2.7182818284590452353602874713527
#define PI 3.1415926535897932384626433832795
#define MPX 1
#define dx (PI/2250.0)
#define S 1000.0
//#define INF 1 / dx
#define DO (PI*4)
double INF = INFINITY;
std::vector<double> vasV;
std::vector<double> hasV;
std::vector<double> kasV;
//#define F (3 - 2 * pow( e, -3*x ) )
//#define F (x*pow(e,x)/((x+2)*(x+2)))
//#define F (sin(x))
//#define F (tan(x))
//#define F (10*sin(x)*cos(x-3.14/2))
//#define F (atan(1+1/x))
//#define F (1/atan(x))
//#define F (1/(x-1)/(x+1)/(x-2)/(x+2))*0.3
//#define F (fabs(tan(x)))
//#define F (fabs(1.0/tan(x)))
//#define F (pow((pow(x,3)-x),(1.0f/3.0f)))
//#define F (pow(-1,((int)(x/dx)))*pow(x,1.0f/2))
//#define F (pow(x*x,1/2))
//#define F (x*x*x)
//#define F (x*x)
//#define F (sqrt(x))
//#define F (x*pow(e,(1-1/(x*x)/2)))
//#define F (x/2+asin(2*x/(1+x*x)))
//#define F (x*atan((x+1)/(x-1)))
//#define F ((x-1)*(x-1)*(x+1)/(x*(x-2)))
//#define F (x-1)*(log(1-1/x))
//#define F 1/x
//#define F (1/((x)*(1+x)*(2+x))+2)
//#define F ((x*x)+(2*x)+2)
//#define F (10*pow(e,(-((x/5)*(x/5)))))
#define F ((pow(x,6)+3*pow(x,4)+8*pow(x,3)+3*pow(x,2)+1)/(x*x+2*x+1))
void tacka(double, double);
void tacka2(double, double, int v);
void tacka3(double, double);
void display();

int isVas(double);
int isHas(double);
int isKas(double);
void vas(double);
void has(double);
void kas(double);

void yJe(double);
void xJe(double);
void yOsa();
void xOsa();

double f(double);
void koord();
void funkcija();
void asimptote();

int main()
{
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(350, 0);
	glutCreateWindow("Tacke");
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}

double f(double x)
{
	return F;
}

void tacka(double x, double y)
{
	if (fabs(y) <= DO)
	{
		x = x*MPX / 15.0f;
		y = y*MPX / 15.0f;
		glBegin(GL_QUADS);
		glColor3f(0, 0, 0);
		glVertex2f(x - D, y - D);
		glVertex2f(x - D, y + D);
		glVertex2f(x + D, y + D);
		glVertex2f(x + D, y - D);
		glEnd();
		glFlush();
	}
}

void tacka2(double x, double y, int v)
{
	if (fabs(y) <= DO)
	{
		x = x*MPX / 15.0f;
		y = y*MPX / 15.0f;
		glBegin(GL_QUADS);
		glColor3f(0.9, 0.9, 0.9);
		glVertex2f(x - D*((v>0) ? 0.5 : 5), y - D*((v>0) ? 5 : 0.5));
		glVertex2f(x - D*((v>0) ? 0.5 : 5), y + D*((v>0) ? 5 : 0.5));
		glVertex2f(x + D*((v>0) ? 0.5 : 5), y + D*((v>0) ? 5 : 0.5));
		glVertex2f(x + D*((v>0) ? 0.5 : 5), y - D*((v>0) ? 5 : 0.5));
		glEnd();
		glFlush();
	}
}

void tacka3(double x, double y)
{
	if (fabs(y) <= DO)
	{
		x = x*MPX / 15.0f;
		y = y*MPX / 15.0f;
		glBegin(GL_QUADS);
		glColor3f(0.9, 1, 1);
		glVertex2f(x - D, y - D);
		glVertex2f(x - D, y + D);
		glVertex2f(x + D, y + D);
		glVertex2f(x + D, y - D);
		glEnd();
		glFlush();
	}
}

void tackaAs(double x, double y)
{
	if (fabs(y) <= DO)
	{
		x = x*MPX / 15.0f;
		y = y*MPX / 15.0f;
		glBegin(GL_QUADS);
		glColor3f(0.9, 0, 0);
		glVertex2f(x - D/2, y - D/2);
		glVertex2f(x - D/2, y + D/2);
		glVertex2f(x + D/2, y + D/2);
		glVertex2f(x + D/2, y - D/2);
		glEnd();
		glFlush();
	}
}

void display()
{
	koord();
	funkcija();
	asimptote();
	tacka(10, 10); tacka(9.9, 9.9); tacka(10.1, 10.1); tacka(10.1, 9.9); tacka(9.9, 10.1);
	std::cout << "Kraj" << std::endl;
}

void koord()
{
	yOsa();
	xOsa();
}

void yOsa()
{
	double X = 0;
	for (double y = -1.05*DO; y <= 1.05*DO; y += dx * 20 * MPX)
	{
		if (((int)(y * 10)) % 10 == 0) tacka2(X - dx, y, -5);
		tacka3(X, y);
		if (((int)(y * 10)) % 10 == 0) tacka2(X + dx, y, -5);
	}
}

void xOsa()
{
	double Y = 0;
	for (double x = -1.05*DO; x <= 1.05*DO; x += dx * 20 * MPX)
	{
		if (((int)(x * 10)) % 10 == 0) tacka2(x, Y - dx, 5);
		tacka3(x, Y);
		if (((int)(x * 10)) % 10 == 0) tacka2(x, Y + dx, 5);
	}
}

void xJe(double X)
{
	for (double y = -1.05*DO; y <= 1.05*DO; y += dx * 20 * MPX)
		tackaAs(X, y);
}

void yJe(double Y)
{
	for (double x = -1.05*DO; x <= 1.05*DO; x += dx * 20 * MPX)
		tackaAs(x, Y);
}

void funkcija()
{
	for (double x = -DO; x <= DO; x += dx)
		tacka(x, f(x));
}

int isVas(double a)
{
	double fx = f(a);
	if (fabs(fx - f(a + dx)) > S || fabs(fx - f(a - dx)) > S)
		return 1;
	return 0;
}

int isHas(double a)
{
	double fx = f(a);
	if (fabs(fx - f(a + 1/dx)) < dx || fabs(fx - f(a - 1/dx)) < dx)
		return 1;
	return 0;
}

int isKas(double p)
{
	return 0;
}

void vas(double p)
{
	if (isVas(p))
	{
		/*if (std::count_if(vasV.begin(), vasV.end(), [p](double x)
		{
			if (fabs(p - x) < 10 * dx)return true;
			return false;
		}) == 0)*/
			xJe(p);
		/*vasV.push_back(p);*/
	}
}

void has(double p)
{
	if (isHas(p))
	{
		if (std::count_if(hasV.begin(), hasV.end(), [p](double x)
		{
			if (fabs(f(p) - x) < 10*dx)return true;
			return false;
		}) == 0)
		{
			yJe(f(p));
			std::cout << "H";
		}
		vasV.push_back(f(p));
	}
}

void kas(double p)
{
	if (isKas(p))
	{

	}
}

void asimptote()
{
	for (double x = -DO; x <= DO; x += dx)
	{
		vas(x);
		has(x);
		kas(x);
	}
}