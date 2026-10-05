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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
      
        ListNode* start   = list1;
        for(int i =0 ; i< a-1; i++){
            start = start->next;
        }
        ListNode* end =start ;
        for(int i = a; i<= b; i++){
            end = end->next;
        }
        start->next = list2;
        ListNode* temp= list2;
    
       
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = end->next;
        return list1;
    }
};
