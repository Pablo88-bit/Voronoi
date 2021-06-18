#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

/********************************************
 * Este archivo utiliza la combinacion convexa
 * para determinar los puntos entre un punto a
 * y un punto b
 * ******************************************/

#define true 1
#define false 0

#define TASA_DE_CAMBIO 0.01

typedef unsigned char bool;

typedef struct Punto
{
	int x, y;
} Punto;

void DibujarPunto(Punto *p, enum COLORS color)
{
	setcolor(color);
	circle(p->x, p->y, 4);
	setfillstyle(SOLID_FILL, color);
	floodfill(p->x, p->y, color);
}

Punto newPunto(int x, int y)
{
	Punto p;

	p.x = x;
	p.y = y;

	return p;
}

int main()
{
	int gd = DETECT, gm;

	char input = '';

	Punto inicial, final, moving, oInicial, oFinal, moving2;

	int xMax, yMax, xMid, yMid;
	bool cambiado;

	double proporcion, modificador;

	initgraph(&gd, &gm, "");

	xMax = getmaxx();
	yMax = getmaxy();
	xMid = xMax / 2;
	yMid = yMax / 2;

	proporcion = 1;

	inicial = newPunto(xMid - 50, yMid - 50);
	final = newPunto(xMid + 50, yMid + 50);
	oInicial = newPunto(inicial.x - 50, inicial.y);
	oFinal = newPunto(final.x - 50, final.y);
	moving = newPunto(xMid, yMid);
	moving2 = newPunto(xMid - 50, yMid);
	cambiado = false;

	DibujarPunto(&inicial, WHITE);
	DibujarPunto(&final, WHITE);
	DibujarPunto(&moving, GREEN);

	DibujarPunto(&oInicial, WHITE);
	DibujarPunto(&oFinal, WHITE);
	DibujarPunto(&moving2, GREEN);
	
	while(input != 'q')
	{
		if(kbhit())
			input = getch();

		switch(input)
		{
			case 'a':
				modificador = TASA_DE_CAMBIO;
				input = '';
				cambiado = true;
				break;
			case 'd':
				modificador = -TASA_DE_CAMBIO;
				cambiado = true;
				input = '';
				break;
		}

		if(cambiado)
		{
			proporcion += modificador;
			proporcion = (proporcion < 0) ? 0 : proporcion;
			proporcion = (proporcion > 1) ? 1 : proporcion;
			moving.x = inicial.x * proporcion + final.x * (1 - proporcion);
			moving.y = inicial.y * proporcion + final.y * (1 - proporcion);

			moving2.x = oInicial.x * proporcion + oFinal.x * (1 - proporcion);
			moving2.y = oInicial.y * proporcion + oFinal.y * (1 - proporcion);
			cleardevice();
			DibujarPunto(&inicial, WHITE);
			DibujarPunto(&final, WHITE);
			DibujarPunto(&moving, GREEN);

			DibujarPunto(&oInicial, WHITE);
			DibujarPunto(&oFinal, WHITE);
			DibujarPunto(&moving2, GREEN);
			cambiado = false;
		}
	}

	closegraph();
	return 0;
}
