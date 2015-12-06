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
	int num1 = 0;
	int num2 = 0;
	int r = 0;
	printf("Enter num1 &num2\n");
	scanf("%d", &num1);
	scanf("%d", &num2);
	printf("enter r value\n");
	scanf("%d", &r);
	for (int i = 1; i <= r; i++){
		head1 = insert(head1, num1*i);
		head2 = insert(head2, num2*i);
	}
	NODE *head = mergelists(head1, head2);
	ptr = head;
	int count = 1;//since before coming out ofthe loop ptr will increment to ptr->next
	while (count != r){
		if (ptr->data != ptr->next->data)
			count++;
		ptr = ptr->next;
	}
	printf("%d\n", ptr->data);
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
		merged_list = head1;
		merged_list->next = mergelists(head1->next, head2);
	}
	else{
		merged_list = head2;
		merged_list->next = mergelists(head1, head2->next);
	}
	return merged_list;
}