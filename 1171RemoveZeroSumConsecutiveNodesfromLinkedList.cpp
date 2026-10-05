/*
Approach: Prefix Sum + Hash Map

1. Create a dummy node before the head so that we can
   easily remove zero-sum nodes starting from the head.

2. FIRST PASS:
   - Calculate the prefix sum while traversing the list.
   - Store each prefix sum with the LAST node having that sum.
   - If the same prefix sum occurs again, the nodes between
     those two positions have sum = 0.

3. SECOND PASS:
   - Calculate the prefix sum again.
   - For the current sum, find the LAST node with the same sum.
   - Jump to the node after it:
       temp->next = mp[sum]->next;
   - This skips all consecutive nodes whose sum is 0.

Example:
   1 → 2 → -3 → 3 → 1

   Prefix sum becomes:
   1 → 3 → 0 → 3 → 4

   Since the prefix sum 0 repeats, 1 + 2 + (-3) = 0,
   so those nodes are removed.

Final:
   3 → 1

Time Complexity: O(n) average
Space Complexity: O(n)
*/
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode * dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int , ListNode*> mp;
        int sum =0 ;
        ListNode* temp = dummy;
        while(temp!= nullptr){
            sum += temp->val;
            mp[sum] = temp;
            temp = temp->next;
        }
        sum = 0 ;
        temp = dummy;
        while(temp != nullptr){
            sum += temp->val;
            temp->next = mp[sum]->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
