/*
*	Assignment: Dungeon_Crawler Midtern
*	Author:		Rylan Wallace
*	Class:		CS-3150
*	Date:		10/25/2020
*
*
*
*	*Requirements*
*
*	Code Quality - Added comments and made the user interface easy to use.
*
*	Logical use of multiple files - Used 2 header files as well as 2 additional .cpp files.
*
*	Overall Functionality - Keeps the player on the map by ingoring movements off the map.
*
*	Logical use of enum type - The main hero had a status enum type (alive or dead).
*
*	Proper use of extern variable - gameBoard is made in GameFunctions.cpp and used in 
*		Driver with the use of extern.
*
*	Propper use of static variable - The hero was created as a static variable. We want
*		to use the same hero through the entire program.
*
*	Logical use of a struct - Character was a struct and the main hero was built off it.
*
*	Logical use of random number generator - Used a random number generator for the monsters
*		hit points as well as which monster to display and where monsters and potions are.
*
*/


#include <iostream>
#include "Tiles.h"
#include "GameFunctions.h"
#include "Character.h"
#include <time.h>
#include <stdlib.h>
//Used to wait for the user to push enter to quit the program after win/loss 
#include <limits>

using namespace std;

extern int gameBoard[8][8];

int main()
{
	//Seed the random number generator with time. Used for the monsters hit points
	srand (time(NULL));
	
	//Create the main good guy hero
	typedef character goodguy;
	static goodguy hero;
	hero.name="Super Good Guy";
	hero.health=10;
	hero.xpos=0;
	hero.ypos=0;
	hero.status = alive;
	
	
	//Prints the instructions for the player
	cout<<"-----------------------------------------------------------------------\n";
	cout<<"|Instructions: Move around the map with wasd                          |\n";
	cout<<"|The rooms have been filled randomly with monsters and health potions |\n";
	cout<<"|Get to the bottom right room before you run out of health            |\n";
	cout<<"|You start with 10 health points                                      |\n";
	cout<<"|Every time you fight a monster you will lose 1-5 health points       |\n";
	cout<<"|After you go into a room, there wont be anything there again         |\n";
	cout<<"|Good Luck!!                                                          |\n";
	cout<<"-----------------------------------------------------------------------\n";
	
	//Print all the tiles with the hero in the top left position
	print_tiles(hero.xpos,hero.ypos);
	
	//Print out the heros health as well as the instructions below the tiles
	cout << "\n\nHealth= " << hero.health;
	cout<<"\n\nUse WSAD to move up, down, left and right(type quit to exit the game)\n*If you can not see the instructions at the top, please expand the window and scrooll up*\n";
	
	//Create a 2D array for the gameboard. This is where the monsters/potion will be placed
	
	//Fill the game board with monsters and potion
	fill_gameboard();
	
	//Any string is taken from the user but only wasd will move the user.
	std::string input;
	
	//Keep playing the game unless the user types quit
	while(input != "quit")
	{
		cin >> input;
		
		//Move the hero based on the above user-entered string
		hero = move_character(input, hero);
	
		//Clear the screen
		if(system("cls"))
		{
			system("clear");
		}
		
		//Checks what room the hero is in
		//If 1 is returned there is a monster in the room
		//If 2 is returned there is medecine in the room
		int spot = check_spot(gameBoard, hero.xpos, hero.ypos);
		
		//If a monster is in the room fight the momster
		if(spot==1)
		{
			//Clear the screen
			if(system("cls"))
			{
				system("clear");
			}
			
			//Tell the user a monster was found and display a monster
			cout<< "A monster was found!\n";
			display_monster();
			//Give the monster a random hit point value between 1 and 5
			int monster_hit_points = rand()%5+1;
			//Let the user know how much health was lost from the fight
			cout<<"You fought and lost " << monster_hit_points << " health" << endl;
			hero.health -= monster_hit_points;
			//Ensure the hero is still alive
			statusCheck(hero);
			//If the hero is dead, display you died!!
			//If the hero is alive, continue with the game
			if(statusCheck(hero)==1)
			{
				cout<<" _  _  _____  __  __    ____  ____  ____  ____  /\\/\\"<<endl;
				cout<<"( \\/ )(  _  )(  )(  )  (  _ \\(_  _)( ___)(  _ \\ )()("<<endl;
				cout<<" \\  /  )(_)(  )(__)(    )(_) )_)(_  )__)  )(_) )\\/\\/"<<endl;
				cout<<" (__) (_____)(______)  (____/(____)(____)(____/ ()()"<<endl;
				
				//Waits for the user to push enter then quits the program
				cout<<"Press <enter> to quit\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin.get();
				return 1;
			}
		}
		
		//If there is potion in the room, the user gains 1 health point.
		else if(spot==2)
		{
			cout << "You found some potion +1 Health\n";
			hero.health++;
		}
		
	
		cout << "";
		//Re-print the gameboard tiles
		print_tiles(hero.xpos, hero.ypos);
		
		//Display the heros health and instructions for the user
		cout << "\n\nHealth= " << hero.health;
		cout<<"\n\nUse WSAD to move up, down, left and right(type quit to exit the game)\n";
		
		//If the user gets to the bottom right of the screen without dying, display You Win!!!
		if(hero.xpos ==7 && hero.ypos==7)
		{
			if(system("cls"))
			{
				system("clear");
			}
			
			cout << " _  _  _____  __  __    _    _  ____  _  _ /\\/\\/\\"<<endl;
			cout << "( \\/ )(  _  )(  )(  )  ( \\/\\/ )(_  _)( \\( ))()()("<<endl;
			cout << " \\  /  )(_)(  )(__)(    )    (  _)(_  )  ( \\/\\/\\/"<<endl;
			cout << " (__) (_____)(______)  (__/\\__)(____)(_)\\_)()()()"<<endl;
			
			//Waits for the user to push enter then quits the program
			cout<<"Press <enter> to quit\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cin.get();
			return 1;
		}
		cout<< endl;
	}
}
