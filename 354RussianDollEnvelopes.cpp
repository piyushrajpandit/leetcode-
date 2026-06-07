dekho yaha par kya karna hai 
sabse pehle jo diya rahta hai yo vector(row)(coulmn) hota hai 
row = width 
column = height 

arrange row in incresing order 
and if it is same then arrange column in decending order 

now apply height vector and add height part means vector[1] 
in it and apply longesst increassing subsequence function we have done this in leetcode 300 
so you get the answer 
 here are two version of code
difference is only sort function second one is chatgpt one and first one is easy one 


class Solution {
public:

    // Custom comparator
    static bool cmp(vector<int>& a, vector<int>& b) {

        // If widths are same,
        // sort heights in descending order
        if(a[0] == b[0]) {
            return a[1] > b[1];
        }

        // Otherwise sort widths in ascending order
        return a[0] < b[0];
    }

    int LIS(vector<int>& heights) {

        vector<int> ans;
        ans.push_back(heights[0]);

        for(int i = 1; i < heights.size(); i++) {

            if(heights[i] > ans.back()) {
                ans.push_back(heights[i]);
            }
            else {

                int index =
                    lower_bound(
                        ans.begin(),
                        ans.end(),
                        heights[i]
                    ) - ans.begin();

                ans[index] = heights[i];
            }
        }

        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        if(envelopes.size() == 0) {
            return 0;
        }

        // Step 1: Sort envelopes
        sort(
            envelopes.begin(),
            envelopes.end(),
            cmp
        );

        // Step 2: Extract heights
        vector<int> heights;

        for(int i = 0; i < envelopes.size(); i++) {
            heights.push_back(envelopes[i][1]);
        }

        // Step 3: Find LIS on heights
        return LIS(heights);
    }
};





class Solution {
public:
    int solve(vector<int> &a){

       vector<int> ans;
       ans.push_back(a[0]);

       for(int i=1; i<a.size(); i++){
        if(a[i] > ans.back())
            ans.push_back(a[i]);
        else{
            //find index of just bada element in ans 
            int index = lower_bound(ans.begin(), ans.end(), a[i])- ans.begin();
            ans[index] = a[i];

        }
       }
       return ans.size();

    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
     [](vector<int>& a, vector<int>& b) {
         if(a[0] == b[0])
             return a[1] > b[1];   // height descending
         return a[0] < b[0];       // width ascending
     });

        vector<int> heights;

        for(auto& e : envelopes) {
            heights.push_back(e[1]);
        } 
        
         return solve(heights);
        
        
    }
};
