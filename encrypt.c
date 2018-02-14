#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void main()
{
	char fname[20], ch;
	FILE *fps, *fpt;
	printf("Enter a text file to encrypt : ");
	gets(fname);
	fps=fopen(fname, "r");
	if(fps==NULL)
	{
		printf("Error in opening file");
		printf("\nPress any key to exit");
		getch();
		exit(1);
	}
	fpt=fopen("temp.txt", "w");
	if(fpt==NULL)
	{
		printf("Error in creating temp.txt file");
		fclose(fps);
		printf("\nPress any key to exit");
		getch();
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fps);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+40;
			fputc(ch,fpt);
		}
	}
	fclose(fps);
	fclose(fpt);
	fps=fopen(fname, "w");
	if(fps==NULL)
	{
		printf("Error in opening source file");
		printf("\nPress any key to exit");
		getch();
		exit(3);
	}
	fpt=fopen("temp.txt", "r");
	if(fpt==NULL)
	{
		printf("Error in opening temp.txt file");
		fclose(fps);
		printf("\nPress any key to exit");
		getch();
		exit(4);
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
			fputc(ch, fps);
		}
	}
	printf("File %s encrypted successfully", fname);
	printf("\nPress any key to exit");
	fclose(fps);
	fclose(fpt);
	getch();
}