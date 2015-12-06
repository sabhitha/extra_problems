#include<stdio.h>
void maxSubArr(int*, int, int*, int*);
int main(){
	int inp_arr[20];
	int no_of_ele;
	int str_pos = 0;
	int end_pos = 0;
	printf("enter no of elements in array\n");
	scanf("%d", &no_of_ele);
	printf("Enter elements of the array");
	for (int i = 0; i < no_of_ele; i++){
		scanf("%d", &inp_arr[i]);
	}
	int sum_of_ele = 0;
	maxSubArr(inp_arr, no_of_ele, &str_pos, &end_pos);
	for (int i = str_pos; i < end_pos+1; i++){
		sum_of_ele += inp_arr[i];
		printf("%3d", inp_arr[i]);
	}
	printf("sum:%d", sum_of_ele);
	return 0;
}
void maxSubArr(int *Arr, int no_ele, int *str, int *end){
	int large = 0;
	int current_sum = 0;
	int pos = -1;
	for (int i = 0; i < no_ele; i++)
	{
		current_sum = current_sum + Arr[i];
		if (pos == -1)
			pos = i;
		if (current_sum <= 0){
			current_sum = 0;
			pos = -1;
		}
		if (large < current_sum){
			large = current_sum;
			*str = pos;
			*end = i;
		}
	}
	return;
}