
class Solution {
public:
    
    bool hasCycle(ListNode *head) {
        if(head == NULL){
            return false;
        }
      ListNode* slow = head ; 
      ListNode* fast = head; 
      while (fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        if(fast == slow){
            return 1;
        }
      
      }
      return false;

    }
};
