// brute force 
// for(i)
//     for(j)
//         for(k)
//             for(l)

// first sort 

// so our approach fix tow first number i and j 
// and then two pointer approach for remaining using left and right 

// for(i)

//     for(j)      j starts from i + 1 

//         left        == i+1

//         right       == n-1 

//         while(left<right)




// case 1 sum == target move both targets 

// case 2 sum < target means increse left to increase sum 

// case 3 sum > target  means want smaller element decrese from right 


// now the problem is that is we wil get duplicate numbers 
// to solve this if nums[i] = nums[i-1] if this happen then we continue 
// and same we do for j 
// still one place 
// we get duplicate numbers in left and right 
// so place there also 

// at last problem is sum may over flow to solve this we sum sum as long long that is used as 

//   long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];

// now we have whole solution 




class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        
            
            int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i =0 ;  i< n-3; i++){
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            for(int j =i+1 ; j < n-2 ; j++){
                  if(j > i + 1 && nums[j] == nums[j - 1])
                        continue;
                int left = j+1; 
                int right = n-1; 
                while(left < right){
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                       while(left < right && nums[left] == nums[left - 1])
                            left++;

                        while(left < right && nums[right] == nums[right + 1])
                             right--;
                    }
                    else if( sum < target){
                        left++;
                    }
                    else{
                        right--;
                    }
                }
            }
           
        } 
       return ans;
       
    }
};
