#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char string[10000];

void IS_FUNNY(int str_len)
{
	int ji = 1;
	int jf = str_len - 2;
	while (jf >= ji) {
		printf("%d:%d:%d:%d\n", abs(string[ji]-string[ji-1]),
				abs(string[jf]-string[jf+1]), ji, jf);
		if (abs(string[ji]-string[ji-1]) != abs(string[jf]-string[jf+1])) {
			printf("Not funnyn\n");
			return ;
		}
		jf--; ji++;
	}
	printf("Funny\n");
	return;
}

int main() 
{
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int T = 0;
	int i = 0;
	int len_str = 0;

	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		scanf("%s", string);
		IS_FUNNY(strlen(string));
	}

	return 0;
}
