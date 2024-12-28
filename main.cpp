#include <iostream>
#include <iomanip>
using namespace std;

// Меню
void displayMenu() {
    cout << "----------SUCCESSFULLY---------- \n";
    cout << "Menu:\n";
    cout << "1. Derivation of grades\n"; // Виведення оцінок
    cout << "2. Retaking the exam\n"; // Перескладання іспиту
    cout << "3. Is there a scholarship?\n"; // Чи виходить стипендія?
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Введення оцінок
void Diary(int *arr, int SIZE) {

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter the grade " << i + 1 << ": ";
        cin >> arr[i];
        if (arr[i] < 0 || arr[i] > 12) {
            cout << "Invalid grade. Please try again.\n";
            i--;
        }
    }

    cout << "Grades entered successfully.\n";
}

// Виведення оцінок
void print (int *arr, int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        cout << setw(3) << arr[i];
    }
    cout << endl;
}

// Перескладання іспиту
void retake(int *arr, int SIZE) {
    int remove;
    cout << "Enter the grade you want to remove: ";
    cin >> remove;
    int enter;
    cout << "Enter the new grade: ";
    cin >> enter;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == remove) {
            arr[i] = enter;
            break;
        }
    }
    cout << endl;
}

// Чи виходить стипендія?
void mid(int *arr, int SIZE) {
    double sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += arr[i];
    }
    double average = sum / SIZE;
    cout << " Average score: " << average << endl;

    if (average >= 10.7) {
        cout << "You have a scholarship.\n";
    } else {
        cout << "You don't have a scholarship.\n";
    }
}

int main() {
    int SIZE = 10;
    int *arr = new int[SIZE];
    int choice;

    Diary(arr, SIZE);

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 1) {
            print(arr, SIZE);
        } else if (choice == 2) {
            retake(arr, SIZE);
            print(arr, SIZE);
        } else if (choice == 3) {
            mid(arr, SIZE);
        } else if (choice == 4) {
            cout << "You selected Exit\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    delete[] arr;
    return 0;
}