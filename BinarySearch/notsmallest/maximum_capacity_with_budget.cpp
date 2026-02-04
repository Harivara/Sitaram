https://leetcode.com/problems/maximum-capacity-within-budget/description/

class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> machines(n);

        // combine cost and capacity
        for (int i = 0; i < n; i++) {
            machines[i] = {costs[i], capacity[i]};
        }

        // sort by cost
        sort(machines.begin(), machines.end(),
             [](const pair<int,int>& a, const pair<int,int>& b) {
                 return a.first < b.first;
             });

        int ans = 0;

        // one machine
        for (int i = 0; i < n; i++) {
            if (machines[i].first < budget) {
                ans = max(ans, machines[i].second);
            }
        }

        // prefix max of capacities
        vector<int> prefixmax(n);
        prefixmax[0] = machines[0].second;
        for (int i = 1; i < n; i++) {
            prefixmax[i] = max(prefixmax[i - 1], machines[i].second);
        }

        // two machines
        // We fix one machine as the right machine (r) and try to find the best left machine.
        for (int r = 1; r < n; r++) {
            int remaining = budget - machines[r].first;
            if (remaining <= 0) continue;

            int l = 0, h = r - 1, idx = -1;
            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (machines[mid].first < remaining) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }
            // 👉 the most expensive machine ≤ remaining budget

            if (idx != -1) {
                ans = max(ans, prefixmax[idx] + machines[r].second);
            }
            // if we can afford cost of idx we can afford the machine less than that cost with more capccity
            // so we use the prefixmax for machine capacity
        }

        return ans;
    }
};