#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <mouse.h>

#include <voronoi/geom.h>
#include <voronoi/ui.h>
#include <voronoi/voro.h>

#define COLOR_VERTICE WHITE
#define COLOR_VERTICE_MEDIO GREEN

int main()
{
	int gd = DETECT, gm;

	/* elementos */

	/* limites del plano */
	int xMax, yMax, xMid, yMid;

	/* manejo de entrada */
	char input;

	/* manejo de raton */
	Mouse raton;

	/* Coleccion de vertices agregados por el usuario */
	Vertices vertices;
	Vertices puntosMedios;

	/* inicio aplicacion grafica */
	initgraph(&gd, &gm, "C:\\tc20\\BIN");
	cleardevice();

	/* limites del plano */
	xMax = getmaxx();
	xMid = xMax / 2;
	yMax = getmaxy();
	yMid = yMax / 2;

	/* inicializando coleccion de vertices */
	vertices = newVertices(0);
	puntosMedios = newVertices(0);

	/* inicializando raton */
	raton = newMouse();
	mver();

	/* manejando entrada */
	do
	{
		if(kbhit())
			input = getch();

		ActualizarMouse(&raton);

		/* manejando entrada de teclado */
		switch(input)
		{
			case 'p':
				puntosMedios = ObtenerPuntosMedios(&vertices);
				cleardevice();
				DibujarVertices(&vertices, COLOR_VERTICE);
				DibujarVertices(&puntosMedios, COLOR_VERTICE_MEDIO);
				input = '';
				break;
		}

		/* manejando click izquierdo, agrega un vertice y lo dibuja */
		if(raton.clickIzquierdo == Presionado && raton.operacionClickIzquierdo == NoHecho)
		{
			AgregarVertice(&vertices, &raton.posicion);

			/* dibujando vertices */
			mocultar();
			DibujarVertice(&raton.posicion, COLOR_VERTICE);
			mver();

			/* actualizando estado de operacion */
			raton.operacionClickIzquierdo = Hecho;
		}

		/* actualizando estado de operacion */
		if(raton.clickIzquierdo == NoPresionado && raton.operacionClickIzquierdo == Hecho)
		{
			raton.operacionClickIzquierdo = NoHecho;
		}

		/* manejando click derecho, elimina el ultimo vertice en la coleccion */
		if(raton.clickDerecho == Presionado && raton.operacionClickDerecho == NoHecho)
		{
			/* borrando de pantalla el vertice */
			mocultar();
			DibujarVertice(&vertices.elementos[vertices.longitud - 1], getbkcolor());
			mver();
			
			/* removiendo de coleccion */
			RemoverUltimoVertice(&vertices);

			raton.operacionClickDerecho = Hecho;
		}

		/* actualizando estado de operacion */
		if(raton.clickDerecho == NoPresionado && raton.operacionClickDerecho == Hecho )
		{
			raton.operacionClickDerecho = NoHecho;
		}

	}while(input != 'q');

	closegraph();
	return 0;
}
