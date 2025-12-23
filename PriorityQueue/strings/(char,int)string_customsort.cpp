https://leetcode.com/contest/weekly-contest-400/problems/lexicographically-minimum-string-after-removing-stars/

class Solution {
public:
    struct cmp {
        bool operator()(const pair<char,int>& a, const pair<char,int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };
    

    string clearStars(string s) {
        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> pq;
        vector<bool> removed(s.size(), false);

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*') {
                pq.push({s[i], i});
            } else if (!pq.empty()) {
                removed[pq.top().second] = true;
                pq.pop();
            }
        }

        string res="";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != '*' && !removed[i])
                res += s[i];
        }
        return res;
    }
};
©leetcode