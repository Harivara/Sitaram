https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/2163495627/

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int>v(3,0);
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++){
            v[s[right]-'a']++;
            while(v[0]>0 && v[1]>0 && v[2]>0){
                ans+=n-right;
                v[s[left]-'a']--;
                left++;
            }
        }
        return ans;
    }
};