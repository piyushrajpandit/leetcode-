/*
LeetCode 61: Rotate List

Approach: Find Length + Make List Circular

Example:
1 -> 2 -> 3 -> 4 -> 5, k = 2

After rotating right 2 times:
4 -> 5 -> 1 -> 2 -> 3

Steps:

1. If head is nullptr, only one node, or k == 0, return head.
2. Traverse the list to find:
       - length of the list
       - last node (tail)
3. Use k = k % length because rotating length times gives the
   original list.
4. Connect tail to head to make the list circular:
       tail->next = head;
5. Find the new tail.
   The new tail is at position:
       length - k
6. The node after newTail becomes the new head:
       newHead = newTail->next;
7. Break the circular list:
       newTail->next = nullptr;
8. Return newHead.

Example:
1 -> 2 -> 3 -> 4 -> 5, k = 2

Circular:
1 -> 2 -> 3 -> 4 -> 5
     ^              |
     |______________|

newTail = 3
newHead = 4

Break after 3:

4 -> 5 -> 1 -> 2 -> 3

Important:
k = k % length avoids unnecessary rotations.

Time: O(n)
Space: O(1)

Remember:
Find length -> k % length -> make circular ->
find new tail -> break circle -> return new head.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
            return head;
        int len = 1;
        ListNode* tail = head;
            while(tail->next != nullptr){
                tail = tail->next;
                len++;
            }
            k= k% len;
            if(k==0 )
                return head;

            tail->next = head;
            ListNode* newTail = head;
            for(int i =1; i< len - k ; i++){
                newTail = newTail -> next;
            }
            ListNode* newHead = newTail-> next;
            newTail->next = nullptr;
        
        return newHead;
    }
};
