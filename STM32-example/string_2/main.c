#include <stdio.h>
#include <stdint.h>
#include <string.h>
typedef struct
{
    uint8_t RollNumber;
    uint8_t Semester;
    char date[128];
    char branch[128];
    char name[128];
} STUDENT_RECORD;

STUDENT_RECORD students[10];

void display_menu();
void Display_records(STUDENT_RECORD *record, uint8_t max_record);
uint8_t Check_exist(uint8_t rollnum, STUDENT_RECORD *record, uint8_t max_record);
void Add_new_record(uint8_t rollnum, STUDENT_RECORD *record, uint8_t max_record);
uint8_t Delete_record(uint8_t rollnum, STUDENT_RECORD *record, uint8_t max_record);

uint8_t const max_record = 10;
uint8_t continue_app = 1;

int main()
{
    while(continue_app)
    {
        display_menu();
    }
    return 0;
}

void display_menu()
{
    uint8_t choice;

    printf("\n");
    printf("1. Display all records\n");
    printf("2. Add new student\n");
    printf("3. Delete existed student\n");
    printf("0. Exit the application\n");
    printf("Enter your option: ");
    scanf("%u", &choice);
    switch (choice)
    {
        case 0:
            continue_app = 0;
            printf("Exiting option...\n");
            break;
        case 1:
            printf("\n***** Display all records *****\n");
            Display_records(students, max_record);
            break;
        case 2:
            printf("\n***** Add new student *****\n");
            uint8_t rollnum_add;
            printf("Enter roll number to add: ");
            scanf("%hhu", &rollnum_add);
            Add_new_record(rollnum_add, students, max_record);
            break;
        case 3:
        	uint8_t rollnum_del;
            printf("\n***** Delete existed student *****\n");
            printf("Enter roll number to delete: ");
            scanf("%hhu", &rollnum_del);
            uint8_t temp = Delete_record(rollnum_del, students, max_record);
            temp ? printf("Deleted successfully !\n") : printf("Deleted unsuccessfully !\n");
            break;
        default:
            printf("Invalid input option !\n");
            break;
    }
}

void Display_records(STUDENT_RECORD *record, uint8_t max_record)
{
    uint8_t is_empty = 0;
    for(uint8_t i = 0; i < max_record; i++)
    {
        if(record[i].RollNumber)
        {
            is_empty = 1;
            printf("*****************\n");
            printf("Roll number: %u\n", record[i].RollNumber);
            printf("Semester: %u\n", record[i].Semester);
            printf("Student name: %s\n", record[i].name);
            printf("Date of birth: %s\n", record[i].date);
            printf("Specialization: %s\n", record[i].branch);
            printf("*****************\n");
        }
    }
    if(!is_empty) printf("No record found. Please add new record !\n");
}

uint8_t Check_exist(uint8_t rollnum, STUDENT_RECORD *record, uint8_t max_record)
{
    uint8_t is_exist = 0;
    for(uint8_t i = 0; i < max_record; i++)
    {
        if(rollnum == record[i].RollNumber)
        {
            is_exist = 1;
            break;
        }
    }
    return is_exist;
}

void Add_new_record(uint8_t rollnum, STUDENT_RECORD *record, uint8_t max_record)
{
    uint8_t exist;
    uint8_t flag_full = 0;
    for(uint8_t i = 0; i < max_record; i++)
    {
    	flag_full = i;
        if(record[i].RollNumber == 0)
        {
            exist = Check_exist(rollnum, students, max_record);
            if(!exist)
            {

                record[i].RollNumber = rollnum;
                printf("Enter Semester: ");
                scanf("%hhu", &record[i].Semester);

                fflush(stdin);

                printf("Enter Student name: ");
                gets((record+i)->name);

                printf("Enter Student date: ");
                gets((record+i)->date);

                printf("Enter Student Specialization: ");
                gets((record+i)->branch);

            }
            else printf("Student already existed !\n");
            break;
        }
    }
    if(flag_full == max_record) printf("List is full !\n");
}

uint8_t Delete_record(uint8_t rollnum, STUDENT_RECORD *record, uint8_t max_record)
{
    uint8_t is_deleted = 0;
    for(uint8_t i = 0; i < max_record; i++)
    {
        if(rollnum == record[i].RollNumber)
        {
            is_deleted = 1;
            memset(&record[i],0,sizeof(STUDENT_RECORD));
            break;
        }
    }
    if(!is_deleted) printf("Record not found !\n");

    return is_deleted;
}
