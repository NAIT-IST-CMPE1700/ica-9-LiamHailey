#pragma once

struct student 
{
	char* firstName;
	int studentID;
	int mark;
	struct student* next;
};

typedef struct student* ptr;
