https://leetcode.com/problems/soup-servings/description/

// class Solution {
// public:
// vector<vector<double>> dp;

// double P(int a, int b) {
//     // Base cases
//     if (a <= 0 && b <= 0) return 0.5;
//     if (a <= 0) return 1.0;
//     if (b <= 0) return 0.0;

//     // Memoization check
//     if (dp[a][b] >= 0) return dp[a][b];

//     // Recurrence
//     double res = 0.25 * (
//         P(a - 4, b) +
//         P(a - 3, b - 1) +
//         P(a - 2, b - 2) +
//         P(a - 1, b - 3)
//     );

//     return dp[a][b] = res;
// }

// double soupServings(int n) {
//     int m = (n + 24) / 25; // Convert to units of 25 mL
//     dp.assign(m + 1, vector<double>(m + 1, -1.0));
//     return P(m, m);
// }
// };

class Solution {
public:
struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return ((size_t)p.first << 32) ^ p.second;
    }
};

unordered_map<pair<int,int>, double, PairHash> memo;

double P(int a, int b) {
    if (a <= 0 && b <= 0) return 0.5;
    if (a <= 0) return 1.0;
    if (b <= 0) return 0.0;

    auto key = make_pair(a, b);
    if (memo.count(key)) return memo[key];

    double res = 0.25 * (
        P(a - 4, b) +
        P(a - 3, b - 1) +
        P(a - 2, b - 2) +
        P(a - 1, b - 3)
    );

    return memo[key] = res;
}

double soupServings(int n) {
    if (n > 4800) return 1.0; // cutoff optimization
    int m = (n + 24) / 25;
    memo.clear();
    return P(m, m);
}
};

pair<int,int> a = {4, 7};
PairHash h;
size_t hv = h(a);