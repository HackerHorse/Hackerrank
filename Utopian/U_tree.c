#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    int N = 0;
    int i;
    scanf("%d", &T);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    for(i = 0; i < T; i++) {
        scanf("%d", &N);
        if(N == 0) {
            printf("1\n");
            continue;
        }
        int div = 0;
        if (N%2 == 0) {
            div = N/2;
            printf("%d\n", (1<<div)+((1<<div)-1));
        } else {
            div = (N+1)/2;
            printf("%d\n", (1<<div)+((1<<div)-2));
        }
    }
    return 0;
}
