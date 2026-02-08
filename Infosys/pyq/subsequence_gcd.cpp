#include <bits/stdc++.h>
using namespace std;

// Function to process the problem
int get_ans(int n, vector<int>& a, int p, int q, vector<vector<int>>& queries) {
    int yesCount = 0;

    multiset<int> vals;   // stores a[i]/p where a[i] % p == 0
    int cntDiv = 0;

    auto computeGCD = [&]() {
        int g = 0;
        for (int x : vals)
            g = gcd(g, x);
        return g;
    };

    // Initial preprocessing
    for (int x : a) {
        if (x % p == 0) {
            vals.insert(x / p);
            cntDiv++;
        }
    }

    // Process queries
    for (auto &qr : queries) {
        int i = qr[0] - 1;
        int newVal = qr[1];

        // Remove old value
        if (a[i] % p == 0) {
            vals.erase(vals.find(a[i] / p));
            cntDiv--;
        }

        // Insert new value
        a[i] = newVal;
        if (a[i] % p == 0) {
            vals.insert(a[i] / p);
            cntDiv++;
        }

        // Check GOOD subsequence condition
        if (cntDiv > 0 && cntDiv < n) {
            int g = computeGCD();
            if (g == 1)
                yesCount++;
        }
    }

    return yesCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int p;
    cin >> p;

    int q;
    cin >> q;

    int two;   // always 2, but still read it
    cin >> two;

    vector<vector<int>> queries(q, vector<int>(2));
    for (int i = 0; i < q; i++)
        cin >> queries[i][0] >> queries[i][1];

    cout << get_ans(n, a, p, q, queries) << "\n";
    return 0;
}
