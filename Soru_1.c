1. Soru: Insertion Sort ve Selection Sort Karşılaştırması

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int n = 500;
    int arr1[500], arr2[500];
    clock_t start, end;

    srand(time(0));
    for (int i = 0; i < n; i++) {
        int r = rand() % 1001;
        arr1[i] = r;
        arr2[i] = r;
    }

    // Insertion Sort Zaman Ölçümü
    start = clock();
    insertionSort(arr1, n);
    end = clock();
    printf("Insertion Sort Calisma Suresi: %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Selection Sort Zaman Ölçümü
    start = clock();
    selectionSort(arr2, n);
    end = clock();
    printf("Selection Sort Calisma Suresi: %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}


