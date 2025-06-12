class Solution {
  public:
  int length(Node* head ){
        int cnt = 0;
        while(head != NULL){
            cnt++;
            head = head -> next;
        }
        return cnt;
        }
    int solve(Node* head , int cnt,int k ){
        int target = cnt-k+1;
        int ans ;
        
        //base case
        if(target <= 0){
             ans = -1 ;
        }
        
        else{Node* curr = head;
        for(int i =1 ;i<target;i++){
            curr = curr -> next;
        }
         ans= curr -> data;
        }
        return ans;
}
    int getKthFromLast(Node *head, int k) {
        // Your code here
        int cnt = length(head);
        return solve(head,cnt,k);
        
    }
};