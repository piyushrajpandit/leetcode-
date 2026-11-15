class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin() , bank.end());

        queue<string> q;
        q.push(startGene);

        int count =0 ;
        while(!q.empty()){
            int n = q.size();
            while(n--){
                string gene = q.front();
                q.pop();

                if(gene == endGene){
                    return count;
                }
                for(string nextGene : bank){
                    int diff = 0;

                    for(int i =0 ; i< gene.size(); i++){
                    if(gene[i] != nextGene[i]){
                        diff++;
                    }
                }
                if(diff == 1 && st.find(nextGene) != st.end()){
                    q.push(nextGene);
                    st.erase(nextGene);
                }
            }
        }
        count++;
        }
      return -1;
    }
};



