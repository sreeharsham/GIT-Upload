#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include "cs402.h"
#include <ctype.h>
#include "my402list.h"
#include <locale.h>
#include <pthread.h>
#include <unistd.h>
#include <signal.h>

void *tokenbucket(void *);
void *packetarrival(void *);
void *serverone(void *);
void *servertwo(void *);
My402List q1buff, q2buff;
//global value declaration
// int lambdavalue = 1;
double lambdavalue = 2;
double muvalue = 0.35;
// double rvalue = 1.5;
double rvalue = 4;
int Bvalue = 10;
long Pvalue = 3;
long numvalue = 20;
int arrtok, tokcap, tokdrop;
int packetnum, numberofpackets;
int endofpacketgen;
int emptybuffercheck;
struct timeval tvalBefore;
struct timeval tvalAfter;
struct timeval tokbucktime;
struct timeval packtime;

pthread_mutex_t mutexvar = PTHREAD_MUTEX_INITIALIZER;

pthread_t tdep, parr, serv1, serv2, termination;



// //struct for packet execution
typedef struct packetinfo {
	double packintarrtime;
	int nooftokens;
	int currpackno;
	double servicetime, q1start, q1end, q2start, q2end, servstart, servend;
}packinfo;

packinfo *packet, *temppacket, *tokenpacket;



// //thread functions

void *tokenbucket(void *arg) {
	printf("Token Bucket thread\n");
	// int i;
	// i = 0;
	double tokenarrivaltime = 1/rvalue;
	
	printf("TOKEN ARRIVAL TIME:\t %f\n", tokenarrivaltime);
	My402ListElem *ele;
	while(1){
	usleep(tokenarrivaltime * 1000000);
	if(My402ListEmpty(&q1buff) == FALSE || endofpacketgen > 0){
		printf("LENGTH OF Q1 : %d\t\tEOP gen: %d\n", My402ListLength(&q1buff) , endofpacketgen);
		if(tokcap < Bvalue) {
			pthread_mutex_lock(&mutexvar);
			arrtok++;
			tokcap++;
			
			gettimeofday (&tokbucktime, NULL);
			// usleep(2000000);
			fprintf(stdout, "%012.3fms: token t%d arrives, token bucket now has %d token\n", (tokbucktime.tv_sec * 1000 +  tokbucktime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), arrtok, tokcap);
			pthread_mutex_unlock(&mutexvar);
		}

		else {
		tokdrop++;
		arrtok++;
		gettimeofday(&tokbucktime, NULL);
		fprintf(stdout, "%012.3fms: token t%d arrives, dropped\n", (tokbucktime.tv_sec * 1000 +  tokbucktime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), arrtok);
		// break;
	}
	pthread_mutex_lock(&mutexvar);
	if(My402ListEmpty(&q1buff) == FALSE) {
		ele = My402ListFirst(&q1buff);
		tokenpacket = (packinfo*) ele->obj;
			if(tokcap >= tokenpacket->nooftokens) {
		// // 	printf("-------------------------------------ENOUGH TOKENS!!\n");
			// temppacket = packet;
		// 	My402ListUnlink(&q1buff, My402ListFirst(&q1buff));
		// 	gettimeofday(&packtime, NULL);
		// 	packet->q1end = (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001);
			tokcap = tokcap - tokenpacket->nooftokens;
			My402ListUnlink(&q1buff, My402ListFirst(&q1buff));
		// 	printf("\t\t%d\n", tokcap - packet->nooftokens);
			
			// fprintf(stdout, "%012.3fms: p%d leaves Q1, time in Q1 = %.3fms, token bucket now has %d tokens\n", (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), packet->currpackno, packet->q1end - packet->q1start, tokcap);
		// 	My402ListAppend(&q2buff, temppacket);
			gettimeofday(&packtime, NULL);
			tokenpacket->q1end = (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001);
			fprintf(stdout, "%012.3fms: p%d leaves Q1, time in Q1 = %.3fms, token bucket now has %d tokens\n", (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), tokenpacket->currpackno, tokenpacket->q1end - tokenpacket->q1start, tokcap);
			My402ListAppend(&q2buff, temppacket);
			tokenpacket->q2start = (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001);
			fprintf(stdout, "%012.3fms: p%d enters Q2\n", (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), tokenpacket->currpackno);
			
		}
	}
	pthread_mutex_unlock(&mutexvar);
	}
	else {
		break;
	}

}
	return 0;
}


void *packetarrival(void *arg) {
	printf("Packet Arrival thread\n");
	double packetarrivaltime = 1/lambdavalue;
	double lastarrivedtime;
	int i;
	endofpacketgen = numvalue;
	// packinfo *packet, *temppacket;
	printf("PACKET ARRIVAL TIME:\t%f\n", packetarrivaltime);
	numberofpackets = numvalue;

	// while(1) {
		for(i = 0; i < numberofpackets; i++) {
		usleep(packetarrivaltime * 1000000);
		pthread_mutex_lock(&mutexvar);
		// if (packetnum >= numvalue) {
		// 	break;
		// }
		packetnum++;
		packet = malloc(sizeof(packinfo));
		packet->packintarrtime = packetarrivaltime;
		packet->currpackno = packetnum;
		packet->nooftokens = Pvalue;
		gettimeofday (&packtime, NULL);
		
		// fprintf(stdout, "-------------->%012.3f\n",lastarrivedtime);
		fprintf(stdout, "%012.3fms: p%d arrives, needs %d tokens, inter-arrival time = %.3fms\n", (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), packet->currpackno, packet->nooftokens, (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001) - lastarrivedtime);
		lastarrivedtime = (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)- (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001);
		emptybuffercheck = My402ListEmpty(&q1buff);
		My402ListAppend(&q1buff, packet);
		gettimeofday(&packtime, NULL);
		packet->q1start = (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001);
		// if (My402ListLength(&q1buff) == 1 && tokcap > packet->nooftokens) {
		fprintf(stdout, "%012.3fms: p%d enters Q1\n", (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), packet->currpackno);
		// printf("\t\t\t\t%d\n", tokcap);
		printf("emptybuffercheck: \t%d\n", emptybuffercheck);
		printf("\n\nTOKCAP:\t\t%d\tNOOFTOKENS:\t\t%d\n\n", tokcap, packet->nooftokens);
		if(emptybuffercheck == TRUE && tokcap >= packet->nooftokens) {
		// // 	printf("-------------------------------------ENOUGH TOKENS!!\n");
			temppacket = packet;
		// 	My402ListUnlink(&q1buff, My402ListFirst(&q1buff));
		// 	gettimeofday(&packtime, NULL);
		// 	packet->q1end = (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001);
			tokcap = tokcap - packet->nooftokens;
			My402ListUnlink(&q1buff, My402ListFirst(&q1buff));
		// 	printf("\t\t%d\n", tokcap - packet->nooftokens);
			
			// fprintf(stdout, "%012.3fms: p%d leaves Q1, time in Q1 = %.3fms, token bucket now has %d tokens\n", (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), packet->currpackno, packet->q1end - packet->q1start, tokcap);
		// 	My402ListAppend(&q2buff, temppacket);
			gettimeofday(&packtime, NULL);
			packet->q1end = (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001);
			fprintf(stdout, "%012.3fms: p%d leaves Q1, time in Q1 = %.3fms, token bucket now has %d tokens\n", (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), packet->currpackno, packet->q1end - packet->q1start, tokcap);
			My402ListAppend(&q2buff, temppacket);
			packet->q2start = (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001);
			fprintf(stdout, "%012.3fms: p%d enters Q2\n", (packtime.tv_sec * 1000 +  packtime.tv_usec * 0.001)   - (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001), packet->currpackno);
			
		}
	// }
		endofpacketgen--;
		pthread_mutex_unlock(&mutexvar);

	}
		// }	
	// int i;
	// i = 0;
	// while(i < 10) {
	// packetnum++;
	// gettimeofday (&tvalAfter, NULL);
	// printf("%ldms: p%d arrives, needs %d tokens, inter-arrival time = %ldms\n", (tvalAfter.tv_sec - tvalBefore.tv_sec) +  tvalAfter.tv_usec - tvalBefore.tv_usec, packetnum, Pvalue, (tvalAfter.tv_sec - tvalBefore.tv_sec) +  tvalAfter.tv_usec - tvalBefore.tv_usec);
	// i++;
	// }
	return NULL;

}

void *serverone(void *arg) {
	// printf("Server One thread\n");
	// printf("p2 leaves Q2, time in Q2 = ms\n");
	// printf("p1 begins service at S1, requesting ms of service\n");
	// printf("p1 departs from S1, service time = ms, time in system = ms\n");
	return NULL;

}

void *servertwo(void *arg) {
	// printf("Server two thread\n");
	// printf("p2 leaves Q2, time in Q2 = ms\n");
	// printf("p1 begins service at S2, requesting ms of service\n");
	// printf("p1 departs from S2, service time = ms, time in system = ms\n");
	return NULL;

}


int main(int argc, char *argv[]) {
	
	(void)My402ListInit(&q1buff);
	(void)My402ListInit(&q2buff);
	// char buff[1026];
	// FILE *fp;
	// printf("BEFORE TIME:%ld\n", tvalBefore.tv_usec);
	fprintf(stdout, " Emulation Parameters:\n");
	fprintf(stdout, "     number to arrive =%ld\n", numvalue);
    fprintf(stdout, "     lambda = %.6g\n", lambdavalue); 
    fprintf(stdout, "     mu = %.6g\n", muvalue);
    fprintf(stdout, "     r = %.6g\n", rvalue);
    fprintf(stdout, "     B = %d\n", Bvalue);
    fprintf(stdout, "     P = %ld\n", Pvalue);
    fprintf(stdout, "     tsfile = FILENAME\n");
     // lambda = 2
        // mu = 0.35
        // r = 4
        // B = 10
        // P = 3
        // tsfile = FILENAME");
    gettimeofday (&tvalBefore, NULL);
	fprintf(stdout, "00000000.000ms: emulation begins\n");
	pthread_create(&tdep, NULL, &tokenbucket, NULL);
	pthread_create(&parr, NULL, &packetarrival, NULL);
	pthread_create(&serv1, NULL, &serverone, NULL);
	pthread_create(&serv2, NULL, &servertwo, NULL);


	pthread_join(tdep, NULL);
	pthread_join(parr, NULL);
	pthread_join(serv1, NULL);
	pthread_join(serv2, NULL);

	// gettimeofday (&tvalBefore, NULL);
	// printf("beforetvsec= %ld\n", tvalBefore.tv_usec);
    // int i =0;
    // while ( i < 1000) {
    //     i ++;
    // }
    // sleep(3);

    gettimeofday (&tvalAfter, NULL);
    // printf("aftertvsec= %ld\n", tvalAfter.tv_usec);
    printf("%012.3fms: emulation ends\n", (tvalAfter.tv_sec * 1000 + tvalAfter.tv_usec * 0.001) -  (tvalBefore.tv_sec * 1000 + tvalBefore.tv_usec * 0.001));

    // Changed format to long int (%ld), changed time calculation
    // sleep(3);
    // printf("Time in microseconds: %ld microseconds\n",
    //         ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L
    //        +tvalAfter.tv_usec) - tvalBefore.tv_usec
    //       );

	return(0);
}

