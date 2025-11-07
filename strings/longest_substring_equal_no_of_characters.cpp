https://leetcode.com/problems/longest-balanced-substring-i/

class Solution {
public:
    bool check(vector<int> &fq)
    {
        int freq=0;
        for(int i=0;i<26;i++){
            if(fq[i]!=0) {freq=fq[i]; break;}
        }
        //freq will store the first non-zero frequency value
        for(int i=0;i<26;i++)
            {
                if(fq[i]!=0 && fq[i]!=freq) return false; //if any of the non-zero frequency value is not equal to freq then its false
            }

        return true;
    }
    int longestBalanced(string s) {

        int i=0; int n = s.size();
        if(n==1) return 1; //edge case
        int ans=0;
        while(i<n)
            {
                if(ans>(n-i)) break;  //if the maximum substring starting from i is smaller than ans 
                
                vector<int> fq(26,0); //initialising frequency array
                fq[s[i]-'a']++;  //adding frequency of s[i]

                int j = i+1;
                while(j<n)
                    {
                        fq[s[j]-'a']++; //adding frequency of our increasing subarray
                        if(check(fq)){  //checking if frequency of all distinct is the same i.e is it a balanced string
                            ans=max(ans,(j-i)+1);  // (j-i)+1 is the length of current subarray -> we r maximising ans
                        }
                        j++;
                    }
                i++;
            }
        return ans;
    }
};