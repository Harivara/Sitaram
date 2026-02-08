// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

// class Solution {
// public:
//     vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

//         int n = deadline.size();
//         vector<pair<int,int>> jobs;

//         for (int i = 0; i < n; i++) {
//             jobs.push_back({profit[i], deadline[i]});
//         }

//         // sort by profit descending
//         sort(jobs.begin(), jobs.end(), greater<>());

//         int maxDeadline = *max_element(deadline.begin(), deadline.end());
//         vector<int> slot(maxDeadline + 1, -1);

//         int count = 0, totalProfit = 0;

//         for (auto &job : jobs) {
//             int d = job.second;
//             int p = job.first;

//             // find latest free slot
//             for (int t = d; t > 0; t--) {
//                 if (slot[t] == -1) {
//                     slot[t] = 1;
//                     count++;
//                     totalProfit += p;
//                     break;
//                 }
//             }
//         }

//         return {count, totalProfit};
//     }
// };


class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = deadline.size();
        vector<pair<int,int>> jobs;

        for (int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }

        // sort jobs by profit descending
        sort(jobs.begin(), jobs.end(), greater<>());

        int maxDeadline = *max_element(deadline.begin(), deadline.end());

        parent.resize(maxDeadline + 1);
        for (int i = 0; i <= maxDeadline; i++) {
            parent[i] = i;
        }

        int count = 0, totalProfit = 0;

        for (auto &job : jobs) {
            int p = job.first;
            int d = job.second;

            int slot = find(d);  // find latest free slot
            if (slot > 0) {
                count++;
                totalProfit += p;
                parent[slot] = find(slot - 1); // occupy slot
            }
        }

        return {count, totalProfit};
    }
};
