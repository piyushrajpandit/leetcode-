maximum width = n - p -1
n = next smallest element 
p = prevous smallest element

time complexity o(n)
space complexity o(n)


#appraoch 
find maximum width 
  1. to find that we have find last samll element and next small element to find that we have function

              how to do this 
              first last element ka samllest elemnt -1 rakho 
              aur ek ek kar ke age baado of curr next wale se chota hai to top ko pop kara do 
              aur uss bar ka next small element stack ke top wala hoga 
              fir ek step piche jaoo aur isse element ko push kar do 



   2. vector<int> nextSmallestElement(vector<int>& heights, int n){
        stack<int> s ;
        s.push(-1);
        vector<int> ans(n);
        for(int i = n-1 ; i >= 0 ; i--){
            int curr = heights[i];
            while(s.top() != -1 &&heights[s.top()]>= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

3. same for prev 

    vector<int> prevSmallestElement(vector<int>& heights, int n){
        stack<int> s ;
        s.push(-1);
        vector<int> ans(n);

4. bass loop change karo 
        for(int i = 0 ; i < n ; i++){
            int curr = heights[i];
            while(s.top() != -1 &&heights[s.top()]>= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }


 5. now har bar ke liye maximum area nikla lo aur maximum ko store karate raho 

        
    }
};
