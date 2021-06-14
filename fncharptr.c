#include<stdio.h>
#include<string.h>
void swap(char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}
void sort(char **a, int size)
{
    int i, j, compare;
    for (i = 0; i < size; i++){
        for (j = i; j < size; j++){
            compare = strcasecmp((a[i]), (a[j]));
            if (compare > 0)
                swap(&a[i], &a[j]);
        }
    }
}
void nameswitha(char **a, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i][0]=='A'|| a[i][0]=='a')
			printf("%s",a[i]);
	}
}
int main()
{
	char*ptr[7]={"Melo","Sri","Chad","Tyler","Aimmy","Davis","Porter"};
	int i;
	for(i=0;i<7;i++)
	{
	printf("%s\n",ptr[i]);
	}
	sort(ptr,7);
	for(i=0;i<7;i++)
    {
	printf("name %d is %s \n",i+1,ptr[i]);
    }
	printf("names with A or a is ");
	nameswitha(ptr,7);
	printf("\n");
return 0;
}