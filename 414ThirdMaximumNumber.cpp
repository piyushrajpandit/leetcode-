

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        if(s.size() < 3){
           return *s.rbegin();
        }
        int count =0 ; 
        for(auto x = s.rbegin(); x!= s.rend(); x++){
            count++;
            if(count ==3 )
                return *x;
        }
        return 0;
    }
};

/*
set<int> s(...) → removes duplicates and sorts numbers.
s.rbegin() → starts from the largest number.
s.rend() → marks the end of reverse traversal.
auto x → x is an iterator pointing to a number.
*x → gets the actual number.
count++ → counts largest, second largest, third largest.
count == 3 → we found the third maximum, so return *x.

*/
