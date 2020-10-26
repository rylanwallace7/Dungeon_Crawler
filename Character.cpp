/*
*	Assignment: Dungeon_Crawler Midtern
*	Author:		Rylan Wallace
*	Class:		CS-3150
*	Date:		10/25/2020
*/

#include "Character.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

//Moves the character based on the user inputed string
//Will only move with wasd. It will ignore all other inputs
character move_character(std::string input, character hero)
{
	if(input=="w")
		{
			if(hero.xpos>0)
				hero.xpos--;
		}
		
		if(input=="s")
		{
			if(hero.xpos<7)
				hero.xpos++;
		}
		
		if(input=="d")
		{
			if(hero.ypos<7)
				hero.ypos++;
		}
		
		if(input=="a")
		{
			if(hero.ypos>0)
				hero.ypos--;
		}
		
		return hero;
}

//Determine if the character should be alive or dead
STATUS statusCheck(character c)
{
	if (c.health > 0) return c.status=alive; else return c.status=dead;

}