//https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/?envType=daily-question&envId=2025-02-05
//1790. Check if One String Swap Can Make Strings Equal
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int x = -1;
        for(int i =0 ;i<s1.length();i++){
            if(s1[i] != s2[i]){
                if(x==-1){
                    x=i;
                }
                else{
                    swap(s2[i],s2[x]);
                    return s1 == s2;
                }
            }
        }
        return s1 == s2;
    }
};