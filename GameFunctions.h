#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

/*
*	Assignment: Dungeon_Crawler Midtern
*	Author:		Rylan Wallace
*	Class:		CS-3150
*	Date:		10/25/2020
*/

#include<string>
#include <stdlib.h>

extern int gameBoard[8][8];

//Fills the gameboard with enemys and potion
void fill_gameboard();

//Checks to see what is in the room the hero is in
int check_spot(int[8][8], int, int);

//Displays one of three mosnters
void display_monster();

#endif
