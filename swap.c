#include <stdio.h>
#include <limits.h>


void printBits(unsigned int num)
{
   for(int bit=0;bit<(sizeof(unsigned int) * 8); bit++)
   {
      printf("%i", num & 0x01);
      num = num >> 1;
   }
   printf("\n");
}


int main() {

char a;
char b;
printf("Enter two characters: \n");
printf("a:");
scanf("%c",&a);
printf("b:");
scanf("%c",&b);

int a1 = a;
int b1 = b;

printf("Ascii value for a: %d",a1);
printf("Ascii value for b: %d",b1);

unsigned a_num = a1;
unsigned b_num = b1;

printf("%d: ", a_num);
printBits(a_num);
printf("%d: ", b_num);
printBits(b_num);
printf("XOR of %d and %d: ", a_num, b_num);
printBits((a_num)^(b_num));
printf("XOR of %d and %d and %d: ", a_num, b_num, a_num);
printBits((a_num)^(b_num)^(a_num));

/*

unsigned a, b;
a = 5;
b = 9;

printf("%d: ", a);
printBits(5);
printf("%d: ", b);
printBits(9);
printf("XOR of %d and %d: ", a, b);
printBits(a^b);
printf("XOR of %d and %d and %d: ", a, b, a);
printBits(a^b^a);

//b = (a+b) - (a=b);

b = (a^b) ^ (a=b);


printf("Final (a,b): %u %u", a, b);



*/
return 0;
}
