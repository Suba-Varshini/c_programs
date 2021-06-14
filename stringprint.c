#include <stdio.h>
int main(void)
{
    char array[100],hello[]="hello";
    printf("Enter a string\n");
    scanf("%s", array);
    printf("Your string: %s\n", array);
	int i=0;
	while(hello[i]!='\0')
	{
		printf("%c\n",hello[i]);
		i++;
	}
    return 0;
}