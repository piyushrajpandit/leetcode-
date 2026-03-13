#approach 1 
1. make simple copy of list
2. count how much far is random pointer and then connect it manually 
3. now one by one for each node copy the random pointers
4. time com o(n^2)


#appraoch 2 
1. copy simple link list crete a clone list using next pointers
3. do the mapping of link list
4. unordered_map<Node * , Node * > OldToNew;  and this is  OldToNew[orignalNode] = cloneNode; is mapping code 
5. and ti get clone->random = mapping(orignal , random )      cloneNode ->random = OldToNew[orignalNode ->random];
6. time complexity o(n)
7. time complexity o(n)
   
  
#approach 3 
1. Create a clone list
2. clonenode and add in between orignal
3. yaha par dono linklist for joe rahe hai purane next tor kar
4. step 2 
            3. node * next = orignal->next;
            4. orignal->next = clone;
            5. orignal->node = next

   same for clone 
            3. node * next = clone->next;
            4. clone->next = clone;
            5. clone->node = next
6.  step 3  random pointer set temp -> nexxt ->random  = temp ->random -> next
7.  https://youtu.be/83mPr0i56Gg?si=tZKCqQLSX5njDmbK
8.  step 4  revert changes in step 2 (jo pehle tore the wo thik kar rahe hai)
            9.  orignal->next = clone ->next ;
            10.  orignal = orignal ->next ;
    same for clone node 
            9.  clone->next = orignal ->next ;
            10.  clone = clone ->next ;
11.  step 5 return answer
12.  time complexity o(n)
13.  space complexity o(1) 
