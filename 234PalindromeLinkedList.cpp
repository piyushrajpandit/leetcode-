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
    bool checkpalindrome(vector <int> arr){
        int start = 0 ; 
        int end = arr.size() -1;
        while (start<end){
            if(arr[start]!=arr[end]){
                return false;
            }
            start++;
            end--;
          
        }
          return true ;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> arr; 
        ListNode * temp = head ; 

        while (temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return checkpalindrome(arr);
    }
};


//approach 2 
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
ListNode * getmiddle(ListNode *head){
    ListNode* slow = head; 
    ListNode* fast = head->next ; 
    while(fast!=NULL && fast->next !=NULL){
        slow = slow ->next;
        fast= fast->next;
        if(fast->next!=NULL){
            fast = fast ->next;
        }
       
    }
     return slow;

}
ListNode* reverse(ListNode *head){
    ListNode * curr = head ; 
    ListNode *prev = NULL;
    ListNode * next= NULL;
    
    while(curr != NULL){
        next = curr->next ; 
        curr->next = prev; 
        prev = curr ;
        curr = next ; 
    }
    return prev;

}
  
    bool isPalindrome(ListNode* head) {
        if(head ->next == NULL){
            return true;
        }
     //find middle 
     ListNode * mid = getmiddle(head);
     //to do that we will use slow and fast 

     //make two linklist 

     //reverse the second linklist 
     ListNode *temp = mid->next;
     mid->next = reverse(temp);


     // compare both link list 
     ListNode * head1 = head ;
     ListNode * head2 = mid->next;
     while(head2!=NULL){
        if(head1->val!= head2->val){
            return false ;
        }
        head1 = head1->next;
        head2 = head2->next;
     }
     //repeat 2 beacuse you want to give same list as it 
     temp = mid->next ;
     mid->next = reverse(temp);
     return true;
    }
};
