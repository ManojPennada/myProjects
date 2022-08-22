/* 
Title 			: 	A Program to calculate the Sum and Product of two large numbers (say 50 digits)
Group Number 	: 	3
Group Members 	:
					1. Pennada Manoj Harshavardhan Teja - 	AP21110010547
					2. Sarvani Panchumarthy 			- 	AP21110010548
					3. Darapureddy Rahul Sarvesh 		- 	AP21110010550
					4. Vuhaaditya Kancharalapalli 		- 	AP21110010554
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a>=b)?(a):(b))

char 	str1[50] , str2[50] ;
int 	arr1[50] , arr2[50] 	, arr3[100] ;
int 	i , j , l, len1, len2 	, choice = 0 , carry = 0;
char    c , sign[3] ;

int makezero()
{
	for( i =0 ;i<50; i++ )
	{
		arr1[i]  = 0;
		arr2[i] = 0;
	}
	for(i= 0; i<100;i++)
	{
		arr3[i] = 0;
	}
}

int removezero(int a)
{
	i = a;
	while(1)
	{
		if(arr3[i] == 0)
		i--;
		else
		break;
	}
	return i;
}

int store_num()
{
	now:
	printf("Please Enter sign of the Number 1 ('+' OR '-') : ");
	scanf("%c" ,&sign[0]);
	printf("Enter Number 1: ");
	scanf("%s" ,str1);	
	printf("\nPlease Enter sign of the Number 2 ('+' OR '-') : ");
	fflush(stdin);
	scanf("%c" ,&sign[1]);
	printf("Enter Number 2: ");
	scanf("%s",str2);
	len1 = strlen(str1);
	len2 = strlen(str2);
	for(i = len1 - 1; i >= 0 ; i--)
   		arr1[i] = str1[(len1 - i) - 1] % 48;
    for(i = len2 - 1; i >= 0 ; i--)
	   	arr2[i] = str2[(len2 - i) - 1] % 48;
    return 0;
}

int show()
{
	printf("\n---------------------------------------------------------------------------\n");
	printf("The Entered Number 1 is : ");
	for(i = strlen(str1) - 1 ; i >=0  ; i--)
	printf("%d",arr1[i]);
	printf("\nThe Entered Number 2 is : ");
	for(i = strlen(str2) - 1 ; i >=0 ; i--)
	printf("%d",arr2[i]);
	printf("\n---------------------------------------------------------------------------\n");
	return 0;
}

int visual(char c)
{
	printf("\n---------------------------------------------------------------------------\n");
    printf("\t  ");
    if(len1>=len2)
    {
    	for(i = len1 - 1 ; i >=0  ; i--)
		printf("%d",arr1[i]);
		printf("\n\t%c ",c);
    	for(i=1;i<=len1 - len2;i++)
    	printf(" ");
    	for(i = len2 - 1 ; i >=0 ; i--)
		printf("%d",arr2[i]);
	}
	else
	{ 
		for(i = len2 - 1 ; i >=0 ; i--)
		printf("%d",arr2[i]);
		printf("\n\t%c ",c);
		for(i=1;i<=len2 - len1;i++)
    	printf(" ");
    	for(i = len1 - 1 ; i >=0  ; i--)
		printf("%d",arr1[i]);
	}
	return 0;
}

int add()
{
	if(sign[0] == '-' && sign[1] == '+' || sign[0] == '+' && sign[1] == '-')
	{
		printf("\nAddition for two different signed numbers is not built\n");
		return 0;
	}
	
	if(sign[0] == '+' && sign[1] == '+')
	sign[2] = '+' ;
	
	else if (sign[0] == '-' && sign[1] == '-')
	sign[2] = '-' ;
	
    c = '+';
    visual(c);
	l = max(len1,len2);
	for(i = 0; i<l; i++)
	{
		arr3[i] += arr1[i] + arr2[i];
		carry = arr3[i] / 10;
		arr3[i] = arr3[i] % 10;
		arr3[i+1] = arr3[i+1] + carry;
	}
	i = removezero(l + 1);
	printf("\n---------------------------------------------------------------------------");
	printf("\nSum :\t%c ",sign[2]);
	for(i; i>=0 ; i--)
	printf("%d",arr3[i]);
	return 0;
}

int product()
{
	if(sign[0] == '-' && sign[1] == '+' || sign[0] == '+' && sign[1] == '-')
	sign[2] = '-';
	
	else if(sign[0] == '+' && sign[1] == '+' || sign[0] == '-' && sign[1] == '-')
	sign[2] = '+';
	
    c = '*';
    visual(c);
	for(i = 0 ; i < len1 ;i++)
	{
		for(j = 0 ; j < len2 ;j++)
		{
			arr3[i+j] = ( arr1[i] * arr2[j] ) + arr3[i+j];
		}
	}
	for(i = 0 ; i < (len1 + len2) ; i++)
	{
		carry = arr3[i] / 10;
		arr3[i] = arr3[i] % 10;
		arr3[i+1] = arr3[i+1] + carry;
	}
	
	i = removezero(len1+len2);	// remove excess zeros in the final product
	
	if(i <= 0)
	printf("\nProduct = 0");
	
	else
	{
		printf("\n---------------------------------------------------------------------------");
		printf("\nProduct = (%c) ",sign[2]);
		for(i; i >= 0 ; i--)
		printf("%d",arr3[i]);
	}
	
	return 0;
}

int main()
{	
	makezero();			// to set the memory blocks default to zero
	
	store_num();		// to store the numbers
	
	show(); 		 	// to show the stored numbers
	printf("\n");
	
	back :
	printf("Enter 1 for Addition\n");
	printf("Enter 2 for Multiplication\n");
	printf("Choice : ");
	scanf("%d",&choice);
	printf("\n");
	
	switch(choice)
	{
		case 1 : add();			// addition is done here
				 break;
				 
		case 2 : product();		// product is calculated here
				 break;
				 
		default : printf("Please :\n");
				  goto back;
						 
	}
	
	return 0;
}