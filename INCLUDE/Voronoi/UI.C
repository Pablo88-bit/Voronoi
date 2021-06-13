#include <Voronoi\ui.h>

/* inicializa un mouse */
Mouse newMouse()
{
	Mouse m;

	m.operacionClickIzquierdo = NoHecho;
	m.operacionClickDerecho = NoHecho;

	ActualizarMouse(&m);

	return m;
}

/* actualiza toda la informacion del mouse */
void ActualizarMouse(Mouse *mouse)
{
	switch(mclick())
	{
		case 0:
			mouse->clickIzquierdo = NoPresionado;
			mouse->clickDerecho = NoPresionado;
			break;
		case 1:
			mouse->clickIzquierdo = Presionado;
			break;
		case 2:
			mouse->clickDerecho = Presionado;
			break;
	}

	mouse->posicion = newVertice(mxpos(1), mypos(1));
}


