class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        // code here
         queue<int> q1;
         queue<int> q2;
         int n = q.size();
         int mid = n/2;
         for(int i =0 ;i < mid;i++){
            q1.push(q.front());
            q.pop();
         }
         int m = q.size();
         for(int i =0 ;i <m;i++){
            q2.push(q.front());
            q.pop();
         }
         while(!q1.empty() && !q2.empty()){
            q.push(q1.front());
            q1.pop();
            q.push(q2.front());
            q2.pop();
         }
         return q;
    }
};