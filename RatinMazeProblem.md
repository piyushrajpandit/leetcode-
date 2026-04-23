we have 3 finction first is to check safe of not to move 
we have check 4 things that its should not be visited 
it should be 1 
and newx>=0 and newx< n same with y to maintain it in range

2nd function is solve for this we 
first create base case if x ==n-1 and y == n-1 means it reach the final diestination then break it 
first this is make it visited if its safe then go down left right and up recurrsive ly and at last when you are back tracking mark them 0 as visited 


  
🧠 Backtracking (actual meaning)

Backtracking is:

Try a choice → go deeper → if it fails, undo it and try another choice

It’s basically controlled trial-and-error with memory.

🪤 Think of it like this

You’re in a maze:

You pick a path
Walk until:
You reach the end ✅
Or hit a dead end ❌
If dead end → go back and try a different path

That “go back and try again” = backtracking
