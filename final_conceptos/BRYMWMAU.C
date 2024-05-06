#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<mouse.h>

int salir(void){
closegraph();
}
void main(void){
 int adaptador=DETECT,modo,x,y,contador,z,v,w=0,e=0;
 initgraph(&adaptador,&modo,"C:\\TC20\\bin");
 mlimit(1,1,1,636,472);
 setbkcolor(3);
	   do{

		mver();
		x=mxpos(1);
		y=mypos(1);

	if(mclick()==1){
	contador=1 ;
	if(minlimit(1,z+18,v,z+180,v+150)==1 && w==1){
	contador=0;
	e=1;
	if(z>260){z=z-250;}
	setfillstyle(1,15);
	bar(z+178,v+20,z+270,v+40);
	setfillstyle(1,8);
	bar(z+180,v+20,z+178,v+40);
	bar(z+270,v+20,z+273,v+40);
	outtextxy(z+190,v+23,"OPCION X");
	}
	if(minlimit(1,z+178,v+20,z+270,v+40)==1 && e==1){
	contador=0;
	salir();
	}
	setcolor(GREEN);
	}

//* -------------------------------------------------------------------------*//
    //*   click derecho abrir ventana*//
	if(mclick()==2){contador=3;}

       //*click derecho validar y ejecutar*//
	delay(100);
	setcolor(8);

       if(contador+w==3){
	mocultar();
	if(x>470){ x=x-180;}
	if(y>330){ y=y-150; }

       setfillstyle(1,15);
       bar(x+18,y,x+180,y+150);
       setfillstyle(1,8);

       bar(x+18,y+20,x+170,y+20);
       bar(x+18,y+40,x+170,y+40);
       bar(x+18,y+60,x+170,y+60);
       bar(x+18,y+80,x+170,y+80);
       bar(x+18,y+100,x+170,y+100);
       bar(x+18,y+120,x+170,y+120);
       bar(x+180,y,x+178,y+150);
       bar(x+18,y+1,x+180,y);

       settextstyle(2,0,5);
       outtextxy(x+30,y+5,"MENU DEL MAUSE");
       settextstyle(2,0,4);
       outtextxy(x+30,y+23,"Actualizar");
       outtextxy(x+30,y+43,"Ordenar");
       outtextxy(x+30,y+63,"Fondo de escritorio");
       outtextxy(x+30,y+83,"Nuevo");
       outtextxy(x+30,y+103,"Personalizar");
       outtextxy(x+30,y+123,"configuracion de pantalla");

       z=x;
       v=y;
       w=1;
       contador=0;
       mver();
      }
//* -------------------------------------------------------------------------*//
       //limpiar con cualquier clip//
       if(contador+w==4||contador+w==2){
       w=0; e=0;
       mocultar();
       cleardevice();}
		}while(!kbhit());
		closegraph();

	}
