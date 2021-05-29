#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )


int partition(int list[], int list2[], int left, int right) // 리스트 2개를 받음 list-> 정렬해야 하는 리스트 | list2-> 정렬되는 수들의 번호를 담은 리스트
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do
			low++;
		while (list[low] < pivot); 
		do
			high--;
		while (list[high] > pivot);
		if (low < high) {
			SWAP(list[low], list[high], temp); 
			SWAP(list2[low], list2[high], temp); // 리스트 두개를 동시에 swap
		}
	} while (low < high);
	SWAP(list[left], list[high], temp);
	SWAP(list2[left], list2[high], temp); // 리스트 두개를 동시에 swap
	return high;
}
void quick_sort(int list[], int list2[], int left, int right)
{
	if (left < right) {
		int q = partition(list, list2, left, right);
		quick_sort(list, list2, left, q - 1);
		quick_sort(list, list2, q + 1, right);
	}
}

int compare(const void* arg1, const void* arg2) { 
	if (*(int*)arg1 > *(int*)arg2) return 1;
	else if (*(int*)arg1 < *(int*)arg2) return -1;
	else return 0;
}

int num[8]; //점수를 저장하는 배열
int order[8]; //문제의 번호를 저장하는 배열
int sorted[5]; //상위 5개의 번호를 저장하는 배열
int main(void)
{
	int i;
	int sum = 0;
	for (i = 0; i < 8; i++) {
		scanf("%d", &num[i]);
		order[i] = i + 1;
	}
	quick_sort(num, order, 0, 7); // 두 리스트를 동시에 매개변수로 담아 정렬
	for (i = 3; i <= 7; i++)
		sum += num[i];
	printf("%d\n", sum);
	for (i = 3; i <= 7; i++) {
		;
		sorted[i - 3] = order[i];
	} // 상위 5개만 sorted 배열에 담음
	qsort((void*)sorted, 5, sizeof(int), compare); // 퀵 내장함수로 정렬
	for (i = 0; i < 5; i++) {
		printf("%d ", sorted[i]);
	}
	return 0;
}