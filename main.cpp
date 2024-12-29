#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Створення масиву
int createArray(int *A, int size) {
    int arifmetic = 0;
    for (int i = 0; i < size; i++) {
        A[i] = rand() % 100 - 50;
        arifmetic += A[i];
    }
    return arifmetic;
}

// Виведення масиву
void print(int *A, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << A[i];
    }
    cout << endl;
}

// Сортування масиву
void QuickSort(int *A, int first, int last) {
    int i = first;
    int j = last;
    int mid = A[(first + last) / 2];
    do {
        while (A[i] < mid) i++;
        while (A[j] > mid) j--;

        if (i <= j) {
            swap(A[i], A[j]);
            i++;
            j--;
        }
    } while (i <= j);

    if (first < j) QuickSort(A, first, j);
    if (i < last) QuickSort(A, i, last);
}

// Зворотний порядок частини масиву
void reverseArray(int *A, int start, int end) {
    while (start < end) {
        swap(A[start], A[end]);
        start++;
        end--;
    }
}

// Обробка масиву
void processArray(int *A, int SIZE) {
    int arifmetic = createArray(A, SIZE) / SIZE;

    if (arifmetic > 0) {
        QuickSort(A, 0, (2 * SIZE) / 3 - 1);
        reverseArray(A, (2 * SIZE) / 3, SIZE - 1);
    } else {
        QuickSort(A, 0, SIZE / 3 - 1);
        reverseArray(A, SIZE / 3, SIZE - 1);
    }

    print(A, SIZE);
}

int main() {
    srand(time(0));

    int SIZE = 20;
    int *A = new int[SIZE];
    createArray(A, SIZE);

    cout << "Original array: ";
    print(A, SIZE);

    cout << "Processed array: ";
    processArray(A, SIZE);

    delete[] A;
    return 0;
}
