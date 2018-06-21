#include <stdio.h>
#include <time.h>
#include <windows.h>

#define DESL_MAX 40

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = (short)x;
	coord.Y = (short)y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int rgb()
{
	int colors[4] = {FOREGROUND_BLUE, FOREGROUND_GREEN, FOREGROUND_RED, FOREGROUND_INTENSITY};

	return colors[rand() % 4] | colors[rand() % 4] | colors[rand() % 4];
}

int main()
{
	srand(time(NULL));

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	while (1)
	{
		system("cls");

		int x = rand() % DESL_MAX + rand() % DESL_MAX;
		int y = rand() % DESL_MAX;

		gotoxy(x,     y);printf("\n");
		gotoxy(x, y + 1);printf("##########     ####     #######         ##                 #########  ##########  ##\n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y + 2);printf("##########   ########   ########       ####               #########   ##########  ##\n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y + 3);printf("###         ###    ###  ###    ##     ##  ##              ####        ###         ##\n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y + 4);printf("###         ###    ###  ###    ##     ##  ##              ####        ###         ##\n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y + 5);printf("##########  ###    ###  ###     ##    ##  ##               ########   ###         ##\n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y + 6);printf("##########  ###    ###  ###     ##   ########   ########   #########  ##########  ##\n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y + 7);printf("###         ###    ###  ###     ##   ##    ##   ########     #######  ##########  ##\n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y + 8);printf("###         ###    ###  ###    ##    ##    ##                   ####  ###         ##\n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y + 9);printf("###         ###    ###  ###    ##   ###    ###                  ####  ###           \n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y +10);printf("###          ########   ########    ###    ###             #########  ##########    \n");SetConsoleTextAttribute(hConsole, rgb());
		gotoxy(x, y +11);printf("###            ####     #######     ###    ###            #########   ##########  ##\n");SetConsoleTextAttribute(hConsole, rgb());

		Sleep(200);
	}
}
