#include <bits/stdc++.h>
using namespace std;

class Bank {
private:
    unordered_map<string, long long> users;

public:
    bool create(string X, long long Y) {
        if (users.find(X) == users.end()) {
            users[X] = Y;
            return true; // new account created
        } else {
            users[X] += Y;
            return false; // already exists, just added money
        }
    }

    bool debit(string X, long long Y) {
        if (users.find(X) == users.end() || users[X] < Y) {
            return false;
        }
        users[X] -= Y;
        return true;
    }

    bool credit(string X, long long Y) {
        if (users.find(X) == users.end()) {
            return false;
        }
        users[X] += Y;
        return true;
    }

    long long balance(string X) {
        if (users.find(X) == users.end()) {
            return -1;
        }
        return users[X];
    }
};

int main() {
    int Q;
    cin >> Q;

    Bank bank;

    while (Q--) {
        string query;
        cin >> query;

        if (query == "CREATE") {
            string X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.create(X, Y) ? "true" : "false") << endl;
        } 
        else if (query == "DEBIT") {
            string X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.debit(X, Y) ? "true" : "false") << endl;
        } 
        else if (query == "CREDIT") {
            string X;
            long long Y;
            cin >> X >> Y;
            cout << (bank.credit(X, Y) ? "true" : "false") << endl;
        } 
        else if (query == "BALANCE") {
            string X;
            cin >> X;
            cout << bank.balance(X) << endl;
        }
    }

    return 0;
}