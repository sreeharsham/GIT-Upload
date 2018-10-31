#include<stdio.h>
void main()
{
	int a = 10, b = 20;
	printf("Before Swap:\t a: %d\t b: %d\n ", a, b);
	swap(a,b);
	printf("After Swap:\t a: %d\t b: %d\n ", a, b);
}

void swap(int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
	printf("After Swap:\t a: %d\t b: %d\n ", x, y);
}
