//https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03
//3105. Longest Strictly Increasing or Strictly Decreasing Subarray
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int x=1 ,y=1,maxi=1;
        int n = nums.size();
        for(int i = 0 ;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                x++;
                y=1;
            }
            else if(nums[i]>nums[i+1]){
                y++;
                x=1;
            }
            else{
            x=1;
            y=1;
        }
        
        maxi = max(maxi, max(x, y));
        }
        return maxi;
    }
};