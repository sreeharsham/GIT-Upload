#include<stdio.h>
#include<stdlib.h>
typedef struct Bank
{
	char* sign;
	char* desc;
	double amt;

	int timestamp;
	char* time;

	double balance;
}account;
void main() {
//	FILE *fp;
//	char buff[1024];
//	fp = fopen("C:\\Users\\win 8.1\\Desktop\\testfile.txt", "r");
//	
//	fgets(buff, 1024, fp);
//	
//	fclose(fp);
//FILE *fileStream; 
//char fileText[100];
//fileStream = fopen ("C:\\Users\\win 8.1\\Desktop\\C\\example.txt", "r");
//fgets (fileText, 100, fileStream);
//fclose(fileStream);
char buff[1026];
typedef struct transactions {
	char *ttype;
	char unixtime;
	char tamount;
	char *tdesc;
//	double tbalance;
	}trans;
FILE *fp;
char line[1026];
time_t timet,timetcurr;
char *p,*amt,*timec,*desc;
int timei,i,lc=0,tc=0,lineno=1;
struct tm *newtime;
//char *type, *time, *desc;
//double *amt;
//int lineno = 0;
if ((fp = fopen("C:\\Users\\win 8.1\\Desktop\\testfile.txt","r")) == NULL)
{
	printf("Could not open myinputfile.txt\n");
	exit(1);
}


//My420List list;
//if (!My402ListInit(&list)) { 
///* error */
// }
//if (!ReadInput(fp, &list)) { 
///* error */
// }
//if (fp != stdin) fclose(fp);
//SortInput(&list);
//PrintStatement(&list);


trans *tr = malloc(sizeof(trans));
while ( !feof(fp))
{
	// read in the line and make sure it was successful
	if (fgets(buff,sizeof(buff),fp) != NULL)
	{
//		printf("%d: %s",lineno++,buffer);

//		if(tabptr != NULL) {
//			  *tabptr++ = '\0';
//		}
//		printf("%s", buffer);
		
		trans *t = malloc(sizeof(trans));
		account *ac=malloc(sizeof(account));
		p = strdup(strtok(line,"\t"));
		ac->sign=p;
		timec = strdup(strtok (NULL,"\t"));
		timei=atoi(timec);
		ac->timestamp=timei;
		timet=timei;                  /*time_t variable*/
		newtime=localtime(&timet);
		time(&timetcurr);
		ac->time=strdup(asctime(newtime));
		ac->time=rearrangetime(ac->time);
		amt = strdup(strtok (NULL,"\t"));
		ac->amt=(double)atof(amt);
		desc = strdup(strtok (NULL,"\t"));
		desc[strlen(desc)-1]='\0';
		ac->desc=desc;
		trim(ac->desc);
		My402ListAppend(list,ac);
		lineno++;

//		printf("%s", buff);
	}
	
	
//printf("%d", strlen(buffer));

}
//printf("%s", buff);
}
