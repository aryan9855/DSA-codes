class Solution {
  public:
    stack<int> insertAtBottom(stack<int> st, int x) {
        stack<int> st2;
        while(!st.empty()){
            st2.push(st.top());
            st.pop();
        }
        st2.push(x);
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        return st;
    }
};