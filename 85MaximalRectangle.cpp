class Solution {
public:
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col, 0); 
        int area =0;
        for(int i = 0 ; i< row ; i++){
            for(int j =0 ; j<  col; j++){
                if(matrix[i][j]!= '0'){
                 heights[j]++; 
                }
                else{
                   heights[j] = 0;
                }
                
            }
             area = max(area,maximumarea(heights) );
           
        }
        return area;
    }
};
