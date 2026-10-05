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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* next = nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        while(head != nullptr && head->next != nullptr){
            next = head->next;
            int gcdval = gcd(head->val , next->val);
            ListNode* between = new ListNode(gcdval);
            head->next= between;
            between->next = next;
            head = next;

        }
        return dummy->next;
    }
};
