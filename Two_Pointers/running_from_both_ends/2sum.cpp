https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>v;
        int j=numbers.size()-1;
        int i=0;
        while(i<j){
            if(i>0 && numbers[i]==numbers[i-1]){
                continue;
            }
            if(numbers[i]+numbers[j]==target){
                v.push_back(i+1);
                v.push_back(j+1);
                break;
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
                
            }
            else{
                i++;
            }
            
        }
        return v;
    }
};