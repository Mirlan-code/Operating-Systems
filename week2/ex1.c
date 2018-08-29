#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("%i\n%lf\n%lf\n", a, b, c);

	return 0;
}

