#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 *  * Complete the function below.
 *   */
int maxXor(int l, int r) {
    int xor_l_r = l^r;
    int highest_bit_set = 0;
    
    while(xor_l_r) {
        int temp = ~(xor_l_r) + 1;
        highest_bit_set = temp & xor_l_r;
        xor_l_r -= highest_bit_set;
    }
    xor_l_r = l^r;
    int max_l = l;
    int max_r = r;
    while(highest_bit_set) {
        if(!(highest_bit_set & xor_l_r)) {
            int temp_l = max_l^highest_bit_set;
            if (temp_l <= l || temp_l >= r) {
                int temp_r = max_r^highest_bit_set;
                if (!(temp_r <= l || temp_r >= r)) {
                    max_r = temp_r;
                }
            } else {
                max_l = temp_l;
            }
        }
        highest_bit_set >>= 1;
    }
    return max_l^max_r;
}
int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
