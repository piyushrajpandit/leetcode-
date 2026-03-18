 #approach
    1. first find row and column of matrix 
    
        int row = matrix.size();
        int col = matrix[0].size();
   2. create a vector height 
        vector<int> heights(col, 0); 

   3. intial area = 0

   4. now one by ine first row and then col move forward if matrix[i][j] = 0 height =0 else increse last height + 

   5. for that find maximum area by formula of maximum area of histogram
  
             area = max(area,maximumarea(heights) );

    
          int maximumarea(vector<int> & heights ){
            int n = heights.size();
            vector<int> next(n);
            next = nextsmallestelement(heights,n);
    
            vector<int> prev(n);
            prev = prevsmallestelement(heights,n);
    
            int area = INT_MIN;
            for(int i =0 ; i<n ;i++){
                int l = heights[i];
                if(next[i]== -1){
                    next[i] = n;
                }
                int b = next[i] - prev[i] -1 ;
                int newarea = l*b;
                area = max(newarea, area);
            }
            return area;
    
        }
      vector<int> nextsmallestelement(vector<int> & arr, int n){
        stack<int> s ;
        s.push(-1);
        vector<int> ans(n);

        for(int i = n-1 ; i>=0 ;i--){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()]>=curr){
                s.pop();
            
            }
            ans[i]= s.top();
            s.push(i);

        }
        return ans;
    }
     vector<int> prevsmallestelement(vector<int> & arr, int n){
        stack<int> s ;
        s.push(-1);
        vector<int> ans(n);

        for(int i = 0 ; i< n ;i++){
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()]>=curr){
                s.pop();
            
            }
            ans[i]= s.top();
            s.push(i);

        }
        return ans;
    }
    
           
 
