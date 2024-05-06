#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <mouse.h>
#include <dos.h>

int main()
{
    int gd = DETECT,gm;
    int mx = 0,my = 0, click_procesado = 0,i = 0;
    int cuadrante = 0, boton = 0;

    initgraph(&gd,&gm,"C:\\TC20\\BIN");
    msituar(1,320,240);
    mver();
    do
    {
        if(mclick() == 2 && minlimit(1,321,0,640,239) == 1 && click_procesado == 0) /* Arriba derecha */
        {
            boton = 0;
            cuadrante = 1;
            mocultar();
            cleardevice();
            click_procesado = 1;
            mx = mxpos(1);
            my = mypos(1);
            for (i = 0; i < 3; i++)
            {
                settextjustify(1,1);
                settextstyle(7,0,2);
                setcolor(WHITE);
                bar(mx,my+(i*30),mx-110,my+30+(i*30));
                setcolor(8);
                rectangle(mx,my+(i*30),mx-110,my+30+(i*30));
                if(i == 0)
                {
                    outtextxy(mx-70,my+14,"SALIR");
                }
                if(i == 1)
                {
                    outtextxy(mx-70,my+14*3,"   LIMPIAR");
                }
                if(i == 2)
                {
                    outtextxy(mx-70,my+14*5,"BOTON");
                }
                
            }
            mver();
        }

        if(mclick() == 2 && minlimit(1,0,0,320,240) == 1 && click_procesado == 0) /* Arriba izquierda */
        { 
            boton = 0;
            cuadrante = 2;
            mocultar();
            cleardevice();
            click_procesado = 1;
            mx = mxpos(1);
            my = mypos(1);
            for (i = 0; i < 3; i++)
            {
                settextjustify(1,1);
                settextstyle(7,0,2);
                setcolor(WHITE);
                bar(mx,my+(i*30),mx+110,my+30+(i*30));
                setcolor(8);
                rectangle(mx,my+(i*30),mx+110,my+30+(i*30));
                if(i == 0)
                {
                    outtextxy(mx+40,my+14,"SALIR");
                }
                if(i == 1)
                {
                    outtextxy(mx+40,my+14*3,"   LIMPIAR");
                }
                if(i == 2)
                {
                    outtextxy(mx+40,my+14*5,"BOTON");
                }
                
            }
            mver();
        }


        if(mclick() == 2 && minlimit(1,321,241,640,480) == 1 && click_procesado == 0) /* Abajo derecha */
        {
            boton = 0;
            cuadrante = 4;
            mocultar();
            cleardevice();
            click_procesado = 1;
            mx = mxpos(1);
            my = mypos(1);
            for (i = 0; i < 3; i++)
            {
                settextjustify(1,1);
                settextstyle(7,0,2);
                setcolor(WHITE);
                bar(mx,my-(i*30),mx-110,my-30-(i*30));
                setcolor(8);
                rectangle(mx,my-(i*30),mx-110,my-30-(i*30));
                if(i == 1)
                {
                    outtextxy(mx-70,my-14*3,"   LIMPIAR");
                }
                if(i == 2)
                {
                    outtextxy(mx-70,my-14,"BOTON");
                }  
                outtextxy(mx-70,my-15*5,"SALIR");
                
            }
            mver();
        }

        if(mclick() == 2 && minlimit(1,0,239,319,480) == 1 && click_procesado == 0) /* Abajo izquierda */
        {
            boton = 0;
            cuadrante = 3;
            mocultar();
            cleardevice();
            click_procesado = 1;
	    mx = mxpos(1);
	    my = mypos(1);
	    for (i = 0; i < 3; i++)
	    {
            settextjustify(1,1);
            settextstyle(7,0,2);
            setcolor(WHITE);
            bar(mx,my-(i*30),mx+110,my-30-(i*30));
            setcolor(8);
            rectangle(mx,my-(i*30),mx+110,my-30-(i*30));
            if(i == 1)
            {
                outtextxy(mx+40,my-14*3,"   LIMPIAR");
            }
            if(i == 2)
            {
                outtextxy(mx+40,my-14,"BOTON");
            }        
        }
		    outtextxy(mx+40,my-15*5,"SALIR");

            mver();
        }
        

        if(cuadrante == 1  && mclick() == 1 && minlimit(1,mx-110,my,mx,my+30) == 1 && click_procesado == 0) /* Salir */
        {
            click_procesado = 1;
            mocultar();
            cleardevice();
            closegraph();
            return 0;
        }

	    if(cuadrante == 1 && mclick() == 1 && minlimit(1,mx-110,my+30,mx,my+30*2) == 1 && click_procesado == 0) /* Limpiar */
        {
            click_procesado = 1;
            mocultar();
            cleardevice();
            cuadrante = 0;
            mver();
        }

	    if(cuadrante == 1 && mclick() == 1 && minlimit(1,mx-110,my+30*2,mx,my+30*3) == 1 && click_procesado == 0 && boton == 0) /* boton */
        {
            boton = 1;
            click_procesado = 1;
            mocultar();
            setcolor(WHITE);
            bar(mx-110,my+30*2,mx-110-90,my+30*3);
            setcolor(8);
            rectangle(mx-110,my+30*2,mx-110-90,my+30*3);
		    outtextxy(mx-110-45, my+30*2+15,"Sonido");
            mver();
        }

        if(cuadrante == 1 && mclick() == 1 && minlimit(1,mx-110-90,my+30*2,mx-110,my+30*3) == 1 && click_procesado == 0 && boton == 1) /* boton */
        {
            click_procesado = 1;
            mocultar();
            sound(256);
            delay(200);
            nosound();
            mver();
        }

        if(cuadrante == 1 && mclick() == 1 && minlimit(1,mx-110,my+30*2,mx,my+30*3) == 1 && click_procesado == 0 && boton == 1) /* boton */
        {
            boton = 0;
            click_procesado = 1;
            mocultar();
            cleardevice();
            for (i = 0; i < 3; i++)
            {
                settextjustify(1,1);
                settextstyle(7,0,2);
                setcolor(WHITE);
                bar(mx,my+(i*30),mx-110,my+30+(i*30));
                setcolor(8);
                rectangle(mx,my+(i*30),mx-110,my+30+(i*30));
                if(i == 0)
                {
                    outtextxy(mx-70,my+14,"SALIR");
                }
                if(i == 1)
                {
                    outtextxy(mx-70,my+14*3,"   LIMPIAR");
                }
                if(i == 2)
                {
                    outtextxy(mx-70,my+14*5,"BOTON");
                }
                
            }
            mver();
        }

        if(cuadrante == 2  && mclick() == 1 && minlimit(1,mx,my,mx+110,my+30) == 1 && click_procesado == 0) /* Salir */
        {
            click_procesado = 1;
            mocultar();
            cleardevice();
            closegraph();
            return 0;
        }

	    if(cuadrante == 2 && mclick() == 1 && minlimit(1,mx,my+30,mx+110,my+30*2) == 1 && click_procesado == 0) /* Limpiar */
        {
            click_procesado = 1;
            mocultar();
            cleardevice();
            cuadrante = 0;
            mver();
        }

	    if(cuadrante == 2 && mclick() == 1 && minlimit(1,mx,my+30*2,mx+110,my+30*3) == 1 && click_procesado == 0 && boton == 0) /* boton */
        {
            boton = 1;
            click_procesado = 1;
            mocultar();
            setcolor(WHITE);
            bar(mx+110,my+30*2,mx+110+90,my+30*3);
            setcolor(8);
            rectangle(mx+110,my+30*2,mx+110+90,my+30*3);
		    outtextxy(mx+110+45, my+30*2+15,"Sonido");
            mver();
        }

        if(cuadrante == 2 && mclick() == 1 && minlimit(1,mx+110,my+30*2,mx+110+90,my+30*3) == 1 && click_procesado == 0 && boton == 1) /* boton */
        {
            click_procesado = 1;
            mocultar();
            sound(256);
            delay(200);
            nosound();
            mver();
        }

        if(cuadrante == 2 && mclick() == 1 && minlimit(1,mx,my+30*2,mx+110,my+30*3) == 1 && click_procesado == 0 && boton == 1) /* boton */
        {
            boton = 0;
            click_procesado = 1;
            mocultar();
            cleardevice();
            for (i = 0; i < 3; i++)
            {
                settextjustify(1,1);
                settextstyle(7,0,2);
                setcolor(WHITE);
                bar(mx,my+(i*30),mx+110,my+30+(i*30));
                setcolor(8);
                rectangle(mx,my+(i*30),mx+110,my+30+(i*30));
                if(i == 0)
                {
                    outtextxy(mx+40,my+14,"SALIR");
                }
                if(i == 1)
                {
                    outtextxy(mx+40,my+14*3,"   LIMPIAR");
                }
                if(i == 2)
                {
                    outtextxy(mx+40,my+14*5,"BOTON");
                }
                
            }
            mver();
        }

        if(cuadrante == 3  && mclick() == 1 && minlimit(1,mx,my-90,mx+110,my-60) == 1 && click_procesado == 0) /* Salir */
        {
            click_procesado = 1;
            mocultar();
            cleardevice();
            closegraph();
            return 0;
        }

	    if(cuadrante == 3 && mclick() == 1 && minlimit(1,mx,my-60,mx+110,my-30) == 1 && click_procesado == 0) /* Limpiar */
        {
            click_procesado = 1;
            mocultar();
            cleardevice();
            cuadrante = 0;
            mver();
        }

	    if(cuadrante == 3 && mclick() == 1 && minlimit(1,mx,my-30,mx+110,my) == 1 && click_procesado == 0 && boton == 0) /* boton */
        {
            boton = 1;
            click_procesado = 1;
            mocultar();
            setcolor(WHITE);
            bar(mx+110,my-30,mx+110+90,my);
            setcolor(8);
            rectangle(mx+110,my-30,mx+110+90,my);
		    outtextxy(mx+110+45, my-15,"Sonido");
            mver();
        }

        if(cuadrante == 3 && mclick() == 1 && minlimit(1,mx+110,my-30,mx+110+90,my) == 1 && click_procesado == 0 && boton == 1) /* boton */
        {
            click_procesado = 1;
            mocultar();
            sound(256);
            delay(200);
            nosound();
            mver();
        }

        if(cuadrante == 3 && mclick() == 1 && minlimit(1,mx,my-30,mx+110,my) == 1 && click_procesado == 0 && boton == 1) /* boton */
        {
            boton = 0;
            click_procesado = 1;
            mocultar();
            cleardevice();
            for (i = 0; i < 3; i++)
	        {
            settextjustify(1,1);
            settextstyle(7,0,2);
            setcolor(WHITE);
            bar(mx,my-(i*30),mx+110,my-30-(i*30));
            setcolor(8);
            rectangle(mx,my-(i*30),mx+110,my-30-(i*30));
            if(i == 1)
            {
                outtextxy(mx+40,my-14*3,"   LIMPIAR");
            }
            if(i == 2)
            {
                outtextxy(mx+40,my-14,"BOTON");
            }        
            }
		    outtextxy(mx+40,my-15*5,"SALIR");
            mver();
        }

        if(cuadrante == 4  && mclick() == 1 && minlimit(1,mx-110,my-90,mx,my-60) == 1 && click_procesado == 0) /* Salir */
        {
            click_procesado = 1;
            mocultar();
            cleardevice();
            closegraph();
            return 0;
        }

	    if(cuadrante == 4 && mclick() == 1 && minlimit(1,mx-110,my-60,mx,my-30) == 1 && click_procesado == 0) /* Limpiar */
        {
            click_procesado = 1;
            mocultar();
            cleardevice();
            cuadrante = 0;
            mver();
        }

	    if(cuadrante == 4 && mclick() == 1 && minlimit(1,mx-110,my-30,mx,my) == 1 && click_procesado == 0 && boton == 0) /* boton */
        {
            boton = 1;
            click_procesado = 1;
            mocultar();
            setcolor(WHITE);
            bar(mx-110,my-30,mx-110-90,my);
            setcolor(8);
            rectangle(mx-110,my-30,mx-110-90,my);
		    outtextxy(mx-110-45, my-15,"Sonido");
            mver();
        }

        if(cuadrante == 4 && mclick() == 1 && minlimit(1,mx-110-90,my-30,mx-110,my) == 1 && click_procesado == 0 && boton == 1) /* boton */
        {
            click_procesado = 1;
            mocultar();
            sound(256);
            delay(200);
            nosound();
            mver();
        }

        if(cuadrante == 4 && mclick() == 1 && minlimit(1,mx-110,my-30,mx,my) == 1 && click_procesado == 0 && boton == 1) /* boton */
        {
            boton = 0;
            click_procesado = 1;
            mocultar();
            cleardevice();
            for (i = 0; i < 3; i++)
            {
                settextjustify(1,1);
                settextstyle(7,0,2);
                setcolor(WHITE);
                bar(mx,my-(i*30),mx-110,my-30-(i*30));
                setcolor(8);
                rectangle(mx,my-(i*30),mx-110,my-30-(i*30));
                if(i == 1)
                {
                    outtextxy(mx-70,my-14*3,"   LIMPIAR");
                }
                if(i == 2)
                {
                    outtextxy(mx-70,my-14,"BOTON");
                }  
                
            }
            outtextxy(mx-70,my-15*5,"SALIR");
            mver();
        }

        if(mclick() == 1 && click_procesado == 0)
        {
            boton = 0;
            cuadrante = 0;
    ;
            mocultar();
            click_procesado = 1;
            cleardevice();
            mver();
        }

        if(mclick() == 0)
        {
            click_procesado = 0;
        }

    }while(1);
}
