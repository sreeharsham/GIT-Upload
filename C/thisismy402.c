/******************************************************************************/
/* Important CSCI 402 usage information:                                      */
/*                                                                            */
/* This fils is part of CSCI 402 programming assignments at USC.              */
/*         53616c7465645f5f2e8d450c0c5851acd538befe33744efca0f1c4f9fb5f       */
/*         3c8feabc561a99e53d4d21951738da923cd1c7bbd11b30a1afb11172f80b       */
/*         984b1acfbbf8fae6ea57e0583d2610a618379293cb1de8e1e9d07e6287e8       */
/*         de7e82f3d48866aa2009b599e92c852f7dbf7a6e573f1c7228ca34b9f368       */
/*         faaef0c0fcf294cb                                                   */
/* Please understand that you are NOT permitted to distribute or publically   */
/*         display a copy of this file (or ANY PART of it) for any reason.    */
/* If anyone (including your prospective employer) asks you to post the code, */
/*         you must inform them that you do NOT have permissions to do so.    */
/* You are also NOT permitted to remove or alter this comment block.          */
/* If this comment block is removed or altered in a submitted file, 20 points */
/*         will be deducted.                                                  */
/******************************************************************************/

/*
 * Author:      William Chia-Wei Cheng (bill.cheng@acm.org)
 *
 * @(#)$Id: listtest.c,v 1.2 2018/01/02 23:09:34 william Exp $
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>

#include "cs402.h"

#include "my402list.h"

int  My402ListLength(My402List* list) {

	return list -> num_members;

 }	 

int  My402ListEmpty(My402List* list) {
	if (list -> num_members == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
  }	 

int  My402ListAppend(My402List* list, void* obj1) {
	My402ListElem *temp = (My402ListElem *)malloc(sizeof(My402ListElem));
	temp -> obj = obj1;
	if (My402ListEmpty(list) == TRUE) {
		list -> anchor.next = temp;
		list -> anchor.prev = temp;
		temp -> prev = &list -> anchor;
		temp -> next = &list -> anchor;
	}
	else {
		My402ListElem *lastOne = My402ListLast(list);
		lastOne -> next = temp;
		temp -> prev = lastOne;
		temp -> next = &list -> anchor;
		list -> anchor.prev = temp;
	}
	list -> num_members++;
	return TRUE;
 }	 

int  My402ListPrepend(My402List* list, void* obj1) {
	My402ListElem *temp = (My402ListElem *)malloc(sizeof(My402ListElem));
	temp -> obj = obj1;
	if (My402ListEmpty(list) == TRUE) {
		list -> anchor.next = temp;
		list -> anchor.prev = temp;
		temp -> prev = &list -> anchor;
		temp -> next = &list -> anchor;
	}
	else {
		My402ListElem *firstOne = My402ListFirst(list);
		list -> anchor.next = temp;
		temp -> prev = &list -> anchor;
		temp -> next = firstOne -> prev;
		firstOne -> prev = temp;
	}
	list -> num_members++;
	return TRUE;
}	 

void My402ListUnlink(My402List* list, My402ListElem* myElement) {
	if (myElement != NULL) {
		if(My402ListEmpty(list) != TRUE) {
			myElement -> prev -> next = myElement -> next;
			myElement -> next -> prev = myElement -> prev;
			free(myElement);
		}
		list ->num_members--;
	}

  }	 

void My402ListUnlinkAll(My402List* list) {
My402ListElem *first = My402ListFirst(list);
    int len = My402ListLength(list);
    while(len != 0) {
     list -> anchor.next = first -> next;
     first -> next -> prev = &list -> anchor;
     first -> prev = NULL;
     first -> next = NULL;
     free(first);
     first = list -> anchor.next;
     len--;
    }
	
 }	 

int  My402ListInsertAfter(My402List* list, void* obj1, My402ListElem* myElement) {
	if (myElement == NULL) {
		return My402ListAppend(list, obj1);
	}
	else {
		My402ListElem *temp = (My402ListElem *)malloc(sizeof(My402ListElem));
		temp -> obj = obj1;
		temp -> next = myElement -> next;
		myElement -> next -> prev = temp;
		temp -> prev = myElement;
		myElement -> next = temp;
	}
	list -> num_members++;
	return TRUE;

 }

int  My402ListInsertBefore(My402List* list, void* obj1, My402ListElem* myElement) {
	if (myElement == NULL) {
		return My402ListPrepend(list, obj1);
	}
	else {
		My402ListElem *temp = (My402ListElem *)malloc(sizeof(My402ListElem));
		temp -> obj = obj1;
		temp -> prev = myElement -> prev;
		myElement -> prev -> next = temp;
		temp -> next = myElement;
		myElement -> prev = temp;
	}
	list -> num_members++;
 	return TRUE;
 }	 

My402ListElem *My402ListFirst(My402List* list){ 
	if (My402ListEmpty(list) == TRUE) {
		return NULL;
		}
	else {
		return list -> anchor.next;
		}

	}	 

My402ListElem *My402ListLast(My402List* list) {
	if (My402ListEmpty(list) != TRUE) {
		return list -> anchor.prev;
	}
	else {
		return NULL;
	}
 }	 

My402ListElem *My402ListNext(My402List* list, My402ListElem* myElement) {
	if ( myElement == list -> anchor.prev) {
		return NULL;
	}
	else {
		return myElement -> next;
	}

 }




My402ListElem *My402ListPrev(My402List* list, My402ListElem* myElement) {
	if (myElement == list -> anchor.next) {
		return NULL;
	}
	else {
		return myElement -> prev;
	}

 }	 

My402ListElem *My402ListFind(My402List* list, void* obj1) {
	int l = My402ListLength(list);
	My402ListElem *temp = My402ListFirst(list);
	int i = 0;
	if (My402ListEmpty(list) != TRUE) {
		for (i = 0; i < l; i++) {
			if (temp -> obj == obj1) {
				return temp;
			}
		temp = My402ListNext(list, temp);
		}
		return NULL;
	}
	else {
		return NULL;
	}
 }	 

int My402ListInit(My402List* list) { 
	if (list != NULL) {
	list -> anchor.obj = NULL;
	list -> anchor.prev = &list  -> anchor;
	list -> anchor.next = &list -> anchor;
	list -> num_members = 0;
	return TRUE;
	}
	else {
		return FALSE;
	}
}	
