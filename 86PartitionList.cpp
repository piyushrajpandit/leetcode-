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
    ListNode* partition(ListNode* head, int x) {
        ListNode * smallDummy = new ListNode(0);
        ListNode * largeDummy = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* large = largeDummy;

        ListNode* temp = head;
        
        while(temp != nullptr){
            if(temp->val < x){
                small->next = temp;
                small = small->next;

            }
            else{
                large->next = temp;
                large = large->next;
            }

            temp = temp->next;
        }
        temp->next =  newTail->next;
        return head;
    }
};
