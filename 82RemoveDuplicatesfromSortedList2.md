#approach 
1. first is like head and head next are duplicates so you have to remove both of them them to do this you can make dummy head 
ListNode * dummy = new ListNode(0);
and at the time of return return dummy->next;
and mention curr = head 
            prev = dummy 

2. while value of curr value and curr next value are same increase iteration by deleting one item to do that 
curr - > value ko value me save karlo
while (curr!= NULL && curr_>val = value )
then delete curr 
to do that 
crete ListNOde *temp = curr
now increse curr = curr_>next 
delete (temp);

3. when while is complete also increse prev = curr;

4. else increse curr  = curr_>next
   prev = curr
