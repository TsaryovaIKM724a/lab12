#include <iostream>
#include <Windows.h>

using namespace std;

const int ROWS = 3, COLS = 3;
int sumMaxInRows(int matrix[ROWS][COLS]) {
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        int maxVal = matrix[i][0];
        for (int j = 1; j < COLS; j++) {
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
        }
        sum += maxVal;
    }
    return sum;
}
void convertTo1D(int matrix[ROWS][COLS], int oneDArray[ROWS * COLS]) {
    int index = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            oneDArray[index++] = matrix[i][j];
        }
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int matrix[ROWS][COLS] = {
        {3, 5, 9},
        {1, 6, 4},
        {7, 2, 8}
    };

    int sumMax = sumMaxInRows(matrix);
    cout << "Сума максимальних елементів рядків: " << sumMax << endl;

    int oneDArray[ROWS * COLS];
    convertTo1D(matrix, oneDArray);

    cout << "Одномірний масив: ";
    for (int i = 0; i < ROWS * COLS; i++) {
        cout << oneDArray[i] << " ";
    }
    cout << endl;
}
