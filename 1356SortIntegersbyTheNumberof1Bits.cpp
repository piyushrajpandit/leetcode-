// unordered_map is unsortable 

// in this question we have to sort numbers according to number of 1 they contain to do this we have to 
// count number of 1 then we store them in unordered map now we will get one element at a time and then secnod element and sort them 


// we have written here is custom sort function 
// out comparator is 
// [&](int a, int b) {
//     ...
// }

// think it as 
// bool compare(int a, int b)

// if function true a comes first 
// else b comes first 
// first we are if number of one are same in both then we are comparing it number 
// else we are comparing the number of one and according to  number of 1 we are arranging then 

// to count number of 1 we use 
// n&1 this is and operator for the digit like 
// 0 & 0 = 0 
// 1 & 1 = 1
// 1 & 0 = 0 
//   so if number is odd answer is one 
// else 0
//   after that we are doing n>>= 1 here 


 class Solution {
public:
    //first make fuction to calculate number of 1 
    int One(int n){
        int count = 0;
        while( n> 0){
            int ans = n&1;
            if(ans == 1 ){
                count++;
            }
            n >>= 1;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        unordered_map<int, int> dp;
        for(int i =0 ; i < arr.size(); i++){
            
            dp[arr[i]] = One(arr[i]);
        }
        sort(arr.begin(), arr.end(), [&](int a, int b){

                if(dp[a] == dp[b])
                    return a < b;

                return dp[a] < dp[b];
            });
        return arr;
    }
};
