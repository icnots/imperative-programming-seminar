#include <stdio.h>


int main(){
	int n;
	int max;
	//int a, b;
	int i = 1; /* int i; i = 1; */
	printf("%d\n", i);
	
	i = -8;
	if (i % 2 == 0){
		printf("%d is even.\n", i);
	}else{
		printf("%d is odd.\n", i);
	}
	fflush(stdout);
	
	/* 3. feladat */
	/*
	scanf("%d", &n);
	while(n % 2 == 0){
		printf("%d is even.\n", n);
		fflush(stdout);
		scanf("%d", &n);
	}
	printf("%d is odd.\n", n);
	*/
	
	/* 4. feladat */
	n = 3.14;
	printf("3.14: %d\n", n);
	
	n = 'A';
	printf("A: %d\n", n);
	
	n = 0 < 1;
	printf("0 < 1: %d\n", n);
	
	//n = "ferike";
	//printf("\"ferike\": %d\n", n);
	
	/* 5. feladat */
	/*
	scanf("%d", &a);
	scanf("%d", &b);
	printf("average: %.1f\n", (a+b)/2.0);
	*/
	
	/* 6. feladat */
	/*
	for (float f = 0.0; f <= 1.01; f = f + 0.1){
		printf("%f\n", f);
	}
	*/
	for (i = 0; i <= 10; i += 1){
		printf("%f\n", i/10.0);
	}
	
	
	max = 1;
	for (unsigned int m = 0; m < sizeof(int)*8-2; m++){
		max *= 2;
		max += 1;		
	}
	printf("max: %d\n", max);
	printf("min: %d\n", max+1);
	
	return 0;
}