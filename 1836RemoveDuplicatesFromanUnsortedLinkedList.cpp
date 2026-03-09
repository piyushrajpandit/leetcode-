class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      while (curr ! = NULL){
        ListNode * temp = curr->next;
        while(temp!= curr){
          if(curr->data == temp->data){
          //deletion wali backchodi 
          }
            
          else{
            temp= temp->next;
          }
        }
        curr= curr->next;
      }
      
        
    }
};
