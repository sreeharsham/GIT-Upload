#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct transaction {
	char* sign;
	int *unixtime;
	double *tamt;
	char* desc;
}trans;
void main() {
		trans *tr = malloc(sizeof(trans));
char buff[1026];

FILE *fp;
//time_t utime;
fp = fopen("C:\\Users\\win 8.1\\Desktop\\testfile.txt","r");

while ( !feof(fp))
{
if (fgets(buff,sizeof(buff),fp) != NULL)
	{
		
		   char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "\t";
   char *token;
   struct tm ptr;
//   time_t t;
   
//   memset(&ptr,0,sizeof(struct tm));
//   const char *time_details = "16:35:12";
//struct tm tm;
//strptime(time_details, "%H:%M:%S", &tm);
//time_t t = mktime(&tm);
   
   /* get the first token */
   token = strtok(buff, s);
   tr->sign = token;
   tr->unixtime = atoi(strtok(NULL, s));
	tr->unixtime = ctime(&tr->unixtime);
	
//	strptime(tr->unixtime, "%a %b %d %X %Y", &ptr);
//	t = mktime(&ptr);
//	ptr = tr->unixtime;
//	strftime(str, 80, "%a %b %d %Y", ptr);
	
//	struct tm *tm = tr->unixtime;
//	strftime(tr->unixtime, 50, "%a %b %d %Y", t);
//	printf("Current Date: %s\n\n", time_details);
//	tr->unixtime = strptime(tr->unixtime, "%a %b %d %X %Y", &tm);
//	tr->unixtime = (tr->unixtime, sizeof(tr->unixtime), "%a %b %d %Y", &tm);
//	printf("%s \n", ctime(&tr->unixtime));
//	printf("%s", strftime(tr->unixtime,80,"%x - %I:%M%p", tr->unixtime));
	
   tr->tamt = strtok(NULL, s);
   tr->desc = strtok(NULL, s);
   
   //Wed Dec 31 05:07:13 2008
   /* walk through other tokens */
//   while( token != NULL ) {
//      printf( " %s\n", token );
//    
//      token = strtok(NULL, s);
//   }
			
		
		
////		printf("%s", buff);
//		char *start_ptr = buff;
////		printf("%s\n", buff);
//		start_ptr[3]='\0';
//		const char tab[2] = "\t";
//		char tabch = '\t';
//		char *tab_ptr;
//		
//		/* get the first token */
//   tab_ptr = strtok(buff, tab);
//   
//   /* walk through other tokens */
//   while( tab_ptr != NULL ) {
//      printf( " %s\n", tab_ptr );
//    
//      tab_ptr = strtok(NULL, tab);
   
//		 = strdup(strtok(buff, tab));
//		tab_pr = strchr(start_ptr, tabch);
//		printf("%s", strtok(buff, tab));
//		tr->sign = strdup(strtok(buff, tab));
//		tr->unixtime = strtok(NULL, tab);
//		printf("%s", buff);
//		printf("%s", tab_ptr);
//		if (tab_ptr != NULL) {
//			printf("wow");
////  				*tab_ptr++ = '\0';
//  					}
  		
//	printf("%s", tr->unixtime);

//	tr->sign = *start_ptr;
//	tr -> sign = *tab_ptr;

//	printf("%s\n", tr->sign);
//	start_ptr = tab_ptr;
//	tab_ptr = strchr(start_ptr, ’\t’);
//	if (tab_ptr != NULL) {
//  		*tab_ptr++ = ’\0’;
//  		}

	}
	printf("%s\t", tr->sign);
	printf("%s\t", (tr->unixtime));
	printf("%.2f\t", atof(tr->tamt));
//	printf("%s", ctime(atoi(tr->unixtime)));
	printf("%d ",atof(tr->tamt) > 100 ? 1:2);
	printf("%s\t", tr->desc);
}
}
