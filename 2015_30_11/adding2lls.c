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
void add(NODE*, NODE*);
int main(){
	int count1 = 0;
	int count2 = 0;
	head1 = insert(head1, 11);
	head1 = insert(head1, 2);
	head1 = insert(head1, 3);
	head2 = insert(head2, 0);
	head2 = insert(head2, 1);
	head2 = insert(head2, 5);
	head2 = insert(head2, 4);
	ptr = head1;
	while (ptr){
		count1++;
		ptr = ptr->next;
	}
	ptr = head2;
	while (ptr){
		count2++;
		ptr = ptr->next;
	}
	if (count1 >= count2){
		if (count2 > 0)
			add(head1, head2);
		ptr = head1;
	}
	else{
		if (count1 > 0)
			add(head2, head1);
		ptr = head2;
	}
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
void add(NODE*head1, NODE*head2){
	while (head1 != NULL || head2 != NULL){
		if (!head2)
			break;
		head1->data += head2->data;
		head1 = head1->next;
		head2 = head2->next;
	}
}