#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define IS_P(a,b) (a == b)
#define IS_S(a,b,x) ((a+b) == x) 
int main(){
    int n; 
    int sum_p = 0;
    int sum_s = 0;
    scanf("%d",&n);
    int a[n][n];
    int a_i, a_j;
    for(a_i = 0; a_i < n; a_i++){
       for(a_j = 0; a_j < n; a_j++){ 
          scanf("%d",&a[a_i][a_j]);
           if (IS_P(a_i, a_j)) {
	       printf("Primary:%d:%d\n", a_i, a_j);
               sum_p += a[a_i][a_j];
	   }
           if (IS_S(a_i, a_j, n-1)) {
	       printf("Secondary:%d:%d\n", a_i, a_j);
               sum_s += a[a_i][a_j];
	  }
       }
    }
    printf("%d:%d", sum_p, sum_s);
    printf("%d", abs(sum_p - sum_s));
    return 0;
}
