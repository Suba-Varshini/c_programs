#include <stdio.h> 
#include<string.h>
void isPalindrome(char* str) 
{ 
    char *ptr, *rev; 
    ptr = str; 
    while (*ptr != '\0')
	{ 
        ++ptr; 
    } 
    --ptr; 
    for (rev = str; ptr >= rev;) 
	{ 
        if (*ptr == *rev) 
		{ 
            --ptr; 
            rev++; 
        } 
        else
            break; 
    } 
    if (rev>ptr) 
        printf("Palindrome\n"); 
    else
        printf("not a Palindrome\n"); 
} 
int main() 
{ 
    char str[100];
	printf("enter the string\n");
	scanf("%[^\n]s",str);
    isPalindrome(str); 
    return 0; 
} 