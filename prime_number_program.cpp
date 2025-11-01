#include <iostream>
#include <cmath>
using namespace std;

void isPrime() {
    int n;
    cout << "ENTER THE VALUE OF N: ";
    cin >> n;

    if (n <= 1) {
        cout << n << " IS NOT A PRIME NUMBER" << endl;
        return;
    }
    if (n <= 3) {
        cout << n << " IS A PRIME NUMBER" << endl;
        return;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        cout << n << " IS NOT A PRIME NUMBER" << endl;
        return;
    }

    // Check divisors of form 6k ± 1
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            cout << n << " IS NOT A PRIME NUMBER" << endl;
            return;
        }
    }

    cout << n << " IS A PRIME NUMBER" << endl;
}

int main() {
    isPrime();
    return 0;
