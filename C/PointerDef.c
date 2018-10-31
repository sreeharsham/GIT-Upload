#include<stdio.h>
void main()
{
	int a = 10;
	int* aPtr = &a;
	printf("a is %d\n", a);
	printf("aPtr is %u\n", aPtr);
	printf("address of a is %d", &a);
	printf("*aPtr is %d\n", *aPtr);
}
