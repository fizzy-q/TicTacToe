#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <conio.h>


using namespace std;

	
int check( char square[][3]);                                  // function to check winner
void board(char square[][3] , char user , char comp);          // function to display board
void clear(char array[][3]);                                  // function to clear the previous input


// timer function for the 5 sec delay in computer's turn

int counter(int n)
{	
    int	timer=5;
    
    while(timer>0)
    {
        cout << timer <<endl;
        Sleep(1000);                      // 1000 represents 1 sec
        --timer;
    }
}

int main()
{
	char square[3][3] = { { '1','2','3' },{ '4','5','6' },{ '7','8','9' } };
	
	int player = 1,i,choice;
	int timer;

	char mark;                                 // variable for symbol
	int returnto;                              // variable for play again option
	
	do 
    {
    	
	char tic , toe;                             // Declaration of variables to take the value of signs used for user and computer turn
    		
    cout << "\t\t HUMAN VS COMPUTER TIC TAC TOE " <<endl;
    
	cout << "\nChoose a symbol (\"X\" or \"O\") for your game: ";
	cin >> tic;                                   // variable for symbol for user
	
	if (tic=='X')
	{
		toe='O';                                 // variable for symbol for computer
	}
	
	else if(tic=='O')
	{
		toe='X';
	}
	
      do
	{
		board(square, tic , toe);

		if(player%2==1)
			player=1;
		else
			player=2;


// for player 2 i.e computer
	if(player==2)
	{
		cout << "Player  " << player<<endl;
		
		counter (timer);
		
		srand(time(0));
		choice = rand()%9 + 1;      // to prevent zero
		
		mark = toe;
		int turn=1;
		int placed=0;
			
		while(placed==0)
		{

		if (choice == 1 && square[0][0] == '1')
		{
			square[0][0] = mark;
			placed=1;
		}
		else if (choice == 2 && square[0][1] == '2')
		{	
				square[0][1] = mark;
				placed=1;
		}
		else if (choice == 3 && square[0][2] == '3')
		{
			square[0][2] = mark;
			placed=1;
		}
		else if (choice == 4 && square[1][0] == '4')
		{
			square[1][0] = mark;
			placed=1;
		}
		else if (choice == 5 && square[1][1] == '5')
		{
			square[1][1] = mark;
			placed=1;
		}
		else if (choice == 6 && square[1][2] == '6')
		{
			square[1][2] = mark;
			placed=1;
		}
		else if (choice == 7 && square[2][0] == '7')
		{
			square[2][0] = mark;
			placed=1;
		}
		else if (choice == 8 && square[2][1] == '8')
		{
			square[2][1] = mark;
			placed=1;
		}
		else if (choice == 9 && square[2][2] == '9')
		{
			square[2][2] = mark;
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

		board(square, tic, toe);
	}

// for player 1 i.e user

	else if(player==1)
	{
		cout << "Player " << player << ", enter a number b/w 1 to 9:  ";
		cin >> choice;
		mark=tic;

		if (choice == 1 && square[0][0] == '1')

			square[0][0] = mark;
		else if (choice == 2 && square[0][1] == '2')

			square[0][1] = mark;
		else if (choice == 3 && square[0][2] == '3')

			square[0][2] = mark;
		else if (choice == 4 && square[1][0] == '4')
		
			square[1][0] = mark;
		else if (choice == 5 && square[1][1] == '5')
		
			square[1][1] = mark;
		else if (choice == 6 && square[1][2] == '6')
		
			square[1][2] = mark;
		else if (choice == 7 && square[2][0] == '7')
		
			square[2][0] = mark;
		else if (choice == 8 && square[2][1] == '8')
		
			square[2][1] = mark;
		else if (choice == 9 && square[2][2] == '9')
		
			square[2][2] = mark;
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
		board(square, tic , toe);
		
	if(i==1)

			cout<<"Congratulation! \nPlayer "<<--player<<" win ";
	else
		{
            cout<<" Draw";
        }
    cout << endl; 
    cout << "Enter 1 to PLAY AGAIN or enter 2 to END program." << endl;
    cin >> returnto;
    
	clear(square);                       // to clear the input
    
	}
	while(returnto == 1);              // condition to play again

return 0;	
}

// function for the displaying tictactoe board
void board(char square[][3] , char tic , char toe)
{

	system ("cls");       
	
	cout << "Player 1 ("<<tic<<")  -  Computer ("<<toe<<")" <<endl;
	cout << endl;

	cout << "\t\t\t     |     |     " << endl;
	cout << "\t\t\t  " << square[0][0] << "  |  " << square[0][1] << "  |  " << square[0][2] << endl;

	cout << "\t\t\t_____|_____|_____" << endl;
	cout << "\t\t\t     |     |     " << endl;

	cout << "\t\t\t  " << square[1][0] << "  |  " << square[1][1] << "  |  " << square[1][2] << endl;

	cout << "\t\t\t_____|_____|_____" << endl;
	cout << "\t\t\t     |     |     " << endl;

	cout << "\t\t\t  " << square[2][0] << "  |  " << square[2][1] << "  |  " << square[2][2] << endl;

	cout << "\t\t\t     |     |     " << endl << endl;
}


int check(char square[][3])
{
	// for checking rows
	if (square[0][0] == square[0][1] && square[0][1] == square[0][2])

		return 1;                                                            // retrun 1 user wins
	else if (square[1][0] == square[1][1] && square[1][1] == square[1][2])

		return 1;
	else if (square[2][0] == square[2][1] && square[2][1] == square[2][2])

		return 1;

	// for checking columns
	else if (square[0][0] == square[1][0] && square[1][0] == square[2][0])

		return 1;
	else if (square[0][1] == square[1][1] && square[1][1] == square[2][1])

		return 1;
	else if (square[0][2] == square[1][2] && square[1][2] == square[2][2])

		return 1;
		
	// for checking diagnals
	else if (square[0][0] == square[1][1] && square[1][1] == square[2][2])

		return 1;
	else if (square[0][2] == square[1][1] && square[1][1] == square[2][0])
	
	// for occupied slots
		return 1;
	else if (square[0][0] != '1' && square[0][1] != '2' && square[0][2] != '3' 
			&& square[1][0] != '4' && square[1][1] != '5' && square[1][2] != '6' 
			&& square[2][0] != '7' && square[2][1] != '8' && square[2][2] != '9')

		return 0;                  // return 0 computer wins
	else
		return -1;                // return -1 draw
}

// function to clear the input of the game played before

void clear(char square[][3])
{
  square[0][0]='1';
  square[0][1]='2';
  square[0][2]='3';
  square[1][0]='4';
  square[1][1]='5';
  square[1][2]='6';
  square[2][0]='7';
  square[2][1]='8';
  square[2][2]='9';
  
}
