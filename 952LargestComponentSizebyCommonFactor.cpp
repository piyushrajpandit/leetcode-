/*Find maximum
     ↓
Initialize DSU
     ↓
Find prime factors of every number
     ↓
Union(number, each prime factor)
     ↓
Find root of every number
     ↓
Count numbers per root
     ↓
Return largest count

*/
// LeetCode 952 - Largest Component Size by Common Factor
//
// Approach: DSU + Prime Factorization
//
// 1. Treat every number and its prime factors as DSU nodes.
// 2. For every number, find all its distinct prime factors.
// 3. Union the number with each of its prime factors.
//    Example:
//       6  -> factors {2,3}
//       10 -> factors {2,5}
//       15 -> factors {3,5}
//    Since they share factor nodes, they become one component.
//
// 4. After all unions are completed, find the root of every
//    original number and count how many numbers belong to each root.
//
// 5. The largest frequency is the size of the largest component.
//
// Prime factorization:
// - Check divisors from 2 while j * j <= n.
// - When a factor is found, add it once.
// - Divide n repeatedly by that factor to remove duplicates.
// - If n > 1 after the loop, n itself is a prime factor.
//
// Complexity:
// - Prime factorization: approximately O(sqrt(M)) per number,
//   where M is the maximum value.
// - DSU operations are nearly O(1) amortized due to path compression.
// - Overall efficient enough for the problem constraints.
class Solution {
public:
    vector<int> parent;
    int find(int i){
        if( parent[i] == i)
            return i;
        return parent[i]  = find(parent[i]);
    }
    void unite(int i, int j){
        int rootI = find(i);
        int rootJ = find(j);
        if(rootI != rootJ)
            parent[rootJ] = rootI;
    }
    vector<int> prime(int i){
        vector<int> ans;
       
           for(int j =2 ; j*j <= i ; j++){
                if(i % j == 0 ){
                    ans.push_back(j);
                    while( i% j == 0)
                        i/= j;
                }
            } 
        if( i>1)
            ans.push_back(i);
        return ans;
    }
    int largestComponentSize(vector<int>& nums) {
        int max =0 ;
        for(int i = 0 ; i< nums.size(); i++){
            if(max < nums[i])
                max= nums[i];
        }
        parent.resize(max + 1);
        for(int i =0; i< parent.size() ; i++){
            parent[i] = i;
        }
        unordered_map<int, int > frequency;
        for(int i=0; i< nums.size(); i++){

            vector<int> primeNo = prime(nums[i]);
            for(int j =0 ; j< primeNo.size() ; j++ ){
                   unite(nums[i], primeNo[j]);
                }
        }
         for(int i=0; i< nums.size(); i++){
  
                    int root = find(nums[i]);
                    frequency[root]++;
   
        }
        int maximum = 0;
        for(auto curr : frequency){
            if(maximum < curr.second)
                maximum = curr.second;
        }
        return maximum;
    }
};
