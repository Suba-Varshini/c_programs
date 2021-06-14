#include <stdio.h>
int main()
{
int r;
printf("enter r");
scanf("%d",&r);
int i,m,k,c,s;
for(i=0;i<r;i++)
{
    for (s=0;s<r-i;s++)
    {
    printf(" ");
    }
    c=r-i-1;
    m=i+1;
    while(c!=r)
    {
        printf("%d",m);
        m++;
        c++;
    }
    for(k=m-2;k>=i+1;k--)
    printf("%d",k);
    printf("\n");
}
return 0;
}
