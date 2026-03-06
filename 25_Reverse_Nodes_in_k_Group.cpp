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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return head;
        }

        //reverse 1st k node ;
        ListNode* next = NULL; 
        ListNode* curr = head;
        ListNode* prev = NULL; 

        int count = 0;
        
         ListNode* temp = head;

        //checcking if  k number of nodes actually exists 
         while(temp != NULL && count < k){
            temp = temp->next;
            count++;
         }
         if(count<k)
         return head ;


        count = 0;

        while(curr != NULL && count < k){
            next= curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(count < k ){
            return head ;
        }
        // step 2 recursive call
        if(next!= NULL){
            head->next = reverseKGroup( next, k);
        }
        //return head of prevous link list 
        return prev;
       

    }
};
