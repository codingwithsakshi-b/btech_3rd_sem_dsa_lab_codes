#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter size of square matrix: ";
    cin >> n;

    int matrix[n][n];

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    cout << "Transpose matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
