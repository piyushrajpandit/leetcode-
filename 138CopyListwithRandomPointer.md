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
   
  
