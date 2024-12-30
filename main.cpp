#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

// Стоворення масиву
void create(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// Виведення масиву
void print(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

// Сортування бульбашкою (удосконалене)
void sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        bool swapped  = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap (arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped ) {
            break;
        }
    }
}

int main() {
    srand(time(0));

    int size = 10;
    int *arr = new int [size];

    create(arr, size);
    print(arr, size);
    sort(arr, size);
    print(arr, size);

    delete[] arr;
    return 0;

}