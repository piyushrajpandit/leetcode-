#approach 
make one mini 
and make one maxi 
and one i 
now point mini to lowest and maxi to highest 

create a new node 

now start a function input are preorder mini maxi i 
base case 
create a new node 
if i > preorder .size return null
or preorder[i] < mini  or preordr [i] < maxi return null

now call recurssion 
of left part and recussion for the right part as well
