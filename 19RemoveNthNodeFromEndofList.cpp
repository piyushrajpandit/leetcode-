/*
LeetCode 19: Remove Nth Node From End of List

Approach: Two Pointers (Fast & Slow)

1. Create a dummy node before head so deleting the first node is also handled easily.
2. Set both fast and slow at dummy.
3. Move fast n steps ahead. This creates a gap of n nodes between fast and slow.
4. Move both fast and slow together until fast reaches the last node.
5. Now slow is exactly one node before the node we need to remove.
6. Remove that node using:
       slow->next = slow->next->next;
7. Return dummy->next because the original head may have been removed.

Example:
1 -> 2 -> 3 -> 4 -> 5, n = 2

After moving fast n steps and then moving both pointers,
slow reaches node 3.
Node 4 is the 2nd node from the end, so remove it:

slow->next = slow->next->next;

Result:
1 -> 2 -> 3 -> 5

Time Complexity: O(n)
Space Complexity: O(1)

Remember:
Move fast n steps -> move both together -> slow skips the target node.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode * fast = dummy ;
        ListNode * slow = dummy;

        while( n>0){
            fast= fast->next;
            n--;
        }
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        slow-> next = slow->next->next;
        return dummy->next;
    }
};
