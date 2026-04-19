#include<bits/stdc++.h>
using namespace std;

string solve(int n, vector<int>& a) {
    // Sort array in descending order
    sort(a.begin(), a.end(), greater<int>());
    
    long long alex_total = 0;
    long long bob_total = 0;
    set<int> alex_used;   // Quantities Alex has already consumed
    set<int> bob_used;    // Quantities Bob has already consumed
    bool alex_turn = true;
    
    for(int i = 0; i < n; i++) {
        if(alex_turn) {
            // Check if Alex has already used this quantity
            if(alex_used.find(a[i]) != alex_used.end()) {
                continue;  // Skip this pile
            }
            alex_used.insert(a[i]);
            alex_total += a[i];
        } else {
            // Check if Bob has already used this quantity
            if(bob_used.find(a[i]) != bob_used.end()) {
                continue;  // Skip this pile
            }
            bob_used.insert(a[i]);
            bob_total += a[i];
        }
        
        // Switch turns
        alex_turn = !alex_turn;
    }
    
    // Determine winner
    if(alex_total > bob_total) {
        return "Alex";
    } else {
        return "Bob";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        cout << solve(n, a) << "\n";
    }
    
    return 0;
}