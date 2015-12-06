#include <stdio.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *ptr;
NODE *cur;
NODE *head = NULL;
void insert(int);
void reverse(NODE*);
int main(){
	//creating a linked list
	insert(2);
	insert(3);
	insert(1);
	insert(4);
	insert(6);
	insert(5);
	ptr = head;
	while (ptr){
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	reverse(head);
	printf("\n");
	ptr = head;
	while (ptr){
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
}
void insert(int ele){
	cur = malloc(sizeof(NODE));
	cur->data = ele;
	if (head == NULL){
		cur->next = head;
		head = cur;
	}
	ptr = head;
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = cur;
	cur->next = NULL;
}
void reverse(NODE *pt){
	if (pt->next == NULL){
		head = pt;
		return;
	}
	reverse(pt->next);
	NODE* pt1 = pt->next;
	pt1->next = pt;
	pt->next = NULL;
}

