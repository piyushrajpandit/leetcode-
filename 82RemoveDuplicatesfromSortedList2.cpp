/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
          if(head==NULL){
            return NULL;
        }
        //dummy head 
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = head ;
        ListNode * prev = dummy;
        while(curr!= NULL){
            
            if( curr->next !=NULL &&curr->val ==curr->next->val){
                int val = curr->val;
                while(curr != NULL && curr->val == val){
                    ListNode * temp = curr;
                    curr = curr->next;
                    delete(temp);
            }
            prev->next = curr;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
            
        }
        return dummy->next;
    }
};
