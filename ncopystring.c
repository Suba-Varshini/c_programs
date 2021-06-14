
#include <stdio.h>

int main()
{
    char text1[100];
    char text2[100];
	int n;
    int i;
    printf("Enter any string: ");
    scanf("%s",text1);
	printf("Enter number");
    scanf("%d",&n);
    for(i=0; i<=3; i++)
    {
        text2[i] = text1[i];
    }
    text2[i] = '\0';
    printf("First string = %s\n", text1);
    printf("Second string = %s\n", text2);
    printf("Total characters copied = %d\n", i);
    return 0;
}