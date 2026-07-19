// here in this question we have number of subarray we have whose sum = k
//  for that we calculate sum for 

// for i < nums.size  i =0 ;
// sum =0;
//   for j = i  
//     sum+= nums[i]


// so we dont have to calculate again and again we make prefix sum chain 
// and
// Subarray Sum =  sum-oldSum = k
// oldsum = sum - k 
// so we dont need to calculte all old sum so store then in unordered_map
//  unodered_map stores Running Sum → Frequency
// and we can calulate count by count += mp[sum-k];

// if(mp.find(sum-k)!=mp.end()) this is the question asked have you seen this prfix before 
// if yes increse count+=mp[sum-k];


// now update the mp[sum]++

// ai form 
// Brute Force:
// 1. Start from every index.
// 2. Calculate the sum of every possible subarray.
// 3. If sum == k, increment count.
// Time: O(n²)

// Optimal Approach (Prefix Sum + Hash Map):
// 1. Maintain a running prefix sum (sum).
// 2. Store each prefix sum and its frequency in a hash map.
// 3. At every index, check if (sum - k) has occurred before.
//    - If yes, then the subarray between the previous prefix sum
//      and the current index has sum = k.
//    - Add its frequency to count because the same prefix sum
//      may have appeared multiple times.
// 4. Store the current prefix sum in the map for future indices.
//
// Why mp[0] = 1?
// - It represents the prefix sum before the array starts.
// - This allows subarrays starting from index 0 to be counted.
//
// Formula:
// Current Prefix Sum - Previous Prefix Sum = k
// => Previous Prefix Sum = Current Prefix Sum - k
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum =0; 
        int count= 0;
       unordered_map<int,int > mp;
         mp[0] = 1; 
        
        for(int i =0; i < nums.size(); i++){
           
            sum += nums[i];
            if(mp.find(sum -k)!= mp.end()){
                count += mp[sum-k];
            }
            mp[sum]++;

        }
        return count;
    }
};
