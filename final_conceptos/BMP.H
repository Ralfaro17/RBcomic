/* Library to load BMP images */

#include <alloc.h>
#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>


struct BMP
{
    char Type[2];                 /*File type. Set to "BM".*/
    unsigned long Size;           /*Size in BYTES of the file.*/
    unsigned long Reserved;      /*Reserved. Set to zero.*/
    unsigned long OffSet;        /*Offset to the data.*/
    unsigned long headsize;      /*Size of rest of header. Set to 40.*/
    unsigned long Width;         /*Width of bitmap in pixels.*/
    unsigned long Height;        /*  Height of bitmap in pixels.*/
    unsigned int  Planes;        /*Number of Planes. Set to 1.*/
    unsigned int  BitsPerPixel;  /*Number of Bits per pixels.*/
    unsigned long Compression;   /*Compression. Usually set to 0.*/
    unsigned long SizeImage;      /*Size in bytes of the bitmap.*/
    unsigned long XPixelsPreMeter;  /*Horizontal pixels per meter.*/
    unsigned long YPixelsPreMeter;  /*Vertical pixels per meter.*/
    unsigned long ColorsUsed;       /*Number of colors used.*/
    unsigned long ColorsImportant;  /*Number of "important" colors.*/
};

int ShowBMP(int x, int y, char* FileName)
{

	int b,a;
	struct  BMP Obj;

	unsigned char* Datas;
	int in=0;
	unsigned char c=0;

	FILE * fp;

	fp = fopen(FileName,"rb");

	if(!fp)
	{
		printf("Error : Unable to open file ..");
		exit(0);
	}

	fread(&Obj, sizeof(Obj), 1, fp);

	if(Obj.BitsPerPixel!=4)  /* This isn't a 16 color bmp we can read; */
	{
		fclose(fp);
		printf("Error : File format not supported ..");
		exit(0);
	};


	fseek(fp,Obj.OffSet,SEEK_SET);

	Datas=(unsigned char*) calloc(Obj.Width/2+1, sizeof(unsigned char));


	for(b=Obj.Height;b>=0;b--)
	{
		fread(Datas, sizeof(unsigned char), Obj.Width/2, fp);
		c=0;
		in=0;

		for(a=0;a<=Obj.Width;a+=2)
		{
			c = (Datas[in] | 0x00) >>4;
	    	putpixel(a+x,b+y,c);

	    	c = (Datas[in] | 0xF0) & 0x0F;
	    	putpixel(a+1+x,b+y,c);

	    	in++;
		}

	}


	free (Datas);
	fclose(fp);
	return 1;
}
