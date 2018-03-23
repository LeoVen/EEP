/*
 * Tetris.h
 *
 * Author: Leonardo Vencovsky
 * Created on 23/03/2018
 *
 * Header for Tetris Functions in C
 *
 */

#ifndef TETRIS_H
#define TETRIS_H

#include <stdio.h>
#include <stdlib.h>

	/* Returns a 10 x 10 tetris-like structure
	 *
	 * @Returns [ CArray** ] Returns array of pointers to CArray Structure
	 */
	CArray** getTetris();

	/* Adds 1 bit to tetris matrix
	 *
	 * @Param [ CArray ***tetris ] Tetris Reference
	 * @Param [ int posx ] X position
	 * @Param [ int posy ] Y position
	 *
	 * @Returns [ int ] Return Code (see code table)
	 */
	int addTetrisBit(CArray **tetris, int posx, int posy);

	int displayTetris(CArray **tetris);

	int fallTetris(CArray **tetris);

	int shiftArray(CArray *array);

#endif