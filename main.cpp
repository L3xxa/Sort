#include <iostream>
#include <vector>
#include <algorithm> // для std::reverse
using namespace std;

// Перевертання частини стопки
void flip(vector<int>& stack, int k) {
    reverse(stack.begin(), stack.begin() + k + 1);
}

// Пошук індексу найбільшого елемента в діапазоні
int findMaxIndex(const vector<int>& stack, int end) {
    int maxIndex = 0;
    for (int i = 1; i < end; i++) {
        if (stack[i] > stack[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

// Сортування оладок
void pancakeSort(vector<int>& stack) {
    int n = stack.size();
    for (int size = n; size > 1; size--) {
        int maxIndex = findMaxIndex(stack, size);

        if (maxIndex == size - 1) continue;

        if (maxIndex > 0) {
            flip(stack, maxIndex);
            cout << "Flip at position " << maxIndex + 1 << ": ";
            for (int x : stack) cout << x << " ";
            cout << endl;
        }

        // Перевертання, щоб перемістити його на правильне місце
        flip(stack, size - 1);
        cout << "Flip at position " << size << ": ";
        for (int x : stack) cout << x << " ";
        cout << endl;
    }
}

int main() {
    vector<int> pancakes = {6, 1, 8, 7, 2, 5, 4, 3}; // Стопка оладок
    cout << "Initial stack: ";
    for (int x : pancakes) cout << x << " ";
    cout << endl;

    pancakeSort(pancakes);

    cout << "Sorted stack: ";
    for (int x : pancakes) cout << x << " ";
    cout << endl;

    return 0;
}
