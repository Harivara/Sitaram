https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int water=0;
        while(left<right){
            water=max(water,(min(height[left],height[right])*(right-left)));
            if(height[left]<=height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return water;
    }
};