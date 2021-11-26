#include <iostream>
#include <unordered_set>
using namespace std;

void initialize(char arr[6][7], char init)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			arr[i][j] = init;
		}
	}
}

void printBoard(char arr[6][7])
{
	cout << endl;
	cout << "   1 2 3 4 5 6 7" << endl;
	cout << "  ---------------" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << i + 1 << " ";
		for (int j = 0; j < 7; j++)
		{
			cout << "|" << arr[i][j];
		}
		cout << "|" << endl;
		cout << "  ---------------";
		cout << endl;
	}
	cout << endl;
}

void printInfo()
{
	cout << endl;
	cout << "                                                      WELCOME TO CONNECT 4" << endl;
	cout << endl;
	cout << "RULES: " << endl;
	cout << "1) Two-player (red & blue) game.\n2) Board size is  6 rows × 7 columns.\n3) A player wins if he/she is able to connect 4 dots horizontally, vertically or diagonally.\n4) It's a draw when the matrix is fully filled.\n5) Game always starts with the player - 1 i.e. Red(R).\n6) In each step, each player can choose the row and column number in which they want to drop the ball.\n   For example, if the player wants to drop the ball in row 3 and column 5 then enter 3 5.\n7) Rows will be filled from bottom to top in any column." << endl;
	cout << endl;
	cout << "LET'S BEGIN!!!" << endl;
}

bool checkPos(char arr[6][7], int r, int c)
{
	if (arr[r - 1][c - 1] == ' ')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void updateBoard(char arr[6][7], int r, int c, char val)
{
	arr[r - 1][c - 1] = val;
}

bool checkWin(char arr[6][7], int r, int c, char player)
{
	for (int i = 5; i >= 0; --i)
	{
		for (int j = 6; j >= 0; --j)
		{
			if (arr[i][j] == player &&
				arr[i - 1][j - 1] == player &&
				arr[i - 2][j - 2] == player &&
				arr[i - 3][j - 3] == player)
			{
				return true;
			}

			if (arr[i][j] == player &&
				arr[i][j - 1] == player &&
				arr[i][j - 2] == player &&
				arr[i][j - 3] == player)
			{
				return true;
			}

			if (arr[i][j] == player &&
				arr[i - 1][j] == player &&
				arr[i - 2][j] == player &&
				arr[i - 3][j] == player)
			{
				return true;
			}

			if (arr[i][j] == player &&
				arr[i - 1][j + 1] == player &&
				arr[i - 2][j + 2] == player &&
				arr[i - 3][j + 3] == player)
			{
				return true;
			}

			if (arr[i][j] == player &&
				arr[i][j + 1] == player &&
				arr[i][j + 2] == player &&
				arr[i][j + 3] == player)
			{
				return true;
			}
		}
	}

	return false;
}

bool boardFull(char arr[6][7])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (arr[i][j] == ' ')
			{
				return false;
			}
			else
			{
				continue;
			}
		}
	}
	return true;
}

int play(char arr[6][7])
{
	int r, c;

	while (!boardFull(arr))
	{
	player1:
		cout << "Player 1(Red) choose the box you want to drop the ball in:";
		cin >> r >> c;

		if (r <= 6 && c <= 7 && r > 0 && c > 0)
		{
			if (checkPos(arr, r, c))
			{
				updateBoard(arr, r, c, 'R');
				printBoard(arr);
				if (checkWin(arr, r, c, 'R'))
				{
					return 1;
				}
			}
			else
			{
				cout << "Enter valid position!" << endl;
				goto player1;
			}
		}
		else
		{
			cout << "Enter valid row and column" << endl;
			goto player1;
		}

		if (boardFull(arr))
		{
			continue;
		}
		else
		{
		player2:
			cout << "Player 2(Blue) choose the box you want to drop the ball in:";
			cin >> r >> c;

			if (r <= 6 && c <= 7)
			{
				if (checkPos(arr, r, c))
				{
					updateBoard(arr, r, c, 'B');
					printBoard(arr);
					if (checkWin(arr, r, c, 'B'))
					{
						return 2;
					}
				}
				else
				{
					cout << "Enter valid position!" << endl;
					goto player2;
				}
			}
			else
			{
				cout << "Enter valid row and column" << endl;
				goto player2;
			}
		}
	}
	return 0;
}

int main()
{
	char arr[6][7];

	initialize(arr, ' ');
	printInfo();
	printBoard(arr);

	int result = play(arr);

	if (result == 0)
	{
		cout << "It's a draw." << endl;
	}
	else if (result == 1)
	{
		cout << "Player 1(Red) won!!!" << endl;
	}
	else if (result == 2)
	{
		cout << "Player 2(Blue) won!!!" << endl;
	}
}