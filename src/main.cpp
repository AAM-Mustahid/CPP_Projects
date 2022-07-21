#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int choice, row, col;
char turn = 'x'; // displaying number in the board

void display_board()
{
	// Displaying Board
	system("cls");
	cout << "\n			T I C K  T O C   T A C		" << endl
		 << endl;
	cout << " =>  Player 1[X] <=" << endl
		 << " 	VS  " << endl
		 << " =>   Player 2[O] <= " << endl;

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
		row = 0;
		col = 0;
		break;
	case 2:
		row = 0;
		col = 1;
		break;
	case 3:
		row = 0;
		col = 2;
		break;
	case 4:
		row = 1;
		col = 0;
		break;
	case 5:
		row = 1;
		col = 1;
		break;
	case 6:
		row = 1;
		col = 2;
		break;
	case 7:
		row = 2;
		col = 0;
		break;
	case 8:
		row = 2;
		col = 1;
		break;
	case 9:
		row = 2;
		col = 2;
		break;
	default:
		cout << endl
			 << "Invalid. Input Again" << endl;
		goto A;
	}
	// change turns

	if (turn == 'x' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'X';
		turn = 'o';
	}
	else if (turn == 'o' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'O';
		turn = 'x';
	}
	else
	{
		cout << endl
			 << "                        Already ***BOOKED***!!!"
			 << endl
			 << endl
			 << "                          **No Cheating**" << endl;
		player_turn();
	}
}

int main()
{

	while (true)
	{
		display_board();

		player_turn();
		display_board();
	}

	cout << endl;
}