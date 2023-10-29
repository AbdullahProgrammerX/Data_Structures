#include <stdio.h>
#include <stdlib.h>

// Öğrenci bilgisi için bir yapı (struct)
typedef struct Student {
    int number;
    char name[50];
    int age;
    struct Student* next;
} Student;

// Bağlı liste için başlangıç düğümü
Student* head = NULL;

// Öğrenci sayısını tutan değişken
int studentCount = 0;

// Karakter dizilerini kullanarak öğrenci ekleyen fonksiyon
void addStudent(int number, char* name, int age) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    newStudent->number = number;
    
    // Öğrenci adını karakter dizisi olarak ele alır ve kopyalama işlemi yapar.
    for (int i = 0; i < 50; i++) {
        newStudent->name[i] = name[i];
        if (name[i] == '\0') {
            break;
        }
    }
    
    newStudent->age = age;
    newStudent->next = head;
    head = newStudent;
    studentCount++;
}

// Bağlı listeyi dolaşarak öğrenci bilgilerini ekrana yazan fonksiyon
void printStudents() {
    int index = 1;
    Student* current = head;
    while (current != NULL) {
        printf("%d- %s %d %d\n", index, current->name, current->age, current->number);
        current = current->next;
        index++;
    }
}

int main() {
    // Öğrenci bilgilerini listeye ekleyelim
    addStudent(201, "Saliha", 27);
    addStudent(203, "Ece", 19);
    addStudent(45,"Abdullah",344);
    addStudent(220,"Hayho",19);
    // Öğrenci bilgilerini ekrana yazdıralım
    printf("Öğrenci Listesi:\n");
    printStudents();

    // Toplam öğrenci sayısını yazdıralım
    printf("Toplam öğrenci sayısı: %d\n", studentCount);

    // Belleği temizleyelim (free kullanarak)
    while (head != NULL) {
        Student* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
