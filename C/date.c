#include<stdio.h>
#include<time.h>
#include<string.h>

void main()
{
char *epochtime = "1230728833";
char *etime = "1263142433";
long d = atoi(epochtime);
long e = atoi(etime);
if(d > e){
	printf("WRONG!");
}
else {
	printf("RIGHT");
}
}
