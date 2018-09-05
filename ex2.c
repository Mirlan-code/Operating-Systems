#include <stdio.h>
void swap(int *a, int *b){
	*a = *a^*b;
	*b = *b^*a;
	*a = *b^*a;
}
void bubble_sort(int *a, int n){
	for(int i = 0; i<n; i++){
		for(int j = 0; j<n-1-i; j++){
			if(a[j]>a[j+1]){
				swap(&a[j], &a[j+1]);
			}
		}
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	bubble_sort(a, n);
	for(int i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

