#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int compare(const void* arg1, const void* arg2) {
	if (*(int*)arg1 > *(int*)arg2) return 1;
	else if (*(int*)arg1 == *(int*)arg2) return 0;
	else return -1;
}


int main() {
	int n, i, j; // n = 활잡이의 수
	int height[MAX]; // 봉우리 높이
	int kill[MAX]; // 각 봉우리에서 처치한 용의 수를 담은 배열
	int killed; // 활잡이가 처치한 용의 수
	int h;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		scanf_s("%d", &height[i]);
	}
	for (i = 0; i < n; i++) {
		killed = 0;
		h = height[i];
		for (j = i+1; j < n; j++) {
			if (h > height[j]) ++killed; // 자신 보다 낮은 봉우리의 용을 처치
			else {
				kill[i] = killed;
				break;
			}
		}
		kill[i] = killed;
	}
	qsort(kill, n, sizeof(int), compare); // 각 봉우리에서 활잡이가 처리한 용의 수를 정렬
	printf("%d\n", kill[n - 1]); // 가장 큰 것을 출력
}