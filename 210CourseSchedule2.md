#approach 
we have to make few finctions 
first we have to make 
1. toposort its bool
      here we have to due few things
   first mark visited true and dfsvisited true

   visited tells “Have I seen this node before?”
   and dfs visited tells “Is this node in my CURRENT path?”

   and how we have to move each neighbout of adj
   if its not visited we will check is their is cycle if cycle detected return true;
   else id dfsvisited[neighbour is true ] then we will return true means cycle existis
   now make dfs[node] visited as false push that node in s and return false 
3. findorder here we make adjcent matrix in so if [1,0] is given the take 0-> 1 because zero should their to go to 1
  now we have to do few things like it its not visited then we will check toposort
        toposort() does two jobs:
        
        DFS traversal
        Store nodes in correct topological order

   A node is pushed into stack only AFTER visiting all its neighbours.
   if cycle is detected return empty if

after that crete ans 
and take one elemnt from stack put in anser and remove form stack and do for the next elements 


 

