#ifndef _GEOM
#define _GEOM

/*****************************************************************************
 * Esta biblioteca contiene los tipos de datos utilizados en el programa,
 * estos tipos representan ciertos elementos geometricos necesarios para
 * el diagrama de voronoi, tambien contiene funciones para el manejo de
 * las mismas estructuras.
 * ***************************************************************************/

/* representa un vertice / punto / vector en el plano 
 * utiliza double para mayor presicion en calculos matematicos */
typedef struct Vertice{
	double x, y;
} Vertice;

/* Un segmento en el plano, con su punto / vertice a y b */
typedef struct Segmento{
	Vertice a, b;
} Segmento;

/* inicializa un vertice */
Vertice newVertice(double x, double y);
/* inicializa un segmento */
Segmento newSegmento(double ax, double ay, double bx, double by);

#include "GEOM.C"

#endif
