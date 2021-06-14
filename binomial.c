#include<stdio.h>
int binomial(int n, int k);
 
int main()
{
        int m,x;
        printf("Enter m and x : \n");
        scanf("%d%d",&m,&x);
        printf("\nBinomial of %d and %d is \n",m,x);
        printf("%d\n",binomial(m,x));
        return 0;
}
int binomial(int n, int k)
{
        if(k==n || k==0)
                return 1;
        return binomial(n, k-1) * (n-k+1)/k;
}

