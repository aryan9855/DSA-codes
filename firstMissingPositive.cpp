//https://leetcode.com/problems/first-missing-positive/description/
//Quse :41 First Missing Positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int positive = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) {
                continue;
            }
            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }
            if (nums[i] != positive) {
                return positive;
            }
            positive++;
        }
        return positive;
    }
};