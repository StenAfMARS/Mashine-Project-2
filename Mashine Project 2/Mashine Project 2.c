// Mashine Project 2.cpp : Defines the entry point for the application.
// ReSharper disable CppInconsistentNaming

#include "Mashine Project 2.h"

char lastComment[24];


void initializeGameScreen()
{
	//Clear screen
	system("cls");

	printf(" C1\tC2\tC3\tC4\tC5\tC6\tC7\n");
	printf("\n");
	printf(" \t\t\t\t\t\t\t[]\tF1\t");
	printf("\n");
	printf("\n");
	printf(" \t\t\t\t\t\t\t[]\tF2\t");
	printf("\n");
	printf("\n");
	printf(" \t\t\t\t\t\t\t[]\tF3\t");
	printf("\n");
	printf("\n");
	printf(" \t\t\t\t\t\t\t[]\tF4\t");
	printf("\n");
	printf("\n");

	printf("LAST Command: \n");
	printf("Message: \n");
	printf("Input >\n");
}

void generateGameBoard()
{
	system("cls");

	int grid[7][8];
	char Hidden = "0";

	// need generate card function
	char card = "C";

	//first loop work with row
	printf(" C1\tC2\tC3\tC4\tC5\tC6\tC7\n");
	printf("\n");

	//Generate grid space
	for (int j = 1; j <= 7; j++)
	{
		for (int k = 0; k < 7; k++)
		{
			if (k == 0)
			{
				printf(" \[]\t", grid[j][k]);
			}
			else
			{
				printf("\[]\t", grid[j][k]);
			}
		}

		if (j == 1)
		{
			printf("\t\[]\tF%d\n", j);
		}
		else
		{
			if (j == 3)
			{
				printf("\t\[]\tF%d\n", j - 1);
			}
			else
			{
				if (j == 5)
				{
					printf("\t\[]\tF%d\n", j - 2);
				}
				else
				{
					if (j == 7)
					{
						printf("\t\[]\tF%d\n", j - 3);
					}
					else
					{
						printf("\n");
					}
				}
			}
		}
	}
}

void update_game_board()
{
}

void init_new_game()
{
	struct C1* C1 = (struct C1*)malloc(sizeof(struct C1));
	struct C2* C2 = (struct C2*)malloc(sizeof(struct C2));
	struct C3* C3 = (struct C3*)malloc(sizeof(struct C3));
	struct C4* C4 = (struct C4*)malloc(sizeof(struct C4));
	struct C5* C5 = (struct C5*)malloc(sizeof(struct C5));
	struct C6* C6 = (struct C6*)malloc(sizeof(struct C6));
	struct C7* C7 = (struct C7*)malloc(sizeof(struct C7));
	
}



int main()
{
	//Initialize game screen
	//initializeGameScreen();
	generateGameBoard();

	char Input = "";

	switch (Input)
	{
		// Load Deck
	case 'LD':
		generateGameBoard();
		break;

		//show Deck
	case 'SD':
		break;

	default:
		printf("Unknown command");
	}

	return 0;
}
