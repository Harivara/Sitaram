// https://leetcode.com/contest/weekly-contest-400/problems/count-days-without-meetings/

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) { 
       sort(meetings.begin(),meetings.end());
        int prev=meetings[0][1];
        int count=meetings[0][0]-1; // days before first meeting
        for(int i=1;i<meetings.size();i++){
              if(meetings[i][0]-prev>1){
                  count=count+meetings[i][0]-prev-1;
              }
            prev=max(prev,meetings[i][1]);
        }
        cout<<count<<endl;
        cout<<prev<<endl;
        // cout<<count<<endl;
        count=count+days-prev;  // days after last meeting
        return count;
    }
};©leetcode