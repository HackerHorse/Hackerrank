#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    int alpha_used;
    int alphabets_index[26];
} alphabets_meta;
alphabets_meta metadata;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i;
    int len = 0;
    char *input;
    
    memset(metadata.alphabets_index, 0, sizeof(int)*26);
    
    input = (char*)malloc(sizeof(char)*1000);
    if (!input) {
        printf("Killed: Insufficient memory");
        exit(1);
    }
    scanf("%999[^\n]", input);
    len = strlen(input);
    //printf("%c %c %c\n", input[len-1], input[len -2], input[len - 3]);
    for (i = 0; i < len; i++){
        if(input[i] >= 97 && input[i] <= 122)
            input[i] -= 32;
        if(input[i] >= 65 && input[i] <= 90) {
            
            int index = input[i] - 65;
            //printf("index:%d\n", index);
            if(!metadata.alphabets_index[index]) {
                metadata.alphabets_index[index] = 1;
                metadata.alpha_used++;
            }
        }
    }
    //printf("alphabets used=%d\n", metadata.alpha_used);
    if (metadata.alpha_used == 26)
        printf("pangram");
    else
        printf("not pangram");
    free(input);
    return 0;
}
