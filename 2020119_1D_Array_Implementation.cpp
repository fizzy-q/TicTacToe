#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>


using namespace std;


int check( char[]);                                     // function to check winner
void board( char[] ,char user , char comp);             // function to display board
void clear(char square[]);                              // function to clear the previous input


// timer function for the 5 sec delay in computer's turn

int counter(int n)
{	
    int	timer=5;
    
    while(timer>0)
    {
        cout << timer <<endl;
        Sleep(1000);
        --timer;
    }
}

int main()
{
	char square[10] = {'0','1','2','3','4','5','6','7','8','9'};
	int player = 1,i,choice;
	int timer;

	char mark;                            // symbol variable
	int returnto;                         // variable for play again option
	
	do
	{
		
	char tic , toe;                           // Declaration of variables to take the value of signs used for user and computer turn
	
	cout << "\t\t HUMAN VS COMPUTER TIC TAC TOE" << endl;
	
	cout << "\nChoose a symbol (\"X\" or \"O\") for your game: ";
	cin >> tic;                                   // variable for user
	
	if (tic=='X')                              
	{
		toe='O';
	}
	
	else if(tic=='O')                            // variable for computer
	{
		toe='X';
	}
	
	do
	{
		board(square,tic,toe);

		if( player % 2 == 1 )
			player=1;
		else
			player=2;


// for player 2 i.e computer
	if( player == 2 )
	{
		cout << "Players  " << player << endl;
		
		counter(timer);
		
		srand(time(0));
		choice = rand()%9 + 1;           // to prevent zero
		
		mark = toe;
		int turn=1;
		int placed=0;
			
		while(placed==0)
		{

		if (choice == 1 && square[1] == '1')
		{
			square[1] = mark;
			placed=1;
		}
		else if (choice == 2 && square[2] == '2')
		{	
				square[2] = mark;
				placed=1;
		}
		else if (choice == 3 && square[3] == '3')
		{
			square[3] = mark;
			placed=1;
		}
		else if (choice == 4 && square[4] == '4')
		{
			square[4] = mark;
			placed=1;
		}
		else if (choice == 5 && square[5] == '5')
		{
			square[5] = mark;
			placed=1;
		}
		else if (choice == 6 && square[6] == '6')
		{
			square[6] = mark;
			placed=1;
		}
		else if (choice == 7 && square[7] == '7')
		{
			square[7] = mark;
			placed=1;
		}
		else if (choice == 8 && square[8] == '8')
		{
			square[8] = mark;
			placed=1;
		}
		else if (choice == 9 && square[9] == '9')
		{
			square[9] = mark;
			placed=1;
		}

		else
		{
			srand(time(0));
			choice = rand()%9 + 1;
		}
	}
    	i=check(square);
		player++;

		board(square,tic,toe);
	}

// for player 1 i.e user
	else if(player==1)
	{
		cout << "Player " << player << ", enter a number b/w 1 to 9:  ";
		cin >> choice;
		mark=tic;

	if (choice == 1 && square[1] == '1')

		square[1] = mark;
	else if (choice == 2 && square[2] == '2')

		square[2] = mark;
	else if (choice == 3 && square[3] == '3')

		square[3] = mark;
	else if (choice == 4 && square[4] == '4')
		
		square[4] = mark;
	else if (choice == 5 && square[5] == '5')
		
		square[5] = mark;
	else if (choice == 6 && square[6] == '6')
		
		square[6] = mark;
	else if (choice == 7 && square[7] == '7')
		
		square[7] = mark;
	else if (choice == 8 && square[8] == '8')
		
		square[8] = mark;
	else if (choice == 9 && square[9] == '9')
		
		square[9] = mark;
	else
		{
			cout<<"Invalid move , try again ";			
				player--;
				Sleep(1000);
		}
		
	i=check(square);

	player++;

     }  
	}	
	while(i==-1);
		board(square,tic , toe);
		
	if(i==1)

		cout<<"Congratulation! \nPlayer "<<--player<<" win ";
	else{
	
		cout<<" Draw";
      }
		 cout << endl; 
		 
		 cout << endl; 
    cout << "Enter 1 to PLAY AGAIN or enter 2 to END program." << endl;
    cin >> returnto;
	
	clear(square);
   
    }
	while(returnto == 1);
   	
return 0; 

}

// function for the displaying tictactoe board
void board(char square[], char tic , char toe)
{

	system ("cls");
	
	cout << "Player 1 ("<<tic<<")  -  Computer ("<<toe<<")" <<endl;
	cout << endl;


	cout << "\t\t\t     |     |     " << endl;
	cout << "\t\t\t  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "\t\t\t_____|_____|_____" << endl;
	cout << "\t\t\t     |     |     " << endl;

	cout << "\t\t\t  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "\t\t\t_____|_____|_____" << endl;
	cout << "\t\t\t     |     |     " << endl;

	cout << "\t\t\t  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "\t\t\t     |     |     " << endl << endl;
}


int check(char square[])
{
	// for checking rows
	if (square[1] == square[2] && square[2] == square[3])

		return 1;                                                       // return 1 user wins
	else if (square[4] == square[5] && square[5] == square[6])

		return 1;
	else if (square[7] == square[8] && square[8] == square[9])

		return 1;
		
	// for checking columns
	else if (square[1] == square[4] && square[4] == square[7])

		return 1;
	else if (square[2] == square[5] && square[5] == square[8])

		return 1;
	else if (square[3] == square[6] && square[6] == square[9])

		return 1;
		
	// for checking diagnals
	else if (square[1] == square[5] && square[5] == square[9])

		return 1;
	else if (square[3] == square[5] && square[5] == square[7])

		return 1;

   // for occupied slots
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
			&& square[4] != '4' && square[5] != '5' && square[6] != '6' 
			&& square[7] != '7' && square[8] != '8' && square[9] != '9')

		return 0;                             // return 0 computer wins
	else
		return -1;                             // return -1 draw 
}

// function to clear the input of the game played before
void clear(char square[])                 
{
	square[1]='1';
	square[2]='2';
    square[3]='3';
    square[4]='4';
    square[5]='5';
	square[6]='6';
    square[7]='7';
    square[8]='8';
	square[9]='9';
}

