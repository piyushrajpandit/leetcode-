#approach 
you have to ad two number 

1. step 1 carry 0 
2. create answer head and answer tail
3. step 2 find sum
4. if both are not equal to null
5. find digit %10. node bano 
         int sum = carry + first->val +second->val;
         int digit = sum % 10;
         
         insertattail(anshead, anstail, digit);


         carry = sum /10;
         first = first ->next;
         second = second -> next;
6. same case if first != null
7. and case second != null
8. at last if carryk remains only sum = carry ;







