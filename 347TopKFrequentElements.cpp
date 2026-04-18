// #approach 
// first make hashmap each element with its count and element 
// second thing is push that in proiorty heap max heap 
// and push top k element in the answer; 



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;
        unordered_map<int ,int> count;
        priority_queue<pair <int, int>> pq;
        
        for(int i =0; i < nums.size(); i++){
            count[nums[i]]++;
            
        }
      //it here used to traverse by pair 
        for(auto &it : count){
            pq.push({it.second, it.first});
        }
        
        for(int i= 0 ; i< k ; i++){
            
            ans.push_back(pq.top().second);
            pq.pop();

        }
        return ans;
       
    }
};
