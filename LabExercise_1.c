#include <stdio.h>
#include <stdlib.h>

// Bağlı liste için düğüm yapısı
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Bağlı liste başlangıç düğümü
Node* head = NULL;

// Tek ve çift sayıları ayırıp listeye ekleyen fonksiyon
void addNumberToList(int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = number;
    newNode->next = NULL;

    // Eğer eklenen sayı tekse, başa ekleyelim
    if (number % 2 == 1) {
        newNode->next = head;
        head = newNode;
    }
    // Eğer eklenen sayı çiftse, sona ekleyelim
    else {
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
    int input;
    
    // Klavyeden -1 girilene kadar sayıları al ve işle
    while (1) {
        printf("Bir sayı girin (-1 çıkış): ");
        scanf("%d", &input);
        
        if (input == -1) {
            break;
        }
        
        addNumberToList(input);
    }
    
    // Liste içeriğini ekrana yazdır
    printf("Bağlı Liste: ");
    printList();

    // Belleği temizle
    /*while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }*/

    return 0;
}
