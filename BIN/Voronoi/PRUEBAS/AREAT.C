#include <stdio.h>
#include <conio.h>

#include <voronoi\geom.h>

/*********************************
 * En este archivo se intenta calcular el area de una triangulo usando la determinante *
 * *************************************************************/

int main()
{
	Vertices vertices = newVertices(0);

	Vertice v1 = newVertice(2, 2);
	Vertice v2 = newVertice(6, 2);
	Vertice v3 = newVertice(4, 7);

	int area;

	AgregarVertice(&vertices, &v1);
	AgregarVertice(&vertices, &v2);
	AgregarVertice(&vertices, &v3);

	area = Area2(&vertices.elementos[0], &vertices.elementos[1], &vertices.elementos[2]);

	clrscr();
	printf("Area: %d", area);

	vertices.elementos[2].y = 0;
	area = Area2(&vertices.elementos[0], &vertices.elementos[1], &vertices.elementos[2]);

	printf("Area: %d", area);

	getch();
	return 0;
}
