#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <mouse.h>
#include <stdlib.h>

void *buff1 = NULL, *buff2 = NULL;

void front(int x, int y, int mode);
void animation(int x, int y);

int main()
{
	int x = 0, y = 0, gd = DETECT, gm, mx,my;
	char tecla;

	initgraph(&gd, &gm, "C:\\TC20\\BIN");

	buff1 = malloc(imagesize(242,90,398,264));
	buff2 = malloc(imagesize(242,264,398,444));

	msituar(1,320,50);
	mver();
	front(x,y,0);

	while(1)
	{
		tecla = getch();
		switch(tecla)
		{
			case 72: /* Flecha arriba */
			y -= 10;
			break;
			case 75: /* Flecha izquierda */
			x -= 10;
			break;
			case 77: /* Flecha derecha */
			x += 10;
			break;
			case 80: /* Flecha abajo */
			y += 10;
			break;
			case 27: /* Escape */
			free(buff1);
			free(buff2);
			closegraph();
			return 0;
		}

		if(90+y <= 10) /* Limite superior */
		{
			cleardevice();
			y = 10;
		}
		else if(242+x <= 10) /* Limite izquierdo */
		{
			cleardevice();
			x = 230;
		}
		else if(242+x >= 480) /* Limite derecho */
		{
			cleardevice();
			x = -230;
		}
		else if(90+y >= 110) /* Limite inferior */
		{
			cleardevice();
			y = -70;
		}
		mver();
		mx = mxpos(1);
		my = mypos(1);
		if(mx >= (242+x) && mx <= (398+x) && my >= (90+y) && my <= (444+y)) /* Si esta dentro del avatar en x */
		{
			mocultar();
			/*
			if(mx < 320)
			{
				msituar(1,mx+162,my);
			}
			else if(mx >= 320)
			{
				msituar(1,mx-164,my);
			}
			*/
		}

		front(x,y,1);
	}
	return 0;
}


void front(int x, int y, int mode)
{
	int click_procesado = 0;
	int pantalon[] = {288,306,288,348,310,348,310,318,330,318,330,348,352,348,352,306,288,306};
	int pies[] = {288,348,288,370,278,370,278,392,310,392,310,348,288,348,330,348,330,392,362,392,362,370,352,370,352,348,330,348};
	int torso[] = {288,306,288,264,278,264,278,274,266,274,266,244,278,244,278,232,362,232,362,244,374,244,374,274,362,274,362,264,352,264,352,306,288,206};
	int t[] = {310,306,330,306,330,242,340,242,340,232,300,232,300,242,310,242,310,306};
	int cara[] = {310,232,330,232,330,210,352,210,352,200,362,200,362,146,278,146,278,200,288,200,288,210,310,210,310,232};
	int pelo[] = {298,168,258,168,258,136,278,136,278,126,288,126,288,116,300,116,300,104,340,104,340,116,362,116,362,126,372,126,372,148,384,148,384,168,342,168,342,156,320,156,320,146,308,146,308,157,298,157,298,168};
	int brazos[] = {266,274,266,296,256,296,256,318,278,318,278,308,288,308,288,296,278,296,278,274,266,274,362,274,362,296,352,296,352,308,362,308,362,318,384,318,384,296,374,296,374,274,362,274};

	if (mode == 0)
	{
	ellipse(320,400,0,360,64,32);
	setfillstyle(SOLID_FILL, 8);
	floodfill(320,430,WHITE);
	drawpoly(9, pantalon); /* Pantalon -> 0 */
	setfillstyle(SOLID_FILL, BLUE);
	floodfill(296,313,WHITE);
	drawpoly(14, pies); /* Pies -> 1 */
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(14, pies);  /* Pies -> 1 */
	drawpoly(16, torso); /* Torso -> 2 */
	drawpoly(9, t); /* Decoracion de camisa -> 3 */
	rectangle(320,284,330,274);
	rectangle(330,264,320,254);
	setfillstyle(SOLID_FILL, 12);
	floodfill(339,263,WHITE);
	floodfill(290,263,WHITE);
	setfillstyle(1, 4);
	floodfill(335,240,WHITE);
	drawpoly(13, cara); /* Cara -> 4 */
	setfillstyle(SOLID_FILL, 6);
	floodfill(320,204, WHITE);
	rectangle(310,200,288,178);
	rectangle(330,178,352,200);
	setfillstyle(1,11);
	floodfill(300,198,WHITE);
	floodfill(340,198,WHITE);
	rectangle(352,190,362,178);
	rectangle(330,178,310,188);
	rectangle(288,178,278,190);
	setfillstyle(1,7);
	floodfill(360,180, WHITE);
	floodfill(320,180, WHITE);
	floodfill(280,180, WHITE);
	setfillstyle(1,0);
	drawpoly(25, pelo); /* Pelo -> 5 */
	fillpoly(25, pelo); /* Pelo -> 5 */
	drawpoly(22, brazos); /* Brazos -> 6 */
	setfillstyle(1,6);
	fillpoly(22, brazos); /* Brazos -> 6 */
	rectangle(310,190,298,178);
	rectangle(340,178,352,190);
	setfillstyle(1,WHITE);
	floodfill(300,180, WHITE);
	floodfill(342,180,WHITE);
		getimage(242,90,398,264,buff1);
		getimage(242,264,398,444,buff2);
	}
	else
	{
		putimage(242+x,90+y, buff1, COPY_PUT);
		putimage(242+x,264+y, buff2, COPY_PUT);
	}

	mver();
	while(!kbhit())
	{
		if (mclick() == 0)
		{
			click_procesado = 0;
		}
		
		if(mclick() == 1 && minlimit(1,242+x, 90+y, 398+x, 444+y) && click_procesado == 0)
		{
			mocultar();
			click_procesado = 1;
			animation(x,y);
		}
	}

	getch();
}

void animation(int x, int y)
{
	int i,j;
	int avatar[7][52] = {{288,306,288,348,310,348,310,318,330,318,330,348,352,348,352,306,288,306},
	{288,348,288,370,278,370,278,392,310,392,310,348,288,348,330,348,330,392,362,392,362,370,352,370,352,348,330,348},
	{288,306,288,254,278,254,278,242,268,242,268,232,256,232,256,222,276,222,276,232,362,232,362,222,384,222,384,232,372,232,372,242,362,242,362,252,352,252,352,306,288,306},
	{310,306,330,306,330,242,340,242,340,232,300,232,300,242,310,242,310,306},
	{310,232,330,232,330,210,352,210,352,200,362,200,362,146,278,146,278,200,288,200,288,210,310,210,310,232},
	{298,168,258,168,258,136,278,136,278,126,288,126,288,116,300,116,300,104,340,104,340,116,362,116,362,126,372,126,372,148,384,148,384,168,342,168,342,156,320,156,320,146,308,146,308,157,298,157,298,168},
	{256,222,256,200,246,200,246,168,266,168,266,190,276,190,276,200,266,200,266,222,256,222,372,222,384,222,384,200,394,200,394,168,372,168,372,190,364,190,364,200,372,200,372,222}};

	cleardevice();
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < (sizeof(avatar[i])/sizeof(int)); j++)
		{
			if(j % 2 == 0)
			{
				avatar[i][j] += x;
			}
			else
			{
				avatar[i][j] += y;
			}
		}

	}

	ellipse(320+x,400+y,0,360,64,32);
	setfillstyle(SOLID_FILL, 8);
	floodfill(320+x,430+y,WHITE);
	drawpoly(9, avatar[0]); /* Pantalon -> 0 */
	setfillstyle(SOLID_FILL, BLUE);
	fillpoly(9,avatar[0]);
	drawpoly(14, avatar[1]); /* Pies -> 1 */
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(14, avatar[1]);  /* Pies -> 1 */
	drawpoly(21, avatar[2]); /* Torso -> 2 */
	drawpoly(9, avatar[3]); /* Decoracion de camisa -> 3 */
	rectangle(320+x,284+y,330+x,274+y);
	rectangle(330+x,264+y,320+x,254+y);
	setfillstyle(SOLID_FILL, 12);
	floodfill(339+x,263+y,WHITE);
	floodfill(290+x,263+y,WHITE);
	setfillstyle(1, 4);
	floodfill(335+x,240+y,WHITE);
	drawpoly(13, avatar[4]); /* Cara -> 4 */
	setfillstyle(SOLID_FILL, 6);
	floodfill(320+x,204+y, WHITE);
	rectangle(310+x,200+y,288+x,178+y);
	rectangle(330+x,178+y,352+x,200+y);
	setfillstyle(1,11);
	floodfill(300+x,198+y,WHITE);
	floodfill(340+x,198+y,WHITE);
	rectangle(352+x,190+y,362+x,178+y);
	rectangle(330+x,178+y,310+x,188+y);
	rectangle(288+x,178+y,278+x,190+y);
	setfillstyle(1,7);
	floodfill(360+x,180+y, WHITE);
	floodfill(320+x,180+y, WHITE);
	floodfill(280+x,180+y, WHITE);
	setfillstyle(1,0);
	drawpoly(25, avatar[5]); /* Pelo -> 5 */
	fillpoly(25, avatar[5]); /* Pelo -> 5 */
	drawpoly(22, avatar[6]); /* Brazos -> 6 */
	setfillstyle(1,6);
	fillpoly(22, avatar[6]); /* Brazos -> 6 */
	rectangle(310+x,190+y,298+x,178+y);
	rectangle(340+x,178+y,352+x,190+y);
	setfillstyle(1,WHITE);
	floodfill(300+x,180+y, WHITE);
	floodfill(342+x,180+y,WHITE);
	delay(300);
	putimage(242+x,90+y, buff1, COPY_PUT);
	putimage(242+x,264+y, buff2, COPY_PUT);
	mver();

}
