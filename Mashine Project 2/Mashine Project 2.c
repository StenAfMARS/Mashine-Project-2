// Mashine Project 2.cpp : Defines the entry point for the application.
// ReSharper disable CppInconsistentNaming

#include "Mashine Project 2.h"
#include <stdio.h>
#include <stdlib.h> // For exit() function
#include <assert.h>
#include <string.h>
char lastComment[24];
struct Node {
	char* data;
	struct Node* next; // Pointer to next node in DLL
	struct Node* prev; // Pointer to previous node in DLL
};

struct Node* head;
struct Node* tail;

void push();
void pop();
void printList();


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
	struct Node* Cards = head;
	//Generate grid space
	bool endOfNode = false;
	for (int j = 1; j <= 7; j++)
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
	struct C1* new_card = (struct C1*)malloc(sizeof(struct C1));
	
}



int main()
{
	//Initialize game screen
	//initializeGameScreen();
	
	char tempArray[20];
	FILE* fp;
	bool endOfGame = 
	printf("type command");
	int Input = scanf("%d", &Input);;
	
	switch (Input)
	{
		// Load Deck
	case 1: // LD = 1
		

		printf("Name File");
		fp = fopen("testData.txt", "r");		// Open the file with 'read' option.	''
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
		printList();
		printf("\n");
		generateGameBoard();
		generateGameBoard();
		break;

		//show Deck
	case 2: // SD = 2
		break;
	case 3: // End = 3
		break;
	default:
		printf("Unknown command");
	}

	return 0;
}
//Doubly Linked List

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
        printf("Node specific addr: %p\n", head);
    }

} 

void pop(){
    if(tail!=NULL){
        struct Node* temp1;
        if(tail->prev != NULL){
            temp1 = tail;
            tail = tail->prev;
            free(temp1);
            tail->next = NULL;
        }
    } else { printf("List is empty.\n"); }
}

/* Use this function to print out the current contents of memory. */
void printList(){
	
	printf("------------------------------------"	
		   "\n------------------------------------"
		   "\nThis function will print info from all the nodes.\n");
	struct Node* Derpina = head;
	int derp =1;
	while (1==1){
		printf("Node data : %s\n", Derpina->data);
		if(Derpina->next == NULL){ // reached the last node, so stop iterating
			break;	
		} else {
			Derpina = Derpina->next;
		}	
	}	
	return;
}