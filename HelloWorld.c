#include<stdio.h>
#include<conio.h>

struct Employee
{
    int ssn;
    char ename[20];
    char dept[20];
}emp[3];

//---------------------------------------------
void main()
{
int i,sum;

//Enter the Employee Details
for(i=0;i<3;i++)
    {
    printf("nEnter the Employee Details : ");
    scanf("%d %s %s",&emp[i].ssn,emp[i].ename,emp[i].dept);
    }
//Print Employee Details
for(i=0;i<3;i++)
       {
       printf("nEmployee SSN   : %d",emp[i].ssn);
       printf("nEmployee Name  : %d",emp[i].ename);
       printf("nEmployee Dept  : %d",emp[i].dept);
       }
getch(); 
}

