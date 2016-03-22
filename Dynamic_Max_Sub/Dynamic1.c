#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long arr[100000];

void cont_max_add(int num)
{

   long long max_so_far = arr[0];
   long long curr_max = arr[0];
   int i =1; 
   for (i = 1; i < num; i++)
   {
        curr_max = ((arr[i] > (curr_max+arr[i])) ? arr[i] : curr_max+arr[i]);
        max_so_far = (max_so_far > curr_max ? max_so_far : curr_max);
   }
    printf("%lld ", max_so_far);//max_sum > prev_max ? max_sum : prev_max);
}
void noncont_max_add(int num)
{
    int i;
    long max_sum = arr[0];
    
    long part_sum = 0;
    for(i = 1; i < num; i++) {
        part_sum = max_sum + arr[i];
        if (part_sum > max_sum)
            max_sum = part_sum;
	if (arr[i] > max_sum)
	    max_sum = arr[i];
    }
    
    printf("%lld", max_sum);
}
int main()
{    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    int T, N;
    int i;
    scanf("%d", &T);
    
    for (i = 0; i < T; i++) {
        scanf("%d", &N);
        int j = 0;
        for (j = 0; j < N; j++) {
            scanf("%lld", &arr[j]);
        }
        cont_max_add(N);
        noncont_max_add(N);
        printf("\n");
    }
    return 0;
}
