#include <stdio.h>
#include <stdlib.h>
#include "student.h"

void main()
{
	int exit = 0;
	int input = 0;

	//create initial arrays
	//student0 to student9 in order
	char names[10][10] = {
		{'s', 't', 'u', 'd', 'e', 'n', 't', '0', '\0'},
		{'s', 't', 'u', 'd', 'e', 'n', 't', '1', '\0'},
		{'s', 't', 'u', 'd', 'e', 'n', 't', '2', '\0'},
		{'s', 't', 'u', 'd', 'e', 'n', 't', '3', '\0'},
		{'s', 't', 'u', 'd', 'e', 'n', 't', '4', '\0'},
		{'s', 't', 'u', 'd', 'e', 'n', 't', '5', '\0'},
		{'s', 't', 'u', 'd', 'e', 'n', 't', '6', '\0'},
		{'s', 't', 'u', 'd', 'e', 'n', 't', '7', '\0'},
		{'s', 't', 'u', 'd', 'e', 'n', 't', '8', '\0'},
		{'s', 't', 'u', 'd', 'e', 'n', 't', '9', '\0'}
	};
	//IDs 0 to 9 randomized
	int IDs[10] = { 1, 6, 3, 8, 0, 2, 7, 4, 5, 9 };
	//mark randomized
	int marks[10] = { 90, 45, 78, 64, 28, 85, 93, 58, 61, 97 };

	while (!exit)
	{
		//menu 
		printf("=======\n Menu\n=======");
		printf("\n1. Display list in order of IDs");
		printf("\n2. Display list in descending order of marks");
		printf("\n3. Display the name, marks and rank of a person given the ID");
		printf("\n4. Display the names and marks of all person above a threshold marks value");
		printf("\n5. Exit\n");

		//get input
		scanf_s("%d", &input, sizeof(int));
		printf("\n");

		//perform input option
		switch (input)
		{
			//option 1 display list in order of ID	
		case 1:
			//sort based on id number
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < (9 - i); j++)
				{
					int IDSave1 = IDs[j];
					int IDSave2 = IDs[j + 1];

					char* nameSave1 = names[j][7];
					char* nameSave2 = names[j + 1][7];

					int markSave1 = marks[j];
					int markSave2 = marks[j + 1];

					if (IDSave1 > IDSave2)
					{
						IDs[j] = IDSave2;
						IDs[j + 1] = IDSave1;

						names[j][7] = nameSave2;
						names[j + 1][7] = nameSave1;

						marks[j] = markSave2;
						marks[j + 1] = markSave1;
					}
				}
			}

			//create the id list
			//create first item
			struct student* headID = NULL;
			headID = (struct student*)malloc(sizeof(struct student));

			headID->studentID = IDs[0];
			headID->firstName = names[0];
			headID->mark = marks[0];
			headID->next = NULL;

			//add nine more items
			for (int i = 1; i < 10; i++)
			{
				struct student* current = headID;
				while (current->next != NULL) {
					current = current->next;
				}

				current->next = (struct student*)malloc(sizeof(struct student));
				current->next->studentID = IDs[i];
				current->next->firstName = names[i];
				current->next->mark = marks[i];
				current->next->next = NULL;
			}

			//loop through list and print
			struct student* currentID = headID;

			while (currentID != NULL) {
				printf("%d", currentID->studentID);
				printf(" %s ", currentID->firstName);
				printf("%d\n", currentID->mark);
				currentID = currentID->next;
			}
			printf("\n");
			break;
			//option 2 display list in descending order of marks		
		case 2:
			printf("");

			//sort based on marks 
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < (9 - i); j++)
				{
					int IDSave1 = IDs[j];
					int IDSave2 = IDs[j + 1];

					char* nameSave1 = names[j][7];
					char* nameSave2 = names[j + 1][7];

					int markSave1 = marks[j];
					int markSave2 = marks[j + 1];

					if (markSave1 < markSave2)
					{
						IDs[j] = IDSave2;
						IDs[j + 1] = IDSave1;

						names[j][7] = nameSave2;
						names[j + 1][7] = nameSave1;

						marks[j] = markSave2;
						marks[j + 1] = markSave1;
					}
				}
			}

			//create the id list

			//create first item
			struct student* headMarks = NULL;
			headMarks = (struct student*)malloc(sizeof(struct student));

			headMarks->studentID = IDs[0];
			headMarks->firstName = names[0];
			headMarks->mark = marks[0];
			headMarks->next = NULL;

			//add nine more items
			for (int i = 1; i < 10; i++)
			{
				struct student* current = headMarks;
				while (current->next != NULL) {
					current = current->next;
				}

				current->next = (struct student*)malloc(sizeof(struct student));
				current->next->studentID = IDs[i];
				current->next->firstName = names[i];
				current->next->mark = marks[i];
				current->next->next = NULL;
			}

			//loop through list and print
			struct student* currentMarks = headMarks;

			while (currentMarks != NULL) {
				printf("%d", currentMarks->studentID);
				printf(" %s ", currentMarks->firstName);
				printf("%d\n", currentMarks->mark);
				currentMarks = currentMarks->next;
			}
			printf("\n");
			break;
		//option 3 search ID
		case 3:
			printf("Enter student ID: ");
			int search;
			scanf_s("%d", &search, sizeof(int));
			printf("\n");

			//sort based on id number
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < (9 - i); j++)
				{
					int IDSave1 = IDs[j];
					int IDSave2 = IDs[j + 1];

					char* nameSave1 = names[j][7];
					char* nameSave2 = names[j + 1][7];

					int markSave1 = marks[j];
					int markSave2 = marks[j + 1];

					if (IDSave1 > IDSave2)
					{
						IDs[j] = IDSave2;
						IDs[j + 1] = IDSave1;

						names[j][7] = nameSave2;
						names[j + 1][7] = nameSave1;

						marks[j] = markSave2;
						marks[j + 1] = markSave1;
					}
				}
			}

			//display the student
			printf("%d", IDs[search]);
			printf(" %s ", names[search]);
			printf("%d\n\n", marks[search]);
			break;
		//option 4 display students above a mark threashold
		case 4: 
			printf("Enter mark threshold: ");
			int threshold;
			scanf_s("%d", &threshold, sizeof(int));
			printf("\n");
			
			//sort based on marks 
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < (9 - i); j++)
				{
					int IDSave1 = IDs[j];
					int IDSave2 = IDs[j + 1];

					char* nameSave1 = names[j][7];
					char* nameSave2 = names[j + 1][7];

					int markSave1 = marks[j];
					int markSave2 = marks[j + 1];

					if (markSave1 < markSave2)
					{
						IDs[j] = IDSave2;
						IDs[j + 1] = IDSave1;

						names[j][7] = nameSave2;
						names[j + 1][7] = nameSave1;

						marks[j] = markSave2;
						marks[j + 1] = markSave1;
					}
				}
			}
			//for each student in the list
			for (int i = 0; i < 10; i++)
			{
				//if their mark is above the threshold
				if (marks[i] > threshold)
				{
					//display the student
					printf("%d", IDs[i]);
					printf(" %s ", names[i]);
					printf("%d\n", marks[i]);
				}
			}
			printf("\n");
			break;
		default:
			exit = 1;
			break;
		}
	}
}