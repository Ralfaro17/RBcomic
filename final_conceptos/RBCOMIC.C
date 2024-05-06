#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <mouse.h>
#include <BMP.H>
#include <time.h>
#include <string.h>
#include <dos.h>

void escenas(int estado);
void cargar_escena(int escena_actual);
void modo_lectura(int escena_actual);


/*============================MODO GRAFICO=================================== */
void main(void) {
    char hora[3], minutos[3], num[3];
    int adaptador=DETECT, modo;
    int i = 0,my;
    int minimizado = 0;
    int menuayuda = 0;
    int scrollbar1=1;
    int menu_escena = 0, click_procesado = 0, escena_actual = -1, pagina = 0, tecla = 'm'; /* 0 == False, 1 == True*/
    int controles = 0; /* 0 == mouse, 1 == teclado*/
    int activado = 0;
    int pulsado = 0;
    struct time now, temp;  /* Para guardar la hora */
    initgraph(&adaptador,&modo,"C:\\TC20\\BIN");


    gettime(&now);

    /*============================INTERFAS======================================= */
    /*----------------------limite de la pantalla-------------------------------- */
    rectangle(0,0,639,479);
    /*----------------------------interfas izquierda----------------------------- */
    setcolor(15);
    setfillstyle(1,1);
    /*..............circulo x */
    circle(150,10,50);
    /*..............limite izquierdo */
    rectangle(0,0,165,430);
    /*..............superior */
    bar(0,0,165,60);
    rectangle(0,0,165,60);
    settextstyle(8,0,3);
    settextjustify(1,1);
    outtextxy(82,25,"AYUDA");
    /*..............ellipse */
    ellipse(150,270,0,360,50,115);
    setfillstyle(1, 3);
    floodfill(180,300,WHITE);
    settextstyle(3,1,4);
    outtextxy(174,270,"COMICS");
    /*		rectangle(168,218,194,325); Hitbox "COMICS" */

    /*..............barra larga izquierda */
    setfillstyle(1,8);
    bar(128,60,165,388);
    setfillstyle(2,3);
    bar(149,60,165,81);
    bar(149,366,165,388);
    rectangle(149,60,165,388);
    rectangle(149,60,165,81);
    rectangle(149,366,165,388);
    setfillstyle(1,3); /*&&&&&&&&&&&&&&&&&&&&&*/
    bar(149,82,164,152);
    rectangle(149,82,164,152); /*&&&&&&&&&&&&&&&&&&&&&&&&&&*/
    /*..............barra ancha mitad */
    setfillstyle(1,9);
    bar(0,60,148,388);
    rectangle(0,60,149,388);
    /*..............inferior */
    setfillstyle(1,1);
    bar(0,388,165,430);
    rectangle(0,388,165,430);
    settextstyle(100,0,1);
    settextjustify(1,1);
    outtextxy(92,408,"PLAY ESCENAS");
    settextstyle(2,0,4 );
    outtextxy(92,418,"(ejecute la pagina)");
    line(26,398,40,406);
    line(26,416,40,406);
    line(26,416,26,398);
    setfillstyle(1,14);
    floodfill(32,407,15);
    /*................recuadros de escena &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
    setfillstyle(1,11);
    for (i = 0; i < 4; i++)
    {
        bar(0,60+(i*82),128,142+(i*82));
        rectangle(0,60+(i*82),128,142+(i*82));
    }
    setcolor(0);
    settextstyle(2, 0, 9);
    settextjustify(1,1);
    outtextxy(64,101,"1");
    outtextxy(64,183,"2");
    outtextxy(64,265,"3");
    outtextxy(64,347,"4");
    setcolor(WHITE);
    /*----------------------------interfas inferior------------------------------*/
    setfillstyle(1,9);
    /*..............inferior limite */
    bar(0,430,640,478);
    rectangle(0,430,640,480);
    ShowBMP(150, 435,"..\\BIN\\escenas\\teclado.bmp");
    ShowBMP(70, 440,"..\\BIN\\escenas\\mouse.bmp");
    /*..............cuadro 1 */
    setfillstyle(1,8);
    bar(334,430,506,479);
    rectangle(334,430,506,479);
    /*      	Salir2 */
    setlinestyle(0,1,3);
    settextstyle(7,0,4);
    settextjustify(1,2);
    setcolor(12);
    outtextxy(440,436,"X");
    /*      	Maximizar inferior */
    setcolor(7);
    rectangle(350,445,380,470);
    /*		Minimizar inferior */
    setcolor(15);
    line(390,456,420,456);
    setlinestyle(0,1,1);
    /*..............cuadro 3 */
    setfillstyle(1,9);
    bar(506,430,640,480);
    rectangle(506,430,639,479);
    itoa(now.ti_hour, hora,10);
    outtextxy(546,435,hora);
    outtextxy(576,432,":");
    itoa(now.ti_min, minutos,10);
    outtextxy(606,435, minutos);
    /*..............cuadro 2 */
    setfillstyle(1,3);
    bar(460,430,506,480);
    rectangle(460,430,506,479);
    /*..............circulo minimizar */
    circle(483,454,20);
    settextstyle(12,0,3);
    setlinestyle(0,1,3);
    setfillstyle(1,RED);
    floodfill(485,456,WHITE);
    rectangle(472,448,494,454);
    outtextxy(483,462,"min");

    /*----------------------------interfas derecha------------------------------- */
    /*..............limite derecho */
    setlinestyle(0,0,1);
    setfillstyle(1,9);
    bar(554,0,640,430);
    rectangle(554,0,639,430);
    /*..............inferior derecho */
    setfillstyle(1,8);
    bar(554,164,640,430);
    rectangle(554,164,639,430);
    ShowBMP(554,165,"..\\BIN\\escenas\\waos.bmp");
    rectangle(554,164,639,430);
    /*      	Salir */
    setlinestyle(0,1,3);
    settextstyle(7,0,4);
    settextjustify(1,2);
    setcolor(12);
    outtextxy(600,20,"X");
    /*      	Maximizar */
    setcolor(7);
    rectangle(586,70,610,90);
    /*		Minimizar */
    setcolor(15);
    line(586,110,610,110);
    /*----------------------------pagina y demas------------------------------- */

    /*..............Color circle */
    setfillstyle(1, RED);
    floodfill(190,30,WHITE);
    settextstyle(8, 0, 3);
    settextjustify(1,1);
    outtextxy(180,18,"X");
    /*		rectangle(170,10,188,36); Hitbox de la X  */


    /*============================FUNCIONES MOUSE======================================= */
    mver();
    msituar(1,320,240);
    do {
        do
        {
            if(mclick() == 0)
            {
                click_procesado = 0;
            }
            gettime(&temp);

            if(temp.ti_hour != now.ti_hour || temp.ti_min != now.ti_min)
            {
                sound(720);
                delay(200);
                nosound();
                settextstyle(7,0,4);
                settextjustify(1,2);
                now.ti_hour = temp.ti_hour;
                now.ti_min = temp.ti_min;
                setfillstyle(1,9);
                bar(506,430,640,480);
                rectangle(506,430,639,479);
                itoa(now.ti_hour, hora,10);
                outtextxy(546,435,hora);
                outtextxy(576,432,":");
                itoa(now.ti_min, minutos,10);
                outtextxy(606,435, minutos);
            }

            /*..............Maximizar pagina */
            if(mclick() == 1 && minlimit(1, 168,218,194,325) == 1 && minimizado == 0 && pagina == 1)
            {
                sound(256);
                delay(200);
                nosound();
                pagina = 1;
                cargar_escena(escena_actual);
                /*..............cuadro 2 */
                setfillstyle(1,3);
                bar(460,430,506,480);
                rectangle(460,430,506,479);
                /*..............circulo minimizar */
                circle(483,454,20);
                settextstyle(12,0,3);
                setlinestyle(0,1,3);
                setfillstyle(1,GREEN);
                floodfill(485,456,WHITE);
                rectangle(475,442,491,456);
                outtextxy(483,462,"max");
            }
            /*..............Minimizar pagina */
            if(mclick() == 1 && minlimit(1,170,10,198,60) == 1 && minimizado == 0 && pagina == 1 && click_procesado == 0)
            {
                sound(256);
                delay(200);
                nosound();
                click_procesado = 1;
                pagina = 0;
                setfillstyle(1, 0);

                bar(222,314,508,384);
                delay(50);
                bar(222,214,508,384);
                delay(50);
                bar(222,114,508,384);
                delay(50);
                bar(222,12,534,414);
                /*..............cuadro 2 */
                setfillstyle(1,3);
                bar(460,430,506,480);
                rectangle(460,430,506,479);
                /*..............circulo minimizar */
                circle(483,454,20);
                settextstyle(12,0,3);
                setlinestyle(0,1,3);
                setfillstyle(1,RED);
                floodfill(485,456,WHITE);
                rectangle(472,448,494,454);
                outtextxy(483,462,"min");

            }

            if(mclick() == 1 && minlimit(1,0,0,165,50) == 1 && minimizado == 0 && click_procesado == 0 && menuayuda == 0)
            {
                sound(256);
                delay(200);
                nosound();
                click_procesado = 1;
                mocultar();
                /*..............Menu de ayuda */
                setlinestyle(1,0,1);
                setfillstyle(1,1);
                bar(0,60,164,388);
                rectangle(0,60,164,388);
                setfillstyle(1,9
                            );
                bar(0,100,164,388);
                setlinestyle(1,0,1);
                rectangle(0,100,164,388);
                setlinestyle(0,0,1);
                rectangle(0,100,164,388);
                rectangle(0,140,164,388);
                rectangle(0,180,164,388);
                rectangle(0,220,164,388);
                rectangle(0,260,164,388);
                rectangle(0,300,164,388);
                rectangle(0,340,164,388);

                settextstyle(8,0,3);
                settextjustify(1,2);
                setcolor(12);
                outtextxy(152,60,"X");
                settextstyle(2,0,6);
                setcolor(12);
                outtextxy(72,70,"Menu de ayuda");

                settextstyle(2,0,4);
                settextjustify(1,1);
                setcolor(15);
                outtextxy(66,120,">Funciones del teclado");
                outtextxy(60,160,">Funciones del mouse");
                menuayuda=1;

                mver();
            }

            if (mclick() == 1 && minlimit(1, 0,100,164,140) == 1 && menuayuda == 1 && minimizado == 0)
            {
                sound(516);
                    delay(200);
                    nosound();
                    activado = 1;
                    setfillstyle(1,1);
                    bar(225,14,254,84);
                    rectangle(225,14,254,84);
                    delay(50);
                    bar(225,14,304,184);
                    rectangle(225,14,304,184);
                    delay(50);
                    bar(225,14,404,284);
                    rectangle(225,14,404,284);
                    delay(50);
                    bar(225,14,512,384);
                    rectangle(225,14,512,390);
                    setfillstyle(1,9);
                        bar(225,14,512,65);
                         rectangle(225,14,512,65);
                    rectangle(225,14,512,390);

                    settextstyle(8,0,3);
                settextjustify(1,1);
                setcolor(15);
                outtextxy(370,36,"opciones de teclado");
                settextstyle(2,0,4);
                outtextxy(360,80,"tocar 1 a 4: carga una escena.");
                outtextxy(368,100,"tocar flecha arriba: scroll arriba.");
                outtextxy(350,120,"tocar flecha abajo: scroll abajo.");
                outtextxy(350,140,"volver a tocar (a): cerrar menu ayuda.");
                outtextxy(360,160,"tocar s o b: minimizar o maximizar.");
                outtextxy(360,180,"tocar p: reproducir escena cargada");
                outtextxy(360,200,"tocar r: reproducir todas las escenas");
                outtextxy(360,220,"tocar m: cambiar a mouse");
                outtextxy(360,240,"tocar k: cambiar a teclado");
            }

            if (mclick() == 1 && minlimit(1, 0,140,164,180) == 1 && menuayuda == 1 && minimizado == 0)
            {
                sound(516);
                    delay(200);
                    nosound();
                    activado = 1;
                    setfillstyle(1,1);
                    bar(225,14,254,84);
                    rectangle(225,14,254,84);
                    delay(50);
                    bar(225,14,304,184);
                    rectangle(225,14,304,184);
                    delay(50);
                    bar(225,14,404,284);
                    rectangle(225,14,404,284);
                    delay(50);
                    bar(225,14,512,384);
                    rectangle(225,14,512,390);
                    setfillstyle(1,9);
                        bar(225,14,512,65);
                         rectangle(225,14,512,65);
                    rectangle(225,14,512,390);

                    settextstyle(8,0,3);
                settextjustify(1,1);
                setcolor(15);
                outtextxy(370,36,"opciones de mouse");
                settextstyle(2,0,4);
                outtextxy(360,80,"click izquierdo en escenas: carga una escena.");
                outtextxy(368,100,"click izquierdo en comics: reproduce una escena.");
                outtextxy(350,120,"click izquierdo en x: cierra programa.");
                outtextxy(350,140,"click izquierdo en (-) para minimizar.");
                outtextxy(360,160,"click izquierdo en ([]) para maximizar.");
                outtextxy(360,180,"click izquierdo en play: reproducir todo");
            }


            /*..............Cerrar menu de ayuda */
            if(mclick() == 1 && minlimit(1,128,62,164,100) == 1 && menuayuda == 1 && click_procesado == 0)
            {
                sound(124);
                delay(200);
                nosound();
                mocultar();
                click_procesado = 1;
                /*..............barra larga izquierda */
                setfillstyle(1,8);
                bar(128,60,165,388);
                setfillstyle(2,3);
                bar(149,60,165,81);
                bar(149,366,165,388);
                rectangle(149,60,165,388);
                rectangle(149,60,165,81);
                rectangle(149,366,165,388);
                setfillstyle(1,3); /*&&&&&&&&&&&&&&&&&&&&&*/
                bar(149,82,164,152);
                rectangle(149,82,164,152); /*&&&&&&&&&&&&&&&&&&&&&&&&&&*/
                /*..............barra ancha mitad */
                setfillstyle(1,9);
                bar(0,60,148,388);
                rectangle(0,60,149,388);
                escenas(menu_escena);
                if(activado == 1)
                {
                    setfillstyle(1, 0);

                    bar(222,314,508,384);
                    delay(50);
                    bar(222,214,508,384);
                    delay(50);
                    bar(222,114,508,384);
                    delay(50);
                    bar(222,12,534,414);
                }
                activado = 0;
                if(pagina == 1)
                {
                    modo_lectura(escena_actual);
                }
                mver();
                menuayuda = 0;
            }

            /* ----------------------------------- BARRAS DE DESPLAZAMIETO ----------------------------- */

            /* -------------- Mediante botones en pantalla */

            if (mclick() == 1 && minlimit(1,128,365,165,388) == 1 && minimizado == 0 && click_procesado == 0 && menuayuda == 0) /* Desplazar abajo */
            {
                sound(256);
                delay(200);
                nosound();
                if((menu_escena+1) < 4)
                {
                    mocultar();
                    menu_escena += 1;

                    if((menu_escena+1) < 3)
                    {
                        delay(100);
                        setfillstyle(1,8);
                        bar(149,82,164,365);
                        rectangle(149,82,165,365);
                        setfillstyle(1,3);
                        bar(149,117+(71*(menu_escena)),164,187+(71*(menu_escena)));
                        rectangle(149,117+(71*(menu_escena)),164,187+(71*(menu_escena)));
                    }
                    delay(100);
                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,82+(71*(menu_escena)),164,152+(71*(menu_escena)));
                    rectangle(149,82+(71*(menu_escena)),164,152+(71*(menu_escena)));
                }
                click_procesado = 1;
                scrollbar1 = menu_escena+1;
                escenas(menu_escena);
                mver();
            }

            if (mclick() == 1 && minlimit(1,128,60,165,81) == 1 && minimizado == 0 && click_procesado == 0 && menuayuda == 0) /* Desplazar arriba */
            {
                sound(256);
                delay(200);
                nosound();
                if((menu_escena-1) >= 0)
                {
                    mocultar();
                    menu_escena -= 1;

                    delay(100);
                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,117+(71*(menu_escena)),164,187+(71*(menu_escena)));
                    rectangle(149,117+(71*(menu_escena)),164,187+(71*(menu_escena)));
                    delay(100);
                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,82+(71*(menu_escena)),164,152+(71*(menu_escena)));
                    rectangle(149,82+(71*(menu_escena)),164,152+(71*(menu_escena)));
                }
                click_procesado = 1;
                scrollbar1 = menu_escena+1;
                escenas(menu_escena);
                mver();
            }

            /* -------------- Tocando la scrollbar */
            setlinestyle(0,0,1);
            if (mclick() == 1 && minlimit(1,129,82,164,152) == 1 && minimizado == 0 && menu_escena != 0 && menuayuda == 0) /* Desplazar arriba */
            {   mocultar();
                menu_escena = 0;

                setfillstyle(1,8);
                bar(149,82,164,365);
                rectangle(149,82,165,365);
                /* ......... animacion scroll 1 */
                switch(scrollbar1) {
                case 2:
                    setfillstyle(1,3);
                    bar(149,102,164,172);
                    rectangle(149,102,164,172);
                    break;
                case 3:

                    setfillstyle(1,3);
                    bar(149,192,164,222);
                    rectangle(149,192,164,222);
                    delay(50);

                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,102,164,172);
                    rectangle(149,102,164,172);
                    break;

                case 4:
                    setfillstyle(1,3);
                    bar(149,223,164,294);
                    rectangle(149,223,164,294);
                    delay(50);

                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,192,164,222);
                    rectangle(149,192,164,222);
                    delay(50);

                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,102,164,172);
                    rectangle(149,102,164,172);
                    delay(50);



                    break;
                }

                delay(100);
                setfillstyle(1,8);
                bar(149,82,164,365);
                rectangle(149,82,165,365);
                setfillstyle(1,3);
                bar(149,82,164,152);
                rectangle(149,82,164,152);
                escenas(menu_escena);
                mver();
                scrollbar1=1;
            }

            if (mclick() == 1 && minlimit(1,129,152,164,223) == 1 && minimizado == 0 && menu_escena != 1 && menuayuda == 0) /* Desplazar arriba */
            {
                mocultar();
                menu_escena = 1;

                setfillstyle(1,8);
                bar(149,82,164,365);
                rectangle(149,82,165,365);

                switch(scrollbar1) {
                case 1:
                    setfillstyle(1,3);
                    bar(149,122,164,203);
                    rectangle(149,122,164,203);

                    break;
                case 3:
                    setfillstyle(1,3);
                    bar(149,182,164,253);
                    rectangle(149,182,164,253);
                    /* ......... animacion scroll 2 */
                    break;
                case 4:
                    setfillstyle(1,3);
                    bar(149,212,164,283);
                    rectangle(149,212,164,283);

                    delay(50);

                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,182,164,253);
                    rectangle(149,182,164,253);
                    break;
                }

                delay(100);
                setfillstyle(1,8);
                bar(149,82,164,365);
                rectangle(149,82,165,365);
                setfillstyle(1,3);
                bar(149,152,164,223);
                rectangle(149,152,164,223);
                escenas(menu_escena);
                mver();
                scrollbar1=2;
            }

            if (mclick() == 1 && minlimit(1,129,223,164,294) == 1 && minimizado == 0 && menu_escena != 2 && menuayuda == 0) /* Desplazar arriba */
            {   mocultar();
                menu_escena = 2;

                setfillstyle(1,8);
                bar(149,82,164,365);
                rectangle(149,82,165,365);
                /* ......... animacion scroll 3 */
                switch(scrollbar1) {
                case 1:
                    setfillstyle(1,3);
                    bar(149,163,164,234);
                    rectangle(149,163,164,234);
                    delay(50);

                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,193,164,264);
                    rectangle(149,193,164,264);
                    break;
                case 2:
                    setfillstyle(1,3);
                    bar(149,193,164,264);
                    rectangle(149,193,164,264);
                    break;
                case 4:
                    setfillstyle(1,3);
                    bar(149,253,164,324);
                    rectangle(149,253,164,324);
                    break;
                }

                delay(100);
                setfillstyle(1,8);
                bar(149,82,164,365);
                rectangle(149,82,165,365);
                setfillstyle(1,3);
                bar(149,223,164,294);
                rectangle(149,223,164,294);
                escenas(menu_escena);
                mver();
                scrollbar1=3;
            }

            if (mclick() == 1 && minlimit(1,129,294,164,365) == 1 && minimizado == 0 && menu_escena != 3 && menuayuda == 0) /* Desplazar arriba */
            {
                mocultar();
                menu_escena = 3;

                setfillstyle(1,8);
                bar(149,82,164,365);
                rectangle(149,82,165,365);
                /* ......... animacion scroll 4 */
                switch(scrollbar1) {
                case 1:
                    setfillstyle(1,3);
                    bar(149,204,164,275);
                    rectangle(149,204,164,275);
                    delay(50);

                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,234,164,305);
                    rectangle(149,234,164,305);
                    delay(50);

                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,264,164,335);
                    rectangle(149,264,164,335);
                    break;
                case 2:
                    setfillstyle(1,3);
                    bar(149,234,164,305);
                    rectangle(149,234,164,305);
                    delay(50);

                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,264,164,335);
                    rectangle(149,264,164,335);

                    break;
                case 3:
                    setfillstyle(1,3);
                    bar(149,264,164,335);
                    rectangle(149,264,164,335);
                    break;
                }

                delay(100);
                setfillstyle(1,8);
                bar(149,82,164,365);
                rectangle(149,82,165,365);
                setfillstyle(1,3);
                bar(149,294,164,365);
                rectangle(149,294,164,365);
                escenas(menu_escena);
                mver();
                scrollbar1=4;
            }

            /* ----------------------------------- CARGA DE ESCENAS ------------------------------------- */
            if(mclick() == 1 && minlimit(1,0,60,128,552) == 1 && minimizado == 0 && click_procesado == 0 && menuayuda == 0)
            {
                mocultar();
                sound(512);
                delay(200);
                nosound();
                pagina = 1;
                /*......................................*/
                click_procesado=1;
                my = mypos(1);
                setlinestyle(0,1,0);
                setfillstyle(1,11);
                bar(0,60+(pulsado*82),128,142+(pulsado*82));
                rectangle(0,60+(pulsado*82),128,142+(pulsado*82));
                itoa(((pulsado+1)+(menu_escena*4)), num, 10);
                setcolor(0);
                settextstyle(2, 0, 9);
                settextjustify(1,1);
                outtextxy(64,101+(pulsado*82),num);
                setlinestyle(0,1,3);
                setcolor(WHITE);
                for(i = 0; i < 4; i++)
                {
                    if(my > 60+(82*i) &&  my < 142+(82*i))
                    {
                        escena_actual = i+(menu_escena*4);
                        rectangle(0,61+(i*82),127,141+(i*82));
                        modo_lectura(escena_actual);
                        pulsado = i;
                    }
                }
                setlinestyle(0,1,0);
                mver();
            }

            /* ---------------------  SALIR, MINIMIZAR Y MAXIMIZAR -------------------------*/

            if((mclick() == 1 && minimizado == 0) && (minlimit(1,574,10,620,40) == 1 || minlimit(1,440,436,460,456) == 1))
            {
                /*..............Cerrar programa */
                mocultar();
                sound(1024);
                delay(200);
                nosound();
                cleardevice();
                closegraph();
                return;
            }

            if(mclick() == 1 && minlimit(1,566,100,620,120) == 1 && minimizado == 0)
            {
                mocultar();
                sound(256);
                delay(200);
                nosound();
                /*..............Miminizar */
                minimizado = 1;
                pagina = 0;
                /*..............cuadro 2 */
                setfillstyle(1,3);
                bar(460,430,506,480);
                rectangle(460,430,506,479);
                /*..............circulo minimizar */
                circle(483,454,20);
                settextstyle(12,0,3);
                setlinestyle(0,1,3);
                setfillstyle(1,RED);
                floodfill(485,456,WHITE);
                rectangle(472,448,494,454);
                outtextxy(483,462,"min");

                ShowBMP(0,0,"..\\BIN\\fondo.BMP");
                /*      	Maximizar3 */
                setcolor(15);
                rectangle(350,445,380,470);
                /*		Minimizar3 */
                setcolor(7);
                line(390,456,420,456);
                mver();
            }

            if(mclick() == 1 && minlimit(1,0,388,165,430) == 1 && minimizado == 0 && click_procesado == 0 && pagina == 1 && menuayuda == 0)
            {
                sound(256);
                delay(200);
                nosound();
                click_procesado = 1;
                escena_actual++;

                for(i = escena_actual; i < 16; i++)
                {
                    cargar_escena(escena_actual);
                    escena_actual++;
                }
            }

            if(mclick() == 1 && minlimit(1,340,435,390,480) == 1 && minimizado == 1)
            {
                sound(256);
                delay(200);
                nosound();
                /*..............Maximizar */
                minimizado = 0;
                setfillstyle(1,14);
                bar(0,0,639,429);
                delay(100);
                setfillstyle(1,0);
                bar(0,0,639,429);
                delay(200);
                /*----------------------------interfas izquierda----------------------------- */
                setcolor(15);
                setfillstyle(1,1);
                /*..............circulo x */
                circle(150,10,50);
                /*..............limite izquierdo */
                rectangle(0,0,165,430);
                /*..............superior */
                bar(0,0,165,60);
                rectangle(0,0,165,60);
                settextstyle(8,0,3);
                settextjustify(1,1);
                outtextxy(82,25,"AYUDA");
                /*..............ellipse */
                ellipse(150,270,0,360,50,115);
                setfillstyle(1, 3);
                floodfill(180,300,WHITE);
                settextstyle(3,1,4);
                outtextxy(174,270,"COMICS");
                /*		rectangle(168,218,194,325); Hitbox "COMICS" */
                /*..............barra larga izquierda */
                setfillstyle(1,8);
                bar(128,60,165,388);
                setfillstyle(2,3);
                bar(149,60,165,81);
                bar(149,366,165,388);
                rectangle(149,60,165,388);
                rectangle(149,60,165,81);
                rectangle(149,366,165,388);
                setfillstyle(1,3); /*posicion del scroll*/
                switch (scrollbar1) {
                case 1:

                    bar(149,82,164,152);
                    rectangle(149,82,164,152); /*&&&&&&&&&&&&&&&&&&&&&&&&&&*/
                    break;
                case 2:
                    bar(149,152,164,223);
                    rectangle(149,152,164,223);
                    break;
                case 3:
                    bar(149,223,164,294);
                    rectangle(149,223,164,294);
                    break;
                case 4:
                    bar(149,294,164,365);
                    rectangle(149,294,164,365);
                    break;
                }
                /*..............barra ancha mitad */
                setlinestyle(0,1,1);
                setfillstyle(1,9);
                bar(0,60,148,388);
                rectangle(0,60,149,388);

                /*..............inferior */
                setfillstyle(1,1);
                bar(0,388,165,430);
                rectangle(0,388,165,430);
                settextstyle(100,0,1);
                settextjustify(1,1);
                outtextxy(92,408,"PLAY ESCENAS");
                settextstyle(2,0,4 );
                outtextxy(92,418,"(ejecute la pagina)");
                line(26,398,40,406);
                line(26,416,40,406);
                line(26,416,26,398);
                setfillstyle(1,14);
                floodfill(32,407,15);
                /*................recuadros de escena &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
                setfillstyle(1,11);
                for(i = 0; i < 4; i++)
                {
                    bar(0,60+(i*82),128,142+(i*82));
                    rectangle(0,60+(i*82),128,142+(i*82));
                }
                escenas(menu_escena);
                /*----------------------------interfas inferior------------------------------*/
                setfillstyle(1,9);
                /*..............inferior limite */
                setlinestyle(0,1,1);
                bar(0,430,640,478);
                rectangle(0,430,640,480);
                ShowBMP(150, 435,"..\\BIN\\escenas\\teclado.bmp");
                ShowBMP(70, 440,"..\\BIN\\escenas\\mouse.bmp");
                /*..............cuadro 1 */
                setfillstyle(1,8);
                bar(334,430,506,479);
                rectangle(334,430,506,479);
                /*      	Salir2 */
                setlinestyle(0,1,3);
                settextstyle(7,0,4);
                settextjustify(1,2);
                setcolor(12);
                outtextxy(440,436,"X");
                /*      	Maximizar2 */
                setcolor(7);
                rectangle(350,445,380,470);
                /*		Minimizar2 */
                setcolor(15);
                line(390,456,420,456);
                /*..............cuadro 2 */
                setlinestyle(0,1,1);
                setfillstyle(1,3);
                bar(460,430,506,480);
                rectangle(460,430,506,479);
                /*..............circulo minimizar */
                circle(483,454,20);
                settextstyle(12,0,3);
                setlinestyle(0,1,3);
                setfillstyle(1,RED);
                floodfill(485,456,WHITE);
                rectangle(472,448,494,454);
                outtextxy(483,462,"min");
                /*----------------------------interfas derecha------------------------------- */
                /*..............limite derecho */
                setlinestyle(0,1,1);
                setfillstyle(1,9);
                bar(554,0,640,430);
                rectangle(554,0,639,430);
                /*..............inferior derecho */
                setfillstyle(1,8);
                bar(554,164,640,430);
                rectangle(554,164,639,430);
                ShowBMP(554,165,"..\\BIN\\escenas\\waos.bmp");
                rectangle(554,164,639,430);
                /*      	Salir */
                setlinestyle(0,1,3);
                settextstyle(7,0,4);
                settextjustify(1,2);
                setcolor(12);
                outtextxy(600,20,"X");
                /*      	Maximizar */
                setcolor(7);
                rectangle(586,70,610,90);
                /*		Minimizar */
                setcolor(15);
                line(586,110,610,110);
                setlinestyle(0,1,1);
                /*----------------------------pagina y demas------------------------------- */

                /*..............Color circle */
                setfillstyle(1, RED);
                floodfill(190,30,WHITE);
                settextstyle(8, 0, 3);
                settextjustify(1,1);
                outtextxy(180,18,"X");
                /*		rectangle(170,10,188,36); Hitbox de la X  */
                gettime(&temp);

                settextstyle(7,0,4);
                settextjustify(1,2);
                setfillstyle(1,9);
                bar(506,430,640,480);
                rectangle(506,430,639,479);
                itoa(now.ti_hour, hora,10);
                outtextxy(546,435,hora);
                outtextxy(576,432,":");
                itoa(now.ti_min, minutos,10);
                outtextxy(606,435, minutos);
                ShowBMP(554,165,"..\\BIN\\escenas\\waos.bmp");
                mver();
            }

            if(kbhit())
            {
                tecla = getch();
                if(tecla == 'k' || tecla == 'K')
                {
                    sound(512);
                    delay(200);
                    nosound();
                    controles = 1;
                    mocultar();
                }
            }
        } while(controles == 0);

        do
        {
            tecla = getch();

            if(tecla == 'm' || tecla == 'M') /* Cambia a mouse */
            {
                sound(512);
                delay(200);
                nosound();
                controles = 0;
                mver();
                msituar(1,320,10);
            }

            if(menuayuda ==  1 && minimizado == 0)
            {
                if (tecla == '1')
                {
                    sound(216);
                    delay(200);
                    nosound();
                    activado = 1;
                    setfillstyle(1,15);
                    bar(225,14,254,84);
                    rectangle(225,14,254,84);
                    delay(50);
                    bar(225,14,304,184);
                    rectangle(225,14,304,184);
                    delay(50);
                    bar(225,14,404,284);
                    rectangle(225,14,404,284);
                    delay(50);

                    bar(225,14,512,384);
                    rectangle(225,14,505,384);

                }
                if (tecla == '2')
                {
		            sound(516);
                    delay(200);
                    nosound();
                    activado = 1;
                    setfillstyle(1,1);
                    bar(225,14,254,84);
                    rectangle(225,14,254,84);
                    delay(50);
                    bar(225,14,304,184);
                    rectangle(225,14,304,184);
                    delay(50);
                    bar(225,14,404,284);
                    rectangle(225,14,404,284);
                    delay(50);
                    bar(225,14,512,384);
                    rectangle(225,14,512,390);
                    setfillstyle(1,9);
                        bar(225,14,512,65);
                         rectangle(225,14,512,65);
                    rectangle(225,14,512,390);

                    settextstyle(8,0,3);
                settextjustify(1,1);
                setcolor(15);
                outtextxy(370,36,"opciones de mouse");
                settextstyle(2,0,4);
                outtextxy(360,80,"click izquierdo en escenas: carga una escena.");
                outtextxy(368,100,"click izquierdo en comics: reproduce una escena.");
                outtextxy(350,120,"click izquierdo en x: cierra programa.");
                outtextxy(350,140,"click izquierdo en (-) para minimizar.");
                outtextxy(360,160,"click izquierdo en ([]) para maximizar.");
                outtextxy(360,180,"click izquierdo en play: reproducir todo");
                }
            }

            if((tecla == 'a' || tecla == 'A') && minimizado == 0) /* Desplegar menu de ayuda */
            {
                if(menuayuda == 0)
                {
                    sound(256);
                    delay(200);
                    nosound();
                    /*..............Menu de ayuda */
                    setlinestyle(1,0,1);
                    setfillstyle(1,1);
                    bar(0,60,164,388);
                    rectangle(0,60,164,388);
                    setfillstyle(1,9
                                );
                    bar(0,100,164,388);
                    setlinestyle(1,0,1);
                    rectangle(0,100,164,388);
                    setlinestyle(0,0,1);
                    rectangle(0,100,164,388);
                    rectangle(0,140,164,388);
                    rectangle(0,180,164,388);
                    rectangle(0,220,164,388);
                    rectangle(0,260,164,388);
                    rectangle(0,300,164,388);
                    rectangle(0,340,164,388);

                    settextstyle(8,0,3);
                    settextjustify(1,2);
                    setcolor(12);
                    outtextxy(152,60,"X");
                    settextstyle(2,0,6);
                    setcolor(12);
                    outtextxy(72,70,"Menu de ayuda");

                    settextstyle(2,0,4);
                    settextjustify(1,1);
                    setcolor(15);
                    outtextxy(66,120,">Funciones del teclado");
                    outtextxy(60,160,">Funciones del mouse");
                    menuayuda=1;
                }
                else if(menuayuda == 1)
                {
                    /*..............barra larga izquierda */
                    setfillstyle(1,8);
                    bar(128,60,165,388);
                    setfillstyle(2,3);
                    bar(149,60,165,81);
                    bar(149,366,165,388);
                    rectangle(149,60,165,388);
                    rectangle(149,60,165,81);
                    rectangle(149,366,165,388);
                    setfillstyle(1,3); /*&&&&&&&&&&&&&&&&&&&&&*/
                    bar(149,82,164,152);
                    rectangle(149,82,164,152); /*&&&&&&&&&&&&&&&&&&&&&&&&&&*/
                    /*..............barra ancha mitad */
                    setfillstyle(1,9);
                    bar(0,60,148,388);
                    rectangle(0,60,149,388);
                    escenas(menu_escena);
                    menuayuda = 0;
                    if(activado == 1)
                    {

                        setfillstyle(1, 0);

                        bar(222,314,508,384);
                        delay(50);
                        bar(222,214,508,384);
                        delay(50);
                        bar(222,114,508,384);
                        delay(50);
                        bar(222,12,534,414);
                    }
		    activado = 0;
                    if(pagina == 1)
                    {
                        modo_lectura(escena_actual);
                    }
                }
            }

            if(tecla == 'x' || tecla == 'X') /* Salir */
            {
                cleardevice();
                closegraph();
                return;
            }

            if(tecla == 72 && minimizado == 0 && menuayuda == 0) /* Desplazar scroll arriba */
            {
                if((menu_escena-1) >= 0)
                {
                    mocultar();
                    menu_escena -= 1;

                    delay(100);
                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,117+(71*(menu_escena)),164,187+(71*(menu_escena)));
                    rectangle(149,117+(71*(menu_escena)),164,187+(71*(menu_escena)));
                    delay(100);
                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,82+(71*(menu_escena)),164,152+(71*(menu_escena)));
                    rectangle(149,82+(71*(menu_escena)),164,152+(71*(menu_escena)));
                }
                scrollbar1 = menu_escena+1;
                escenas(menu_escena);
                mver();
            }

            if(tecla == 80 && minimizado == 0 && menuayuda == 0) /* Desplazar scroll abajo */
            {
                if((menu_escena+1) < 4)
                {
                    mocultar();
                    menu_escena += 1;

                    if((menu_escena+1) < 3)
                    {
                        delay(100);
                        setfillstyle(1,8);
                        bar(149,82,164,365);
                        rectangle(149,82,165,365);
                        setfillstyle(1,3);
                        bar(149,117+(71*(menu_escena)),164,187+(71*(menu_escena)));
                        rectangle(149,117+(71*(menu_escena)),164,187+(71*(menu_escena)));
                    }
                    delay(100);
                    setfillstyle(1,8);
                    bar(149,82,164,365);
                    rectangle(149,82,165,365);
                    setfillstyle(1,3);
                    bar(149,82+(71*(menu_escena)),164,152+(71*(menu_escena)));
                    rectangle(149,82+(71*(menu_escena)),164,152+(71*(menu_escena)));
                }
                scrollbar1 = menu_escena+1;
                escenas(menu_escena);
            }

            if (tecla == '1' && minimizado == 0 && menuayuda == 0)
            {
                pagina = 1;
                setlinestyle(0,1,0);
                setfillstyle(1,11);
                bar(0,60+(pulsado*82),128,142+(pulsado*82));
                rectangle(0,60+(pulsado*82),128,142+(pulsado*82));
                itoa(((pulsado+1)+(menu_escena*4)), num, 10);
                setcolor(0);
                settextstyle(2, 0, 9);
                settextjustify(1,1);
                outtextxy(64,101+(pulsado*82),num);
                setcolor(WHITE);
                escena_actual = (menu_escena*4) + 0;
                pulsado = 0;
                setlinestyle(0,1,3);
                rectangle(0,61+(0*82),127,141+(0*82));
                setlinestyle(0,1,1);
                modo_lectura(escena_actual);
            }

            if (tecla == '2' && minimizado == 0 && menuayuda == 0)
            {
                pagina = 1;
                setlinestyle(0,1,0);
                setfillstyle(1,11);
                bar(0,60+(pulsado*82),128,142+(pulsado*82));
                rectangle(0,60+(pulsado*82),128,142+(pulsado*82));
                itoa(((pulsado+1)+(menu_escena*4)), num, 10);
                setcolor(0);
                settextstyle(2, 0, 9);
                settextjustify(1,1);
                outtextxy(64,101+(pulsado*82),num);
                setcolor(WHITE);
                escena_actual = (menu_escena*4) + 1;
                pulsado = 1;
                setlinestyle(0,1,3);
                rectangle(0,61+(1*82),127,141+(1*82));
                setlinestyle(0,1,1);
                modo_lectura(escena_actual);
            }

            if ((tecla == 'c' || tecla == 'C') && minimizado == 0)
            {
                pagina = 0;
                setfillstyle(1, 0);

                bar(222,314,508,384);
                delay(50);
                bar(222,214,508,384);
                delay(50);
                bar(222,114,508,384);
                delay(50);
                bar(222,12,534,414);
            }
            if (tecla == '3' && minimizado == 0 && menuayuda == 0)
            {
                pagina = 1;
                setlinestyle(0,1,0);
                setfillstyle(1,11);
                bar(0,60+(pulsado*82),128,142+(pulsado*82));
                rectangle(0,60+(pulsado*82),128,142+(pulsado*82));
                itoa(((pulsado+1)+(menu_escena*4)), num, 10);
                setcolor(0);
                settextstyle(2, 0, 9);
                settextjustify(1,1);
                outtextxy(64,101+(pulsado*82),num);
                setcolor(WHITE);
                escena_actual = (menu_escena*4) + 2;
                pulsado = 2;
                setlinestyle(0,1,3);
                rectangle(0,61+(2*82),127,141+(2*82));
                setlinestyle(0,1,1);
                modo_lectura(escena_actual);
            }
            if (tecla == '4' && minimizado == 0 && menuayuda == 0)
            {
                pagina = 1;
                setlinestyle(0,1,0);
                setfillstyle(1,11);
                bar(0,60+(pulsado*82),128,142+(pulsado*82));
                rectangle(0,60+(pulsado*82),128,142+(pulsado*82));
                itoa(((pulsado+1)+(menu_escena*4)), num, 10);
                setcolor(0);
                settextstyle(2, 0, 9);
                settextjustify(1,1);
                outtextxy(64,101+(pulsado*82),num);
                setcolor(WHITE);
                pulsado = 3;
                escena_actual = (menu_escena*4) + 3;
                setlinestyle(0,1,3);
                rectangle(0,61+(3*82),127,141+(3*82));
                setlinestyle(0,1,1);
                modo_lectura(escena_actual);
            }
            if ((tecla == 'p' || tecla == 'P') && minimizado == 0 && pagina == 1 && menuayuda == 0)
            {
                cargar_escena(escena_actual);
            }
            if ((tecla == 'r' || tecla == 'R') && minimizado == 0 && pagina == 1 && menuayuda == 0)
            {
                for(i = escena_actual; i < 16; i++)
                {

                    escena_actual++;
                    cargar_escena(escena_actual);
                }
            }
            if((tecla == 'b' || tecla == 'B') && minimizado == 1) /* Maximizar */
            {
                /*..............Maximizar */
                minimizado = 0;
                setlinestyle(0,1,1);
                setfillstyle(1,14);
                bar(0,0,639,429);
                delay(100);
                setfillstyle(1,0);
                bar(0,0,639,429);
                delay(200);
                /*----------------------------interfas izquierda----------------------------- */
                setcolor(15);
                setfillstyle(1,1);
                /*..............circulo x */
                circle(150,10,50);
                /*..............limite izquierdo */
                rectangle(0,0,165,430);
                /*..............superior */
                bar(0,0,165,60);
                rectangle(0,0,165,60);
                settextstyle(8,0,3);
                settextjustify(1,1);
                outtextxy(82,25,"AYUDA");
                /*..............ellipse */
                ellipse(150,270,0,360,50,115);
                setfillstyle(1, 3);
                floodfill(180,300,WHITE);
                settextstyle(3,1,4);
                outtextxy(174,270,"COMICS");
                /*		rectangle(168,218,194,325); Hitbox "COMICS" */
                /*..............barra larga izquierda */
                setfillstyle(1,8);
                bar(128,60,165,388);
                setfillstyle(2,3);
                bar(149,60,165,81);
                bar(149,366,165,388);
                rectangle(149,60,165,388);
                rectangle(149,60,165,81);
                rectangle(149,366,165,388);
                setfillstyle(1,3); /*posicion del scroll*/
                switch (scrollbar1) {
                case 1:

                    bar(149,82,164,152);
                    rectangle(149,82,164,152); /*&&&&&&&&&&&&&&&&&&&&&&&&&&*/
                    break;
                case 2:
                    bar(149,152,164,223);
                    rectangle(149,152,164,223);
                    break;
                case 3:
                    bar(149,223,164,294);
                    rectangle(149,223,164,294);
                    break;
                case 4:
                    bar(149,294,164,365);
                    rectangle(149,294,164,365);
                    break;
                }
                /*..............barra ancha mitad */
                setlinestyle(0,1,1);
                setfillstyle(1,9);
                bar(0,60,148,388);
                rectangle(0,60,149,388);

                /*..............inferior */
                setfillstyle(1,1);
                bar(0,388,165,430);
                rectangle(0,388,165,430);
                settextstyle(100,0,1);
                settextjustify(1,1);
                outtextxy(92,408,"PLAY ESCENAS");
                settextstyle(2,0,4 );
                outtextxy(92,418,"(ejecute la pagina)");
                line(26,398,40,406);
                line(26,416,40,406);
                line(26,416,26,398);
                setfillstyle(1,14);
                floodfill(32,407,15);
                /*................recuadros de escena &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
                setfillstyle(1,11);
                for(i = 0; i < 4; i++)
                {
                    bar(0,60+(i*82),128,142+(i*82));
                    rectangle(0,60+(i*82),128,142+(i*82));
                }
                escenas(menu_escena);
                /*----------------------------interfas inferior------------------------------*/
                setfillstyle(1,9);
                /*..............inferior limite */
                setlinestyle(0,1,1);
                bar(0,430,640,478);
                rectangle(0,430,640,480);
                ShowBMP(150, 435,"..\\BIN\\escenas\\teclado.bmp");
                ShowBMP(70, 440,"..\\BIN\\escenas\\mouse.bmp");
                /*..............cuadro 1 */
                setfillstyle(1,8);
                bar(334,430,506,479);
                rectangle(334,430,506,479);
                /*      	Salir2 */
                setlinestyle(0,1,3);
                settextstyle(7,0,4);
                settextjustify(1,2);
                setcolor(12);
                outtextxy(440,436,"X");
                /*      	Maximizar2 */
                setcolor(7);
                rectangle(350,445,380,470);
                /*		Minimizar2 */
                setcolor(15);
                line(390,456,420,456);
                /*..............cuadro 2 */
                setlinestyle(0,1,1);
                setfillstyle(1,3);
                bar(460,430,506,480);
                rectangle(460,430,506,479);
                /*..............circulo minimizar */
                circle(483,454,20);
                settextstyle(12,0,3);
                setlinestyle(0,1,3);
                setfillstyle(1,RED);
                floodfill(485,456,WHITE);
                rectangle(472,448,494,454);
                outtextxy(483,462,"min");
                /*----------------------------interfas derecha------------------------------- */
                /*..............limite derecho */
                setlinestyle(0,1,1);
                setfillstyle(1,9);
                bar(554,0,640,430);
                rectangle(554,0,639,430);
                /*..............inferior derecho */
                setfillstyle(1,8);
                bar(554,164,640,430);
                rectangle(554,164,639,430);
                ShowBMP(554,165,"..\\BIN\\escenas\\waos.bmp");
                rectangle(554,164,639,430);
                /*      	Salir */
                setlinestyle(0,1,3);
                settextstyle(7,0,4);
                settextjustify(1,2);
                setcolor(12);
                outtextxy(600,20,"X");
                /*      	Maximizar */
                setcolor(7);
                rectangle(586,70,610,90);
                /*		Minimizar */
                setcolor(15);
                line(586,110,610,110);
                setlinestyle(0,1,1);
                /*..............Color circle */
                setfillstyle(1, RED);
                floodfill(190,30,WHITE);
                settextstyle(8, 0, 3);
                settextjustify(1,1);
                outtextxy(180,18,"X");
                gettime(&temp);
                settextstyle(7,0,4);
                settextjustify(1,2);
                setfillstyle(1,9);
                bar(506,430,640,480);
                rectangle(506,430,639,479);
                itoa(now.ti_hour, hora,10);
                outtextxy(546,435,hora);
                outtextxy(576,432,":");
                itoa(now.ti_min, minutos,10);
                outtextxy(606,435, minutos);
            }

            if((tecla == 's' || tecla == 'S') && minimizado == 0)
            {
                /*..............Miminizar */
                minimizado = 1;
                pagina = 0;
                /*..............cuadro 2 */
                setfillstyle(1,3);
                bar(460,430,506,480);
                rectangle(460,430,506,479);
                /*..............circulo minimizar */
                circle(483,454,20);
                settextstyle(12,0,3);
                setlinestyle(0,1,3);
                setfillstyle(1,RED);
                floodfill(485,456,WHITE);
                rectangle(472,448,494,454);
                outtextxy(483,462,"min");
                ShowBMP(0,0,"..\\BIN\\fondo.BMP");
                /*      	Maximizar3 */
                setcolor(15);
                rectangle(350,445,380,470);
                /*		Minimizar3 */
                setcolor(7);
                line(390,456,420,456);
            }
        } while(controles == 1);
    } while(1);
}

void escenas(int estado) /*&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&*/
{
    int i = 0;
    setfillstyle(1,11);
    for (i = 0; i < 4; i++){
        bar(0,60+(i*82),128,142+(i*82));rectangle(0,60+(i*82),128,142+(i*82));
    }
    setcolor(0);
    if (estado == 0){
        settextstyle(2, 0, 9);settextjustify(1,1);outtextxy(64,101,"1");outtextxy(64,183,"2");outtextxy(64,265,"3");outtextxy(64,347,"4");
    }
    if (estado == 1){
        settextstyle(2, 0, 9);settextjustify(1,1);outtextxy(64,101,"5");outtextxy(64,183,"6");outtextxy(64,265,"7");outtextxy(64,347,"8");
    }
    if (estado == 2){
        settextstyle(2, 0, 9);settextjustify(1,1);outtextxy(64,101,"9");outtextxy(64,183,"10");outtextxy(64,265,"11");outtextxy(64,347,"12");
    }
    if (estado == 3){
        settextstyle(2, 0, 9);settextjustify(1,1);outtextxy(64,101,"13");outtextxy(64,183,"14");outtextxy(64,265,"15");outtextxy(64,347,"16");
    }
    setcolor(WHITE);
}

void cargar_escena(int escena_actual)
{
    switch (escena_actual)
    {
    case 0:
        ShowBMP(224,14,"..\\BIN\\escenas\\1_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\1_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\1_3.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\1_4.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\1_5.bmp");break;
    case 1:
        ShowBMP(224,14,"..\\BIN\\escenas\\2_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\2_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\2_3.bmp");delay(100);break;
    case 2:
        ShowBMP(224,14,"..\\BIN\\escenas\\3_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\3_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\3_3.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\3_4.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\3_5.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\3_6.bmp");break;
    case 3:
        ShowBMP(224,14,"..\\BIN\\escenas\\4_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\4_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\4_3.bmp");break;
    case 4:
        ShowBMP(224,14,"..\\BIN\\escenas\\5_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\5_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\5_3.bmp");break;
    case 5:
        ShowBMP(224,14,"..\\BIN\\escenas\\6_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\6_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\6_3.bmp");break;
    case 6:
        ShowBMP(224,14,"..\\BIN\\escenas\\7_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\7_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\7_3.bmp");break;
    case 7:
        ShowBMP(224,14,"..\\BIN\\escenas\\8_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\8_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\8_3.bmp");break;
    case 8:
        ShowBMP(224,14,"..\\BIN\\escenas\\9_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\9_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\9_3.bmp");break;
    case 9:
        ShowBMP(224,14,"..\\BIN\\escenas\\10_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\10_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\10_3.bmp");break;
    case 10:
        ShowBMP(224,14,"..\\BIN\\escenas\\11_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\11_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\11_3.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\11_4.bmp");break;
    case 11:
        ShowBMP(224,14,"..\\BIN\\escenas\\12_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\12_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\12_3.bmp");break;
    case 12:
        ShowBMP(224,14,"..\\BIN\\escenas\\13_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\13_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\13_3.bmp");break;
    case 13:
        ShowBMP(224,14,"..\\BIN\\escenas\\14_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\14_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\14_3.bmp");break;
    case 14:
        ShowBMP(224,14,"..\\BIN\\escenas\\15_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\15_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\15_3.bmp");break;
    case 15:
        ShowBMP(224,14,"..\\BIN\\escenas\\16_1.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\16_2.bmp");delay(100);ShowBMP(224,14,"..\\BIN\\escenas\\16_3.bmp");break;
    }

}

void modo_lectura(int escena_actual)
{
                setlinestyle(0,1,1);
    /*..............cuadro 2 */
                setfillstyle(1,3);
                bar(460,430,506,480);
                rectangle(460,430,506,479);
    /*..............circulo minimizar */
                circle(483,454,20);
                settextstyle(12,0,3);
                setlinestyle(0,1,3);
                setfillstyle(1,GREEN);
                floodfill(485,456,WHITE);
                rectangle(475,442,491,456);
                outtextxy(483,462,"max");
                setlinestyle(0,1,1);
    switch (escena_actual){
    case 0:
        ShowBMP(224,14,"..\\BIN\\escenas\\1_5.bmp");break;
    case 1:
        ShowBMP(224,14,"..\\BIN\\escenas\\2_3.bmp");break;
    case 2:
        ShowBMP(224,14,"..\\BIN\\escenas\\3_6.bmp");break;
    case 3:
        ShowBMP(224,14,"..\\BIN\\escenas\\4_3.bmp");break;
    case 4:
        ShowBMP(224,14,"..\\BIN\\escenas\\5_3.bmp");break;
    case 5:
        ShowBMP(224,14,"..\\BIN\\escenas\\6_3.bmp");break;
    case 6:
        ShowBMP(224,14,"..\\BIN\\escenas\\7_3.bmp");break;
    case 7:
        ShowBMP(224,14,"..\\BIN\\escenas\\8_3.bmp");break;
    case 8:
        ShowBMP(224,14,"..\\BIN\\escenas\\9_3.bmp");break;
    case 9:
        ShowBMP(224,14,"..\\BIN\\escenas\\10_3.bmp");break;
    case 10:
        ShowBMP(224,14,"..\\BIN\\escenas\\11_4.bmp");break;
    case 11:
        ShowBMP(224,14,"..\\BIN\\escenas\\12_3.bmp");break;
    case 12:
        ShowBMP(224,14,"..\\BIN\\escenas\\13_3.bmp");break;
    case 13:
        ShowBMP(224,14,"..\\BIN\\escenas\\14_3.bmp");break;
    case 14:
        ShowBMP(224,14,"..\\BIN\\escenas\\15_3.bmp");break;
    case 15:
        ShowBMP(224,14,"..\\BIN\\escenas\\16_3.bmp");break;
    }
}