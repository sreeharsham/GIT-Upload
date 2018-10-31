#include<stdio.h>
#include<stdlib.h>


struct node {
	int data;
	struct node *left;
	struct node *right;
};
int len;
struct node *root = NULL;

void append() {
	struct node *temp;
	temp = (struct node*) malloc(sizeof(struct node));
	printf("Enter node data to append:");
	scanf("%d", &temp->data);
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL) {
		root = temp;
	}
	else{
		struct node *p;
		p = root;
		while(p->right != NULL){
			p = p->right;
		}
		p->right = temp;
		temp->left = p;
	}
}

void addatbegin(){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("Enter node data to be added at the beginning:");
	scanf("%d", &temp->data);
	temp->left = NULL;
	temp->right = NULL;
	if(root == NULL) {
		root = temp;
	}
	else {
		temp->right = root;
		root->left = temp;
		root = temp;
	}
}

void addafter(){
	struct node *temp, *p;
	int loc, i = 1;
	printf("Enter location after which node is to be added");
	scanf("%d", &loc);
	len = length();
	if(loc > len){
		printf("Invalid location");
	}
	else {
		temp = (struct node*)malloc(sizeof(struct node));
		printf("Enter node data:");
		scanf("%d", &temp->data);
		temp->left = NULL;
		temp->right = NULL;
		p = root;
		while (i < loc) {
			p = p->right;
			i++;
		}
		if (p->right == NULL){
			temp->left = p;
			p->right = temp;
		}
		else{
		
		temp->right = p->right;
		p->right->left = temp;
		temp->left = p;
		p->right = temp;
	}
	}
}

int length() {
	struct node *temp = root;
	int count = 0;
	while(temp!=NULL) {
		count++;
		temp = temp->right;
	}
	return count;
}

void display() {
	struct node *temp = root;
	if(temp == NULL) {
		printf("Empty list");
	}
	else {
		while(temp != NULL) {
			printf("%d -> ", temp->data);
			temp = temp->right;
		}
	}
}


void del(){
	int j = 1, loc;
	struct node *p = root;
	if(root == NULL) {
		printf("Nothing to delete");
	}
	printf("Enter location where node has to be deleted:");
	scanf("%d", &loc);
	else{
		while(j < loc-1){
			j++;
			p = p->right;
		}
		
		
	}
}



void main() {
	int ch;
	while(1) {
		printf("\nDouble linked list:\n");
		printf("1. Append\n");
		printf("2. Addatbegin\n");
		printf("3. Addatend\n");
		printf("4. Length\n");
		printf("5. Display\n");
		printf("6. Quit\n");
		printf("Enter choice:");
		scanf("%d", &ch);
		switch(ch) {
			case 1: append();
					break;
			case 2: addatbegin();
					break;
			case 3: addafter();
					break;
			case 4: len = length();
					printf("Length:%d", len);
					break;
			case 5: display();
					break;
			case 6: exit(1);
			default: printf("Invalid choice\n");
		}
	}
}
