#include <stdio.h>
#include <stdlib.h>
#include "l1.h"

/**
Дан одномерный массив положительных вещественных чисел.
Преобразовать этот массив следующим образом: сначала обнуляется минимальный элемент, затем максимальный из оставшихся, далее минимальный из оставшихся и т.д. до тех пор, пока не останется единственный элемент. Вывести на экран значение и индекс оставшегося элемента.
 */

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

void showArray(int a[N], int n) {
    printf("\nShow array:\n");
    for(int i = 0 ; i < n; i++) { // ВЫВОДИМ РЕЗУЛЬТАТ
        printf("%d ", a[i]);
    }
    printf("\n\n");
};
int l1() {
    int i;
    int a[N];
    int n;

    printf("\nEnter the number of elements in the array:\n");
    scanf("%d", &n);

    int del = n - (n / 2 + 1);

    for(i = 0 ; i < n; i++) {
        a[i] = rand() % 100;
    }

    qsort(a, n, sizeof(int), cmp ); // СОРТИРУЕМ

    showArray(a, n);

    for(i = 0 ; i < del; i++) {
        a[i] = 0;
        a[n - (i + 1)] = 0;
    }

    a[del] = 0;

    printf("Cleared array:");

    showArray(a, n);

    int fullyIndex = del + 1;
    printf("\nResult value:%d\n", a[fullyIndex]);
    printf("\nIndex:%d\n", fullyIndex);
    return 0;
}