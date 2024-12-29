#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>  // Для std::sort
using namespace std;

struct Contact {
    string name;
    string homePhone;
    string mobilePhone;
};

// Масив мобільних номерів
void Array_1(Contact *arr, int size) {
    string temp[10] = {
        "0971234567", "0662345678", "0503456789", "0934567890", "0685678901",
        "0736789012", "0967890123", "0998901234", "0959012345", "0630123456"
    };
    for (int i = 0; i < size; i++) {
        arr[i].mobilePhone = temp[i];
    }
}

// Масив домашніх номерів
void Array_2(Contact *arr, int size) {
    string temp[10] = {
        "04412", "04523", "04634", "04745", "04856", "04967", "04178", "04289", "04390", "04401"
    };
    for (int i = 0; i < size; i++) {
        arr[i].homePhone = temp[i];
    }
}

// Масив імен
void Name(Contact *arr, int size) {
    string temp[10] = {
        "John", "Doe", "Jane", "Smith", "Alex", "Bob", "Alice", "Eve", "Mike", "Tom"
    };
    for (int i = 0; i < size; i++) {
        arr[i].name = temp[i];
    }
}

// Виведення списку контактів
void print(Contact *arr, int size) {
    cout << " ----------------CONTACTS---------------- " << endl;
    cout << "    Name: mobile phone | home phone " << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(8) << arr[i].name << ": " << setw(8) << arr[i].mobilePhone << " | " << setw(4) << arr[i].homePhone << endl;
    }
    cout << endl;
}

// Сортування за номером мобільних телефонів
bool compareByMobilePhone(const Contact &a, const Contact &b) {
    return a.mobilePhone < b.mobilePhone;
}

// Сортування за номером домашніх телефонів
bool compareByHomePhone(const Contact &a, const Contact &b) {
    return a.homePhone < b.homePhone;
}

// Меню
void menu() {
    cout << " ----------------MENU---------------- " << endl;
    cout << " 1. Print contacts" << endl;
    cout << " 2. Sort by mobile phone" << endl;
    cout << " 3. Sort by home phone" << endl;
    cout << " 4. Exit" << endl;
    cout << " ------------------------------------ " << endl;
    cout << " Enter your choice: ";
}

// Вибір користувача
void clik(Contact *arr, int size) {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            print(arr, size);    // Виводимо список контактів
            menu();
            clik(arr, size);
            break;
        case 2:
            sort(arr, arr + size, compareByMobilePhone);  // Сортуємо за мобільним телефоном
            print(arr, size);
            menu();
            clik(arr, size);
            break;
        case 3:
            sort(arr, arr + size, compareByHomePhone);    // Сортуємо за домашнім телефоном
            print(arr, size);
            menu();
            clik(arr, size);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Try again." << endl;
    }
}

int main() {
    srand(time(0));

    int size = 10;
    Contact *arr = new Contact[size];  // Масив структур Contact

    Array_1(arr, size);  // Заповнюємо мобільними номерами
    Array_2(arr, size);  // Заповнюємо домашніми номерами
    Name(arr, size);     // Заповнюємо іменами

    menu();
    clik(arr, size);  // Вибір користувача

    delete[] arr;  // Очищаємо пам'ять
    return 0;
}
