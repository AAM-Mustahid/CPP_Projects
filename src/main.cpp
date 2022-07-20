#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int choice;
char turn = 'x'; // displaying number in the board

void display_board()
{
	// Displaying Board

	cout << endl;
	cout << "		     |     |     " << endl;
	cout << "		   " << board[0][0] << " |  " << board[0][1] << "  |  " << board[0][2] << " " << endl;
	cout << "		_____|_____|_____" << endl;
	cout << "		     |     |     " << endl;
	cout << "		   " << board[1][0] << " |  " << board[1][1] << "  |  " << board[1][2] << " " << endl;
	cout << "		_____|_____|_____" << endl;
	cout << "		     |     |    " << endl;
	cout << "		   " << board[2][0] << " |  " << board[2][1] << "  |  " << board[2][2] << " " << endl;
	cout << "		     |     |     " << endl;

	cout << endl;
}

void player_turn()
{
	cout << "\n			T I C K  T O C   T A C		" << endl
		 << endl;
	if (turn == 'x')
		cout << " Player 1[X] Turns: ";
	if (turn == 'o')
		cout << " Player 2[O] Turns: ";
A:
	cin >> choice; // turns for players
	switch (choice)
	{
	case 1:
		board[0][0] = 'X';
		break;
	case 2:
		board[0][1] = 'X';
		break;
	case 3:
		board[0][2] = 'X';
		break;
	case 4:
		board[1][0] = 'X';
		break;
	case 5:
		board[1][1] = 'X';
		break;
	case 6:
		board[1][2] = 'X';
		break;
	case 7:
		board[2][0] = 'X';
		break;
	case 8:
		board[2][1] = 'X';
		break;
	case 9:
		board[2][2] = 'X';
		break;
	default:
		cout << endl
			 << "Invalid. Input Again" << endl;
		goto A;
	}
}

int main()
{
	cout << "\n			T I C K  T O C   T A C		" << endl
		 << endl;
	cout << " =>  Player 1[X] <=" << endl
		 << " 	VS  " << endl
		 << "=>   Player 2[O] <= " << endl;

	display_board();
	while (true)
	{

		player_turn();
		display_board();
	}

	cout << endl;
}