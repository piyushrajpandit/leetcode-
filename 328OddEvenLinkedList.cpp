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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr){
            return nullptr;
        }
        ListNode * odddummy = new ListNode(0);
        ListNode * evendummy = new ListNode(0);

        ListNode * odd = odddummy;
        ListNode * even = evendummy;

        ListNode * temp = head;
        int pos = 1;

        while(temp!= nullptr){
            if(pos %2 == 0){
                even->next = temp;
                even = even->next;
            } 
            else{
                odd->next = temp;
                odd = odd->next;
            }
            temp = temp->next;
            pos++;
        }
        even->next = nullptr;
        odd->next = evendummy->next;
        return odddummy->next;
    }
};
