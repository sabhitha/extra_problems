#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp1;
	FILE *fp2;
	int count = 0;
	int k;
	printf("Enter k value\n");
	scanf("%d", &k);
	fp1 = fopen("C:/Users/sabhitha/Desktop/sample_file.txt", "r");
	fp2 = fopen("C:/Users/sabhitha/Desktop/sample_file.txt", "r");
	if (fp1 == NULL){
		printf("file cannot be opened\n");
		exit(1);
	}
	char ch;
	while ((fscanf(fp1, "%c", &ch)) == 1){
		if (ch == '\n'){
			count++;
		}
	}
	fclose(fp1);
	int rem_lines;
	rem_lines = count - k;
	if (rem_lines > 0){
		count = 0;
		while ((fscanf(fp2, "%c", &ch)) == 1){
			if (ch == '\n')
				count++;
			if (count > rem_lines){
				if (count == rem_lines && ch == '\n')
					fscanf(fp2, "%c", &ch);
				printf("%c", ch);
			}
		}
	}
	else
		while ((fscanf(fp2, "%c", &ch)) == 1)
			printf("%c", ch);
	fclose(fp2);
	return 0;
}