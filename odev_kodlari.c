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


3. Soru: Trie (Metin Ağacı) Yapısı Nedir?

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALFABE_BOYUTU 26

struct TrieNode {
    struct TrieNode *children[ALFABE_BOYUTU];
    bool isEndOfWord;
};

struct TrieNode *getNode(void) {
    struct TrieNode *pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    pNode->isEndOfWord = false;
    for (int i = 0; i < ALFABE_BOYUTU; i++)
        pNode->children[i] = NULL;
    return pNode;
}

void insert(struct TrieNode *root, const char *key) {
    struct TrieNode *pCrawl = root;
    for (int level = 0; key[level] != '\0'; level++) {
        int index = key[level] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndOfWord = true;
}

int main() {
    struct TrieNode *root = getNode();
    insert(root, "odev");
    insert(root, "veri");
    printf("Trie yapisi basariyla olusturuldu ve kelimeler eklendi.\n");
    return 0;
}










