#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void print_arr(int *ar, int left, int right)
{
	int i;
	if (left == right)
		return;
	if (left == right - 1)
		return;
	for(i = left; i < right; i++)
		printf("%d ", ar[i]);

	printf("\n");
}
int partition(int *left, int *right, int *size, int *ar)
{
	int pivot = ar[*left];
	int i;
	int left_pos = *left+1;
	int pivot_pos = *left;
	int right_pos = *right;
	int temp;

	while(left_pos < right_pos) {
		while(pivot <= ar[left_pos]) {
			left_pos++;
			if (left_pos > right_pos - 1) {
				goto out;
            		}
        	}

		temp = ar[left_pos];
		right_pos = left_pos;

		while(right_pos > pivot_pos) {
			ar[right_pos] = ar[right_pos - 1];
			right_pos--;
		}

		ar[right_pos] = temp;
		pivot_pos = right_pos + 1;
		right_pos = *right;
		//print_arr(ar_size, ar);
	}
out:
	/*print_arr(ar, *left, pivot_pos);
	print_arr(ar, pivot_pos + 1, *right);*/
	//print_arr(ar, *left, *right);
	return pivot_pos;
}

void quick_sort(int left, int right, int size, int *ar)
{
	int pivot_pos = 0;

	if (left == right)
		return;

	pivot_pos = partition(&left, &right, &size, ar);
	quick_sort(left, pivot_pos, pivot_pos, ar);
	print_arr(ar, left, pivot_pos);

	quick_sort(pivot_pos+1, right, size, ar);
	print_arr(ar, pivot_pos + 1, right);
	//if (start == size)
	//	return;

	return;
}
int main(void)
{
	int _ar_size;
	scanf("%d", &_ar_size);
	int _ar[_ar_size], _ar_i;
	for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
		scanf("%d", &_ar[_ar_i]); 
	}

	quick_sort(0, _ar_size, _ar_size, _ar);
	print_arr(_ar, 0, _ar_size);

	return 0;
}
