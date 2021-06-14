#include <string.h>
 #include<stdio.h>
int main()
{
    char str[100],c1,c2;  
    int  i;
 
    printf("Enter  the string : ");
    fgets(str, sizeof(str), stdin);
    
    printf("Enter a character to find its frequency: ");
    scanf("%c", &c1);
    printf("Enter a character to find its frequency: ");
    scanf("%c", &c2);
    printf("\n before replace:%s",str);
    
    for(i=0;str[i];i++)
	{  
		if(str[i]==c1)
		{
		   str[i]=c2;
	 
	    }
 
	}
    printf("\nafter replace:%s",str);
 	 
    return 0;
}