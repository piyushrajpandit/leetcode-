#approach 
1.
if root is null return null;
2.if 1st case is only have 0 child then delete root and return null
3. if it has one child then if left child is their store left in temp and delete root and return temp
4.similary with right 
5. if two child are there 
6. first find either left maximum or right minimum by different function 
7/ next step change root ->val to right minimum 
8. and then right-> node = deleteNode (rooot->right,mimi);
and return root ;


make sure you first find the correct node by going traversing to their by recurssion if 
key value is less then current then do deleteion in right part 
similary with left part 


     

 
