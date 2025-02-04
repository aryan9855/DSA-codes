//https://leetcode.com/problems/maximum-ascending-subarray-sum/description/?envType=daily-question&envId=2025-02-04
// 1800. Maximum Ascending Subarray Sum
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int sum = nums[0];
        for(int i =1;i<n;i++){
            if(nums[i]> nums[i-1]){
                sum  += nums[i];
            }
            else{
                maxi = max(maxi , sum);
                sum = nums[i];
            }
        }
            return max (maxi , sum);
        }
};