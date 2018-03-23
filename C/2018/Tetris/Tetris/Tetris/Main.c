/*
 * Tetris
 *
 * Author: Leonardo Vencovsky
 * Created on 23/03/2018
 *
 * Tetris Homework
 *
 * Using custom Array for rows. Sorry for CamelCase... Java wins.
 *
 */

#include <stdio.h>
// #include <unistd.h> - UNIX
#include <windows.h>
#include "include\CArray.h"
#include "include\Tetris.h"

// #define CLEAR_SCREEN "clear"
#define CLEAR_SCREEN "cls"

int main()
{
	CArray **tetris = getTetris();
	int i;

	for (i = 0; i < 4; i++) {
		addTetrisBit(tetris, i, 0);
	}
	for (i = 0; i < 6; i++) {
		displayTetris(tetris);
		Sleep(700);
		system(CLEAR_SCREEN);
		fallTetris(tetris);
	}
	displayTetris(tetris);


	free(tetris);
	printf("\n");
	return 0;
}
