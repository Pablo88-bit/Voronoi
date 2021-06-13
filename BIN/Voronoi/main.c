#include <graphics.h>
#include <stdio.h>
#include <conio.h>

#include <Voronoi/geom.h>

int main()
{
	int gd = DETECT, gm;

	/* elementos */

	initgraph(&gd, &gm, "");
	cleardevice();

	/* aplicacion */


	getch();
	closegraph();
	return 0;
}
