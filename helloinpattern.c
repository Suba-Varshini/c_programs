#include<stdio.h>
void main()
{
char str[]="hello";
int i=0,j;
while(str[i]!='\0')
{
for(j=0;j<=i;j++)
{
printf("%7c",str[j]);
}
printf("\n");
i++;
}
i=0;
while(str[i]!='\0')
{
for(j=0;j<=i;j++)
{
printf("%-7c",str[j]);
}
printf("\n");
i++;
}
}

