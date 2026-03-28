

 #apprach 
1. you need the one nodes left node roght node and parent node for this
2. for parent make mappping map<TreeNode*, TreeNode*> nodeToParent;
    to create mapping make a queue
   create a map for res
     push firrst root in queue
   while q !empty do the following
     take the front element of queue and put that in front and remove it from queeue
     next if front -> val == target ek barabar hai to target me stire kar lo nahi to res  do for frony left make
     front left me bhi front ko store ker lo aur queue me front dal do
     same do with right
     at last return res if you get the target
   
3. now you have to move k step in each direction for parents you have mapping else you have left and right
4. make queue for and push root
5. now make mapping treenode and bool name it visited
6. and run the loop till queue is not empty
      you have to make a flag if any element is added in this iteration make ans++ means you moved one step further from target
     now do for loop till q.size
       take out first element from queue and stroe it in front and remove it from queue
     if there is left part exist and it is not visited then make visit and flag to 1 and push element to queue and check if you
     moved  k steps ot not
     do same for right
     now at last you have to check to parent for that node check parent in mapping and it is visited or not if not visited then
     do same steps
   and in all these three you moves k step stoe that node in result 
     


