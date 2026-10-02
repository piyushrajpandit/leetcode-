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
    void reorderList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr){
            return ;
        }
     
        ListNode* curr = head;
        while(curr->next != nullptr && curr->next->next != nullptr){
            ListNode * prev= curr;
            ListNode * temp = curr->next;
            
            while( temp->next != nullptr){
                prev= temp ;
                temp = temp->next;
            }
            temp->next = curr->next;
            curr->next = temp;

            prev->next = nullptr;

            curr= temp->next;
        }
        

  
    }
};
