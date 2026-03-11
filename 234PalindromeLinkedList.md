#approach 1 
1. make a array and copy linklist data in it 
2. use to check plindrome for array by that 
time complexity o(n)
and space complexity o(n)



#approach 2 
space complexity o(1)
time complexit o(n)
1 Find middle 
  slow and fast method 

2 Reverse second half
  reverse karne ke liye ye use karo
  
  while curr!= null
  curr ->next = prev ;
  prev= curr ;
   curr = next 

   return prev 
   
   
3 Compare both halves
one by one each iteration increase karo 


4 Restore the list

repeat step 2 
