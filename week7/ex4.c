#include <stdio.h>
#include <stdlib.h>

void my_realloc(void* ptr, int size){
	if(ptr == NULL) 
		return malloc(size);
	if(!size){
		free(ptr);
		return NULL;
	}
	free(ptr);
	return malloc(size);
	
}

int main(){
	int n;
	printf("print n\n");
	scanf("%d", &n);
	int *a = (int*)malloc(sizeof(int)*n);
	for(int i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\nprint n2\n");
	scanf("%d", &n);
	my_realloc(a, n);	
	for(int i = 0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
