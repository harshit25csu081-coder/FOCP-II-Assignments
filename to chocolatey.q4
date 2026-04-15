#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Step 1: sort descending
    sort(a.begin(), a.end(), greater<int>());

    set<int> Alex, Bob;

    long long alex = 0, bob = 0;

    int turn = 0; // 0 = Alex, 1 = Bob

    for (int i = 0; i < n; i++) {
        int val = a[i];

        if (turn == 0) {
            // Alex's turn
            if (Alex.count(val) == 0) {
                alex =alex + val;
                Alex.insert(val);
                turn = 1; // switch turn
            }
        } else {
            // Bob's turn
            if (Bob.count(val) == 0) {
                bob = bob+ val;
                Bob.insert(val);
                turn = 0; // switch turn
            }
        }
    }

    if (alex > bob)
        cout << "Alex\n";
    else
        cout << "Bob\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
