#include <stdio.h>

int main() {
//QUESTION 1 (Hollow Diamond)
	int x,y,z, rows;
	printf("How many rows should your diamond have?\n");
	scanf("%d", & rows);

	for(x=1;x<=rows;x++){
		for(y=rows;y>=x;y--){
			printf(" ");
		}
		for (z=1;z<=x;z++){
			if(z==1||z==x){
				printf("* ");	
			}
			else{
				printf("  ");
			} 
		}
		printf("\n");
	}
	
	for(x=1;x<=rows;x++){
		for (z=1;z<=x;z++){
			printf(" ");
		}
		for(y=rows;y>=x;y--){
		if(y==rows||y==x){
				printf("* ");	
			}
			else{
				printf("  ");
			} 
		}
		printf("\n");
	}
	
//QUESTION 2 (Hollow Inverted Triangle)	

    printf("How many rows should your triangle have?\n");
	scanf("%d", & rows);
	
    for (x=1; x<2*rows; x++) {
        printf("*");
     }
     printf("\n");
     
    for(x=1;x<=rows-1;x++){
		for (z=1;z<=x;z++){
			printf(" ");
		}
		for(y=rows-1;y>=x;y--){
	    	if(y==rows-1||y==x){
				printf("* ");	
			}
	    	else{
				printf("  ");
			} 
		}
		printf("\n");
	}

	return 0;
}
