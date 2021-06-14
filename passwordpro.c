#include<stdio.h>
#include<string.h>
int main()

{
	int r;
	char password[20];
	char password_correct[20]="admin_id";
	char *ptr1=password;
	char *ptr2=password_correct;
	while(r==0)
	{
		printf("\nEnter the password: ");
	    scanf("\n%s",password);
		while(*ptr1!='\0')
		{
			if(*ptr1==*ptr2)
			{
				ptr1++;
				ptr2++;
				r=1;
			}
			else
				break;
		}
		if(r==1)
		{
			printf("YOU CAN LOG IN NOW\n");
			break;
		}
		else
			printf("try again\n");
	}
	return 0;
}