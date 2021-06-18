#include <stdio.h>
#include <conio.h>

#include <voronoi\geom.h>

/*********************************
 * En este archivo determina si el punto c esta a la izquierda de ab *
 * *************************************************************/

int main()
{
	Vertices vertices = newVertices(0);

	Vertice a = newVertice(2, 2);
	Vertice b = newVertice(6, 2);
	Vertice c = newVertice(4, 7); /* cambia Y a 0 para moverlo a la derecha */

	AgregarVertice(&vertices, &a);
	AgregarVertice(&vertices, &b);
	AgregarVertice(&vertices, &c);

	clrscr();
	if(EnLaIzquierda(&vertices.elementos[0], &vertices.elementos[1], &vertices.elementos[2]))
	{
		printf("El punto c se encuentra en la izquierda\n");
	}
	else
	{
		printf("El punto c no se encuentra en la izquierda\n");
	}

	getch();
	return 0;
}
