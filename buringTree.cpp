class Solution {
public:
TreeNode* createParentMapping(TreeNode* root , int target , map<TreeNode* , TreeNode*> &nodeToParent){
    TreeNode* result = NULL;
    queue <TreeNode*> q;//level order
    q.push(root);
    
    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();
        
        if(front -> val == target ){
            result = front ;
        }
        
        if(front -> left !=NULL ){
            nodeToParent[front -> left]= front;
            q.push(front -> left);
        }
        
        if(front -> right !=NULL ){
            nodeToParent[front -> right]= front;
            q.push(front -> right);
        }
        
        
    }
    return result;
      
  }
  
  int burnTree(TreeNode* root ,map<TreeNode* , TreeNode* > &nodeToParent){
      unordered_map<TreeNode* , bool > visited;
      queue<TreeNode* > q;
      q.push(root);
      visited[root] = true;
      
      int time = 0;
      
      while(!q.empty()){
          bool flag =0;
          int size = q.size();
          
          for(int i =0 ; i< size;i++){
              TreeNode* front = q.front();
              q.pop();
              
              if(front -> left != NULL && !visited[front -> left]){
                  flag = 1;
                  q.push(front -> left);
                  visited[front -> left] = 1;
              }
              
              if(front -> right != NULL && !visited[front -> right]){
                  flag =1;
                  q.push(front -> right);
                  visited[front ->right] = 1;
              }
              
              if(nodeToParent[front] !=NULL && !visited[nodeToParent[front]]){
                  flag =1;
                  q.push(nodeToParent[front]);
                  visited[nodeToParent[front]] =1;
              }
              
          }
          if(flag == 1 ){
              time ++;
          }
      }
      return time;
  }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> nodeToParent;
        TreeNode* targetNode = createParentMapping(root , start ,nodeToParent);
        
        return burnTree(targetNode,nodeToParent);
    }
};



             