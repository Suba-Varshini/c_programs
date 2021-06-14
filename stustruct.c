#include <stdio.h>
struct person 
{
   char *name[50];
   int age;
   float height,weight;
};
person person_create(struct person* per)
{
	per = (struct person*) malloc(10 * sizeof(struct person*));
	for(i=0;i<3;i++)
	{
		printf("Enter the name:\n");
		scanf("%s", (per+i)->name);
		printf("Enter the age:\n");
		scanf("%d", (per+i)->age);
		printf("Enter the height:\n");
		scanf("%f", (per+i)->height);
		printf("Enter the weight:\n");
		scanf("%f", (per+i)->weight);
	}	
}
	
void display(struct student s[10])
{
	int i;
   printf("\nDisplaying information\n");
   for(i=0;i<5;i++)
   {
   printf("Name: %s", s[i].name);
   printf("Age: %d\n", s[i].age);
   }
}

int main()
 {
   int i;
   struct person *p;
   p=person_create(p);

   return 0;
}

