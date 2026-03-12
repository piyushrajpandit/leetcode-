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
void  insertattail(ListNode *& anshead, ListNode *& anstail, int val){
    ListNode * temp = new ListNode(val);
    if(anshead == NULL){
        anshead = temp ;
        anstail = temp ; 
        return;

    }
    else{
        anstail -> next = temp ; 
        anstail= temp;
    }

}

// add better code optimized 
// struct ListNode * add(ListNode * first,ListNode * second){
//     //step 1 carry 0 
//     int carry = 0 ;
   
//    ListNode * anshead = NULL;
//    ListNode * anstail = NULL; 
//     //step 2 find sum 
//     while(first != NULL || second != NULL || carry != 0  ){
//         int val1 = 0;
//         if(first != NULL){
//             val1 = first -> val;
//         }
//         int val2 = 0 ;
//         if(second != NULL){
//             val2 = second -> val;
//         }
//         int sum = carry + val1 + val2 ; 
   
//          int digit = sum % 10;
         
//          insertattail(anshead, anstail, digit);

//     //carry /10
//          carry = sum /10;
//          if(first != NULL)
//          first = first ->next;
//          if(second != NULL)
//          second = second -> next;
//     }
   
   
//     return anshead;
// }

struct ListNode * add(ListNode * first,ListNode * second){
    //step 1 carry 0 
    int carry = 0 ;
   
   ListNode * anshead = NULL;
   ListNode * anstail = NULL; 
    //step 2 find sum 
   while (first!= NULL && second != NULL ){
        //find digit %10. node bano 
         int sum = carry + first->val +second->val;
         int digit = sum % 10;
         
         insertattail(anshead, anstail, digit);

    //carry /10
         carry = sum /10;
         first = first ->next;
         second = second -> next;
    }
    while (first != NULL){
        int sum = carry + first->val;
          int digit = sum % 10;
         insertattail(anshead, anstail, digit);
          carry = sum /10;
          first = first ->next;
    }
    while (second != NULL){
         int sum = carry + second->val;
           int digit = sum % 10;
         insertattail(anshead, anstail, digit);
          carry = sum /10;
          second = second -> next;
    }
    while(carry != 0 ){
        int sum = carry ;
        int digit = sum % 10;
        insertattail(anshead, anstail, digit);
        carry = sum /10;
    }
    return anshead;
}
ListNode * reverse(ListNode * head){
    ListNode * curr = head;
    ListNode * prev = NULL;
    ListNode * next = NULL;
    while (curr!= NULL){
        next = curr->next;
        curr->next = prev ;
        prev = curr;
        curr = next ;
        }
    return prev ;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //step 1 reversre input link list 
      

        ListNode * result = add (l1,l2);
         
       
         return result; 
    }
};
