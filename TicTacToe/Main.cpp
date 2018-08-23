#include<iostream>

int space[2];
int turn = 0;

bool quit = false;
bool play = false;

char input = 0;
char board[3][3];
char playerTurn = 'X';

void ResetBoard();
void DisplayBoard();
bool CheckBoard(int space[2]);

int main()
{
	while (!quit)
	{
		//main menu
		std::cout << "Welcome to Tic Tac Toe!" << std::endl;
		std::cout << std::endl;
		std::cout << "[P]lay or [Q]uit?" << std::endl;
		std::cout << std::endl;
		//user selection
		std::cin >> input; std::cout << std::endl;
		//process
		switch (input)
		{
		case 'p':
		case 'P':
			std::cout << "Playing game!" << std::endl;
			ResetBoard();
			play = true;
			break;
		case 'q':
		case 'Q':
			std::cout << "Quitting..." << std::endl;
			quit = true;
			break;
		default:
			std::cout << "Input invalid" << std::endl;
			break;
		}
		//game
		while (play)
		{
			bool oktogo = false;

			//show whos turn it is and board
			std::cout << "It's " << playerTurn << "'s turn!" << std::endl;
			DisplayBoard();

			//get player row
			while (!oktogo)
			{
				std::cout << "Select a row:" << std::endl;
				std::cin >> space[0];
				space[0]--;
				if (space[0] >= 0 || space[0] < 3)
				{
					oktogo = true;
				}
				else
				{
					std::cout << "Input invalid" << std::endl;
				}
			}
			//get player collumn
			oktogo = false;
			while (!oktogo)
			{
				std::cout << "Select a collumn:" << std::endl;
				std::cin >> space[1];
				space[1]--;
				if (space[1] >= 0 || space[1] < 3)
				{
					oktogo = true;
				}
				else
				{
					std::cout << "Input invalid" << std::endl;
				}
			}
			if (board[space[0]][space[1]] == ' ')
			{
				board[space[0]][space[1]] = playerTurn;
				//Check win
				if (CheckBoard(space))
				{
					//win
					std::cout << "Player " << playerTurn << " wins!" << std::endl;
					DisplayBoard();
					system("pause");
					play = false;
				}
				else
				{
					turn++;
					//tie
					if (turn == 9)
					{
						std::cout << "It's a tie!" << std::endl;
						DisplayBoard();
						system("pause");
						play = false;
					}
					//next turn
					else if (playerTurn == 'X')
					{
						playerTurn = 'O';
					}
					else
					{
						playerTurn = 'X';
					}
				}
				
			}
			else
			{
				std::cout << "Move invalid" << std::endl;
			}
		}
	}
	return 0;
}

void ResetBoard()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard()
{
	std::cout << "  1 2 3" << std::endl;
	std::cout << " +-----+" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << i + 1;
		for (int j = 0; j < 3; j++)
		{
			std::cout << '|' << board[i][j];
		}
		std::cout << '|' << std::endl;
		std::cout << " +-----+" << std::endl;
	}
}

bool CheckBoard(int space[2])
{
	//check rows
	if (board[space[0]][0] == board[space[0]][1] && board[space[0]][0] == board[space[0]][2])
	{
		return true;
	}
	//check collumns
	if (board[0][space[1]] == board[1][space[1]] && board[0][space[1]] == board[2][space[1]])
	{
		return true;
	}
	//check top left to bottom right
	if ((space[0] == 0 && space[1] == 0) || (space[0] == 1 && space[1] == 1) || (space[0] == 2 && space[1] == 2))
	{
		if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		{
			return true;
		}
	}
	//check bottom left to top right
	if ((space[0] == 2 && space[1] == 0) || (space[0] == 1 && space[1] == 1) || (space[0] == 0 && space[1] == 2))
	{
		if (board[2][0] == board[1][1] && board[2][0] == board[0][2])
		{
			return true;
		}
	}
	return false;
}