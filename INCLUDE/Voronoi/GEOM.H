#ifndef _GEOM
#define _GEOM

#include <stdlib.h>
#include <graphics.h>

/************************************************************************************
 * Esta biblioteca contiene los tipos de datos geometricos utilizados en el programa,
 * estos tipos representan ciertos elementos geometricos necesarios para
 * el diagrama de voronoi, tambien contiene funciones para el manejo de
 * las mismas estructuras.
 * ***********************************************************************************/

#define true 1
#define false 0

/* en lugar de un enum para consumir menos memoria */
typedef unsigned char bool;

#define RADIO_VERTICE 2

/* representa un vertice / punto / vector en el plano 
 * utiliza double para mayor presicion en calculos matematicos */
typedef struct Vertice{
	double x, y;
    bool extremo;
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
/* Borra una coleccion de vertices */
void RemoverVertices(Vertices *v);

/* dibuja un vertice con su color */
void DibujarVertice(Vertice *v, enum COLORS color);
/* dibuja un segmento con su color */
void DibujarSegmento(Segmento *s, enum COLORS color);
/* dibuja una coleccion de vertices con su color */
void DibujarVertices(Vertices *v, enum COLORS color);

/* funciones geometricas */
/* calcula el doble del area de un triangulo utilizando la determinante */
int Area2(Vertice *a, Vertice *b, Vertice *c);

/* usa el signo de la determinante de un triangulo
para determinar si c esta a la izquierda del segmento ab */
bool EnLaIzquierda(Vertice *a, Vertice* b, Vertice *c);

/* determina si el punto d se encuentra dentro de el triangulo abc */
bool EnTriangulo(Vertice* a, Vertice* b, Vertice* c, Vertice* d);

#include <Voronoi\geom.c>

#endif
