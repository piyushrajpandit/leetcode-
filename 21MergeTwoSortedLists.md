
#approach 
1. you have to find the least head of the two list and start from there so make a function and put the first least at front of function
2. in fuction you have to chose first two element and the think if any element from second list that is can insert between
3. to do that make three pointers 2 in first list between them er have to insert and one in second list which element we  have to insert
4. just small check if their is only one element in list  1 you make make two pointer so add a if check and add second list after that
5. now we have to transver the list till second pointer of first list or second list ponter not became null
6. if second list value of current pointer is between the first list pointer then insert it and move to next element in second list
7. when we move first element of second list we can lose its excess so make a pointer to store it then move the head in between 
8. else increse the two pointer of first list one step and check between them
9. if first list pointer became null add second list and one return the list 
