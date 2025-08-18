#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<char> types;     // 'L', '*', '#', '%'
    vector<long long> lens; // result length after each operation
    vector<char> values;    // only valid if type == 'L'

    char getChar(long long k, int idx) {
        if (idx < 0 || k < 0 || k >= lens[idx]) return '.';

        char t = types[idx];

        if (t == 'L') {
            return k == lens[idx] - 1 ? values[idx] : getChar(k, idx - 1);
        } else if (t == '*') {
            return getChar(k, idx - 1);
        } else if (t == '#') {
            long long prevLen = lens[idx - 1];
            if (k < prevLen) return getChar(k, idx - 1);
            else return getChar(k - prevLen, idx - 1);
        } else if (t == '%') {
            long long prevLen = lens[idx - 1];
            return getChar(prevLen - 1 - k, idx - 1);
        }

        return '.';
    }

    char processStr(string s, long long k) {
        types.clear();
        lens.clear();
        values.clear();

        for (char c : s) {
            if (islower(c)) {
                types.push_back('L');
                values.push_back(c);
                lens.push_back(lens.empty() ? 1 : lens.back() + 1);
            } else if (c == '*') {
                types.push_back('*');
                values.push_back(0);
                long long newLen = lens.empty() ? 0 : max(0LL, lens.back() - 1);
                lens.push_back(newLen);
            } else if (c == '#') {
                types.push_back('#');
                values.push_back(0);
                long long prevLen = lens.empty() ? 0 : lens.back();
                lens.push_back(min(prevLen * 2, (long long)1e15));
            } else if (c == '%') {
                types.push_back('%');
                values.push_back(0);
                long long prevLen = lens.empty() ? 0 : lens.back();
                lens.push_back(prevLen);
            }
        }

        return getChar(k, lens.size() - 1);
    }
};
