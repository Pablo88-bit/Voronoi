#include <Voronoi\geom.h>

/* inicializa un vertice */
Vertice newVertice(double x, double y)
{
	Vertice v;

	v.x = x;
	v.y = y;
	v.extremo = false;

	return v;
}

/* inicializa un segmento */
Segmento newSegmento(double ax, double ay, double bx, double by)
{
	Segmento s;

	s.a = newVertice(ax, ay);
	s.b = newVertice(bx, by);

	return s;
}

/* inicializa una coleccion de vertices de longitud elementos */
Vertices newVertices(int longitud)
{
	Vertices v;

	/* manteniendo longitud en el rango de numeros naturales */
	if(longitud > 0)
	{
		v.longitud = longitud;
		v.elementos = calloc(longitud, sizeof(Vertice));
	}
	else
	{
		v.longitud = 0;
		v.elementos = NULL;
	}

	return v;
}

/* Agrega un vertice a la coleccion de vertices */
void AgregarVertice(Vertices *vertices, Vertice *vertice)
{
	if(vertices->longitud <= 0)
	{
		vertices->longitud = 1;
		vertices->elementos = calloc(1, sizeof(Vertice));
	}
	else
	{
		vertices->longitud += 1;
		vertices->elementos = realloc(vertices->elementos, sizeof(Vertice) * vertices->longitud);
	}

	if(vertices->elementos == NULL)
		vertices->longitud = 0;
	else
		vertices->elementos[vertices->longitud - 1] = *vertice;
}

/* Elimina el ultimo vertice de la coleccion de vertices */
void RemoverUltimoVertice(Vertices *v)
{
	v->longitud -= 1;
	if(v->longitud == 0)
	{
		free(v->elementos);
		v->elementos = NULL;
	}
	else if(v->longitud > 0)
	{
		v->elementos = realloc(v->elementos, v->longitud * sizeof(Vertice));
	}
	else
	{
		v->longitud = 0;
		v->elementos = NULL;
	}
}

/* Borra una coleccion de vertices */
void RemoverVertices(Vertices *v)
{
	free(v->elementos);
	v->elementos = NULL;
	v->longitud = 0;
}

/* dibuja un vertice con su color */
void DibujarVertice(Vertice *v, enum COLORS color)
{
	setcolor(color);
	circle(v->x, v->y, RADIO_VERTICE);
	setfillstyle(SOLID_FILL, color);
	floodfill(v->x, v->y, color);
}

/* dibuja un segmento con su color */
void DibujarSegmento(Segmento *s, enum COLORS color)
{
	setcolor(color);
	line(s->a.x, s->a.y, s->b.x, s->b.y);
}

/* dibuja una coleccion de vertices con su color */
void DibujarVertices(Vertices *v, enum COLORS color)
{
	if(v->elementos != NULL)
	{
		int i;
		for(i = 0; i < v->longitud; i++)
		{
			DibujarVertice(&v->elementos[i], color);
		}
	}
}

/* funciones geometricas */
/* calcula el doble del area de un triangulo utilizando la determinante */
int Area2(Vertice *a, Vertice *b, Vertice *c)
{
	int area2 = a->x * b->y - a->y * b->x + b->x * c->y - b->y * c->x + c->x * a->y - c->y * a->x;

	return area2;
}

/* usa el signo de la determinante de un triangulo
para determinar si c esta a la izquierda del segmento ab */
bool EnLaIzquierda(Vertice *a, Vertice* b, Vertice *c)
{
	return (Area2(a, b, c) > 0);
}

/* determina si el punto d se encuentra dentro de el triangulo abc */
bool EnTriangulo(Vertice* a, Vertice* b, Vertice* c, Vertice* d)
{
	bool abIzquierda = EnLaIzquierda(a, b, d);
	bool bcIzquierda = EnLaIzquierda(b, c, d);
	bool caIzquierda = EnLaIzquierda(c, a, d);

	return abIzquierda == bcIzquierda && bcIzquierda == caIzquierda;
}
