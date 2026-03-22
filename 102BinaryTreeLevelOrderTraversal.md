#appraoch 

1. first make a queue and store root address
2. now make double vector answer inwhich you return answer
3. now start a loop till q is not empty
   1.now start a for loop for size of q like for first level q .size 1 only root for next 2
   2.now stroe the q.front in temp and pop it out of q
   3. push temp data in q
   4. now put temp -> left in queue and then temp -> right in queue
   5. now if you are at 2nd level for loop goes for 2 times first it store left ->left and then left-> right and same for right and q becames 4 size
   6. but before that both iteration will be completed
   7. when both completed then push level in anwser and create new level for another one 



      
            
   
