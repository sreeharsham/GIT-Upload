#include<stdio.h>
#include<string.h>


void removeSpaces (char *str) {
    // Set up two pointers.
    char *src = str;
    char *dst = src;
    // Process all characters to end of string.
    while (*src != '\0') {
        // If it's not a space, transfer and increment destination.
        if (*src != ' ')
            *dst++ = *src;
        // Increment source no matter what.
        src++;
    }
    // Terminate the new string.
    *dst = '\0';
}


int main (void)
{
    char str[] = "This is a long    string with    lots of spaces...   ";
    printf ("Old string is [%s]\n", str);
    removeSpaces (str);
    printf ("New string is [%s]\n", str);
    return 0;
}

//
//void main() {
//	char *text = " Hello World    ";
//	char *blank = text;
////	char text[100], blank[100];
//	int c = 0; int d = 0;
////	printf("Enter text\n");
////	gets(text);
////	while(text[c] != '\0') {
////		if(!(text[c] == ' ' && text[c+1] == ' ')) {
////			blank[d] = text[c];
////			d++;
////		}
////		c++;
////	}
////	blank[d-1] = '\0';
//	while(*text != '\0') {
//		if(*text != ' ') {
//			*blank++ = *text;
//		}
//		text++;
//	}
//	*blank = '\0';
//	printf("AFTER\n:%sOVER", blank);
//} 
//

