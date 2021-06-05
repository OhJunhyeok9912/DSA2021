#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, t) ((t) = (x), (x)=( y), (y) =(t))

int partition(int list[], int left, int right) {
	int low, high;
	int pivot, temp;
	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do {
			low++;
		} while (list[low] < pivot);
		do {
			high--;
		} while (list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);	
	} while (low < high);
	SWAP(list[left], list[high], temp);
	return high;
}

void quick(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick(list, left, q - 1);
		quick(list, q + 1, right);
	}
}

int main() {
	int scores[20]; // 총 20 명
	int sum = 0;
	for (int i = 0; i < 20; i++) {
		scanf("%d", &scores[i]);
	}
	quick(scores, 0, 9); // W 대학 참가자의 점수를 정렬한다.
	quick(scores, 10, 19); // K 대학 참가자의 점수를 정렬한다. 
	for (int i = 7; i < 10; i++) { // W 대학의 상위 3명의 점수를 모두 합한다. 
		sum += scores[i];
	}
	printf("%d ", sum);
	sum = 0;
	for (int i = 17; i < 20; i++) {// K 대학의 상위 3명의 점수를 모두 합한다. 
		sum += scores[i];
	}
	printf("%d", sum);
}
