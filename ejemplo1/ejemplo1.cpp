#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;




enum direccion 
{
	arriba,
	abajo,
	izquierda,
	derecha

};


void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void sincursor()
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	cursor.dwSize = 2;
	cursor.bVisible = FALSE;

	SetConsoleCursorInfo(hcon, &cursor);
}

void pintar(int x, int y, direccion direscogida)
{
	switch (direscogida)
	{
	case derecha:
		gotoxy(x, y);
		printf("%c%c%c%c%c", 220, 219, 219, 219, 220);
		gotoxy(x, y + 1);
		printf("%c%c%c%c%c", 219, 219, 220, 220, 220);
		gotoxy(x, y + 2);
		printf(" %c%c%c", 223, 223, 223);
		gotoxy(x - 1, y);
		printf(" ");
		gotoxy(x - 1, y + 1);
		printf(" ");
		break;
	case arriba: // muñeco de para arriba
		
		gotoxy(x, y);
		printf("%c%c %c%c", 220, 219, 219, 220);
		gotoxy(x, y + 1);
		printf("%c%c%c%c%c", 219, 219, 220, 219, 219);
		gotoxy(x, y + 2);
		printf(" %c%c%c ", 223, 223, 223);
		gotoxy(x, y + 3); //borrado de rastro
		printf("     ");
		break;
	case izquierda:
		// imagen muñeco a la izquierda y borrado de rastro
	
		gotoxy(x, y);
		printf("%c%c%c%c%c", 220, 219, 219, 219, 220);
		gotoxy(x, y + 1);
		printf("%c%c%c%c%c", 220, 220, 220, 219, 219);
		gotoxy(x, y + 2);
		printf(" %c%c%c ", 223, 223, 223);
		gotoxy(x + 5, y);
		printf(" ");
		gotoxy(x + 5, y + 1);
		printf(" ");
		break;
	case abajo: // muñeco para abajo y borrado de rastro
		
		gotoxy(x, y);
		printf("%c%c%c%c%c", 220, 219, 219, 219, 220);
		gotoxy(x, y + 1);
		printf("%c%c %c%c", 219, 219, 219, 219);
		gotoxy(x, y + 2);
		printf(" %c %c ", 223, 223);
		gotoxy(x, y - 1); //borrado de rastro
		printf("     ");
		break;
	}
}

int main()
{

	sincursor();
	int x = 7, y = 7;
	direccion dir = abajo;
	char tecla ='m';
	//posicion inicial del muñeco derecha
	pintar(x, y, dir);

	

	//detección de teclas

	

	
	while (true)
	{
		switch (dir)
		{
		case arriba:
			Sleep(100);
			break;
		case abajo:
			Sleep(100);
			break;
		case izquierda:
			Sleep(50);
			break;
		case derecha:
			Sleep(50);
			break;
		}
		pintar(x, y, dir);
		if (_kbhit())
		{
			tecla = _getch();		//si se oprime una tecla kbhit se convierte en true y entra, el getch captura la tecla y deja el kbhit en false
			switch (tecla)
			{
			case 'd':

				if (dir == derecha)
				{
					x++;
				}
				else
				{
					dir = derecha;
				}
				break;


			case 'a':
				if (dir == izquierda)
				{
					x--;
				}
				else
				{
					dir = izquierda;
				}
				break;
			case 'w':
				if (dir == arriba)
				{
					y--;
				}
				else
				{
					dir = arriba;
				}
				break;
			case 's':
				if (dir == abajo)
				{
					y++;
				}
				else
				{
					dir = abajo;
				}
				break;

			}
		}
		else 
		{
			 // si no se oprime una tecla entra 
			switch (tecla)
			{
			case 'd': 
				x++;
				break;
			case 'a':
				x--;
				break;
			case 'w':
				y--;
				break;

			case 's':
				y++;
				break;
			default:break;


			}
		}

		
		
		

	}

    return 0;
}

