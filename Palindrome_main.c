#include <stdio.h>
#include <stdlib.h>

int main() {
	int num = 0;
	int reverse = 0;
	int original = 0;
	
	printf("Please input a number:\n");
	scanf("%d", & num);
	
	original = num;
	
	while (num != 0)
     {reverse= ((reverse*10) + (num % 10));
  	  num= num/10;}
	
	if (original == reverse)
    { printf("%d is a palindrome!", original);}	
    else 
    { printf("%d is not a palindrome!", original);}
    
	return 0;
}
