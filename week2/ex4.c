#include <stdio.h>

void swap(int *a, int*b);

int main(){
	printf("Print two integers\n");
	int a,b;
	scanf("%d %d", &a, &b);
	swap(&a,&b);
	printf("%d %d\n", a, b);
	return 0;
}
void swap(int *a, int *b){
	*a = *a^*b;
	*b = *a^*b;
	*a = *b^*a;
}
