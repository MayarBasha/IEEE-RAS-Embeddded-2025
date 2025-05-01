#include <stdio.h>
#include <stdlib.h>
struct empolyee {
char name[50];
int salary;
int id;
char job_title[50];
};

int main()
{

   struct empolyee E ={"Ahmed",20000,125968,"Architect" };
printf("name: %s\nsalary: %d\nid: %d\njob title: %s\n",E.name,E.salary,E.id,E.job_title);


    return 0;
}
