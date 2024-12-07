#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct //store the detail of all the students
{
    int srno;
    char name[50];
    char rollno[10];
    float att;
    char email[100];

}student;

typedef struct //stores the detail of all the students whose attandance is less than 80%
{
    int srno;
    char name[50];
    char rollno[10];
    float att;
    char email[100];

}low_att;


int main()
{
    FILE * fptr;
    fptr = fopen("CSE_3rd_Sem_Attandance_ODD_24.csv","r");

    char data[MAX_LINE_LENGTH]; //collect non-useful data

    // Skip first 11 lines
    for (int i = 0; i < 11; i++) {
        fgets(data, sizeof(data), fptr);
    }

    int n = 0;
    student s[100];
    low_att l[100];
    int j, i = 0, a;

    while (n < 69) //fetch (read) data of student from the excel sheet starting from line 12
    {
        fscanf(fptr, "%d ,%9[^,], %49[^,],%3[^,], %f", &s[n].srno, s[n].rollno, s[n].name, data, &s[n].att);
        fgets(data, sizeof(data), fptr);
        n++;
    }

    printf("what do you want?\n\n");
    printf("enter 1 to see details of all the students in class\n");
    printf("enter 2 for email ids of all the student\n");
    printf("enter 3 to see details of student who have less than 80%% attandance\n");
    printf("enter 4 for email ids of all the student who has less than 80%% attandance\n");

    scanf("%d", &a);

    if (a == 1) //prints the detail of all the students
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d %s %s %.2f\n", s[i].srno, s[i].rollno, s[i].name, s[i].att);
        }
    }

    if (a == 2)
    {
        for (i = 0; i < n; i++)
        {
            strcat(s[i].email, s[i].rollno);
            strcat(s[i].email, "@sot.pdpu.ac.in");
            printf("%s,", s[i].email);
        }
    }

    if (a == 3) //prints the details of all the students whose attandance is less than 80%
    {
        for (i = 0, j = 0; i < n; i++)
        {
            if (s[i].att < 80)
            {
                l[j].att = s[i].att;
                l[j].srno = s[i].srno;
                strcpy(l[j].name, s[i].name);
                strcpy(l[j].rollno, s[i].rollno);
                j++;
            }
        }

        for (i = 0; i < j; i++)
        {
            printf("%d %s %s %.2f\n", l[i].srno, l[i].rollno, l[i].name, l[i].att);
        }
    }

    if (a == 4) //prints the email id of all students whose attandance is less than 80%
    {
        for (i = 0, j = 0; i < n; i++)
        {
            if (s[i].att < 80)
            {
                l[j].att = s[i].att;
                l[j].srno = s[i].srno;
                strcpy(l[j].name, s[i].name);
                strcpy(l[j].rollno, s[i].rollno);
                j++;
            }
        }

        for (i = 0; i < j; i++)
        {
            strcat(l[i].email, l[i].rollno);
            strcat(l[i].email, "@sot.pdpu.ac.in");
            printf("%s,", l[i].email);
        }
    }

    return 0;
}
