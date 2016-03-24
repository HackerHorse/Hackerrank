#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long long A[100000];
int main() {
    unsigned long long N;
    int T;
    int i;
    int j = 0;
    int sum = 0;
    int flag = 0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d", &T);
    for (i = 0; i < T; i++) {
        scanf("%llu", &N);
        sum = 0;
        flag = 0;
        for(j = 0; j < N; j++) {
            scanf("%llu", &A[j]);
            sum += A[j];
        }
        unsigned long long left_sum = 0;
        unsigned long long right_sum = sum;
        for(j = 0; j < N; j++) {
           right_sum -= A[j];
           if (right_sum == left_sum) {
               printf("YES\n");
               flag = 1;
               break;
           }
           left_sum += A[j];
        }
        if (!flag)
            printf("NO\n");
    }
    return 0;
}
