#ifndef CHARACTER_H
#define CHARACTER_H

/*
*	Assignment: Dungeon_Crawler Midtern
*	Author:		Rylan Wallace
*	Class:		CS-3150
*	Date:		10/25/2020
*/

#include<string>

enum STATUS {alive, dead};

//Uses struct for the hero
struct character
{
	std::string name;
	int health;
	STATUS status;
	int xpos;
	int ypos;
};

//Moves the character based on the user inputed string
character move_character(std::string, character);

//Checks if the character is alive or dead
STATUS statusCheck(character);

#endif
