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

