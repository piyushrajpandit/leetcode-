
/*
LeetCode 24: Swap Nodes in Pairs

Approach: Linked List Pointer Manipulation

1. Create a dummy node before head so the first pair can be swapped easily.
2. Use prev to point to the node before the current pair.
3. For every pair:
       first  = prev->next
       second = first->next
4. Swap the nodes by changing their next pointers:
       first->next = second->next;
       second->next = first;
       prev->next = second;
5. Move prev to first because after swapping, first becomes the second
   node of the pair.
6. Continue while two nodes are available.
7. Return dummy->next as the new head.

Example:
1 -> 2 -> 3 -> 4

First pair:
1 -> 2
becomes:
2 -> 1

Second pair:
3 -> 4
becomes:
4 -> 3

Result:
2 -> 1 -> 4 -> 3

Important:
We are swapping the actual NODES by changing next pointers,
not just swapping their values.

Time Complexity: O(n)
Space Complexity: O(1)

Remember:
prev -> first -> second

After swap:
prev -> second -> first -> next pair
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        

        while(prev->next != nullptr && prev->next->next != nullptr){
          ListNode* first= prev->next;
          ListNode* second = first->next;

          first->next = second->next;
          second->next = first;
          prev->next =second;

          prev = first;
            
        }
        return dummy->next;
    }
};
