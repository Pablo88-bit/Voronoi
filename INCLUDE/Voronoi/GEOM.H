#ifndef _GEOM
#define _GEOM

/************************************************************************************
 * Esta biblioteca contiene los tipos de datos geometricos utilizados en el programa,
 * estos tipos representan ciertos elementos geometricos necesarios para
 * el diagrama de voronoi, tambien contiene funciones para el manejo de
 * las mismas estructuras.
 * ***********************************************************************************/

#define RADIO_VERTICE 2

/* representa un vertice / punto / vector en el plano 
 * utiliza double para mayor presicion en calculos matematicos */
typedef struct Vertice{
	double x, y;
} Vertice;

/* Un segmento en el plano, con sus puntos / vertices a y b */
typedef struct Segmento{
	Vertice a, b;
} Segmento;

/* una coleccion de vertices */
typedef struct Vertices
{
    int longitud;
    Vertice *elementos;
} Vertices;

/* inicializa un vertice */
Vertice newVertice(double x, double y);
/* inicializa un segmento */
Segmento newSegmento(double ax, double ay, double bx, double by);
/* inicializa una coleccion de vertices */
Vertices newVertices(int longitud);
/* Agrega un vertice a la coleccion de vertices */
void AgregarVertice(Vertices *vertices, Vertice *vertice);
/* Elimina un vertice de la coleccion de vertices */
void RemoverUltimoVertice(Vertices *v);

/* dibuja un vertice con su color */
void DibujarVertice(Vertice *v, enum COLORS color);
/* dibuja un segmento con su color */
void DibujarSegmento(Segmento *s, enum COLORS color);
/* dibuja una coleccion de vertices con su color */
void DibujarVertices(Vertices *v, enum COLORS color);

#include <Voronoi\geom.c>

#endif
