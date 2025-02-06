//https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06
//1726. Tuple with Same Product
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        vector<int> product;
        for(int i=0 ;i<nums.size();i++){
            for(int j =i+1;j<nums.size();j++){
                if(i!=j){
                    product.push_back(nums[i]*nums[j]);
                }
            }
        }
        int count =0;
        sort(product.begin(),product.end());
             for (int k = 0; k < product.size() - 1; k++) { 
            if (product[k] == product[k + 1]) {
                int freq = 1;
                while (product[k] == product[k + 1]) {
                    freq++;
                    k++;
                }
                count += (freq * (freq - 1)) / 2;
            }
        }
        
        return count * 8;  
    }
};