#include <iostream>
#include <cmath>
using namespace std;

const int MAX_N = 10000000;

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int countCoprimePairs(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            int d1 = i;
            int d2 = n / i;

            // Check if gcd(d1, d2) is 1
            if (gcd(d1, d2) == 1) {
                count += 2; // (d1, d2) and (d2, d1)
            }
            
            // If d1 and d2 are the same, we counted it twice, so we need to subtract one
            if (d1 == d2) {
                count--;
            }
        }
    }
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T; // Read number of test cases
    while (T--) {
        int n;
        cin >> n; // Read each number N
        cout << countCoprimePairs(n) << '\n'; // Output the result (pairs count)
    }

    return 0;
}
