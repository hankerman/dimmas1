#include <iostream>
using namespace std;

void fill(int** B, int size, int size2) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size2; j++) {
            B[i][j] = rand() % 100;
        }
    }
}

void print(int** B, int size, int size2) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size2; j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
}

void copy(int** A, int** B, int size, int size2) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size2; j++) {
            B[i][j] = A[i][j];
        }
    }
}

int main()
{
    
    /*Написать функцию, добавляющую столбец 
    двухмерному массиву в указанную позицию.*/

    srand(time(NULL));
    int m1 = 5, m2 = 4;
    int** A = new int* [m1];

    for (int i = 0; i < m1; i++) {
        A[i] = new int[m2];
    }

    int** B = new int* [m1];

    for (int i = 0; i < m1; i++) {
        B[i] = new int[m2];
    }

    fill(A, m1, m2);
    print(A, m1, m2);

    cout << endl;
    int s1;
    cout << "insert col: ";
    cin >> s1;
    copy(A, B, m1, m2);
    
    for (int i = 0; i < m1; i++) {
        delete[]A[i];
    }
    delete[]A;

    int m3 = m2 + 1;

    A = new int* [m1];

    for (int i = 0; i < m1; i++) {
        A[i] = new int[m3];
    }

    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < m3; j++) {
            if (j < s1) {
                A[i][j] = B[i][j];
            }
            else if (j == s1) {
                A[i][j] = -1;
            }
            else {
                A[i][j] = B[i][j-1];
            }
        }
    }
    cout << endl;
    print(A, m1, m3);

    for (int i = 0; i < m1; i++) {
        delete[]A[i];
    }
    delete[]A;

    for (int i = 0; i < m1; i++) {
        delete[]B[i];
    }
    delete[]B;

}