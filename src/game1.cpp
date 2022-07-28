#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int choice, row, col;
char turn = 'X'; // displaying number in the board
bool draw;

void display_board()
{
	/* Displaying Board*/

	system("cls");
	cout << "\n			T I C K  T O C   T A C		" << endl
		 << endl;
	cout << " =>  Player 1[X] <=" << endl
		 << " 	VS  " << endl
		 << " =>  Player 2[O] <= " << endl;

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

/* turns for players*/

void player_turn()
{
	cout << "\n			T I C K  T O C   T A C		" << endl
		 << endl;

	if (turn == 'X')
		cout << " Player 1[X] Turns: ";
	if (turn == 'O')
		cout << " Player 2[O] Turns: ";

	cin >> choice;
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
		break;
	}
	/*Change Turns*/

	if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O')
	{
		board[row][col] = 'O';
		turn = 'X';
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
/* Result Check*/

bool check()
{
	int i, j;

	/*Wins Check*/

	for (i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) // Check Row
			return false;
		else if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) // Check Column
			return false;

		else if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) // check diagonal
			return false;
	}

	/* There is any box not filled yet*/

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (board[i][j] != 'X' && board[i][j] != 'O')
				return true;
	/* Draw */
	draw = true;
	return false;
}

int main()
{

	while (check())
	{
		display_board();

		player_turn();
		display_board();
	}

	cout << endl;

	/* Decide Who wins*/

	if (turn == 'X' && draw == false)
		cout << "	***Congratulations...!!!***	" << endl
			 << endl
			 << "	    *Player 2[O] Wins* " << endl;
	else if (turn == 'O' && draw == false)
		cout << "	***Congratulations...!!!***" << endl
			 << "	    *Player 1[X] Wins* " << endl;
	else
		cout << "		Game Draw..!!!" << endl;
	cout << endl;

	return 0;
}