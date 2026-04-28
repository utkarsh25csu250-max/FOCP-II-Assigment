#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> bookings;
    const int MAX_SLOTS = 100;

public:
    bool book(int userId, int movieId) {
        // If already booked
        if (bookings[movieId].count(userId)) {
            return false;
        }
        // If full
        if (bookings[movieId].size() >= MAX_SLOTS) {
            return false;
        }
        bookings[movieId].insert(userId);
        return true;
    }

    bool cancel(int userId, int movieId) {
        if (!bookings[movieId].count(userId)) {
            return false;
        }
        bookings[movieId].erase(userId);
        return true;
    }

    bool isBooked(int userId, int movieId) {
        return bookings[movieId].count(userId) > 0;
    }

    int availableTickets(int movieId) {
        return MAX_SLOTS - bookings[movieId].size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    MovieTicket mt;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (mt.book(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (mt.cancel(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (mt.isBooked(x, y) ? "true" : "false") << "\n";
        }
        else if (query == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.availableTickets(y) << "\n";
        }
    }

    return 0;
}