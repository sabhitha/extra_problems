#include <stdio.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *ptr;
NODE *cur;
NODE *head = NULL;
void insertAtFront(int);
void insertAtEnd(int);
int main(){
	insertAtEnd(5);
	insertAtEnd(3);
	insertAtEnd(10);
	insertAtFront(6);
	insertAtFront(7);
	ptr = head;
	while (ptr->next!=head){
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	printf("%d", ptr->data);
	return 0;
}
void insertAtFront(int ele){
	if (head == NULL){
		head = (NODE*)malloc(sizeof(NODE));
		head->data = ele;
		head->next = head;
	}
	else{
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		NODE* ptr = head;
		while (ptr->next != head)
			ptr = ptr->next;
		temp->data = ele;
		temp->next = head;
		head = temp;
		ptr->next = head;
	}
}
void insertAtEnd(int ele){
	if (head == NULL){
		head = (NODE*)malloc(sizeof(NODE));
		head->data = ele;
		head->next = head;
	}
	else{
		NODE* temp = head;
		while (temp->next != head)
			temp = temp->next;
		temp->next = (NODE*)malloc(sizeof(NODE));
		temp->next->data = ele;
		temp->next->next = head;
	}
}