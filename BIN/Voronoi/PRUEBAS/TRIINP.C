#include <stdio.h>
#include <conio.h>

/****************************
 * este archivo cuenta el numero de triangulos
 * segun la cantidad de puntos
 * **************************** */

int main()
{
	int numeroDeTriangulos = 0;
	int numeroDePuntos = 10;

	int a, b, c;

	for(a = 0; a < numeroDePuntos; a++)
		for(b = a + 1; b < numeroDePuntos; b++)
			for(c = b + 1; c < numeroDePuntos; c++)
				numeroDeTriangulos++;

			/* el numero de triangulos es igual a C(numeroDePuntos, 3) */

	printf("%d", numeroDeTriangulos);

	getch();
	return 0;
}