/*  <LIBRARY MANAGEMENT- The program manages the records of a library ,it basically demonstrates the working of a library>
    Copyright (C) <2015>  <Saloni Gandhi>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/
#include"head.h"
void gotoxy(int x,int y)
{
	printf("%c[%d;%df",0x1B,y,x);
}
void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
void returnfunc(void)
{
	{	gotoxy(10,23);
		printf(" Press 'x' to return to main menu");
	}
	if(getchar()=='x') 

	mainmenu();
	

	
}

int t(void) //for time
{
	time_t t;
	time(&t);
	printf("Date and time:%s\n",ctime(&t));
	
	return 0 ;
}

