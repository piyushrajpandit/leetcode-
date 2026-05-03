#appraoch 
we have make first adjacent matrix
we have to make indegre 
now make a queue
and if indegree == 0 push that in queue
now make count 
and start a while loop till q not became empty 
take first elment of queue and decreement its indegreee for all its neighbour
remove it from queue and increse count 
 and if its indegree became == 0 push it in q 

 if at last count == numCourses then return true else return false 
