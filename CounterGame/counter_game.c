#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LOUIE 0
#define RICHARD 1
int main() 
{
    int num;
    int i;
    unsigned long long N = 0;
    unsigned long long halfN = 0;
    int player = LOUIE;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    scanf("%d", &num);
    for(i = 0; i < num; i++) {
        scanf("%llu", &N);
        player = LOUIE;
        //N = 6;
        if (N == 1) {
            printf("Richard");
            continue;
        }
        while( N != 1) {
           if((N&(N-1))) {
             halfN = N;
             halfN--;
             halfN |= (halfN>>1);
             halfN |= (halfN>>2);
             halfN |= (halfN>>4);
             halfN |= (halfN>>8);
             halfN |= (halfN>>16);
             halfN |= (halfN>>32);
             halfN--;
             halfN >>= 1;
             halfN++;
             N = N - halfN;
             //printf("%s turn and N = %llu<---\n", player?"Richard":"Louie", N);
           }
           else {
             /* Reduce by Half */
             halfN = N/2;
             N -= halfN;
             //printf("%s turn and N = %llu\n", player?"Richard":"Louie", N);
           }
           if ( N != 1)
           player = !player;
        }
        if (player == LOUIE)
            printf("Louise\n");
        else
            printf("Richard\n");
    }
    return 0;
}
