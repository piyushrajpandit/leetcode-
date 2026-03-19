#appraoch 1;

here we can create a new stack that store minimum element for every element 
but it take space o(N);

#appraoch 2 
1. crete a stack
2. and a minimum variable
3. if value you are inserting is less than min than insert 2*val - minimun in stack 
4. else directly push the element in stack 
6. reason because you want the excess of old minimum for current 


7. pop if curr > min   pop top simply 
8. if not then mini = 2* mini - curr and pop current 


    
 use this formula you can easily have access to prev current by this way

1. While PUSH (when new value is smaller)
encoded = 2 * val - mini
mini = val

2. While POP (when encoded value is detected)
previous_min = 2 * mini - encoded
mini = previous_min
