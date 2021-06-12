#include "GEOM.H"

/* inicializa un vertice */
Vertice newVertice(double x, double y)
{
	Vertice v;

	v.x = x;
	v.y = y;

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

