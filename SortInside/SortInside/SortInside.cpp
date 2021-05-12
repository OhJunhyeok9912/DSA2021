#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SWAP( x, y, t) ( (t)= (x), (x) = (y), (y)=(t))

int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;
    low = left;
    high = right + 1;
    pivot = list[left]; // 가장 왼쪽을 피봇으로 설정
    do { 
        do
            low++; // 먼저 한번 더하고 판단해야 한다. low의 값이 현재 pivot의 위치이기 때문이다.  
        while (list[low]> pivot); // 이번 문제에서는 내림차순으로 정렬하기 때문에 pivot의 왼쪽은 pivot 보다 커야한다. 
        do
            high--; // 먼저 한번 빼고 판단해야 한다. high의 값이 범위 밖에 있기 때문이다.
        while (list[high] < pivot);// 마찬가지로 내림차순으로 정렬하기 때문에 pivot의 오른쪽은 pivot 보다 작아야한다.
        if (low < high) SWAP(list[low], list[high], temp);
    } while (low < high); // low, high의 역전이 처음 일어나면 그 때 high의 위치가 pivot이 있어야 할 위치가 된다.  
    SWAP(list[left], list[high], temp); 
    return high; // pivot의 위치를 반환
}
void quick_sort(int list[], int left, int right) {
    if (left < right) { // 정렬은 left가 right보다 작을 때 발생한다. 
        int q = partition(list, left, right); // q에 피봇의 위치를 할당
        quick_sort(list, left, q - 1); // 피봇을 기준으로 왼쪽 부분을 다시 정렬
        quick_sort(list, q + 1, right); // 피봇을 기준으로 오른쪽 부분을 다시 정렬
    }
}

int main() // 퀵정렬 내장함수 대신 partition함수를 이용해 작성했음.
{
    int n, count = 0;
    int list[100]; // 숫자의 각 자리수를 담는 배열을 생성. 이 리스트에 내림차순으로 숫자를 정렬
    scanf_s("%d", &n);
    while (n > 0) {
        list[count] = n % 10;
        n /= 10;
        count++;
    }
    quick_sort(list, 0, count-1); // 각 자릿수를 담은 리스트를 퀵정렬로 정렬
    for (int i = 0; i <count; i++) {
        printf("%d", list[i]); // 내림차순된 리스트를 출력
    }

    return 0;
}
