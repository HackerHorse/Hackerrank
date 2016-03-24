#include <stdio.h>

char tape[100000];

#define IS_EXP_STATE(a,b) (b ? (a == 'B'): (a == 'A'))
void count_deletions()
{
        int count = 0;
        int head = 1;
        int next_exp_state;

        if (tape[0] == 'A')
                next_exp_state = 1;
        else
                next_exp_state = 0;

        while(tape[head] != '\0') {
                if (IS_EXP_STATE(tape[head], next_exp_state)) {
                        next_exp_state = (next_exp_state + 1) % 2;
                        head++;
                        continue;
                }
                count++;
                head++;
        }
        printf("%d\n", count);
}
int main()
{
        int T = 0;
        int i;

        scanf("%d", &T);

        for (i = 0; i < T; i++) {
                scanf("%s", tape);
                count_deletions();
        }
        return 0;
}
