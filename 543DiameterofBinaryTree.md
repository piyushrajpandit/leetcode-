#appraoch 
diameter 
longest path between any two nodes

so it can be either left part diameter 
or it can be right part diameter 
or it can be both

so first use recurssion and find left part diameter base case null hai to zero
and for both find left part height and right part height and add 1 
and answer is maximum 

so just write a function of height for this and you are ready but time complexity is o(n^2)
to deal with this we have to write a function and return a pair 
of diameter fo height and diameter 
to do this we have code little complex but its same as finding height and recurssion 
