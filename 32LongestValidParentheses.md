#appraoch 

tranverse the string and do these
1. make two stack first with the iteration stored at which place ( is ther and second store the ( it self
2. if you get ) the check if st1 is not empty and second stack has ( at top
3. then store * at these places in string given by removing bracket
4. and pop both of them from stack both stack
5. now you have string with collection * if correct brackets are their
6. now make two variabel count and result
7. each * comes store count +1 and if their is no star then max bet result and count stored in count and count became 0 and again do for next iterations
8. now last iteration is not stored if last is * then do 

       
        result = max(result, count); 
  9.      return result;
