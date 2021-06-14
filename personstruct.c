#include <stdio.h>
#include<stdlib.h>
struct person 
{
   char name[50];
   int age;
   float height,weight;
};
struct person* person_create(struct person* per)
{
	int i;
	per = (struct person*) malloc(10 * sizeof(struct person*));
	for(i=0;i<10;i++)
	{
		printf("PERSON:%d\n",i+1);
		printf("Enter the name:\n");
		scanf("%s", (per+i)->name);
		printf("Enter the age:\n");
		scanf("%d", &(per+i)->age);
		printf("Enter the height:\n");
		scanf("%f", &(per+i)->height);
		printf("Enter the weight:\n");
		scanf("%f", &(per+i)->weight);
	}	
	return per;
}
void display(struct person* per)
{
	int i;
	for(i=0;i<10;i++)
	{
		printf("PERSON:%d\n",i+1);
		printf("name:   %s\n",(per+i)->name);
		printf("age :   %d\n",(per+i)->age);
		printf("height: %2f\n",(per+i)->height);
		printf("weight: %2f\n",(per+i)->weight);
	}	
}
void disp_max_age(struct person* per)
{
	int i,j;
    int pos;
    for (i = 0; i < 10; i++) 
	{
		pos=i;
      for (j = i+1; j < 10; j++) 
	  {
         if ((per+pos)->age < (per+j)->age)
            pos = j;
      }
    }
	printf("the person with max age is\n");
		printf("PERSON:%d\n",pos+1);
		printf("name:   %s\n",(per+pos)->name);
		printf("age :   %d\n",(per+pos)->age);
		printf("height: %2f\n",(per+pos)->height);
		printf("weight: %2f\n",(per+pos)->weight);

}

int main()
 {
   int i;
   struct person *p;
   p=person_create(p);
   printf("DISPLAY DETAILS\n");
   printf("\n");
   printf("\n");
   display(p);
   printf("\n");
   printf("\n");
   printf("PERSON WITH MAX AGE IS:\n");
   disp_max_age(p);
   return 0;
}

