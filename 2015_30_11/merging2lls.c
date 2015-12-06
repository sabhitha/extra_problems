#include <stdio.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *ptr;
NODE *cur;
NODE *head1 = NULL;
NODE *head2 = NULL;
NODE* insert(NODE*, int);
NODE* mergelists(NODE*, NODE*);
int main(){
	head1 = insert(head1, 1);
	head1 = insert(head1, 2);
	head1 = insert(head1, 3);
	head2 = insert(head2, 4);
	head2 = insert(head2, 5);
	head2 = insert(head2, 6);
	head2 = insert(head2, 7);
	NODE *head = mergelists(head1, head2);
	ptr = head;
	while (ptr){
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
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = cur;
	cur->next = NULL;
	return head;
}
NODE* mergelists(NODE* head1, NODE* head2){
	NODE* merged_list = NULL;
	if (head1 == NULL)
		return head2;
	else if (head2 == NULL)
		return head1;
	if (head1->data <= head2->data){
		//printf("IN if");
		merged_list = head1;
		merged_list->next = mergelists(head1->next, head2);
	}
	else{
		//printf("in else\n");
		merged_list = head2;
		merged_list->next = mergelists(head1, head2->next);
	}
	return merged_list;
}