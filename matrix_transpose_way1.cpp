#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter rows and columns: ";
    cin >> rows >> cols;

    int matrix[rows][cols], transpose[cols][rows];

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            transpose[j][i] = matrix[i][j];
    }

    cout << "Transpose matrix:" << endl;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            cout << transpose[i][j] << " ";
        cout << endl;
    }

    return 0;
}
