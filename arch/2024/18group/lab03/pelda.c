 #include <stdio.h>
 
 int pelda();
 
 int feladat1();
 
 int main(){
	 pelda();
	 
     return 0;
 }
 
 
 int pelda(){
	 int i;
	 char c;
	 unsigned int u;
	 float f;
	 
	 i = 'a';
	 c = 'a';
	 u = -1;
	 f = 19.5;
	 
	 printf("%d\n", i);
	 printf("%c\n", i);
	 printf("%d\n", c);
	 printf("%c\n", c);
	 printf("%u\n", u);
	 printf("%f\n", f);
	 

	
	 return 0;
 }