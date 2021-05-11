// Mashine Project 2.cpp : Defines the entry point for the application.
// ReSharper disable CppInconsistentNaming

#include "Mashine Project 2.h"

char lastComment[24];

struct Node {
	char* data;
	struct Node* next; // Pointer to next node in DLL
	struct Node* prev; // Pointer to previous node in DLL
};

struct Node* head;
struct Node* tail;
struct Node* Cards;

void swap();
void cutDeck(int);
void safeToFile();
void gameBegan();
void push();
void pop();
void printList();
int grid[7][8];

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
void loadDeck()
{
	system("cls");


	char Hidden = "0";

	// need generate card function
	char card = "C";

	//first loop work with row
	printf(" C1\tC2\tC3\tC4\tC5\tC6\tC7\n");
	printf("\n");
	
	Cards = head;
	//Generate grid space
	bool endOfNode = false;
	for (int j = 1; j <= 8; j++)
	{
		for (int k = 0; k < 7; k++)
		{
			if (k == 0)
			{
				
				printf(" \[]\t", grid[j][k]);

			}
			else
			{
				printf(" \[]\t", grid[j][k]);

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
void ShowDeck()
{
	system("cls");

	
	char Hidden = "0";

	// need generate card function
	char card = "C";

	//first loop work with row
	printf(" C1\tC2\tC3\tC4\tC5\tC6\tC7\n");
	printf("\n");
	Cards = head;
	//Generate grid space
	bool endOfNode = false;
	for (int j = 1; j <= 8; j++)
	{
		for (int k = 0; k < 7; k++)
		{
			if (k == 0)
			{
				if (Cards->next == NULL) { // reached the last node, so stop iterating
					if (endOfNode == false) {
						printf(" \%s\t", Cards->data);
						endOfNode = true;
					}
					else
					{
						printf(" \[]\t", grid[j][k]);
					}
					
					
				}
				else {
					printf(" \%s\t", Cards->data);
					Cards = Cards->next;
				}
				

			}
			else
			{
				if (Cards->next == NULL) { // reached the last node, so stop iterating
					if (endOfNode == false) {
						printf(" \%s\t", Cards->data);
						endOfNode = true;
					}
					else
					{
						printf(" \[]\t", grid[j][k]);
					}


				}
				else {
					printf(" \%s\t", Cards->data);
					Cards = Cards->next;
					
				}

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

	struct F1* F1 = (struct F1*)malloc(sizeof(struct F1));
	struct F2* F2 = (struct F2*)malloc(sizeof(struct F2));
	struct F3* F3 = (struct F3*)malloc(sizeof(struct F3));
	struct F4* F4 = (struct F4*)malloc(sizeof(struct F4));
	
}



int main()
{
	//Initialize game screen
	//initializeGameScreen();
	
	char tempArray[20];
	FILE* fp;
	char name[20];
	bool endOfGame = false;
	int Input;
	int cut;

	int number;
	int position;
	
	while(endOfGame == false)
	{
		printf("type command: ");
		scanf("%d", &Input);

		switch (Input)
		{
			// Load Deck
		case 1: // LD = 1

			head = NULL;
			tail = NULL;
			printf("Name File: ");
			scanf("%s", name);
			if(true)
			{
				fp = fopen(name, "r");		// Open the file with 'read' option.	''
				if (fp == NULL) { exit(-1); }
				while (!feof(fp)) {

					fgets(tempArray, 20, fp);
					if (tempArray[strlen(tempArray) - 1] == '\n') {
						tempArray[strlen(tempArray) - 1] = 0;
					}
					push();
					tail->data = strdup(tempArray);
				}
				fclose(fp);
				loadDeck();
			}
			else
			{
				
				fp = fopen("deck.txt", "r");		// Open the file with 'read' option.	''
				if (fp == NULL) { exit(-1); }
				while (!feof(fp)) {

					fgets(tempArray, 20, fp);
					if (tempArray[strlen(tempArray) - 1] == '\n') {
						tempArray[strlen(tempArray) - 1] = 0;
					}
					push();
					tail->data = strdup(tempArray);
				}
				fclose(fp);
				loadDeck();
			}
			
			break;

			//show Deck
		case 2: // SD = 2
			ShowDeck();
			break;
		case 3: // Si = 2
			printf("number of cut");
			scanf("%d", &cut);
			cutDeck(cut);
			ShowDeck();
			break;
		case 4: // Sr = 2
			swap();
			ShowDeck();
			break;
		case 5: // SD = 2
			safeToFile();
			ShowDeck();
			break;
		case 6: // End = 6
			endOfGame = true;
			break;
		case 7: // End = 6
			gameBegan();
			break;
		case 11: // End = 3
			printf("Name File\n");
			printf("Name File\n");
			printf("Name File\n");
			printf("Name File\n");
			break;
		default:
			printf("Unknown command\n");
		}
	}


	return 0;
}
void cutDeck(int cut) {
	struct Node* node1 = head;
	struct Node* node2 = head;
	
	Cards = head;
    int i = 1; 
    while (Cards->next != NULL) {
        Cards = Cards->next;
        i++;
    }
    for (int j = 0; j <= i; j++) {
        if (j < i / 2) {
            head = head->next;
        }
        if (j >= i / 2) {
        	if(head != NULL)
        	{
        		node2->data = head->data;
				node2 = node2->next;
				head = head->next;
        	}
            
        }
    }
}
void swap() {
	struct Node* node1 = head;
	struct Node* node2 = head;

	for (int j = 0; j < 10;) {
		node1 = node1->next;
		if (node1 == NULL) {
			node1 = head;
			j++;
		}
		for (int i = rand() % 3; i >= 0; i--) {
			node2 = node2->next;
			if (node2== NULL) {
				node2 = head;

			}
		}
		char*placeHolder = node1->data;
		node1->data = node2->data;
		node2->data = placeHolder;
		
		
	}
	
}
void safeToFile() {
	FILE* fp;
	int i;
	char name[50];
	printf("file name: ");
	scanf("%s", name);

	fp = fopen(name, "w");
	Cards = head;
	while (Cards->next != NULL)
	{
		fprintf(fp, "\%s\n", Cards->data);
		Cards = Cards->next;
	}
	fprintf(fp, "\%s\n", Cards->data);
		/* close the file*/
	fclose(fp);
	}

void gameBegan() {
	bool gameStarted = true;
	gamesetup();
		while(gameStarted == true)
		{
			int Input2;
			printf("type command");
			scanf("%d", &Input2);

			switch (Input2) {
			case 8:
				gameStarted = false;
				break;
			default:
				printf("Unknown command\n");
			}
			
		}
}
void gamesetup()
{
	system("cls");


	char Hidden = "0";

	// need generate card function
	char card = "C";

	//first loop work with row
	printf(" C1\tC2\tC3\tC4\tC5\tC6\tC7\n");
	printf("\n");

	Cards = head;
	//Generate grid space
	bool endOfNode = false;
	for (int j = 1; j <= 8; j++)
	{
		for (int k = 0; k < 7; k++)
		{
			if (k == 0)
			{
				printf(" \[]\t", grid[j][k]);

			}
			else
			{
				printf(" \[]\t", grid[j][k]);

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
void push(){
	    
    if(head != NULL){
        struct Node* temp1 = malloc(sizeof(struct Node));
        temp1->next = NULL; 
        temp1->prev = tail;
        tail->next = temp1;
        tail = temp1;
    } else { //list is empty
        head = malloc(sizeof(struct Node));	// setting up space in the memory for the 1st node.
        head->prev = NULL;
        head->next = NULL;
        tail = head;
    }

} 
