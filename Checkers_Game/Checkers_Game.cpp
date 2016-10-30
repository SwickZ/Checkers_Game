//Pre-processor directives
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

//class of the program
class CheckersGame
{
public:
	//int GameBoard[64];//declaring the array 'GameBoard[64]' 
	//int Gamepiece;//declaring variable Gamepiece
	//int Choice;//Declaring variable Choice
	int Player;//declaring variable that collects and decides which Player turn is it
	int UserPlayFromI;//declaring variable for initial game-piece ROW position
	int UserPlayFromII;//declaring variable for initial game-piece COLUMN position
	int UserPlayToI;//declaring variable for final game-piece ROW position
	int UserPlayToII;//declaring variable for final game-piece COLUMN position
	char GameBoard[8][8];//declaring a two dimensional array of size 64

						 //Function that contains the Introduction Statement
	void GreetingMessage()
	{
		cout << "Welcome To" << "\n" << "** Tobiloba Komolafe **" << "\n" << "** Ejiro Afokoghene **";
		cout << "\n" << "** Daniel Isang **" << "\n" << "Checkers Game" << "\n" << "\n";
		cout << "This game has a game-board of 8X8 dimension" << "\n";
		cout << "Every player is required to capture their opponents piece when the opportunity" << "\n";
		cout << "arises" << "\n";
		cout << "Do not Make a move on the cells containing '#' " << "\n";
		cout << "Player1 uses game-piece-X" << "\n";
		cout << "Player2 uses game-piece-M" << "\n";
		cout << "\n" << "\n";
	}

	//Function that decides what character is to be contained in the spaces of the array GameBoard[8][8] 
	void BoardFormat()
	{
		//initializing for-loop
		for (int i = 1; i < 9; i++)//declaring and setting boundary for ROW 'i'
		{
			for (int j = 1; j < 9; j++)//declaring and setting boundary for COLUMN 'j'
			{
				//Condition for the ROW less than 4 (which contains player1 Game-pieces)
				if (i < 4)
				{
					//If ROW is EVEN and COLUMN is ODD
					if (i % 2 == 0)
					{
						if (j % 2 != 0)
						{
							GameBoard[i][j] = 'X';//display in the spaces of GameBoard[of rows less than 4 and even][of odd columns],display 'X' in them
						}
					}
					//If ROW is ODD and COLUMN is ODD
					if (i % 2 != 0)
					{
						if (j % 2 != 0)
						{
							GameBoard[i][j] = '#';//display in the spaces of GameBoard[of rows less than 4 and odd][of odd columns],display '#' in them
						}
					}
					//If ROW is EVEN and COLUMN is EVEN
					if (i % 2 == 0)
					{
						if (j % 2 == 0)
						{
							GameBoard[i][j] = '#';//display in the spaces of GameBoard[of rows less than 4 and even][of even columns],display '#' in them
						}
					}

					//If ROW is ODD and COLUMN is EVEN
					if (i % 2 != 0)
					{
						if (j % 2 == 0)
						{
							GameBoard[i][j] = 'X';//display in the spaces of GameBoard[of rows less than 4 and odd][of even columns],display 'X' in them
						}
					}
				}
				//Condition for the ROW greater than 5 (which contains player2 Game-pieces)
				if (i > 5)
				{
					if (i % 2 != 0) //If ROW is ODD and COLUMN is EVEN
					{
						if (j % 2 == 0)
						{
							GameBoard[i][j] = 'M';//display in the spaces of GameBoard[of rows greater than 5 and odd][of even columns],display 'M' in them
						}
					}

					if (i % 2 == 0) //If ROW is EVEN and COLUMN is EVEN
					{
						if (j % 2 == 0)
						{
							GameBoard[i][j] = '#';//display in the spaces of GameBoard[of rows greater than 5 and even][of even columns],display '#' in them
						}
					}

					if (i % 2 != 0) //If ROW is ODD and COLUMN is ODD
					{
						if (j % 2 != 0)
						{
							GameBoard[i][j] = '#';//display in the spaces of GameBoard[of rows greater than 5 and odd][of odd columns],display '#' in them
						}
					}

					if (i % 2 == 0) //If ROW is EVEN and COLUMN is EVEN
					{
						if (j % 2 != 0)
						{
							GameBoard[i][j] = 'M';//display in the spaces of GameBoard[of rows greater than 5 and even][of odd columns],display 'M' in them
						}
					}
				}


				//Condition for the ROW equal 5 (which contains empty spaces and invalid spots '#')
				if (i == 5)
				{
					//If ROW is ODD and COLUMN is EVEN
					if (i % 2 != 0)
					{
						if (j % 2 == 0)
						{
							GameBoard[i][j] = ' ';//display in the spaces of GameBoard[of row equal to 5 and odd][of even columns],display ' ' in them
						}
					}
					//If ROW is ODD and COLUMN is ODD
					if (i % 2 != 0)
					{
						if (j % 2 != 0)
						{
							GameBoard[i][j] = '#';//display in the spaces of GameBoard[of row equal to 5 and odd][of odd columns],display '#' in them
						}
					}
				}
				//Condition for the ROW equal 4 (which contains empty spaces and invalid spots '#')
				if (i == 4)
				{
					if (i % 2 == 0) //If ROW is EVEN and COLUMN is ODD
					{
						if (j % 2 != 0)
						{
							GameBoard[i][j] = ' ';//display in the spaces of GameBoard[of row equal to 5 and even][of odd columns],display ' ' in them
						}

					}
					if (i % 2 == 0) //If ROW is EVEN and COLUMN is EVEN
					{
						if (j % 2 == 0)
						{
							GameBoard[i][j] = '#';//display in the spaces of GameBoard[of row equal to 5 and even][of even columns],display '#' in them
						}

					}
				}

			}
		}
		//For-loop ends
	}

	//Function that sets the location format of the array and displays the characters 
	void MainBoard()
	{
		cout << "Main-Board" << "\n";
		cout << "   1   2   3   4   5   6   7   8  " << endl;
		cout << "  --- --- --- --- --- --- --- --- " << endl;
		cout << "1| " << GameBoard[1][1] << " | " << GameBoard[1][2] << " | " << GameBoard[1][3] << " | " << GameBoard[1][4] << " | " << GameBoard[1][5] << " | " << GameBoard[1][6] << " | " << GameBoard[1][7] << " | " << GameBoard[1][8] << " | " << endl;
		cout << "  --- --- --- --- --- --- --- --- " << endl;
		cout << "2| " << GameBoard[2][1] << " | " << GameBoard[2][2] << " | " << GameBoard[2][3] << " | " << GameBoard[2][4] << " | " << GameBoard[2][5] << " | " << GameBoard[2][6] << " | " << GameBoard[2][7] << " | " << GameBoard[2][8] << " | " << endl;
		cout << "  --- --- --- --- --- --- --- --- " << endl;
		cout << "3| " << GameBoard[3][1] << " | " << GameBoard[3][2] << " | " << GameBoard[3][3] << " | " << GameBoard[3][4] << " | " << GameBoard[3][5] << " | " << GameBoard[3][6] << " | " << GameBoard[3][7] << " | " << GameBoard[3][8] << " | " << endl;
		cout << "  --- --- --- --- --- --- --- --- " << endl;
		cout << "4| " << GameBoard[4][1] << " | " << GameBoard[4][2] << " | " << GameBoard[4][3] << " | " << GameBoard[4][4] << " | " << GameBoard[4][5] << " | " << GameBoard[4][6] << " | " << GameBoard[4][7] << " | " << GameBoard[4][8] << " | " << endl;
		cout << "  --- --- --- --- --- --- --- --- " << endl;
		cout << "5| " << GameBoard[5][1] << " | " << GameBoard[5][2] << " | " << GameBoard[5][3] << " | " << GameBoard[5][4] << " | " << GameBoard[5][5] << " | " << GameBoard[5][6] << " | " << GameBoard[5][7] << " | " << GameBoard[5][8] << " | " << endl;
		cout << "  --- --- --- --- --- --- --- --- " << endl;
		cout << "6| " << GameBoard[6][1] << " | " << GameBoard[6][2] << " | " << GameBoard[6][3] << " | " << GameBoard[6][4] << " | " << GameBoard[6][5] << " | " << GameBoard[6][6] << " | " << GameBoard[6][7] << " | " << GameBoard[6][8] << " | " << endl;
		cout << "  --- --- --- --- --- --- --- --- " << endl;
		cout << "7| " << GameBoard[7][1] << " | " << GameBoard[7][2] << " | " << GameBoard[7][3] << " | " << GameBoard[7][4] << " | " << GameBoard[7][5] << " | " << GameBoard[7][6] << " | " << GameBoard[7][7] << " | " << GameBoard[7][8] << " | " << endl;
		cout << "  --- --- --- --- --- --- --- --- " << endl;
		cout << "8| " << GameBoard[8][1] << " | " << GameBoard[8][2] << " | " << GameBoard[8][3] << " | " << GameBoard[8][4] << " | " << GameBoard[8][5] << " | " << GameBoard[8][6] << " | " << GameBoard[8][7] << " | " << GameBoard[8][8] << " | " << endl;
		cout << endl;
		cout << endl;
	}

	//Function that manages tokens and calls the fuvtion PlayerMoves
	void UserPlay()
	{
		int UserChoice;//declaring token that collects input from user, decides if the entire function continues or stops
					   //initializing Do-While loop
		do
		{
			cout << "Enter 1 for Player1 || 2 for Player2 turn" << "\n";
			cout << "Player:";
			//collecting input from the user for the token 'Player'(decides which player condition to initialize)
			cin >> Player;
			cout << "\n" << "\n";

			cout << "Select the Game-Piece you want to move" << "\n";
			cout << "Enter the ROW of the Game-piece you want to move from:";
			cin >> UserPlayFromI;//collecting input from the user for the token 'UserPlayFromI'(initial Row position of the game-piece)
			cout << "\n";

			cout << "Enter the COLUMN of the Game-piece you want to move from:";
			cin >> UserPlayFromII;//collecting input from the user for the token 'UserPlayFromII'(initial Column position of the game-piece)
			cout << "\n" << "\n";

			cout << "Select the position you want to move your Game-Piece to" << "\n";
			cout << "Enter the ROW you want to move the Game-piece to:";
			cin >> UserPlayToI;//collecting input from the user for the token 'UserPlayToI'(intended Row position of the game-piece)
			cout << "\n";
			cout << "Enter the COLUMN you want to move the Game-piece to:";
			cin >> UserPlayToII;//collecting input from the user for the token 'UserPlayToII'(intended Column position of the game-piece)
			cout << "\n";

			//calling te fuction/method PlayersMoves 
			PlayersMoves();
			cout << "Do you want to Continue or Exit this Program" << "\n";
			cout << "1-Continue, 0-Exit" << "\n";
			cout << "Choice:";//
			cin >> UserChoice;//token that collects input from user, decides if the entire function continues or stops
		} while (UserChoice != 0);
		//Finalizing Do-While loop
	}

	void PlayersMoves()
	{
		//Player1 Movement Control
		if (Player == 1)//if player1 is playing,
		{
			if (GameBoard[UserPlayFromI][UserPlayFromII] == 'X')//if player1 must moves his game-piece 'X' and only that,
			{
				if (GameBoard[UserPlayToI][UserPlayToII] == ' ')//if where his playing is empty,
				{
					if (UserPlayFromII != 1 || UserPlayFromII != 8)//if where is playing is not on column 1 or 8,
					{
						if (UserPlayToI == UserPlayFromI + 1)//if the row is playing to is 1 more than the previous row,
						{
							if (UserPlayToII == UserPlayFromII - 1 || UserPlayToII == UserPlayFromII + 1)//if the column he is playing to is 1 more than his previous row or if the column he is playing to his 1 less from the previous column,
							{//then display...
								GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//his previous position should be empty,
								GameBoard[UserPlayToI][UserPlayToII] = 'X';//his new position must contain his transfered game-piece 'X',
								MainBoard();//all this changes should be computed on the board(Mainboard function called).
							}
						}

						//code for capture for player1
						else if (GameBoard[UserPlayToI - 1][UserPlayToII - 1] = 'M')//if 1 less from the row he and 1 less from his new column contains 'M',
						{
							if (UserPlayToI - UserPlayFromI == 2)//if the difference of the old row and from the new row equals 2
							{
								if (UserPlayToII - UserPlayFromII == 2 || UserPlayFromII - UserPlayToII == 2)//if the difference of the old column from the column or difference of new column frolm old is 2,
								{//then display...
									GameBoard[UserPlayToI][UserPlayToII] = 'X';//on the desired position the new board position contains 'X',
									GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//on the previos position,the cell should be empty
									GameBoard[UserPlayToI - 1][UserPlayToII - 1] = ' ';//the game-piece position you are capturing should be empty
									MainBoard();//display all this changes on the board(called board function).
								}
							}
						}

						//code for capture fro player1 II
						else if (GameBoard[UserPlayToI - 1][UserPlayToII + 1] = 'M')//if the position you the game-piece you are trying to capture contains 'M',
						{
							if (UserPlayToI - UserPlayFromI == 2)//if the difference between the old row from the new is 2,
							{
								if (UserPlayToII - UserPlayFromII == 2 || UserPlayFromII - UserPlayToII == 2)//if the difference of the old column from the new is 2,
								{//then display...
									GameBoard[UserPlayToI][UserPlayToII] = 'X';//the desired position cell should contain 'X',
									GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//the previous position should be empty,
									GameBoard[UserPlayToI - 1][UserPlayToII + 1] = ' ';//the position of the game-piece you are capturing shoud be empty
									MainBoard();//all this changes should be updated on the board(Called MainBoard Function). 
								}
							}
						}
					}
					//regular movement for column1
					else if (UserPlayFromII == 1)//if he is moving his game-piece from column1, 
					{
						if (UserPlayToI == UserPlayFromI + 1)//if the new row is 1 more than the preious row,
						{
							if (UserPlayToII == UserPlayFromII + 1)//if the new column is 1 more than the previous row,
							{//then display...
								GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//the old position should be empty,
								GameBoard[UserPlayToI][UserPlayToII] = 'X';//the new position should contain the game-piece 'X',
								MainBoard();//compute all this changes on te board(called MainBoard Function).
							}
						}
					}
					//regular movement for column8
					else if (UserPlayFromII == 8)//if player1 is moving from column8,
					{
						if (UserPlayToI == UserPlayFromI + 1)//if the new row is 1 more than the previous the old column,
						{
							if (UserPlayToII == UserPlayFromII - 1)//if the new column is 1 less from the old column,
							{//then display...
								GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//the previous cell should be empty,
								GameBoard[UserPlayToI][UserPlayToII] = 'X';//the desired position should contain the transfered game-piece 'X',
								MainBoard();//computing all this changes on the board(called MainBoard function).
							}
						}
					}
				}
			}
			//Check for player1 moves including capture checks 
			//Any move made by player1 that does follow the ones stated above its invalid
			else
			{
				cout << "Invalid Move Player1!!!" << "\n";
			}
		}

		//Player2 Moves Control
		if (Player == 2)//if she selects player2,
		{
			if (GameBoard[UserPlayFromI][UserPlayFromII] == 'M')//if the current position contains player2 game-piece 'M',
			{
				if (GameBoard[UserPlayToI][UserPlayToII] == ' ')//if the new position is empty,
				{
					if (UserPlayFromII != 1 || UserPlayFromII != 8)//if the columns are not 1 or 8,
					{
						if (UserPlayToI == UserPlayFromI - 1)//if the new row is 1 less from the previous row, 
						{
							if (UserPlayToII == UserPlayFromII - 1 || UserPlayToII == UserPlayFromII + 1)//if the new column is 1 less from te previous column or the new column is 1 more than the previous column
							{//then display...
								GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//the previous cell should be empty,
								GameBoard[UserPlayToI][UserPlayToII] = 'M';//the desired position should contain the transfered game-piece 'M'
								MainBoard();//compute this changes on the board(called MainBoard Function)
							}
						}

						//1st part for capture
						else if (GameBoard[UserPlayToI + 1][UserPlayToII + 1] = 'X')//or if on the array Gameboard,1 more than the desired row and one more than the desired column contains the game-piece 'X', 
						{
							if (UserPlayFromI - UserPlayToI == 2)//if the difference between the old row and the new row is 2
							{
								if (UserPlayToII - UserPlayFromII == 2 || UserPlayFromII - UserPlayToII == 2)//if the difference of the old column from the new column is 2 or the new column from the old is 2,
								{//the display...
									GameBoard[UserPlayToI][UserPlayToII] = 'M';//then the desired osition sould contain player2 game-piece 'M',
									GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//the old position should be empty,
									GameBoard[UserPlayToI + 1][UserPlayToII + 1] = ' ';//the position of the game-piece she is trying to capture should be empty,
									MainBoard();//compute all this on the board(called MainBoard function).
								}
							}
						}

						//2nd part for capture
						else if (GameBoard[UserPlayToI + 1][UserPlayToII - 1] = 'X')//if 1 more than the desired position's row and one more than its column of the array contains the game-piece 'X',
						{
							if (UserPlayFromI - UserPlayToI == 2)//if the difference of the new row from the old row is 2
							{
								if (UserPlayToII - UserPlayFromII == 2 || UserPlayFromII - UserPlayToII == 2)//if the difference of the old column from the new column or the new column from the old is 2,
								{//then display...
									GameBoard[UserPlayToI][UserPlayToII] = 'M';//the disired position should contain the player2 game-piece 'M',
									GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//the previous position should be empty
									GameBoard[UserPlayToI + 1][UserPlayToII - 1] = ' ';//the position of the game-piece she is trying to capture should be empty
									MainBoard();//compute all this on the MainBoard(Called MainBoard function)
								}
							}
						}
					}
					//Regular Movement for player2
					else if (UserPlayFromII == 1)//if the game-piece column she is trying to move from is 1,
					{
						if (UserPlayToI == UserPlayFromI - 1)//if the desired row is 1 less from the old row,
						{
							if (UserPlayToII == UserPlayFromII + 1)//if the desired column is 1 more than the old column,
							{//then display...
								GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//the old cell of the array should be empty
								GameBoard[UserPlayToI][UserPlayToII] = 'M';//the desired position should contain player2 game-piece 'M'
								MainBoard();//compute all this on the board (called MainBoard function)
							}
						}
					}
					//Regular Movement for player2
					else if (UserPlayFromII == 8)//if the game-piece column she is trying to move from is 8,
					{
						if (UserPlayToI == UserPlayFromI - 1)//if the desired row is 1 less from the old row,
						{
							if (UserPlayToII == UserPlayFromII - 1)//if the desired column is 1 less from the old column,
							{//then display
								GameBoard[UserPlayFromI][UserPlayFromII] = ' ';//the old cell of the array should be empty
								GameBoard[UserPlayToI][UserPlayToII] = 'M';//the desired position should contain player2 game-piece 'M'
								MainBoard();//compute all this on the board (called MainBoard function)
							}
						}
					}
				}
			}
			//Check for player2 moves including capture checks 
			//any move made by player2 except from the ones stated above, the move is invalid
			else
			{
				cout << "Invalid Move Player2!!!" << "\n";
			}
		}
	}

	//Function that declares the winner of the game
	void WinScenario()
	{
		//if the game-piece of player1 is found in any ex-position of player2 game-piece then player1 wins
		if (GameBoard[8][1] == 'X' || GameBoard[8][3] == 'X' || GameBoard[8][5] == 'X' || GameBoard[8][7] == 'X')
		{
			cout << "Congratulations Player1! You have Won" << "\n";
		}
		//if the game-piece of player2 is found in any ex-position of player1 game-piece then player2 wins
		if (GameBoard[1][2] == 'Y' || GameBoard[1][4] == 'Y' || GameBoard[1][6] == 'Y' || GameBoard[1][8] == 'Y')
		{
			cout << "Congratulations Player2! You have Won" << "\n";
		}
	}

};

//Main Function begins
int main()
{
	CheckersGame MyCheckersGame;
	MyCheckersGame.GreetingMessage();//calling the Function GreetingMessage
	MyCheckersGame.BoardFormat();//calling the Function BoardFormat
	MyCheckersGame.MainBoard();//calling the Function MainBoard
	MyCheckersGame.UserPlay();//calling the Function UserPlay
	MyCheckersGame.WinScenario();//calling the Function WinScenario


								 //Hold Output Screen
	system("pause");
	return 0;
}
//Main Function Ends