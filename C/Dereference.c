#include<stdio.h>

void main() {

int a = 3; 
int *b = &a;
int **c = &b;
int ***d = &c;
printf("&a:%d\n", &a);

printf("b:%d\n", b);

printf("&b:%d\n", &b);

printf("*b:%d\n", *b);

printf("&c:%d\n", &c);

printf("*c:%d\n", *c);

printf("**c:%d\n", **c);

printf("d:%d\n", d);

printf("&d:%d\n", &d);

printf("*d:%d\n", *d);

printf("**d:%d\n", **d);

printf("***d:%d\n", ***d);
}
