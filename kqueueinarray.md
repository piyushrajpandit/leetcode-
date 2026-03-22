#approach 
1. crete variable arrays
  1. front which is of k space and it store the front of each query  (all are -1 in starting)
   2. rear which contain last of k th quey index    (all are -1 in starting)
   3. next which contain the 
      next[] has two jobs at the same time:

              1️⃣ Connect elements inside each queue
              2️⃣ Maintain the list of free spaces in the array
                     
2. crate free variable contain first freespace 

3. push
   1. check if full  freespot == -1;
   2. find freespace ( index = freespace)
   3. check if its first element (front[qn-1] == -1 if its first element update front
   4. else if its not first elment link new element to prev elment by next  next(rear[qn-1])= index;
   5. update next    next =-1 ;
   6. update rear (rear[qn-1] = index
   7. push element arr[index]= data
  
4. pop
   1. check if underflown   front[qn-1]=-1
   2. find top index           indexx = front[qn-1];
   3. front ko increase karo          front[qn-1]= next[index];
   4. freeslot jo hai agar wo array ka index hua jiske baad koi element ho kaise pata chale ga iss liye  next[index] = freespot dalo
   5. freespot = index dalo 

      

          

  
}


