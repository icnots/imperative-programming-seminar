#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int fel1();
int fel2();
int fel3();
int fel4();
int randomSzamKiiras(int n);

int main(){
	srand(time(NULL));
	//fel1();
	//fel2();
	//fel3();
	//fel4();
	
	randomSzamKiiras(100);
	
	return 0;
}


int fel1(){
	int i;
	printf("sizeof(int): %d\n", (int)sizeof(i));
	printf("sizeof(long long): %d\n", (int)sizeof(long long));
	printf("sizeof(char): %d\n", (int)sizeof(char));
	printf("sizeof(short): %d\n", (int)sizeof(short));
		
	return 0;
}


int fel2(){
	int a = 8, b = 9, c = 10;
	
	if ((a < b) && (b < c)){
		printf("True\n");
	}else{
		printf("False\n");
	}
	
	a = -10, b = -9, c = -8;
	if ((a < b) && (b < c)){
		printf("True\n");
	}else{
		printf("False\n");
	}
	
	return 0;
}


int fel3(){
	/*
	i--; --i; i-=1; i+=-1; i=i-1;
	*/
	for (int i = 10; i >= 0; i = i-1){
		printf("%d ", i);
	}
	printf("\n");
	
	for (unsigned int i = 10; i < 11; i = i-1){
		printf("%d ", i);
	}
	printf("\n");
	
	return 0;
}


int fel4(){
	int valami;
	int n;
	printf("Give me a year!\n");
	fflush(stdout);
	scanf("%d", &n);
	
	valami =
		(n % 4 == 0 && n % 100 != 0) ||
		(n % 400 == 0);
	
	printf(
		"This year (%d) is %s.\n",
		n,
		valami ? "leap year" : "not a leap year"
	);
	
	return 0;
}


int randomSzamKiiras(int n){
	for (int i = 0; i < n; i++){
		int randomSzam = rand() % 11 + 100;
		printf("%d ", randomSzam);
	}
	printf("\n");
	return 0;
}