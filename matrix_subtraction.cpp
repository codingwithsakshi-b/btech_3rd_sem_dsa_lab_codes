#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int A[rows][cols], B[rows][cols], C[rows][cols];

    cout << "Enter elements of first matrix:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix:" << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> B[i][j];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            C[i][j] = A[i][j] - B[i][j];
    }

    cout << "Difference of matrices:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}
