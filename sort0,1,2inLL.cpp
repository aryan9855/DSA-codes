 Node* segregate(Node* head) {
        Node* zeroCnt = 0;
        Node* oneCnt =0;
        Node* twoCnt =0;
        Node* temp = head;
        while(temp != NULL){
            if(temp -> data == 0){
                zeroCnt++;
            }
            if(temp -> data == 1){
                oneCnt++;
            }
            if(temp -> data == 2){
                twoCnt++;
            }
         temp = temp -> next;   
        }
        temp = head;
        while(temp != NULL){
            if(zeroCnt!=0){
                temp -> data = 0;
                zeroCnt--;
        }
        
         else if(oneCnt!=0){
                temp -> data = 1;
                oneCnt--;
        }
        
         else if(twoCnt!=0){
                temp -> data = 2;
                twoCnt--;
        }
        temp = temp -> next;
        }
        return head;
    }