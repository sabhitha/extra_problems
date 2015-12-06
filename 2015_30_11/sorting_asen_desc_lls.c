#include <stdio.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *ptr;
NODE *cur;
NODE *head = NULL;
NODE *insert(NODE*, int);
void sort(NODE*);
int main(){
	head = insert(head,1);
	head = insert(head, 2);
	head = insert(head, 7);
	head = insert(head, 27);
	head = insert(head, 15);
	head = insert(head, 10);
	ptr = head;
	cur = head;
	NODE* prev;
	while (ptr){
		if (ptr->data > ptr->next->data){
			sort(ptr);
			prev->next= head;
			break;
		}
		prev = ptr;
		ptr = ptr->next;
	}
	ptr= cur;
	while (ptr)
	{
		printf("%d->", ptr->data);
		ptr = ptr->next;
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
	while (ptr->next != NULL)
		ptr = ptr->next;
	ptr->next = cur;
	cur->next = NULL;
	return head;
}
//reversing the descending part of list
void sort(NODE* pt){
	if (pt->next == NULL){
		head = pt;
		return;
	}
	sort(pt->next);
	NODE* pt1 = pt->next;
	pt1->next = pt;
	pt->next = NULL;
}