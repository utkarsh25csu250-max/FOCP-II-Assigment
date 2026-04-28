#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Bank {
private:
    unordered_map<int, long long> balanceMap;

public:
    bool create(int userId, long long amount) {
        if (balanceMap.count(userId)) {
            balanceMap[userId] += amount;
            return false;
        }
        balanceMap[userId] = amount;
        return true;
    }

    bool debit(int userId, long long amount) {
        if (!balanceMap.count(userId) || balanceMap[userId] < amount) {
            return false;
        }
        balanceMap[userId] -= amount;
        return true;
    }

    bool credit(int userId, long long amount) {
        if (!balanceMap.count(userId)) {
            return false;
        }
        balanceMap[userId] += amount;
        return true;
    }

    long long getBalance(int userId) {
        if (!balanceMap.count(userId)) {
            return -1;
        }
        return balanceMap[userId];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            int x;
            long long y;
            cin >> x >> y;
            cout << (bank.create(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "DEBIT") {
            int x;
            long long y;
            cin >> x >> y;
            cout << (bank.debit(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "CREDIT") {
            int x;
            long long y;
            cin >> x >> y;
            cout << (bank.credit(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "BALANCE") {
            int x;
            cin >> x;
            cout << bank.getBalance(x) << "\n";
        }
    }

    return 0;
}