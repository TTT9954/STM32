// character pointer is stored in ROM (Read Only Memory)
// character array is stored in RAM
#include <stdio.h>
#include <stdint.h>

typedef struct StudentRecord
{
	uint32_t rollNumber;
	uint8_t studentSemester;
	char DOB[128];
	char studentBranch[128];
	char studentName[128];
}record;

void Display_menu();
int  Choice_menu();
int check_exist(int rollnumber, record *student_rec, uint32_t max_record);
void Choice_choosen(int choice);
int Add(record *student_rec, uint32_t max_record);
void Display_record(record *student_rec, uint32_t max_record);
int Delete_record(int rollnumber, record *student_rec, uint32_t max_record);

record Student_Record[10];

uint32_t const max_record = 10;

int main()
{


	int menu_choice;
	int app_continue = 1;
	while(app_continue)
	{
		printf("\n---------------Student record management application---------------\n");
		Display_menu();
		menu_choice = Choice_menu();
		if(menu_choice)
		{
			Choice_choosen(menu_choice);
		}
		else
		{
			app_continue = 0;
			printf("Exiting the application ...");
		}
	}
	return 0;
}

void Display_menu()
{
	printf("1. Display all records\n");
	printf("2. Add new record\n");
	printf("3. Delete existing record\n");
	printf("0. Exit the application\n");
	printf("Enter your option here: ");
}

int Choice_menu()
{
	int choice;
	scanf("%d", &choice);
	return choice;
}

void Choice_choosen(int choice)
{
	int temp;
	switch(choice)
	{
		case 1:
			printf("\n***** Display all records *****\n");
			Display_record(Student_Record, max_record);
			break;
		case 2:
			printf("\n***** Add new record *****\n");
			temp = Add(Student_Record, max_record);
			!temp ? printf("Record is added unsuccessfully\n") : printf("Record is added successfully\n");
			break;
		case 3:
			printf("\n***** Delete existed record *****\n");
			int rollnumber_delete;
			printf("Enter roll number to delete: ");
			scanf("%d", &rollnumber_delete);
			temp = Delete_record(rollnumber_delete, Student_Record, max_record);
			temp ? printf("Deleted successfully !") : printf("Deleted unsuccessfully !");
			break;
		default:
			printf("Invalid option !");
			break;
	}
}

int check_exist(int rollnumber, record *student_rec, uint32_t max_record)
{
	int Is_exist = 0;
	for(uint32_t i = 0; i < max_record; i++)
	{
		if(rollnumber == (student_rec+i)->rollNumber)
		{
			Is_exist = 1;

			break;
		}
	}
	return Is_exist;
}

int Add(record *student_rec, uint32_t max_record)
{
	uint8_t exist;
	uint8_t rollnumber;
	uint8_t add_status = 0;
	uint32_t is_exceed;
	for(uint32_t i = 0; i < max_record; i++)
	{
		is_exceed = i;
		if((student_rec+i)->rollNumber == 0)
		{
			printf("Enter Roll Number: ");
			scanf("%hhu", &rollnumber);
			exist = (uint8_t)check_exist(rollnumber, Student_Record, max_record);
			if(!exist)
			{
				add_status = 1;
				(student_rec+i)->rollNumber = rollnumber;
				printf("Enter student Semester:  ");
				scanf("%hhu", &(student_rec+i)->studentSemester);
				fflush(stdin);
				//getchar();
				printf("Enter date of birth:  ");
				gets((student_rec+i)->DOB);
				//scanf("%[^\n]s", (student_rec+i)->DOB);

				//getchar();
				printf("Enter student branch: ");
				gets((student_rec+i)->studentBranch);
							//scanf("%[^\n]s", (student_rec+i)->studentBranch);

				//getchar();
				printf("Enter student name: ");
				gets((student_rec+i)->studentName);
				//scanf("%[^\n]s", (student_rec+i)->studentName);
			}
			else
			{
			    printf("Roll number already exist\n");
			}
			break;
		}
	}
	if(is_exceed > max_record)
	{
		printf("No space available\n");
	}
	return add_status;
}

void Display_record(record *student_rec, uint32_t max_record)
{
	uint32_t record_found = 0;
	for(uint32_t i = 0; i < max_record; i++)
	{

		if((student_rec+i)->rollNumber)
		{
			printf("-----------------------------------------------------------------\n");
			record_found = 1;
			printf("Roll Number: %u\n", (student_rec+i)->rollNumber);
			printf("Student Semester: %hhu\n", (student_rec+i)->studentSemester);
			printf("Date of birth: %s\n", (student_rec+i)->DOB);
			printf("Student branch: %s\n", (student_rec+i)->studentBranch);
			printf("Student name: %s\n", (student_rec+i)->studentName);
			printf("-----------------------------------------------------------------\n");
		}

	}
	if(!record_found)
	{
		printf("Record not found !\n");
	}

}

int Delete_record(int rollnumber, record *student_rec, uint32_t max_record)
{
	int is_deleted = 0;
	int index_deleted = -1;
	for(int i = 0; i < max_record; i++)
	{
		if(rollnumber == ((student_rec+i)->rollNumber))
		{
			index_deleted = i;
		}
	}
	if(index_deleted == -1)
	{
		is_deleted = 0;
		printf("Record not found !\n");
	}
	else
	{
		is_deleted = 1;
		for(int i = index_deleted; i < max_record; i++)
		{
			*(student_rec+i) = *(student_rec+i+1);
		}
		max_record--;
	}

	return is_deleted;
}
