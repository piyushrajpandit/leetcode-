// deleling loop from linklist 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *flyodintersection(ListNode *head){
        ListNode * slow = head;
        ListNode * fast = head;

        while (fast!= NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow ->next;
            if(fast == slow){
                return slow;
            }
            
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* intersection = flyodintersection(head);
        if (intersection == NULL) return NULL;
        ListNode* slow = head;
        while(intersection != slow){
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;
    }
List *deleteNode(ListNode* head){
  if(head == NULL){
    return NULL;
  }
  ListNode * startingloop = detectCycle(head);
  ListNOde * temp = startinglloop;

  while (temp -> next != startingloop){
    temp = temp->next;
  }
  temp-> next = NULL;
  return tmep;
};
