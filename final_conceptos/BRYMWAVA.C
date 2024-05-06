#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<mouse.h>
#include<stdlib.h>


	void main(void){

	int points[]={320,242,285,239,257,224,245,212,239,194,243,208,222,197,210,183,211,164,224,157,225,99,420,99,415,157,428,164,430,183,417,198,395,208,400,194,394,212,381,225,355,238,320,242};
	int points1[]={252,159,241,131,232,149,230,177,223,158,216,161,209,106,239,60,294,38,344,38,401,60,431,106,425,161,417,158,409,177,408,149,397,131,387,159};
	int points2[]={308,225,320,221,331,225};

	int points3[]={287,325,300,252,343,252,352,325};

	int  points4[]={313,431,305,432,290,381,288,368,286,325,320,324,320,347,316,347,314,432};
	int  points5[]={353,324,352,372,349,388,336,432,324,432,324,348,321,348,320,325,353,325};
	int points44[]={320,348,316,348,296,430,286,428,282,380,286,324,320,324,320,345,320,348};

	int pierna2[]={320,348,320,325,353,325,356,359,357,382,354,428,344,430,322,350,320,348};
	int pierna3[]={320,348,320,325,353,325,356,359,357,382,354,428,344,430,322,350,320,348};

	int points6[]={309,250,320,256,332,250,331,242,308,242,309,250};

	int points7[]={305,270,284,313,286,326,280,323,280,334,270,340,265,333,275,298,299,252,306,273};
	int points8[]={334,271,348,295,356,315,355,325,360,322,360,333,370,341,375,333,366,300,342,252};

	int points9[]={343,279,398,240,411,241,406,236,417,235,424,224,418,220,381,233,340,254,330,254};
	int points10[]={295,275,240,240,227,242,231,236,221,235,214,225,222,222,259,238,268,242,331,269};

	int adaptador=DETECT,modo,x,y,i,z=0,w=0,velocidad_movimiento=10;int contador=0, contador1=0,contador2=0, contador3=0; char key;

	initgraph(&adaptador,&modo,"C:\\TC20\\BIN");
	msituar(1,310,240);
	setbkcolor(7);
	   //* CUELLO *//
	    setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
	    setfillstyle(1,14);
	    fillpoly(6,points6);

		//* brazos *//
		 setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,14);
		fillpoly(10,points8);
		fillpoly(10,points7);
	   //* TORZO *//
		   setcolor(4);
	    setfillstyle(1,4);
	    fillpoly(4,points3);
	    //* PIERNAS *//
	setfillstyle(1,8);
	setcolor(0);
	fillpoly(9,points4);
	fillpoly(9,points5);
	    //* CARA FONDO *//
		setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,14);
		fillpoly(22,points);
	      // CABELLO *//
		setcolor(8);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,8);
		fillpoly(18,points1);
	      //* PESTANAS *//
	       setcolor(4);
		rectangle(251,160,301,168);
		rectangle(339,160,388,168);
		setfillstyle(1,8);
		bar(251,160,301,168);
		bar(339,160,388,168);

	       //* cejas *//
	       setfillstyle(1,4);
		setcolor(WHITE);
		bar(302,152,250,150);
		bar(337,152,389,150);
	       //* boca *//
		setcolor(4);
	       drawpoly(3,points2);
		//* ojos *//
		setlinestyle(SOLID_LINE,0,3);
		ellipse(280,180,0,360,5,10);
		ellipse(357,180,0,360,5,10);
		setfillstyle(SOLID_FILL, 8);
		floodfill(357,179,4);
		floodfill(282,181,4);
		//* interfas*//
		setfillstyle(1,3);
		bar(0,0,115,480);
		bar(512,2,640,480);

		setfillstyle(1,11);
		bar(0,450,640,480);
		bar(0,0,640,17);
		setcolor(8);
		setfillstyle(1,5);
		rectangle(0,0,640,17);
		rectangle(0,450,640,480);

		setfillstyle(1,3);
		rectangle(0,0,640,17);



		setlinestyle(1,0,3);
		line(513,16,513,450);
		line(116,448,116,16);


	      //* botones*//
		setfillstyle(1,1);
		bar(11,119,100,236);
		bar(11,249,100,362);
		bar(539,249,627,362);
		bar(539,119,627,236);


		setlinestyle(0,0,3);
		rectangle(11,119,100,236);
		rectangle(11,249,100,362);
		rectangle(539,249,627,362);
		rectangle(539,119,627,236);
		settextstyle(2,0,4); setcolor(15);
		outtextxy(33,173,"Brazo 1");
		outtextxy(33,299,"pierna 1");
		outtextxy(556,180,"Brazo 2");
		outtextxy(556,303,"pierna 2");

	do{

		settextstyle(10,0,1);
		outtextxy(120,20,"AVATAR");
	     rectangle(1,1,639,477);
	     mlimit(1,1,1,636,472);
		mver();

	if(mclick()==1){



	if(minlimit(1,539,249,627,362)==1){
		mocultar();
		 setfillstyle(1,9);
		bar(539,249,627,362);
		settextstyle(2,0,5);
		 setcolor(15);
		outtextxy(556,502,"pierna 2");
		delay(200);


		switch(contador3){
		case 0:
		setcolor(7);
		setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,7);

		fillpoly(9,points5);

		 setcolor(8);

		setfillstyle(1,8);
		fillpoly(9,pierna2);
		setcolor(8);
		bar(300+z,330+w,342+z,344+w);
		 contador3=1;
		break;

		case 1:
		setcolor(7);
			setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,7);
		fillpoly(9,pierna2);

		 setcolor(8);
			setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,8);
		fillpoly(9,points5);
		setcolor(8);
		contador3=0;
		bar(290+z,320+w,342+z,348+w);
		break;
		}
		   setcolor(4);
	    setfillstyle(1,4);
	    fillpoly(4,points3);

		}
		  if (contador3==3){
		  fillpoly(9,pierna3);
		  }

	if(minlimit(1,11,249,100,362)==1){
		mocultar();
		 setfillstyle(1,9);
		bar(11,249,100,362);
		settextstyle(2,0,5);
		 setcolor(15);
		outtextxy(28,299,"pierna 1");
		delay(200);


		switch(contador2){
		case 0:
		setcolor(7);
	setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,7);

		fillpoly(9,points4);

		 setcolor(8);

		setfillstyle(1,8);
		fillpoly(9,points44);
		setcolor(8);
		 contador2=1; bar(300+z,330+w,342+z,344+w);
		break;

		case 1:
		setcolor(7);
			setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,7);
		fillpoly(9,points44);

		 setcolor(8);
			setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,8);
		fillpoly(9,points4);
		setcolor(8);
		contador2=0;  bar(300+z,320+w,352+z,349+w);
		break;
		}
	     setcolor(4);
	    setfillstyle(1,4);
	    fillpoly(4,points3);
		}

      if(minlimit(1,11,119,100,236)==1){
		mocultar();
		 setfillstyle(1,9);
		bar(11,119,100,236);
		settextstyle(2,0,5); setcolor(15);
		outtextxy(28,173,"Brazo 1");
		delay(200);


		switch(contador){
		case 0:
		setcolor(7);
		setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,7);
		fillpoly(10,points7);

		 setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,14);
		fillpoly(10,points10);
		setcolor(6);
		 contador=1;
		break;

		case 1:
		setcolor(7);
		setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,7);
		fillpoly(10,points10);

		 setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,14);
		fillpoly(10,points7);
		setcolor(6);
		contador=0;
		break;
		}
		   setcolor(4);
	    setfillstyle(1,4);
	    fillpoly(4,points3);

		}




		if(minlimit(1,539,119,627,236)==1){
		mocultar();
		setfillstyle(1,9);
		bar(539,119,627,236);
		settextstyle(2,0,5); setcolor(15);
		outtextxy(550,180,"Brazo 2");
		delay(200);

		switch(contador1){
		case 0:
		setcolor(7);
		setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,7);
		fillpoly(10,points8);

		 setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,14);
		fillpoly(10,points9);
		setcolor(6);
		 contador1=1;
		break;

		case 1:
		setcolor(7);
		setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,7);
		fillpoly(10,points9);

		 setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,14);
		fillpoly(10,points8);
		setcolor(6);
		contador1=0;
		break;
		}
		   setcolor(4);
	    setfillstyle(1,4);
	    fillpoly(4,points3);

		}

		setcolor(8);
		//* botones*//
		setfillstyle(1,1);
		bar(11,119,100,236);
		bar(11,249,100,362);
		bar(539,249,627,362);
		bar(539,119,627,236);


		setlinestyle(0,0,3);
		rectangle(11,119,100,236);
		rectangle(11,249,100,362);
		rectangle(539,249,627,362);
		rectangle(539,119,627,236);
		settextstyle(2,0,4); setcolor(15);
		outtextxy(33,173,"Brazo 1");
		outtextxy(33,299,"pierna 1");
		outtextxy(556,180,"Brazo 2");
		outtextxy(556,303,"pierna 2");

		  }



  if(kbhit()){
    key=getch();
    mocultar();
  switch (key) {
	    case 72:
	    //*Mueve hacia la arriba*//
	    if(w>-16){
		for (i = 1; i < 22 * 2; i += 2) {
		    points[i] -= velocidad_movimiento;}
		for (i = 1; i < 18 * 2; i += 2) {
		    points1[i] -= velocidad_movimiento;  }
		for (i = 1; i < 3 * 2; i += 2) {
		    points2[i] -= velocidad_movimiento;    }
		for (i = 1; i < 4 * 2; i += 2) {
		    points3[i] -= velocidad_movimiento;   }
		for (i = 1; i < 9 * 2; i += 2) {
		    points4[i] -= velocidad_movimiento;   }
		for (i = 1; i < 9 * 2; i += 2) {
		    points5[i] -= velocidad_movimiento;   }
		for (i = 1; i < 9 * 2; i += 2) {
		    points44[i] -= velocidad_movimiento;  }
		for (i = 1; i < 9 * 2; i += 2) {
		    pierna2[i] -= velocidad_movimiento;  }
		for (i = 1; i < 6 * 2; i += 2) {
		    points6[i] -=  velocidad_movimiento-10; }
		for (i = 1; i < 22 * 2; i += 2) {
		    points7[i] -= velocidad_movimiento;  }
		for (i = 1; i < 10 * 2; i += 2) {
		    points8[i] -= velocidad_movimiento; }
		for (i = 1; i < 10 * 2; i += 2) {
		    points9[i] -= velocidad_movimiento;}
		for (i = 1; i < 10 * 2; i += 2) {
		    points10[i] -= velocidad_movimiento;
		}
		w -=velocidad_movimiento;
		}
		break;
		//*Mueve hacia la abajo*//
	    case 80:
	    if(w<10){
		for (i = 1; i < 22 * 2; i += 2) {
		    points[i] += velocidad_movimiento;
		}
			for (i = 1; i < 18 * 2; i += 2) {
		    points1[i] += velocidad_movimiento;  }
		for (i = 1; i < 3 * 2; i += 2) {
		    points2[i] += velocidad_movimiento;    }
		for (i = 1; i < 4 * 2; i += 2) {
		    points3[i] += velocidad_movimiento;   }
		for (i = 1; i < 9 * 2; i += 2) {
		    points4[i] += velocidad_movimiento;   }
		for (i = 1; i < 9 * 2; i += 2) {
		    points5[i] += velocidad_movimiento;   }
		for (i = 1; i < 9 * 2; i += 2) {
		    points44[i] += velocidad_movimiento;  }
		    for (i = 1; i < 9 * 2; i += 2) {
		    pierna2[i] += velocidad_movimiento;  }
		for (i = 1; i < 6 * 2; i += 2) {
		    points6[i] += velocidad_movimiento-10;  }
		for (i = 1; i < 22 * 2; i += 2) {
		    points7[i] += velocidad_movimiento;  }
		for (i = 1; i < 10 * 2; i += 2) {
		    points8[i] += velocidad_movimiento; }
		for (i = 1; i < 10 * 2; i += 2) {
		    points9[i] += velocidad_movimiento;}
		for (i = 1; i < 10 * 2; i += 2) {
		    points10[i] += velocidad_movimiento;
		}
		w +=velocidad_movimiento;
		}
		break;
		//*Mueve hacia la izquierda*//
	    case 75:
	    if(z>-90){
		for (i = 0; i < 22 * 2; i += 2) {
		    points[i] -= velocidad_movimiento;
		}
		for (i = 0; i < 18 * 2; i += 2) {
		    points1[i] -= velocidad_movimiento;  }
		for (i = 0; i < 3 * 2; i += 2) {
		    points2[i] -= velocidad_movimiento;    }
		for (i = 0; i < 4 * 2; i += 2) {
		    points3[i] -= velocidad_movimiento;   }
		for (i = 0; i < 9 * 2; i += 2) {
		    points4[i] -= velocidad_movimiento;   }
		for (i = 0; i < 9 * 2; i += 2) {
		    points5[i] -= velocidad_movimiento;   }
		for (i = 0; i < 9 * 2; i += 2) {
		    points44[i] -= velocidad_movimiento;  }
		    for (i = 0; i < 9 * 2; i += 2) {
			pierna2[i] -= velocidad_movimiento;  }
		for (i = 0; i < 6 * 2; i += 2) {
		    points6[i] -= velocidad_movimiento-10;  }
		for (i = 0; i < 22 * 2; i += 2) {
		    points7[i] -= velocidad_movimiento;  }
		for (i = 0; i < 10 * 2; i += 2) {
		    points8[i] -= velocidad_movimiento; }
		for (i = 0; i < 10 * 2; i += 2) {
		    points9[i] -= velocidad_movimiento;}
		for (i = 0; i < 10 * 2; i += 2) {
		    points10[i] -= velocidad_movimiento;
		}
		z -=velocidad_movimiento;
		}

		break;

		//*Mueve hacia la derecha*//
	    case 77:
	    if(z<80){
		for (i = 0; i < 22 * 2; i += 2) {
		    points[i] += velocidad_movimiento;
		}
		for (i = 0; i < 18 * 2; i += 2) {
		    points1[i] += velocidad_movimiento;  }
		for (i = 0; i < 3 * 2; i += 2) {
		    points2[i] += velocidad_movimiento;    }
		for (i = 0; i < 4 * 2; i += 2) {
		    points3[i] += velocidad_movimiento;   }
		for (i = 0; i < 9 * 2; i += 2) {
		    points4[i] += velocidad_movimiento;   }
		for (i = 0; i < 9 * 2; i += 2) {
		    points5[i] += velocidad_movimiento;   }
		for (i = 0; i < 9 * 2; i += 2) {
		    points44[i] +=velocidad_movimiento;  }
		for (i = 0; i < 9 * 2; i += 2) {
		    pierna2[i] +=velocidad_movimiento;  }
		for (i = 0; i < 6 * 2; i += 2) {
		    points6[i] += velocidad_movimiento-10;  }
		for (i = 0; i < 22 * 2; i += 2) {
		    points7[i] += velocidad_movimiento;  }
		for (i = 0; i < 10 * 2; i += 2) {
		    points8[i] += velocidad_movimiento; }
		for (i = 0; i < 10 * 2; i += 2) {
		    points9[i] += velocidad_movimiento;}
		for (i = 0; i < 10 * 2; i += 2) {
		    points10[i] += velocidad_movimiento;
		}
		z +=velocidad_movimiento;
		}
		break;
		}

	   setfillstyle(1,7);
	  bar(118,19,511,447);
	   //* CUELLO *//
	    setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
	    setfillstyle(1,14);
	    fillpoly(6,points6);

		//* brazos *//
		 setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,14);
		fillpoly(10,points8);
		fillpoly(10,points7);
	   //* TORZO *//
		   setcolor(4);
	    setfillstyle(1,4);
	    fillpoly(4,points3);
	    //* PIERNAS *//
	setfillstyle(1,8);
	setcolor(0);
	fillpoly(9,pierna2);
	fillpoly(9,points44);
	    //* CARA FONDO *//
		setcolor(6);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,14);
		fillpoly(22,points);
	      // CABELLO *//
		setcolor(8);
	       setlinestyle(SOLID_LINE,0,3);
		setfillstyle(1,8);
		fillpoly(18,points1);
	      //* PESTANAS *//
	       setcolor(4);
		rectangle(251+z,160+w,301+z,168+w);
		rectangle(339+z,160+w,388+z,168+w);
		setfillstyle(1,8);
		bar(251+z,160+w,301+z,168+w);
		bar(339+z,160+w,388+z,168+w);

	       //* cejas *//
	       setfillstyle(1,4);
		setcolor(WHITE);
		bar(302+z,152+w,250+z,150+w);
		bar(337+z,152+w,389+z,150+w);
	       //* boca *//
		setcolor(4);
	       drawpoly(3,points2);
		//* ojos *//
		setlinestyle(SOLID_LINE,0,3);
		ellipse(280+z,180+w,0,360,5,10);
		ellipse(357+z,180+w,0,360,5,10);
		setfillstyle(SOLID_FILL, 8);
		floodfill(357+z,179+w,4);
		floodfill(282+z,181+w,4);
		//* PIERNAS *//
	setfillstyle(1,7);
	setcolor(0);
	fillpoly(9,pierna2);
	fillpoly(9,points44);
	//* TORZO *//
		   setcolor(4);
	    setfillstyle(1,4);
	    fillpoly(4,points3);
		//* PIERNAS *//
	setfillstyle(1,8);
	setcolor(0);
	fillpoly(9,points4);
	fillpoly(9,points5);


	       mver();
		}


	setcolor(8);
		}while(key !=13);
		cleardevice();
		closegraph();

	     }
