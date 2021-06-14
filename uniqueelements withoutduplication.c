#include <stdio.h>
int main()
{
    int i,n,arr[50],c=0;
    printf("enter the number of elements\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the element arr[%d]\n",i);
        scanf("%d",&arr[i]);
    }
    for (i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                c++;
                break;
            }
        }
        if(c==0)
        printf("%d\t",arr[i]);
        c=0;
    }
    return 0;
}