#approach 
1. crete a queue that is double ended
2. put the index of first k number in deque
3. now if queue is not empty and front of deque is i-k means at out of box remove one front element
4. while dq is not empty and nums[dq.back()] < nums[i] means current element is grates then  prevous element remove last elements from back
5. and add current element
6. and if i reaches k-1 plus or equal then put the element in answer and re do these iterations 
  
        

        for(int i =0 ; i < N ;i++ ){
            //removal
            if((!dq.empty() )&&(dq.front() == i- k )){
                dq.pop_front();
            }
           
            // remove smaller elements from back
        while(!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i);

        // window fully formed, store answer
        if(i >= k - 1)
            ans.push_back(nums[dq.front()]); 

        }

return ans;

    }
};
