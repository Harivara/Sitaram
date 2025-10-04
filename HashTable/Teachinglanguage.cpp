https://leetcode.com/problems/minimum-number-of-people-to-teach

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size(); // number of people
        vector<unordered_set<int>> lan(m);
        
        // Store each person's languages in a set
        for (int i = 0; i < m; i++) {
            for (int l : languages[i]) {
                lan[i].insert(l);
            }
        }
        
        // Step 1: Find people who cannot communicate
        unordered_set<int> needTeach;
        for (auto &f : friendships) {
            int u = f[0] - 1, v = f[1] - 1; // 0-index
            bool canCommunicate = false;
            for (int l : lan[u]) {
                if (lan[v].count(l)) {
                    canCommunicate = true;
                    break;
                }
            }
            if (!canCommunicate) {
                needTeach.insert(u);
                needTeach.insert(v);
            }
        }
        
        if (needTeach.empty()) return 0; // everyone already communicates
        
        // Step 2: Count frequency of each language among those who need teaching
        vector<int> freq(n + 1, 0);
        for (int person : needTeach) {
            for (int l : lan[person]) {
                freq[l]++;
            }
        }
        
        // Step 3: Maximize coverage
        int maxKnown = 0;
        for (int l = 1; l <= n; l++) {
            maxKnown = max(maxKnown, freq[l]);
        }
        
        // Step 4: Minimum teachings = people who need teaching - those who already know the best language
        return needTeach.size() - maxKnown;
    }
};
