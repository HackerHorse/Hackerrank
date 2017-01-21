#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int is_valid_char(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return 1;
}

int is_valid_digit(char A)
{
    return isdigit(A);
}
int (*check_valid[10]) (char);

void setup_function()
{
    int i;
    for(i = 0; i < 5; i++)
        check_valid[i] = is_valid_char;
    for(; i < 9; i++)
        check_valid[i] = is_valid_digit;
    check_valid[9] = is_valid_char;
}
int isvalid(char *num)
{
    int i;
    int rc;
    if (strlen(num) != 10)
        return 0;
    for(i = 0; i < 10; i++) {
        rc = check_valid[i](num[i]);
        if (rc == 0)
            return rc;
    }
    return 1;
}
int main() {
    int N;
    int i;

    setup_function();
    scanf("%d", &N);
    for(i = 0; i < N; i++) {
        char pan_num[11];
        scanf("%s", pan_num);
        pan_num[10] = '\0';
        printf("%s\n", isvalid(pan_num) ? "YES" : "NO");
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}
