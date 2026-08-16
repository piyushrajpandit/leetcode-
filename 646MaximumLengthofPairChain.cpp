
/*
// LeetCode 646: Maximum Length of Pair Chain
//
// Approach: Greedy
//
// 1. Sort all pairs by their second element in ascending order.
//    -> We choose the pair that finishes earliest so that we leave
//       maximum possible space for future pairs.
//
// 2. Start with the first pair.
//    -> count = 1
//    -> b = ending value of the selected pair.
//
// 3. Traverse the remaining pairs.
//    -> If current pair's first element > b,
//       the current pair can be added to the chain.
//
// 4. When a pair is selected:
//    -> Increment count.
//    -> Update b to the current pair's second element.
//
// 5. Return count.
//
// Important condition:
//    current pair's first element > previous pair's second element
//
// Time Complexity:
//    O(n log n) -> sorting
//
// Space Complexity:
//    O(1) extra space (ignoring sorting implementation)
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 0 ) return 0;
        int count = 1; 
        sort(pairs.begin(), pairs.end(),[](const vector<int> & a, const vector<int> & b){
            return  a[1] < b[1];
        });
        
        int b = pairs[0][1];
        for(int i = 1; i< pairs.size(); i++){
            int one = pairs[i][0];
            int second = pairs[i][1];
            if(one > b){
                count++;
             
                b = second;
            }
        }
        return count;
    }
};
