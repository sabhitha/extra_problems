#include <stdio.h>
struct node {
	int data;
	struct node* next;
};
typedef struct node NODE;
NODE* head = NULL;
NODE* ptr;
NODE* cur;
NODE* insert(NODE*, int);
void change(NODE*);
int main(){
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 10);
	head = insert(head, 4);
	head = insert(head, 15);
	head = insert(head, 20);
	change(head);
	while (head){
		printf("%d->", head->data);
		head = head->next;
	}
	return 0;
}
NODE* insert(NODE*head, int ele){
	cur = malloc(sizeof(NODE));
	cur->data = ele;
	if (head == NULL){
		cur->next = head;
		head = cur;
		return head;
	}
	ptr = head;
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = cur;
	cur->next = NULL;
	return head;
}
void change(NODE* head){
	NODE* ptr1 = NULL;
	NODE* ptr2 = NULL;
	ptr = head;
	cur = head;
	while (ptr){
		if (ptr->data > ptr->next->data){
			ptr1 = ptr->data;
			break;
		}
		ptr = ptr->next;
	}
	while (ptr)
	{
		if (ptr->next == NULL){
			break;
		}
		if (ptr->data > ptr->next->data){
			ptr2 = ptr->next->data;
		}
		ptr = ptr->next;
	}
	while (cur){
		if (cur->data == ptr1){
			cur->data = ptr2;
		}
		else if (cur->data == ptr2){
			cur->data = ptr1;
		}
		cur = cur->next;
	}
}
