#include <stdio.h>
#include <conio.h>

#include <voronoi\geom.h>

/*********************************
 * En este archivo determina si el punto d esta dentro del triangulo abc *
 * *************************************************************/

int main()
{
	Vertices vertices = newVertices(0);

	Vertice a = newVertice(2, 2);
	Vertice b = newVertice(6, 2);
	Vertice c = newVertice(4, 7);
	Vertice d = newVertice(2, 4); /* cambia X a 2 para sacarlo del triangulo */


	AgregarVertice(&vertices, &a);
	AgregarVertice(&vertices, &b);
	AgregarVertice(&vertices, &c);
	AgregarVertice(&vertices, &d);

	clrscr();
	if(EnTriangulo(&vertices.elementos[0], &vertices.elementos[1], &vertices.elementos[2], &vertices.elementos[3]))
	{
		printf("Esta dentro del triangulo\n");
	}
	else
	{
		printf("No esta dentro del triangulo\n");
	}

	getch();
	return 0;
}
