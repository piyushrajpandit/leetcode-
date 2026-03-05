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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head -> next == NULL){
            return head;
        }
        ListNode* curr= head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        while(curr != NULL){
            forward = curr -> next ; 
            curr -> next = prev;
            prev = curr; 
            curr = forward;
        
        }
        return prev; 
    }
};
//2n recurssion 
// ListNode* reverse1(ListNode*& head){
//     if(head == NULL || head -> next == NULL){
//         return head ;
//     }
//     ListNode* chotahead = reverse1(head->next);

//     head-> next-> next = head;
//     head -> next = NULL;
//     return chotahead;


// }




// with recursion 
// public:
//     void reverse(ListNode* cur, ListNode* prev , ListNode*& head){
//         if(cur == NULL){
//             head = prev;
//             return ;
//         }
//         ListNode* forward = cur -> next;
//         reverse(forward , cur , head );
//         cur ->next  = prev;
//     }
//     ListNode* reverseList(ListNode* head) {
//         ListNode* cur = head;
//         ListNode* prev = NULL;

//         reverse(cur, prev , head);
//         return head; 
