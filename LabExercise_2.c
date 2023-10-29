#include <stdio.h>
#include <stdlib.h>

// Bağlı liste için düğüm yapısı
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Bağlı liste başlangıç düğümü
Node* head = NULL;

// Yeni düğüm ekleyen fonksiyon
void addNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Bağlı listeyi büyükten küçüğe sıralayan fonksiyon
void sortList() {
    Node* current = head;
    Node* index = NULL;
    int temp;

    if (head == NULL) {
        return;
    } else {
        while (current != NULL) {
            index = current->next;

            while (index != NULL) {
                if (current->data < index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// Bağlı listeyi ekrana yazdıran fonksiyon
void printList() {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Rastgele üretilen 100 sayıyı liste içine ekleyelim
    for (int i = 0; i < 100; i++) {
        int randomValue = rand() % 1000;  // 0 ile 999 arasında rastgele sayılar
        addNode(randomValue);
    }
    
    // Listeyi büyükten küçüğe sıralayalım
    sortList();

    // Sıralanmış listeyi ekrana yazdıralım
    printf("Sıralı Liste: ");
    printList();

    // Belleği temizleyelim
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
