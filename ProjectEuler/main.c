#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int T;
	unsigned long long int N;
    
	scanf("%d", &T);

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	for (int i = 0; i < T; i++) {
		scanf("%llu", &N);
		unsigned long num_3 = (N - 1)/3;
		unsigned long num_5 = (N - 1)/5;
		unsigned long num_15 = (N - 1)/15;
        
		unsigned long sum_3 = ((num_3)*((3 + (3*num_3))))/2;
		unsigned long sum_5 = ((num_5)*((5 + (5*num_5))))/2;
		unsigned long sum_15 = ((num_15)*((15 + (15*num_15))))/2;
		printf("%lu\n", (sum_3 + sum_5) - sum_15);
	}

	return 0;
}
