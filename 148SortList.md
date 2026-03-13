#appraoch 
1. find mid  (slow and fast wala method use karo )
2. left part alag right part alag
3. abb left right pe recurrsion call karo
4. left right ko merge karo answer return karo

merge karne ka code 
complexity o(nlogn)
ListNode * merge (ListNode * left , ListNode * right){
    if(left == NULL){
        return right ; 
    }
    if(right == NULL){
        return left ; 
    }
    ListNode * ans = new ListNode (-1);// dummy node hai 
    ListNode * temp = ans;
    while(left != NULL && right != NULL){
        if(left->val < right->val){
            temp->next = left ;
            temp = left ;
            left = left->next ;
        }
        else {
              temp->next = right ;
            temp = right ;
            right = right->next ;
        }


        }
        while(left !=NULL){
            temp->next = left ;
            temp = left ;
            left = left->next ;
        }
        while(right != NULL){
            temp->next = right ;
            temp = right ;
            right = right->next ;
        }
        ans = ans->next ;
        return ans;

    }


