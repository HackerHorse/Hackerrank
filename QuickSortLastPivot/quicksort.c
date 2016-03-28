#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void print_arr(int *ar, int left, int right)
{
	int i;
	for(i = left; i < right; i++)
		printf("%d ", ar[i]);

	printf("\n");
}
int partition(int left, int right, int size, int *ar)
{
	int pivot_pos = right - 1;
	int pivot = ar[pivot_pos];
	int last_small_index = left;
	int num_ele = right - left;

	while(left < right-1) {
		if (ar[left] < pivot) {
			if (last_small_index == left) {
				last_small_index++;
				left++;
				continue;
			}

			
			int tmp = ar[left];
			ar[left] = ar[last_small_index];
			ar[last_small_index] = tmp;
			last_small_index++;
		}

		left++;
	}

	int tmp = ar[last_small_index];
	ar[last_small_index] = ar[pivot_pos];
	ar[pivot_pos] = tmp;
	
	if (num_ele > 1)
		print_arr(ar, 0, size);
	return last_small_index;
}

void quick_sort(int left, int right, int size, int *ar)
{
	int pivot_pos;

	if (left == right)
		return;

	pivot_pos = partition(left, right, size, ar);
	quick_sort(left, pivot_pos, size, ar);
	//print_arr(ar, 0, size);

	quick_sort(pivot_pos + 1, right, size, ar);

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
	//print_arr(_ar, 0, _ar_size);

	return 0;
}
