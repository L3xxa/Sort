#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Створення масиву
void Array (int *A, int size) {
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 100;
    }
}

// Виведення масиву
void print(int *A, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << A[i];
    }
    cout << endl;
}

// Сортування масиву
void sort(int *A, int size) {
    for (int i = 0; i < size; i++) {
        int key = A[i];
        int j = i - 1;
        for (; j >= 0 && A[j] > key; j--) {
            A[j + 1] = A[j];
        }
        A[j + 1] = key;
    }
}

int main () {
    srand(time(0));

    int SIZE = 10;
    int *A = new int [SIZE];
    Array(A, SIZE);
    print(A, SIZE);
    sort(A, SIZE);
    print(A, SIZE);

    return 0;
}