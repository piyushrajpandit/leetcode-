  class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trust_count(n,0);
        for(vector<int> t: trust){
            trust_count[t[0]-1]--;
            trust_count[t[1]-1]++;
        }
        int result = -1; 
        for(int i=0; i< n; ++i){
            if(trust_count[i] == n-1)
                return i+1;
        }
        return result;
    }
};

// #apprach first thing we do is make a trust count of n and put every thing as 0
// now we one by one each of trust open it and make first count -- and seconf count ++ and at last result = -1 and if trust count of any is 
// equla to n-1 then retunr that index else return -1 
