class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       
        unordered_map<char, int> freq;
        for(int i =0 ; i< tasks.size() ;i++){
            freq[tasks[i]]++;
        }
        priority_queue<int> times; // greates element first;
        for(auto temp: freq){
            times.push(temp.second);
        }
        int count = 0;
        while(!times.empty()){
            vector<int> temp;
            int cycle = n+1;
            for(int i =0 ; i<=n ; i++){
                if(!times.empty()){
                    int f = times.top();
                    times.pop();
                    if(f> 1){
                        temp.push_back(f-1);
                    }
                    count++;
                    cycle--;
                }
            }
            for(int f : temp){
                times.push(f);
            }
            if(!times.empty()){
                count+= cycle;
            }
          
        }
        return count;

    }
};
