#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	char ch,fname[20];
	FILE *fps, *fpt;
	printf("Enter file name of the text file which you have encrypted earlier to decrypt : ");
	gets(fname);
	fps=fopen(fname, "w");
	if(fps==NULL)
	{
		printf("Error in opening source file");
		printf("\nPress any key to exit");
		getch();
		exit(7);
	}
	fpt=fopen("temp.txt", "r");
	if(fpt==NULL)
	{
		printf("Error in opening temp.txt file");
		fclose(fps);
		printf("\nPress any key to exit");
		getch();
		exit(9);
	}
	while(1)
	{
		ch=fgetc(fpt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch-40;
			fputc(ch, fps);
		}
	}
	printf("File %s decrypted successfully",fname);
	printf("\nPress any key to exit");
	fclose(fps);
	fclose(fpt);
	getch();
}