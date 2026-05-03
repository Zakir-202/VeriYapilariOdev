2. Soru: Özel Sıralama Algoritması (Bir Büyük, Bir Küçük)

#include <stdio.h>

void ozelSirala(int arr[], int n) {
    // Önce diziyi küçükten büyüğe sıralayalım (Selection Sort kullanıldı)
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min]) min = j;
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }

    int sonuc[n];
    int bas = 0, son = n - 1;
    
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            sonuc[i] = arr[son--]; // En büyük
        } else {
            sonuc[i] = arr[bas++]; // En küçük
        }
    }

    printf("Sirali Dizi: ");
    for (int i = 0; i < n; i++) printf("%d ", sonuc[i]);
    printf("\n");
}

int main() {
    int dizi[] = {60, 80, 3, 9, 57, 11};
    int n = sizeof(dizi) / sizeof(dizi[0]);
    ozelSirala(dizi, n);
    return 0;
}


