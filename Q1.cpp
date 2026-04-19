#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Function to check if it is possible to turn off all bulbs
 * using at most k operations with a range of length L.
 */
bool canTurnOffAll(int n, int k, const string& bulbs, int l) {
    int operations = 0;
    for (int i = 0; i < n; ) {
        if (bulbs[i] == '1') {
            // If we find an ON bulb, we must use an operation starting here
            operations++;
            // If operations exceed k, this L is too small
            if (operations > k) return false;
            // Skip the next L bulbs as they are covered by this operation
            i += l;
        } else {
            // Bulb is already OFF, move to the next one
            i++;
        }
    }
    return operations <= k;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (!(cin >> n >> k)) return 0;

    string bulbs;
    cin >> bulbs;

    int low = 1, high = n;
    int ans = n;

    // Binary search for the minimum possible L
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (canTurnOffAll(n, k, bulbs, mid)) {
            ans = mid;      // mid works, try to find a smaller value
            high = mid - 1;
        } else {
            low = mid + 1;  // mid is too small, increase L
        }
    }

    cout << ans << endl;

    return 0;
}
