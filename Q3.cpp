#include <iostream>

using namespace std;

/**
 * Problem: Help Alice to find the Parity
 * Logic: The parity of the XOR sum depends solely on how many odd numbers 
 * are in the range [L, R]. If the count of odd numbers is odd, the result 
 * is odd. If the count of odd numbers is even, the result is even.
 */

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    
    // Read input L and R. Using long long because constraints are up to 10^18.
    if (!(cin >> L >> R)) return 0;

    // Function to count odd numbers from 1 to N is (N + 1) / 2
    long long odds_upto_R = (R + 1) / 2;
    long long odds_upto_L_minus_1 = L / 2; // Equivalent to ((L-1) + 1) / 2

    long long total_odds = odds_upto_R - odds_upto_L_minus_1;

    // If the number of odd integers is even, the XOR sum parity is even
    if (total_odds % 2 == 0) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }

    return 0;
}
