#include <stdio.h>
struct node {
	int data;
	struct node *next;
};
typedef struct node NODE;
NODE *ptr;
NODE *cur;
NODE *head = NULL;
NODE* insert(NODE*,int);
int *toFindMedian(NODE*);
int main(){
	//creating a linked list in sorted order
	head = insert(head,12);
	head = insert(head,23);
	head = insert(head,31);
	head = insert(head,40);
	head = insert(head,41);
	head = insert(head,45);
	ptr = head;
	while (ptr){
		printf("%d->", ptr->data);
		ptr = ptr->next;
	}
	int median = toFindMedian(head);
	printf("median of linked is:%d\n", median);
	return 0;
}
NODE* insert(NODE*head,int ele){
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
	//head = ptr;
	return head;
}
int *toFindMedian(NODE *head){
	int median = 0;
	ptr = head;
	int count = 0;
	while (ptr){
		count++;
		ptr = ptr->next;
	}
	ptr = head;
	if (count % 2 == 0){
		for (int i = 1; i < count / 2; i++){
			printf("%d:i", i);
			ptr = ptr->next;
		}
		printf("%d",ptr->data);
		printf("%d", ptr->next->data);
		median = (ptr->data + ptr->next->data) / 2;
	}
	else{
		for (int i = 0; i < (count-1) / 2; i++){
			printf("%d:i", i);
			ptr = ptr->next;
		}
		median = ptr->data;
	}
	return median;
}

