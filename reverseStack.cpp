//https://leetcode.com/problems/reverse-string/
// Leetcode problem 344

class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char>st;
        for(char c:s){
            st.push(c);
        }
        for(int i =0;i<s.size();i++){
            s[i] = st.top();
            st.pop();
        }
    }
}; 