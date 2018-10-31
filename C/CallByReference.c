#include<stdio.h>

void swap(int*, int*);
void main()
{
	int a = 10, b = 20;
	printf("Before Swap:\t a: %d\t b: %d\n ", a, b);
	swap(&a,&b);
	printf("After Swap:\t a: %d\t b: %d\n ", a, b);
}

void swap(int* x, int* y)
{
	int temp = *x;
	
//	int* temp = *x;
	*x = *y;
	*y = temp;
}
