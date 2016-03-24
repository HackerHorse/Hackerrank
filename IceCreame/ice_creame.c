#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int flr[10000];

void print_arr(int num)
{
    int i;
    for(i=0; i < num; i++){
        printf(" %d ", flr[i]);
    }
    printf("\n");
}
void Search_Arr(int sum_total, int num_flr)
{
    int i = 0;
    int j;
    for (i = 0; i < num_flr; i++)
        scanf("%d", &flr[i]);

    for(i = 0; i < num_flr; i++) {
        if (flr[i] >= sum_total)
            continue;
        int temp = sum_total - flr[i];
        j = i+1;
        while(j < num_flr) {
            if(temp == flr[j]) {
                printf("%d %d\n", i+1, j+1);
                goto out;
            }
            j++;
        }
    }
out:
    return ;
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int num_test = 0;
    int sum_total = 0;
    int num_flvr = 0;
    int i;
    scanf("%d", &num_test);
    for (i = 0; i < num_test; i++) {
        scanf("%d", &sum_total);
        scanf("%d", &num_flvr);
        Search_Arr(sum_total, num_flvr);
    }
    return 0;
}
