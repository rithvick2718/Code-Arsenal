#include <bits/stdc++.h>
using namespace std;

// Partition `files` into the minimum number of strictly‑decreasing subsequences.
// Returns a vector of piles, where each pile is one pass.
vector<vector<int>> decompose_decreasing_passes(const vector<int>& files) {
    vector<vector<int>> piles;      // the actual subsequences
    vector<int> pile_tops;          // pile_tops[i] = last element in piles[i]

    for (int x : files) {
        // find the first pile whose top >= x
        auto it = lower_bound(pile_tops.begin(), pile_tops.end(), x);
        if (it == pile_tops.end()) {
            // no such pile → start a new one
            piles.push_back({x});
            pile_tops.push_back(x);
        } else {
            // append x to that pile (maintains strict decrease)
            int idx = it - pile_tops.begin();
            piles[idx].push_back(x);
            *it = x;  // update the top
        }
    }
    return piles;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> files(n);
    for (int i = 0; i < n; i++) {
        cin >> files[i];
    }

    auto passes = decompose_decreasing_passes(files);
    cout << passes.size() << "\n";
    // If you also want to print each pass:
    for (int i = 0; i < (int)passes.size(); i++) {
        cout << "Pass " << (i+1) << ":";
        for (int x : passes[i])
            cout << " " << x;
        cout << "\n";
    }
    return 0;
}
