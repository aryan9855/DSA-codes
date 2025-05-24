class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
     stack<int> s;
     if (k > q.size() || k < 0) return q;  

     int n = q.size();
     for(int i = 0 ; i<k ;i++){
        s.push(q.front());
        q.pop();
     }
     while(!s.empty()){
         q.push(s.top());
         s.pop();
     }
     int t = n-k;
     while(t--){
         q.push(q.front());
         q.pop();
         
     }
     return q;
    }
};