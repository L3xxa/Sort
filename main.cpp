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

// Сортування
void QuickSort(int *A, int first, int last) {
    int i = first;
    int j = last;
    int mid = A[(first + last) / 2];
    do {
        while (A[j] > mid)
            j--;
        while (A[i] < mid)
            i++;

        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    } while (i <= j) ;

    if (j > first)
        QuickSort(A, first, j);
    if (i < last)
        QuickSort(A, i, last);
}


int main () {
    srand(time(0));

    int SIZE = 10;
    int *A = new int [SIZE];
    Array(A, SIZE);
    print(A, SIZE);
    QuickSort(A, 0, SIZE - 1);
    print(A, SIZE);

    return 0;
}