class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        int maxi = INT_MIN;

        // Count frequency of each element
        for (int i : arr) {
            mp[i]++;
            maxi = max(maxi, mp[i]);
        }

        int result = INT_MIN;

        // Among all elements with max frequency, pick the largest one
        for (auto i : mp ){
            if (i.second == maxi) {
                result = max(result, i.first);
            }
        }

        return result;
        
    }
};