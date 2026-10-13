#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    cout << "Enter value of n: ";
    cin >> n;

    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 0;
    }

    cout << "Fibonacci sequence up to term " << n << ": ";
    for (int i = 0; i <= n; i++)
        cout << fibonacci(i) << " ";
    cout << endl;

    cout << "The nth Fibonacci number is: " << fibonacci(n) << endl;
    return 0;
}
