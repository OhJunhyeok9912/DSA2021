#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SWAP( x, y, t) ( (t)= (x), (x) = (y), (y)=(t))

int partition(int list[], int left, int right) {
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do
            low++;
        while (list[low]> pivot);
        do
            high--;
        while (list[high] < pivot);
        if (low < high) SWAP(list[low], list[high], temp);
    } while (low < high);
    SWAP(list[left], list[high], temp);
    return high;
}
void quick_sort(int list[], int left, int right) {
    if (left < right) {
        int q = partition(list, left, right);
        quick_sort(list, left, q - 1);
        quick_sort(list, q + 1, right);
    }
}

int main()
{
    int n, count = 0;
    int list[100];
    scanf_s("%d", &n);
    while (n > 0) {
        list[count] = n % 10;
        n /= 10;
        count++;
    }
    quick_sort(list, 0, count-1);
    for (int i = 0; i <count; i++) {
        printf("%d", list[i]);
    }
    return 0;
}
