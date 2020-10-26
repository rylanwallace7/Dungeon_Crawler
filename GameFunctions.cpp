/*
*	Assignment: Dungeon_Crawler Midtern
*	Author:		Rylan Wallace
*	Class:		CS-3150
*	Date:		10/25/2020
*/

#include "GameFunctions.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int gameBoard[8][8] = {};

//Fills the gameboard with enemys and potion
void fill_gameboard()
{
	srand (time(NULL));
	//1 is bad guy, 2 is health, 3 is nothing
	for(int i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			gameBoard[i][j]= rand()%3+1;
		}
	}
	
	gameBoard[0][0] = 3;
}

//Checks to see what is in the room the hero is in
int check_spot(int gameBoard[8][8], int x, int y)
{
	//If there is a monster return 1
	if(gameBoard[x][y]==1)
	{
		gameBoard[x][y]=3;
		return 1;
	}
	//If there is a potion return 2
	else if(gameBoard[x][y]==2)
	{
		gameBoard[x][y]=3;
		return 2;
	}
	//If there is nothing in the room, say nothin here and return 3
	else
		cout<<"Nothing Here\n";
		return 3;
}

//Displays one of three monsters
void display_monster()
{
	srand (time(NULL));
	int monster_num = rand()%3+1;
	
	if(monster_num==1)
	{
		cout<<"		,     \\    /       ,        "<<endl;
		cout<<"	       / \\    )\\__/(     / \\       "<<endl;
		cout<<"	      /   \\  (_\\  /_)   /   \\      "<<endl;
		cout<<"	 ____/_____\\__\\@  @/___/_____\\____ "<<endl;
		cout<<"	|             |\\../|              |"<<endl;
		cout<<"	|              \\VV/               |"<<endl;
		cout<<"	|        ----------------         |"<<endl;
		cout<<"	|_________________________________|"<<endl;
		cout<<"	 |    /\\ /      \\\\       \\ /\\    | "<<endl;
		cout<<"	 |  /   V        ))       V   \\  | "<<endl;
		cout<<"	 |/     `       //        '     \\| "<<endl;
		cout<<"	 `              V                ' "<<endl;
	}
	if(monster_num==2)
	{
		cout<<"                   _ ___                /^^\\ /^\\  /^^\\_"<<endl;
		cout<<"                 _@)@) \\            ,,/ '` ~ `'~~ ', `\\."<<endl;
		cout<<"  _/o\\_ _ _ _/~`.`...'~\\        ./~~..,'`','',.,' '  ~:"<<endl;
		cout<<" / `,'.~,~.~  .   , . , ~|,   ,/ .,' , ,. .. ,,.   `,  ~\\_"<<endl;
		cout<<"( ' _' _ '_` _  '  .    , `\\_/ .' ..' '  `  `   `..  `,   \\_"<<endl;
		cout<<" ~V~ V~ V~ V~ ~\\ `   ' .  '    , ' .,.,''`.,.''`.,.``. ',   \\_"<<endl;
		cout<<"  _/\\ /\\ /\\ /\\_/, . ' ,   `_/~\\_ .' .,. ,, , _/~\\_ `. `. '.,  \\_"<<endl;
		cout<<" < ~ ~ '~`'~'`, .,  .   `_: ::: \\_ '      `_/ ::: \\_ `.,' . ',  \\_"<<endl;
		cout<<"  \\ ' `_  '`_    _    ',/ _::_::_ \\ _    _/ _::_::_ \\   `.,'.,`., \\-,-,-,_,_,"<<endl;
		cout<<"   `'~~ `'~~ `'~~ `'~~  \\(_)(_)(_)/  `~~' \\(_)(_)(_)/ ~'`\\_.._,._,'_;_;_;_;_;"<<endl;
	}
	if(monster_num==3)
	{
		    cout<<"              ______________  " <<endl;
            cout<<"        ,===:'.,            `-._  " <<endl;  
            cout<<"             `:.`---.__         `-._ " <<endl;   
            cout<<"               `:.     `--.         `." <<endl;   
            cout<<"                 \\.        `.         `." <<endl;  
            cout<<"         (,,(,    \\.         `.   ____,-`.," <<endl;   
            cout<<"      (,'     `/   \\.   ,--.___`.' " <<endl;  
            cout<<"  ,  ,'  ,--.  `,   \\.;'         ` " <<endl;   
            cout<<"   `{D, {    \\  :    \\; " <<endl;   
            cout<<"     V,,'    /  /    //" <<endl;    
            cout<<"     j;;    /  ,' ,-//.    ,---. " <<endl;    
            cout<<"     \\;'   /  ,' /  _  \\  /  _  \\   ,'/ " <<endl;   
            cout<<"           \\   `'  / \\  `'  / \\  `.' / " <<endl;    
            cout<<"            `.___,'   `.__,'   `.__,'" <<endl;
		
	}
}

