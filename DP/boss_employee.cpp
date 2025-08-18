class Solution {
public:
    int n;

    // Check if discount applies
    bool discount(int ind, unordered_map<int, vector<int>>& mp, vector<int>& bought) {
        for (int boss : mp[ind]) {
            if (bought[boss]) return true;
        }
        return false;
    }

    int dfs(int ind, vector<int>& present, vector<int>& future,
            vector<int>& bought, unordered_map<int, vector<int>>& mp,
            int budget) {
        if (ind == n) return 0;

        int maxProfit = dfs(ind + 1, present, future, bought, mp, budget);  // skip current

        int price = present[ind];
        if (discount(ind, mp, bought)) {
            price /= 2;
        }

        if (budget >= price) {
            bought[ind] = 1;
            int profit = future[ind] - price +
                         dfs(ind + 1, present, future, bought, mp, budget - price);
            bought[ind] = 0;  // backtrack
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }

    int maxProfit(int _n, vector<int>& present, vector<int>& future,
                  vector<vector<int>>& hierarchy, int budget) {
        n = _n;
        unordered_map<int, vector<int>> mp;

        for (auto& h : hierarchy) {
            int boss = h[0] - 1;
            int emp = h[1] - 1;
            mp[emp].push_back(boss);
        }

        vector<int> bought(n, 0);
        return dfs(0, present, future, bought, mp, budget);
    }
};
